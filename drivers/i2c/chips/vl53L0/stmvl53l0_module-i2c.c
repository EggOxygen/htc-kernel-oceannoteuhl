/*
 *  stmvl53l0_module-i2c.c - Linux kernel modules for STM VL53L0 FlightSense TOF
 *							sensor
 *
 *  Copyright (C) 2016 STMicroelectronics Imaging Division.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/input.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/time.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>
#include <linux/regulator/consumer.h>
#include <linux/pinctrl/consumer.h>
#include <linux/clk.h>
#include <linux/of_gpio.h>
#include "vl53l0_api.h"
#include "vl53l0_def.h"
#include "vl53l0_platform.h"
#include "stmvl53l0-i2c.h"
#include "stmvl53l0-cci.h"
#include "stmvl53l0.h"
#ifndef CAMERA_CCI

#define HTC_MODIFY
#define HTC
#ifdef HTC
#define CALIBRATION_DATA_PATH "/calibration_data"
#define SENSOR_FLASH_DATA "gyro_flash"
#endif
static int stmvl53l0_parse_vdd(struct device *dev, struct i2c_data *data);
struct laser_device_data *g_laser_data;

static int stmvl53l0_parse_vdd(struct device *dev, struct i2c_data *data)
{
    int ret = 0;

    vl53l0_dbgmsg("Enter++\n");

    if (dev->of_node) {
        data->vana = regulator_get(dev, "vdd");
        if (IS_ERR(data->vana)) {
            vl53l0_errmsg("vdd supply is not provided\n");
            ret = -1;
        }
    }
    vl53l0_dbgmsg("End--\n");

    return ret;
}

#ifdef HTC
static int Laser_parse_dt(struct device *dev, struct stmvl53l0_data *data)
{
    struct device_node *dt = dev->of_node;
    struct device_node *sensor_offset;
    char *sensor_cali_data = NULL;
    int sensor_cali_size = 0;
    int i = 0;

    data->pwdn_gpio = of_get_named_gpio(dt, "laser,pwdn-gpio", 0);
    if (!gpio_is_valid(data->pwdn_gpio))
        vl53l0_errmsg("pwdn_gpio value is not valid\n");
    else
        vl53l0_dbgmsg("pwdn_gpio = %d\n", data->pwdn_gpio);

    data->power_gpio = of_get_named_gpio(dt, "laser,power-2v8", 0);
    if (!gpio_is_valid(data->power_gpio)) {
        data->power_2v8 = devm_regulator_get(dev, "POWER_2v8");
        if (IS_ERR(data->power_2v8)) {
            data->power_2v8 = NULL;
            E("%s: Unable to get power_gpio and POWER_2v8\n", __func__);
        }
    } else
        I("%s: power_gpio = %d\n", __func__, data->power_gpio);

    data->laser_irq_gpio = of_get_named_gpio(dt, "laser,intr-gpio", 0);
    if (!gpio_is_valid(data->laser_irq_gpio))
        E("%s: laser_irq_gpio value is not valid\n", __func__);
    else
        I("%s: laser_irq_gpio = %d\n", __func__, data->laser_irq_gpio);

    data->camio_1v8 = devm_regulator_get(dev, "CAMIO_1v8");
    if (IS_ERR(data->camio_1v8)) {
        data->camio_1v8 = NULL;
        E("%s: Unable to get CAMIO_1v8\n", __func__);
    }

    sensor_offset = of_find_node_by_path(CALIBRATION_DATA_PATH);
    if (sensor_offset) {
        sensor_cali_data = (char *)
            of_get_property(sensor_offset,
                    SENSOR_FLASH_DATA,
                    &sensor_cali_size);
        vl53l0_dbgmsg("sensor cali_size = %d\n", sensor_cali_size);

        if (sensor_cali_data) {
            for (i = 100; (i < sensor_cali_size) && (i < 108); i++) {
                vl53l0_dbgmsg("gyro sensor cali_data[%d] = %02x\n", i, sensor_cali_data[i]);
            }

            if ((s8)sensor_cali_data[100] == CALIBRATED) {
                data->offset_kvalue = (s8) sensor_cali_data[103];
                vl53l0_dbgmsg("Update offset_kvalue = %d\n", data->offset_kvalue);

                data->cali_status = OFFSET_CALIBRATED;


                data->isApertureSpads = (u8) sensor_cali_data[101];
                data->refSpadCount = (u32) sensor_cali_data[102];
                vl53l0_dbgmsg("Update SpadCount = %d and IsAperture = %d\n",
                                       data->refSpadCount, data->isApertureSpads);
                if (data->isApertureSpads || data->refSpadCount)
                    data->cali_status |= REF_SPAD_CALIBRATED;
            }

            if ((s8)sensor_cali_data[104] == CALIBRATED) {
                data->xtalk_kvalue = (sensor_cali_data[107]<<8) | sensor_cali_data[106];
                vl53l0_dbgmsg("Update xtalk_kvalue = 0x%X\n", data->xtalk_kvalue);

                data->cali_status |= XTALK_CALIBRATED;
            }
        }
    } else {
        vl53l0_errmsg("%s: Sensor Calibration data offset not found\n", __func__);
    }
    return 0;
}

static int Laser_pinctrl_init(struct stmvl53l0_data *laser_data)
{
    
    int ret = 0;
    vl53l0_dbgmsg("Enter++\n");

    
    ret = regulator_enable(laser_data->camio_1v8);
    if (ret) {
        vl53l0_errmsg("Failed to enable camio_1v8\n");
        return ret;
    }

    
    if(gpio_is_valid(laser_data->power_gpio)) {
        ret = gpio_direction_output(laser_data->power_gpio, 1);
        if (ret) {
            vl53l0_errmsg("Failed to pull up power_gpio\n");
            return ret;
        }
        gpio_set_value(laser_data->power_gpio, 1);
    } else {
        ret = regulator_enable(laser_data->power_2v8);
        if (ret) {
            vl53l0_errmsg("Failed to enable POWER_2v8\n");
            return ret;
        }
    }
    msleep(1);

    
    ret = gpio_direction_output(laser_data->pwdn_gpio, 1);
    if (ret) {
        vl53l0_errmsg("Failed to pull up pwdn_gpio\n");
        return ret;
    }
    gpio_set_value(laser_data->pwdn_gpio, 1);
    msleep(2);

    vl53l0_dbgmsg("End--\n");
    return 0;
}
#endif
static int stmvl53l0_probe(struct i2c_client *client,
        const struct i2c_device_id *id)
{
    int rc = 0;
    struct stmvl53l0_data *vl53l0_data = NULL;
    struct i2c_data *i2c_object = NULL;

    vl53l0_dbgmsg("Enter++\n");

    if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE)) {
        rc = -EIO;
        return rc;
    }

    vl53l0_data = kzalloc(sizeof(struct stmvl53l0_data), GFP_KERNEL);
    if (!vl53l0_data) {
        rc = -ENOMEM;
        return rc;
    }
    if (vl53l0_data) {
        vl53l0_data->client_object = kzalloc(sizeof(struct i2c_data), GFP_KERNEL);
        i2c_object = (struct i2c_data *)vl53l0_data->client_object;
    }
    i2c_object->client = client;
    vl53l0_data->sensor_dev = &client->dev;

#ifdef HTC
    if (client->dev.of_node) {
        Laser_parse_dt(&client->dev, vl53l0_data);
    }
#endif
    
    vl53l0_data->bus_type = I2C_BUS;

    
    stmvl53l0_parse_vdd(&i2c_object->client->dev, i2c_object);

    
    vl53l0_data->dev_name = dev_name(&client->dev);

    
    dev_set_drvdata(&client->dev, vl53l0_data);

    
    i2c_set_clientdata(client, vl53l0_data);

    
    Laser_pinctrl_init(vl53l0_data);

    
    rc = stmvl53l0_setup(vl53l0_data);

    
    i2c_object->power_up = 0;

    if(gpio_is_valid(vl53l0_data->power_gpio))
        gpio_set_value(vl53l0_data->power_gpio, 0);
    else {
        regulator_disable(vl53l0_data->power_2v8);
        if (rc)
            vl53l0_errmsg("Failed to disable power_2v8\n");
    }

    gpio_set_value(vl53l0_data->pwdn_gpio, 0);
    rc = regulator_disable(vl53l0_data->camio_1v8);
    if (rc)
        vl53l0_errmsg("Failed to disable camio_1v8\n");

    vl53l0_dbgmsg("Success--\n");
    return rc;
}

static int stmvl53l0_remove(struct i2c_client *client)
{
    struct stmvl53l0_data *data = i2c_get_clientdata(client);

    vl53l0_dbgmsg("Enter\n");

    
    stmvl53l0_power_down_i2c(data->client_object);
	stmvl53l0_cleanup(data);
    kfree(data->client_object);
    kfree(data);
    vl53l0_dbgmsg("End\n");
    return 0;
}

static const struct i2c_device_id stmvl53l0_id[] = {
    { STMVL53L0_DRV_NAME, 0 },
    { },
};
MODULE_DEVICE_TABLE(i2c, stmvl53l0_id);

static const struct of_device_id st_stmvl53l0_dt_match[] = {
    
    { .compatible = "htc_laser"},
    { },
};

static struct i2c_driver stmvl53l0_driver = {
    .driver = {
        .name	= STMVL53L0_DRV_NAME,
        .owner	= THIS_MODULE,
        .of_match_table = st_stmvl53l0_dt_match,
    },
    .probe	= stmvl53l0_probe,
    .remove	= stmvl53l0_remove,
    .id_table = stmvl53l0_id,

};

int stmvl53l0_power_up_i2c(void *i2c_object, unsigned int *preset_flag)
{
    int ret = 0;
    struct i2c_data *data = (struct i2c_data *)i2c_object;

    vl53l0_dbgmsg("Enter\n");
#ifdef HTC_MODIFY
    data->power_up = 1;
    *preset_flag = 1;
#endif
    vl53l0_dbgmsg("End\n");
    return ret;
}

int stmvl53l0_power_down_i2c(void *i2c_object)
{
    int ret = 0;
    struct i2c_data *data = (struct i2c_data *)i2c_object;

    vl53l0_dbgmsg("Enter\n");
#ifdef HTC_MODIFY
    data->power_up = 0;
#endif
    vl53l0_dbgmsg("End\n");
    return ret;
}

int stmvl53l0_init_i2c(void)
{
    int ret = 0;

#ifdef STM_TEST
    struct i2c_client *client = NULL;
    struct i2c_adapter *adapter;
    struct i2c_board_info info = {
        .type = "stmvl53l0",
        .addr = STMVL53L0_SLAVE_ADDR,
    };
#endif

    vl53l0_dbgmsg("Enter\n");

    
    ret = i2c_add_driver(&stmvl53l0_driver);
    if (ret)
        vl53l0_errmsg("%d erro ret:%d\n", __LINE__, ret);

#ifdef STM_TEST
    if (!ret) {
        adapter = i2c_get_adapter(4);
        if (!adapter)
            ret = -EINVAL;
        else
            client = i2c_new_device(adapter, &info);
        if (!client)
            ret = -EINVAL;
    }
#endif

    vl53l0_dbgmsg("End with rc:%d\n", ret);

    return ret;
}

void stmvl53l0_exit_i2c(void *i2c_object)
{
    vl53l0_dbgmsg("Enter\n");
    i2c_del_driver(&stmvl53l0_driver);

    vl53l0_dbgmsg("End\n");
}

#endif 
