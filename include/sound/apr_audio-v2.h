/* Copyright (c) 2012-2016, The Linux Foundation. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/


#ifndef _APR_AUDIO_V2_H_
#define _APR_AUDIO_V2_H_

#include <linux/qdsp6v2/apr.h>

#define APR_CMD_OB_HDR_SZ  12

#define APR_CMD_GET_HDR_SZ 16

struct param_outband {
	size_t       size;
	void        *kvaddr;
	phys_addr_t  paddr;
};

#define ADSP_ADM_VERSION    0x00070000

#define ADM_CMD_SHARED_MEM_MAP_REGIONS    0x00010322
#define ADM_CMDRSP_SHARED_MEM_MAP_REGIONS 0x00010323
#define ADM_CMD_SHARED_MEM_UNMAP_REGIONS 0x00010324

#define ADM_CMD_MATRIX_MAP_ROUTINGS_V5 0x00010325
#define ADM_CMD_STREAM_DEVICE_MAP_ROUTINGS_V5 0x0001033D
#define ADM_MATRIX_ID_AUDIO_RX              0

#define ADM_MATRIX_ID_AUDIO_TX              1

#define ADM_MATRIX_ID_COMPRESSED_AUDIO_RX   2
#define ADM_MATRIX_ID_AUDIOX              1

#define ADM_MAX_COPPS 5

#define SP_V2_NUM_MAX_SPKR 2

struct adm_session_map_node_v5 {
	u16                  session_id;


	u16                  num_copps;
} __packed;


struct adm_cmd_matrix_map_routings_v5 {
	struct apr_hdr	hdr;

	u32                  matrix_id;
	u32                  num_sessions;
	
} __packed;

#define ADM_CMD_DEVICE_OPEN_V5                          0x00010326

#define ADM_CMD_DEVICE_OPEN_V6                      0x00010356

#define ADM_LOW_LATENCY_DEVICE_SESSION			0x2000

#define ADM_ULTRA_LOW_LATENCY_DEVICE_SESSION		0x4000

#define ADM_ULL_POST_PROCESSING_DEVICE_SESSION		0x8000

#define ADM_LEGACY_DEVICE_SESSION                                      0

#define ADM_CMD_COPP_OPEN_END_POINT_ID_2_IGNORE				0xFFFF

#define ADM_CMD_COPP_OPEN_MODE_OF_OPERATION_RX_PATH_COPP		 1

#define ADM_CMD_COPP_OPEN_MODE_OF_OPERATIONX_PATH_LIVE_COPP		 2

#define ADM_CMD_COPP_OPEN_MODE_OF_OPERATIONX_PATH_NON_LIVE_COPP	 3

#define ADM_CMD_COPP_OPEN_CHANNEL_CONFIG_MONO		1

#define ADM_CMD_COPP_OPEN_CHANNEL_CONFIG_STEREO		2

#define ADM_CMD_COPP_OPEN_SAMPLE_RATE_8K 8000

#define ADM_CMD_COPP_OPEN_SAMPLE_RATE_16K 16000

#define ADM_CMD_COPP_OPEN_SAMPLE_RATE_48K 48000

#define ADM_BIT_MASK_COPP_LIVE_INPUT_FLAG (0x0001U)

#define ADM_SHIFT_COPP_LIVE_INPUT_FLAG	 0

#define ADM_BIT_MASK_COPP_ID  (0x0000FFFFUL)

#define ADM_SHIFT_COPP_ID	0

#define ADM_BIT_MASK_SERVICE_ID  (0x00FF0000UL)

#define ADM_SHIFT_SERVICE_ID	16

#define ADM_BIT_MASK_DOMAIN_ID    (0xFF000000UL)

#define ADM_SHIFT_DOMAIN_ID	24

struct adm_cmd_device_open_v5 {
	struct apr_hdr		hdr;
	u16                  flags;

	u16                  mode_of_operation;

	u16                  endpoint_id_1;

	u16                  endpoint_id_2;

	u32                  topology_id;
	

	u16                  dev_num_channel;

	u16                  bit_width;

	u32                  sample_rate;

	u8                   dev_channel_mapping[8];
} __packed;

struct adm_cmd_device_open_v6 {
	struct apr_hdr		hdr;
	u16                  flags;

	u16                  mode_of_operation;

	u16                  endpoint_id_1;

	u16                  endpoint_id_2;

	u32                  topology_id;

	u16                  dev_num_channel;

	u16                  bit_width;

	u32                  sample_rate;

	u8                   dev_channel_mapping[8];

	u16                  dev_num_channel_eid2;

	u16                  bit_width_eid2;

	u32                  sample_rate_eid2;

	u8                   dev_channel_mapping_eid2[8];
} __packed;

#define ADM_CMD_DEVICE_CLOSE_V5                         0x00010327

#define ADM_CMD_SET_PP_PARAMS_V5                        0x00010328

struct adm_cmd_set_pp_params_v5 {
	struct apr_hdr hdr;
	u32		payload_addr_lsw;
	
	u32		payload_addr_msw;
	

	u32		mem_map_handle;

	u32		payload_size;
} __packed;

struct adm_param_data_v5 {
	u32                  module_id;
	
	u32                  param_id;
	
	u16                  param_size;
	u16                  reserved;
} __packed;

#define ADM_CMD_SET_PSPD_MTMX_STRTR_PARAMS_V5                        0x00010344
struct adm_cmd_set_pspd_mtmx_strtr_params_v5 {
	struct apr_hdr hdr;
	
	u32		payload_addr_lsw;
	
	u32		payload_addr_msw;
	
	
	
	u32		mem_map_handle;
	
	
	
	u32		payload_size;
	u16		direction;
	u16		sessionid;
	u16		deviceid;
	u16		reserved;
} __packed;

struct adm_cmd_set_pp_params_inband_v5 {
	struct apr_hdr hdr;
	
	u32             payload_addr_lsw;
	
	u32             payload_addr_msw;
	
	
	
	u32             mem_map_handle;
	
	
	
	u32             payload_size;
	
	struct adm_param_data_v5        params;
} __packed;

#define ADM_CMDRSP_DEVICE_OPEN_V5                      0x00010329

struct adm_cmd_rsp_device_open_v5 {
	u32                  status;
	

	u16                  copp_id;
	

	u16                  reserved;
	
} __packed;

#define ADM_CMDRSP_DEVICE_OPEN_V6                      0x00010357


#define ADM_CMD_GET_PP_PARAMS_V5                                0x0001032A

struct adm_cmd_get_pp_params_v5 {
	struct apr_hdr hdr;
	u32                  data_payload_addr_lsw;
	

	u32                  data_payload_addr_msw;
	


	u32                  mem_map_handle;

	u32                  module_id;
	

	u32                  param_id;
	

	u16                  param_max_size;
	u16                  reserved;
} __packed;

#define ADM_CMDRSP_GET_PP_PARAMS_V5		0x0001032B

struct adm_cmd_rsp_get_pp_params_v5 {
	u32                  status;
	
} __packed;



struct audproc_softvolume_params {
	u32 period;
	u32 step;
	u32 rampingcurve;
} __packed;

#define AUDPROC_MODULE_ID_MFC                               0x00010912

#define AUDPROC_PARAM_ID_MFC_OUTPUT_MEDIA_FORMAT            0x00010913


struct audproc_mfc_output_media_fmt {
	struct adm_cmd_set_pp_params_v5 params;
	struct adm_param_data_v5 data;
	uint32_t sampling_rate;
	uint16_t bits_per_sample;
	uint16_t num_channels;
	uint16_t channel_type[8];
} __packed;

struct audproc_volume_ctrl_master_gain {
	struct adm_cmd_set_pp_params_v5 params;
	struct adm_param_data_v5 data;
	
	uint16_t                  master_gain;
	
	uint16_t                  reserved;
} __packed;

struct audproc_soft_step_volume_params {
	struct adm_cmd_set_pp_params_v5 params;
	struct adm_param_data_v5 data;
	uint32_t                  period;
	uint32_t                  step;
	uint32_t                  ramping_curve;
} __packed;

struct audproc_enable_param_t {
	struct adm_cmd_set_pp_params_inband_v5 pp_params;
	uint32_t                  enable;
};

#define ADM_CMD_MATRIX_RAMP_GAINS_V5                                 0x0001032C

#define ADM_CMD_MATRIX_RAMP_GAINS_COPP_ID_ALL_CONNECTED_COPPS     0xFFFF

#define ADM_CMD_MATRIX_RAMP_GAINS_RAMP_DURATION_IMMEDIATE         0x0000

#define ADM_CMD_MATRIX_RAMP_GAINS_RAMP_CURVE_LINEAR               0x0000

struct adm_cmd_matrix_ramp_gains_v5 {
	u32                  matrix_id;

	u16                  num_gains;
	

	u16                  reserved_for_align;
	
} __packed;

struct adm_session_copp_gain_v5 {
	u16                  session_id;

	u16                  copp_id;

	u16                  ramp_duration;

	u16                  step_duration;

	u16                  ramp_curve;

	u16                  reserved_for_align;
	

	u16                  target_gain_ch_1;
	

	u16                  target_gain_ch_2;
	

	u16                  target_gain_ch_3;
	

	u16                  target_gain_ch_4;
	

	u16                  target_gain_ch_5;
	

	u16                  target_gain_ch_6;
	

	u16                  target_gain_ch_7;
	

	u16                  target_gain_ch_8;
	
} __packed;

#define ADM_CMD_MATRIX_MUTE_V5                                0x0001032D

#define ADM_CMD_MATRIX_MUTE_COPP_ID_ALL_CONNECTED_COPPS     0xFFFF

struct adm_cmd_matrix_mute_v5 {
	u32                  matrix_id;

	u16                  session_id;

	u16                  copp_id;

	u8                  mute_flag_ch_1;
	

	u8                  mute_flag_ch_2;
	

	u8                  mute_flag_ch_3;
	

	u8                  mute_flag_ch_4;
	

	u8                  mute_flag_ch_5;
	

	u8                  mute_flag_ch_6;
	

	u8                  mute_flag_ch_7;
	

	u8                  mute_flag_ch_8;
	

	u16                 ramp_duration;

	u16                 reserved_for_align;
	
} __packed;

#define ASM_PARAM_ID_AAC_STEREO_MIX_COEFF_SELECTION_FLAG_V2 (0x00010DD8)

struct asm_aac_stereo_mix_coeff_selection_param_v2 {
	struct apr_hdr          hdr;
	u32                     param_id;
	u32                     param_size;
	u32                     aac_stereo_mix_coeff_flag;
} __packed;


#define ADM_CMD_CONNECT_AFE_PORT_V5	0x0001032E
#define ADM_CMD_DISCONNECT_AFE_PORT_V5	0x0001032F
#define ADM_STRTR_ID_RX                    0
#define ADM_STRTR_IDX                    1

struct adm_cmd_connect_afe_port_v5 {
	struct apr_hdr     hdr;
	u8                  mode;

	u8                  session_id;
	

	u16                 afe_port_id;
	
	u32                 num_channels;

	u32                 sampling_rate;
} __packed;




#define PRIMARY_I2S_RX 0
#define PRIMARY_I2S_TX 1
#define SECONDARY_I2S_RX 4
#define SECONDARY_I2S_TX 5
#define MI2S_RX 6
#define MI2S_TX 7
#define HDMI_RX 8
#define RSVD_2 9
#define RSVD_3 10
#define DIGI_MIC_TX 11
#define VOICE2_PLAYBACK_TX 0x8002
#define VOICE_RECORD_RX 0x8003
#define VOICE_RECORD_TX 0x8004
#define VOICE_PLAYBACK_TX 0x8005

#define SLIMBUS_0_RX		0x4000
#define SLIMBUS_0_TX		0x4001
#define SLIMBUS_1_RX		0x4002
#define SLIMBUS_1_TX		0x4003
#define SLIMBUS_2_RX		0x4004
#define SLIMBUS_2_TX		0x4005
#define SLIMBUS_3_RX		0x4006
#define SLIMBUS_3_TX		0x4007
#define SLIMBUS_4_RX		0x4008
#define SLIMBUS_4_TX		0x4009
#define SLIMBUS_5_RX		0x400a
#define SLIMBUS_5_TX		0x400b
#define SLIMBUS_6_RX		0x400c
#define SLIMBUS_6_TX		0x400d
#define SLIMBUS_PORT_LAST	SLIMBUS_6_TX
#define INT_BT_SCO_RX 0x3000
#define INT_BT_SCO_TX 0x3001
#define INT_BT_A2DP_RX 0x3002
#define INT_FM_RX 0x3004
#define INT_FM_TX 0x3005
#define RT_PROXY_PORT_001_RX	0x2000
#define RT_PROXY_PORT_001_TX	0x2001

#define AFE_PORT_INVALID 0xFFFF
#define SLIMBUS_INVALID AFE_PORT_INVALID

#define AFE_PORT_CMD_START 0x000100ca

#define AFE_EVENT_RTPORT_START 0
#define AFE_EVENT_RTPORT_STOP 1
#define AFE_EVENT_RTPORT_LOW_WM 2
#define AFE_EVENT_RTPORT_HI_WM 3

#define ADSP_AFE_VERSION    0x00200000

#define  AFE_PORT_ID_AUDIO_IF_PORT_RANGE_SIZE	0xF

#define AFE_PORT_ID_INTERNAL_BT_FM_RANGE_SIZE	0x6

#define AFE_PORT_ID_SLIMBUS_RANGE_SIZE	0xA

#define  AFE_PORT_ID_RT_PROXY_PORT_RANGE_SIZE	0x2

#define AFE_PORT_ID_PSEUDOPORT_RANGE_SIZE	0x5

#define  AFE_PORT_ID_AUDIO_IF_PORT_RANGE_START	0x1000

#define  AFE_PORT_ID_AUDIO_IF_PORT_RANGE_END \
	(AFE_PORT_ID_AUDIO_IF_PORT_RANGE_START +\
	AFE_PORT_ID_AUDIO_IF_PORT_RANGE_SIZE - 1)

#define  AFE_PORT_ID_RT_PROXY_PORT_RANGE_START	0x2000

#define  AFE_PORT_ID_RT_PROXY_PORT_RANGE_END \
	(AFE_PORT_ID_RT_PROXY_PORT_RANGE_START +\
	AFE_PORT_ID_RT_PROXY_PORT_RANGE_SIZE-1)

#define AFE_PORT_ID_INTERNAL_BT_FM_RANGE_START	0x3000

#define AFE_PORT_ID_INTERNAL_BT_FM_RANGE_END \
	(AFE_PORT_ID_INTERNAL_BT_FM_RANGE_START +\
	AFE_PORT_ID_INTERNAL_BT_FM_RANGE_SIZE-1)

#define AFE_PORT_ID_SLIMBUS_RANGE_START	0x4000

#define AFE_PORT_ID_SLIMBUS_RANGE_END \
	(AFE_PORT_ID_SLIMBUS_RANGE_START +\
	AFE_PORT_ID_SLIMBUS_RANGE_SIZE-1)

#define AFE_PORT_ID_PSEUDOPORT_RANGE_START	0x8001

#define AFE_PORT_ID_PSEUDOPORT_RANGE_END \
	(AFE_PORT_ID_PSEUDOPORT_RANGE_START +\
	AFE_PORT_ID_PSEUDOPORT_RANGE_SIZE-1)

#define AFE_PORT_ID_TDM_PORT_RANGE_START	0x9000

#define AFE_PORT_ID_TDM_PORT_RANGE_END \
	(AFE_PORT_ID_TDM_PORT_RANGE_START+0x40-1)

#define AFE_PORT_ID_TDM_PORT_RANGE_SIZE \
	(AFE_PORT_ID_TDM_PORT_RANGE_END - \
	AFE_PORT_ID_TDM_PORT_RANGE_START+1)

#define AFE_PORT_ID_PRIMARY_MI2S_RX         0x1000
#define AFE_PORT_ID_PRIMARY_MI2S_TX         0x1001
#define AFE_PORT_ID_SECONDARY_MI2S_RX       0x1002
#define AFE_PORT_ID_SECONDARY_MI2S_TX       0x1003
#define AFE_PORT_ID_TERTIARY_MI2S_RX        0x1004
#define AFE_PORT_ID_TERTIARY_MI2S_TX        0x1005
#define AFE_PORT_ID_QUATERNARY_MI2S_RX      0x1006
#define AFE_PORT_ID_QUATERNARY_MI2S_TX      0x1007
#define AUDIO_PORT_ID_I2S_RX				0x1008
#define AFE_PORT_ID_DIGITAL_MIC_TX          0x1009
#define AFE_PORT_ID_PRIMARY_PCM_RX          0x100A
#define AFE_PORT_ID_PRIMARY_PCM_TX          0x100B
#define AFE_PORT_ID_SECONDARY_PCM_RX        0x100C
#define AFE_PORT_ID_SECONDARY_PCM_TX        0x100D
#define AFE_PORT_ID_MULTICHAN_HDMI_RX       0x100E
#define AFE_PORT_ID_SECONDARY_MI2S_RX_SD1	0x1010
#define AFE_PORT_ID_TERTIARY_PCM_RX          0x1012
#define AFE_PORT_ID_TERTIARY_PCM_TX          0x1013
#define AFE_PORT_ID_QUATERNARY_PCM_RX        0x1014
#define AFE_PORT_ID_QUATERNARY_PCM_TX        0x1015
#define AFE_PORT_ID_QUINARY_MI2S_RX		0x1016
#define AFE_PORT_ID_QUINARY_MI2S_TX		0x1017
#define AFE_PORT_ID_SENARY_MI2S_RX		0x1018
#define AFE_PORT_ID_SENARY_MI2S_TX		0x1019
#define AFE_PORT_ID_SPDIF_RX                0x5000
#define  AFE_PORT_ID_RT_PROXY_PORT_001_RX   0x2000
#define  AFE_PORT_ID_RT_PROXY_PORT_001_TX   0x2001
#define AFE_PORT_ID_INTERNAL_BT_SCO_RX      0x3000
#define AFE_PORT_ID_INTERNAL_BT_SCO_TX      0x3001
#define AFE_PORT_ID_INTERNAL_BT_A2DP_RX     0x3002
#define AFE_PORT_ID_INTERNAL_FM_RX          0x3004
#define AFE_PORT_ID_INTERNAL_FM_TX          0x3005
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_0_RX      0x4000
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_0_TX      0x4001
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_1_RX      0x4002
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_1_TX      0x4003
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_2_RX      0x4004
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_2_TX      0x4005
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_3_RX      0x4006
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_3_TX      0x4007
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_4_RX      0x4008
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_4_TX      0x4009
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_5_RX      0x400a
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_5_TX      0x400b
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_6_RX      0x400c
#define AFE_PORT_ID_SLIMBUS_MULTI_CHAN_6_TX      0x400d

#define AFE_PORT_ID_PSEUDOPORT_01      0x8001
#define AFE_PORT_ID_PSEUDOPORT_02      0x8002

#define AFE_PORT_ID_PRIMARY_PCM_TX      0x100B
/* Pseudoport that corresponds to the voice Rx path.
 * For recording, the voice Rx path samples are written to this
 * port and consumed by the audio path.
 */

#define AFE_PORT_ID_VOICE_RECORD_RX	0x8003

/* Pseudoport that corresponds to the voice Tx path.
 * For recording, the voice Tx path samples are written to this
 * port and consumed by the audio path.
 */

#define AFE_PORT_ID_VOICE_RECORD_TX	0x8004
#define AFE_PORT_ID_VOICE2_PLAYBACK_TX  0x8002
#define AFE_PORT_ID_VOICE_PLAYBACK_TX   0x8005

#define AFE_PORT_ID_PRIMARY_TDM_RX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x00)
#define AFE_PORT_ID_PRIMARY_TDM_RX_1 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x02)
#define AFE_PORT_ID_PRIMARY_TDM_RX_2 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x04)
#define AFE_PORT_ID_PRIMARY_TDM_RX_3 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x06)
#define AFE_PORT_ID_PRIMARY_TDM_RX_4 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x08)
#define AFE_PORT_ID_PRIMARY_TDM_RX_5 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x0A)
#define AFE_PORT_ID_PRIMARY_TDM_RX_6 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x0C)
#define AFE_PORT_ID_PRIMARY_TDM_RX_7 \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x0E)

#define AFE_PORT_ID_PRIMARY_TDM_TX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x01)
#define AFE_PORT_ID_PRIMARY_TDM_TX_1 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x02)
#define AFE_PORT_ID_PRIMARY_TDM_TX_2 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x04)
#define AFE_PORT_ID_PRIMARY_TDM_TX_3 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x06)
#define AFE_PORT_ID_PRIMARY_TDM_TX_4 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x08)
#define AFE_PORT_ID_PRIMARY_TDM_TX_5 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x0A)
#define AFE_PORT_ID_PRIMARY_TDM_TX_6 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x0C)
#define AFE_PORT_ID_PRIMARY_TDM_TX_7 \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x0E)

#define AFE_PORT_ID_SECONDARY_TDM_RX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x10)
#define AFE_PORT_ID_SECONDARY_TDM_RX_1 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x02)
#define AFE_PORT_ID_SECONDARY_TDM_RX_2 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x04)
#define AFE_PORT_ID_SECONDARY_TDM_RX_3 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x06)
#define AFE_PORT_ID_SECONDARY_TDM_RX_4 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x08)
#define AFE_PORT_ID_SECONDARY_TDM_RX_5 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x0A)
#define AFE_PORT_ID_SECONDARY_TDM_RX_6 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x0C)
#define AFE_PORT_ID_SECONDARY_TDM_RX_7 \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x0E)

#define AFE_PORT_ID_SECONDARY_TDM_TX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x11)
#define AFE_PORT_ID_SECONDARY_TDM_TX_1 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x02)
#define AFE_PORT_ID_SECONDARY_TDM_TX_2 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x04)
#define AFE_PORT_ID_SECONDARY_TDM_TX_3 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x06)
#define AFE_PORT_ID_SECONDARY_TDM_TX_4 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x08)
#define AFE_PORT_ID_SECONDARY_TDM_TX_5 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x0A)
#define AFE_PORT_ID_SECONDARY_TDM_TX_6 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x0C)
#define AFE_PORT_ID_SECONDARY_TDM_TX_7 \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x0E)

#define AFE_PORT_ID_TERTIARY_TDM_RX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x20)
#define AFE_PORT_ID_TERTIARY_TDM_RX_1 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x02)
#define AFE_PORT_ID_TERTIARY_TDM_RX_2 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x04)
#define AFE_PORT_ID_TERTIARY_TDM_RX_3 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x06)
#define AFE_PORT_ID_TERTIARY_TDM_RX_4 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x08)
#define AFE_PORT_ID_TERTIARY_TDM_RX_5 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x0A)
#define AFE_PORT_ID_TERTIARY_TDM_RX_6 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x0C)
#define AFE_PORT_ID_TERTIARY_TDM_RX_7 \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x0E)

#define AFE_PORT_ID_TERTIARY_TDM_TX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x21)
#define AFE_PORT_ID_TERTIARY_TDM_TX_1 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x02)
#define AFE_PORT_ID_TERTIARY_TDM_TX_2 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x04)
#define AFE_PORT_ID_TERTIARY_TDM_TX_3 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x06)
#define AFE_PORT_ID_TERTIARY_TDM_TX_4 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x08)
#define AFE_PORT_ID_TERTIARY_TDM_TX_5 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x0A)
#define AFE_PORT_ID_TERTIARY_TDM_TX_6 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x0C)
#define AFE_PORT_ID_TERTIARY_TDM_TX_7 \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x0E)

#define AFE_PORT_ID_QUATERNARY_TDM_RX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x30)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_1 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x02)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_2 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x04)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_3 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x06)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_4 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x08)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_5 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x0A)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_6 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x0C)
#define AFE_PORT_ID_QUATERNARY_TDM_RX_7 \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x0E)

#define AFE_PORT_ID_QUATERNARY_TDM_TX \
	(AFE_PORT_ID_TDM_PORT_RANGE_START + 0x31)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_1 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x02)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_2 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x04)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_3 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x06)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_4 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x08)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_5 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x0A)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_6 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x0C)
#define AFE_PORT_ID_QUATERNARY_TDM_TX_7 \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x0E)

#define AFE_PORT_ID_INVALID             0xFFFF

#define AAC_ENC_MODE_AAC_LC 0x02
#define AAC_ENC_MODE_AAC_P 0x05
#define AAC_ENC_MODE_EAAC_P 0x1D

#define AFE_PSEUDOPORT_CMD_START 0x000100cf
struct afe_pseudoport_start_command {
	struct apr_hdr hdr;
	u16 port_id;		
				
				
	u16 timing;		
} __packed;

#define AFE_PSEUDOPORT_CMD_STOP 0x000100d0
struct afe_pseudoport_stop_command {
	struct apr_hdr hdr;
	u16 port_id;		
				
				
	u16 reserved;
} __packed;


#define AFE_MODULE_SIDETONE_IIR_FILTER	0x00010202
#define AFE_PARAM_ID_ENABLE	0x00010203


struct afe_mod_enable_param {
	u16                  enable;
	

	u16                  reserved;
} __packed;

#define AFE_PARAM_ID_SIDETONE_IIR_FILTER_CONFIG	0x00010204
#define MAX_SIDETONE_IIR_DATA_SIZE 220
#define MAX_NO_IIR_FILTER_STAGE   10

struct afe_sidetone_iir_filter_config_params {
	u16                  num_biquad_stages;

	u16                  pregain;
	uint8_t   iir_config[MAX_SIDETONE_IIR_DATA_SIZE];
} __packed;

#define AFE_MODULE_LOOPBACK	0x00010205
#define AFE_PARAM_ID_LOOPBACK_GAIN_PER_PATH	0x00010206


struct afe_port_cmd_set_param_v2 {
	u16 port_id;

	u16 payload_size;

u32 payload_address_lsw;

u32 payload_address_msw;

u32 mem_map_handle;
} __packed;

#define AFE_PORT_CMD_SET_PARAM_V2	0x000100EF

struct afe_port_param_data_v2 {
	u32 module_id;

u32 param_id;

u16 param_size;

u16 reserved;
} __packed;

struct afe_loopback_gain_per_path_param {
	struct apr_hdr	hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	u16                  rx_port_id;

u16                  gain;
} __packed;

#define AFE_PARAM_ID_LOOPBACK_CONFIG	0x0001020B
#define AFE_API_VERSION_LOOPBACK_CONFIG	0x1

enum afe_loopback_routing_mode {
	LB_MODE_DEFAULT = 1,
	
	LB_MODE_SIDETONE,
	
	LB_MODE_EC_REF_VOICE_AUDIO,
	
	LB_MODE_EC_REF_VOICE
	
} __packed;

struct afe_loopback_cfg_v1 {
	struct apr_hdr	hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	u32		loopback_cfg_minor_version;
	u16                  dst_port_id;
	
	u16                  routing_mode;

	u16                  enable;
	u16                  reserved;

} __packed;

struct afe_loopback_sidetone_gain {
	uint16_t                  rx_port_id;
	uint16_t                  gain;
} __packed;

struct loopback_cfg_data {
	u32		loopback_cfg_minor_version;
	u16                  dst_port_id;
	
	u16                  routing_mode;

	u16                  enable;
	u16                  reserved;
} __packed;



struct afe_st_loopback_cfg_v1 {
	struct apr_hdr	hdr;
	struct afe_port_cmd_set_param_v2  param;
	struct afe_port_param_data_v2     gain_pdata;
	struct afe_loopback_sidetone_gain gain_data;
	struct afe_port_param_data_v2     cfg_pdata;
	struct loopback_cfg_data          cfg_data;
} __packed;

struct afe_loopback_iir_cfg_v2 {
	struct apr_hdr                          hdr;
	struct afe_port_cmd_set_param_v2        param;
	struct afe_port_param_data_v2           st_iir_enable_pdata;
	struct afe_mod_enable_param             st_iir_mode_enable_data;
	struct afe_port_param_data_v2           st_iir_filter_config_pdata;
	struct afe_sidetone_iir_filter_config_params 	st_iir_filter_config_data;
} __packed;



#define AFE_MODULE_SPEAKER_PROTECTION	0x00010209
#define AFE_PARAM_ID_SPKR_PROT_CONFIG	0x0001020a
#define AFE_API_VERSION_SPKR_PROT_CONFIG	0x1
#define AFE_SPKR_PROT_EXCURSIONF_LEN	512
struct afe_spkr_prot_cfg_param_v1 {
	u32       spkr_prot_minor_version;

int16_t        win_size;

int16_t        margin;

int16_t        spkr_exc_limit;

int16_t        spkr_resonance_freq;

int16_t        limhresh;

int16_t        hpf_cut_off_freq;

int16_t        hpf_enable;

int16_t        reserved;

int32_t        amp_gain;

int16_t        excursionf[AFE_SPKR_PROT_EXCURSIONF_LEN];
} __packed;


#define AFE_SERVICE_CMD_REGISTER_RT_PORT_DRIVER	0x000100E0

struct afe_service_cmd_register_rt_port_driver {
	struct apr_hdr hdr;
	u16                  port_id;

	u16                  reserved;
	
} __packed;

#define AFE_SERVICE_CMD_UNREGISTER_RT_PORT_DRIVER	0x000100E1

struct afe_service_cmd_unregister_rt_port_driver {
	struct apr_hdr hdr;
	u16                  port_id;

	u16                  reserved;
	
} __packed;

#define AFE_EVENT_RT_PROXY_PORT_STATUS	0x00010105
#define AFE_EVENTYPE_RT_PROXY_PORT_START	0
#define AFE_EVENTYPE_RT_PROXY_PORT_STOP	1
#define AFE_EVENTYPE_RT_PROXY_PORT_LOW_WATER_MARK	2
#define AFE_EVENTYPE_RT_PROXY_PORT_HIGH_WATER_MARK	3
#define AFE_EVENTYPE_RT_PROXY_PORT_INVALID	0xFFFF

struct afe_event_rt_proxy_port_status {
	u16                  port_id;

	u16                  eventype;
} __packed;

#define AFE_PORT_DATA_CMD_RT_PROXY_PORT_WRITE_V2 0x000100ED

struct afe_port_data_cmd_rt_proxy_port_write_v2 {
	struct apr_hdr hdr;
	u16                  port_id;

	u16                  reserved;
	

	u32                  buffer_address_lsw;

	u32                  buffer_address_msw;

	u32					mem_map_handle;

	u32                  available_bytes;
} __packed;

#define AFE_PORT_DATA_CMD_RT_PROXY_PORT_READ_V2	0x000100EE

struct afe_port_data_cmd_rt_proxy_port_read_v2 {
	struct apr_hdr hdr;
	u16                  port_id;

	u16                  reserved;
	

	u32                  buffer_address_lsw;


	u32                  buffer_address_msw;

		u32				mem_map_handle;

	u32                  available_bytes;
} __packed;


#define AFE_MODULE_AUDIO_DEV_INTERFACE    0x0001020C
#define AFE_PORT_SAMPLE_RATE_8K           8000
#define AFE_PORT_SAMPLE_RATE_16K          16000
#define AFE_PORT_SAMPLE_RATE_48K          48000
#define AFE_PORT_SAMPLE_RATE_96K          96000
#define AFE_PORT_SAMPLE_RATE_192K         192000
#define AFE_LINEAR_PCM_DATA				0x0
#define AFE_NON_LINEAR_DATA				0x1
#define AFE_LINEAR_PCM_DATA_PACKED_60958 0x2
#define AFE_NON_LINEAR_DATA_PACKED_60958 0x3

#define AFE_PARAM_ID_I2S_CONFIG	0x0001020D
#define AFE_API_VERSION_I2S_CONFIG	0x1
#define AFE_PORT_I2S_SD0                     0x1
#define AFE_PORT_I2S_SD1                     0x2
#define AFE_PORT_I2S_SD2                     0x3
#define AFE_PORT_I2S_SD3                     0x4
#define AFE_PORT_I2S_QUAD01                  0x5
#define AFE_PORT_I2S_QUAD23                  0x6
#define AFE_PORT_I2S_6CHS                    0x7
#define AFE_PORT_I2S_8CHS                    0x8
#define AFE_PORT_I2S_MONO                    0x0
#define AFE_PORT_I2S_STEREO                  0x1
#define AFE_PORT_CONFIG_I2S_WS_SRC_EXTERNAL  0x0
#define AFE_PORT_CONFIG_I2S_WS_SRC_INTERNAL  0x1

struct afe_param_id_i2s_cfg {
	u32                  i2s_cfg_minor_version;

	u16                  bit_width;

	u16                  channel_mode;

	u16                  mono_stereo;

	u16                  ws_src;

	u32                  sample_rate;

	u16					data_format;
		u16                  reserved;
	
} __packed;


#define AFE_API_VERSION_SPDIF_CONFIG 0x1
#define AFE_API_VERSION_SPDIF_CH_STATUS_CONFIG 0x1
#define AFE_API_VERSION_SPDIF_CLK_CONFIG 0x1
#define AFE_CH_STATUS_A 1
#define AFE_CH_STATUS_B 2

#define AFE_PARAM_ID_SPDIF_CONFIG 0x00010244
#define AFE_PARAM_ID_CH_STATUS_CONFIG 0x00010245
#define AFE_PARAM_ID_SPDIF_CLK_CONFIG 0x00010246

#define AFE_PORT_CLK_ROOT_LPAPLL 0x3
#define AFE_PORT_CLK_ROOT_LPAQ6PLL   0x4

struct afe_param_id_spdif_cfg {
	u32	spdif_cfg_minor_version;

	u32	sample_rate;

	u16	data_format;
	u16	num_channels;
	u16	bit_width;
	u16	reserved;
} __packed;

struct afe_param_id_spdif_ch_status_cfg {
	u32 ch_status_cfg_minor_version;

	u32 status_type;

	u8 status_bits[24];

	u8 status_mask[24];
} __packed;

struct afe_param_id_spdif_clk_cfg {
	u32 clk_cfg_minor_version;

	u32 clk_value;

	u32 clk_root;
} __packed;

struct afe_spdif_clk_config_command {
	struct apr_hdr                    hdr;
	struct afe_port_cmd_set_param_v2  param;
	struct afe_port_param_data_v2     pdata;
	struct afe_param_id_spdif_clk_cfg clk_cfg;
} __packed;

struct afe_spdif_chstatus_config_command {
	struct apr_hdr                    hdr;
	struct afe_port_cmd_set_param_v2  param;
	struct afe_port_param_data_v2     pdata;
	struct afe_param_id_spdif_ch_status_cfg ch_status;
} __packed;

struct afe_spdif_port_config {
	struct afe_param_id_spdif_cfg            cfg;
	struct afe_param_id_spdif_ch_status_cfg  ch_status;
} __packed;

#define AFE_PARAM_ID_PCM_CONFIG        0x0001020E
#define AFE_API_VERSION_PCM_CONFIG	0x1

#define AFE_PORT_PCM_SYNC_SRC_EXTERNAL 0x0
#define AFE_PORT_PCM_SYNC_SRC_INTERNAL  0x1
#define AFE_PORT_PCM_AUX_MODE_PCM  0x0
#define AFE_PORT_PCM_AUX_MODE_AUX    0x1
#define AFE_PORT_PCM_BITS_PER_FRAME_8  0x0
#define AFE_PORT_PCM_BITS_PER_FRAME_16   0x1

#define AFE_PORT_PCM_BITS_PER_FRAME_32 0x2

#define AFE_PORT_PCM_BITS_PER_FRAME_64   0x3

#define AFE_PORT_PCM_BITS_PER_FRAME_128 0x4

#define AFE_PORT_PCM_BITS_PER_FRAME_256 0x5

#define AFE_PORT_PCM_ALAW_NOPADDING 0x0

#define AFE_PORT_PCM_MULAW_NOPADDING 0x1
#define AFE_PORT_PCM_LINEAR_NOPADDING 0x2
#define AFE_PORT_PCM_ALAW_PADDING  0x3
#define AFE_PORT_PCM_MULAW_PADDING 0x4
#define AFE_PORT_PCM_LINEAR_PADDING 0x5
#define AFE_PORT_PCM_CTRL_DATA_OE_DISABLE 0x0
#define AFE_PORT_PCM_CTRL_DATA_OE_ENABLE  0x1


struct afe_param_id_pcm_cfg {
	u32                  pcm_cfg_minor_version;

	u16                  aux_mode;

	u16                  sync_src;

	u16                  frame_setting;

	u16                  quantype;

	u16                  ctrl_data_out_enable;
		u16                  reserved;
	

	u32                  sample_rate;

	u16                  bit_width;

	u16                  num_channels;

	u16                  slot_number_mapping[4];
} __packed;

#define AFE_PARAM_ID_DIGI_MIC_CONFIG	0x0001020F
#define AFE_API_VERSION_DIGI_MIC_CONFIG 0x1


#define AFE_PORT_DIGI_MIC_MODE_LEFT0  0x1



#define AFE_PORT_DIGI_MIC_MODE_RIGHT0  0x2


#define AFE_PORT_DIGI_MIC_MODE_LEFT1  0x3


#define AFE_PORT_DIGI_MIC_MODE_RIGHT1 0x4

#define AFE_PORT_DIGI_MIC_MODE_STEREO0  0x5



#define AFE_PORT_DIGI_MIC_MODE_STEREO1    0x6


#define AFE_PORT_DIGI_MIC_MODE_QUAD     0x7

struct afe_param_id_digi_mic_cfg {
	u32                  digi_mic_cfg_minor_version;

	u16                  bit_width;

	u16                  channel_mode;

	u32                  sample_rate;
} __packed;

#define AFE_PARAM_ID_HDMI_CONFIG     0x00010210

#define AFE_API_VERSION_HDMI_CONFIG 0x1

struct afe_param_id_hdmi_multi_chan_audio_cfg {
	u32                  hdmi_cfg_minor_version;

u16                  datatype;

u16                  channel_allocation;


u32                  sample_rate;

	u16                  bit_width;
		u16                  reserved;
	
} __packed;

#define AFE_PARAM_ID_INTERNAL_BT_FM_CONFIG  0x00010211

#define AFE_API_VERSION_INTERNAL_BT_FM_CONFIG	0x1

struct afe_param_id_internal_bt_fm_cfg {
	u32                  bt_fm_cfg_minor_version;

	u16                  num_channels;

	u16                  bit_width;

	u32                  sample_rate;
} __packed;



#define AFE_PARAM_ID_SLIMBUS_CONFIG    0x00010212

#define AFE_API_VERSION_SLIMBUS_CONFIG 0x1

#define AFE_SLIMBUS_DEVICE_1           0x0

#define AFE_SLIMBUS_DEVICE_2          0x1

#define AFE_SB_DATA_FORMAT_NOT_INDICATED 0x0


#define AFE_PORT_MAX_AUDIO_CHAN_CNT	0x8


struct afe_param_id_slimbus_cfg {
	u32                  sb_cfg_minor_version;

	u16                  slimbus_dev_id;


	u16                  bit_width;

	u16                  data_format;


	u16                  num_channels;

	u8  shared_ch_mapping[AFE_PORT_MAX_AUDIO_CHAN_CNT];

	u32              sample_rate;
} __packed;

#define AFE_PARAM_ID_RT_PROXY_CONFIG 0x00010213

#define AFE_API_VERSION_RT_PROXY_CONFIG 0x1

struct afe_param_id_rt_proxy_port_cfg {
	u32                  rt_proxy_cfg_minor_version;

	u16                  bit_width;

	u16                  interleaved;


	u16                  frame_size;
	u16                  jitter_allowance;

	u16                  low_water_mark;

	u16                  high_water_mark;


	u32					sample_rate;

	u16                  num_channels;

	u16                  reserved;
	
} __packed;



#define AFE_PARAM_ID_PSEUDO_PORT_CONFIG	0x00010219

#define AFE_API_VERSION_PSEUDO_PORT_CONFIG                          0x1

#define AFE_PSEUDOPORT_TIMING_MODE_FTRT                             0x0

#define AFE_PSEUDOPORT_TIMING_MODE_TIMER                            0x1

struct afe_param_id_pseudo_port_cfg {
	u32                  pseud_port_cfg_minor_version;

	u16                  bit_width;
	

	u16                  num_channels;
	

	u16                  data_format;

	u16                  timing_mode;

	u32                  sample_rate;
} __packed;

#define AFE_PARAM_ID_TDM_CONFIG		0x0001029D

#define AFE_API_VERSION_TDM_CONFIG              1

#define AFE_PORT_TDM_SHORT_SYNC_BIT_MODE        0
#define AFE_PORT_TDM_LONG_SYNC_MODE             1
#define AFE_PORT_TDM_SHORT_SYNC_SLOT_MODE       2

#define AFE_PORT_TDM_SYNC_SRC_EXTERNAL          0
#define AFE_PORT_TDM_SYNC_SRC_INTERNAL          1

#define AFE_PORT_TDM_CTRL_DATA_OE_DISABLE       0
#define AFE_PORT_TDM_CTRL_DATA_OE_ENABLE        1

#define AFE_PORT_TDM_SYNC_NORMAL                0
#define AFE_PORT_TDM_SYNC_INVERT                1

#define AFE_PORT_TDM_DATA_DELAY_0_BCLK_CYCLE    0
#define AFE_PORT_TDM_DATA_DELAY_1_BCLK_CYCLE    1
#define AFE_PORT_TDM_DATA_DELAY_2_BCLK_CYCLE    2

struct afe_param_id_tdm_cfg {
	u32	tdm_cfg_minor_version;

	u32	num_channels;

	u32	sample_rate;

	u32	bit_width;

	u16	data_format;

	u16	sync_mode;

	u16	sync_src;

	u16	nslots_per_frame;

	u16	ctrl_data_out_enable;

	u16	ctrl_invert_sync_pulse;

	u16	ctrl_sync_data_delay;

	u16	slot_width;

	u32	slot_mask;
} __packed;


#define AFE_MODULE_TDM		0x0001028A

#define AFE_PARAM_ID_PORT_SLOT_MAPPING_CONFIG	0x00010297

#define AFE_API_VERSION_SLOT_MAPPING_CONFIG	0x1

#define AFE_SLOT_MAPPING_DATA_ALIGN_MSB		0
#define AFE_SLOT_MAPPING_DATA_ALIGN_LSB		1

#define AFE_SLOT_MAPPING_OFFSET_INVALID		0xFFFF

struct afe_param_id_slot_mapping_cfg {
	u32	minor_version;

	u16	num_channel;

	u16	bitwidth;

	u32	data_align_type;

	u16	offset[AFE_PORT_MAX_AUDIO_CHAN_CNT];
} __packed;

#define AFE_PARAM_ID_CUSTOM_TDM_HEADER_CONFIG		0x00010298

#define AFE_API_VERSION_CUSTOM_TDM_HEADER_CONFIG	0x1

#define AFE_CUSTOM_TDM_HEADER_TYPE_INVALID		0x0
#define AFE_CUSTOM_TDM_HEADER_TYPE_DEFAULT		0x1
#define AFE_CUSTOM_TDM_HEADER_TYPE_ENTERTAINMENT_MOST	0x2

#define AFE_CUSTOM_TDM_HEADER_MAX_CNT	0x8

struct afe_param_id_custom_tdm_header_cfg {
	u32	minor_version;

	u16	start_offset;

	u16	header_width;

	u16	header_type;

	u16	num_frame_repeat;
	u16	header[AFE_CUSTOM_TDM_HEADER_MAX_CNT];
} __packed;

struct afe_slot_mapping_config_command {
	struct apr_hdr	hdr;
	struct afe_port_cmd_set_param_v2	param;
	struct afe_port_param_data_v2	pdata;
	struct afe_param_id_slot_mapping_cfg	slot_mapping;
} __packed;

struct afe_custom_tdm_header_config_command {
	struct apr_hdr	hdr;
	struct afe_port_cmd_set_param_v2	param;
	struct afe_port_param_data_v2	pdata;
	struct afe_param_id_custom_tdm_header_cfg	custom_tdm_header;
} __packed;

struct afe_tdm_port_config {
	struct afe_param_id_tdm_cfg				tdm;
	struct afe_param_id_slot_mapping_cfg		slot_mapping;
	struct afe_param_id_custom_tdm_header_cfg	custom_tdm_header;
} __packed;

#define AFE_PARAM_ID_DEVICE_HW_DELAY     0x00010243
#define AFE_API_VERSION_DEVICE_HW_DELAY  0x1

struct afe_param_id_device_hw_delay_cfg {
	uint32_t    device_hw_delay_minor_version;
	uint32_t    delay_in_us;
} __packed;

#define AFE_PARAM_ID_SET_TOPOLOGY    0x0001025A
#define AFE_API_VERSION_TOPOLOGY_V1 0x1

struct afe_param_id_set_topology_cfg {
	u32		minor_version;
	u32		topology_id;
} __packed;

union afe_port_config {
	struct afe_param_id_pcm_cfg               pcm;
	struct afe_param_id_i2s_cfg               i2s;
	struct afe_param_id_hdmi_multi_chan_audio_cfg hdmi_multi_ch;
	struct afe_param_id_slimbus_cfg           slim_sch;
	struct afe_param_id_rt_proxy_port_cfg     rtproxy;
	struct afe_param_id_internal_bt_fm_cfg    int_bt_fm;
	struct afe_param_id_pseudo_port_cfg       pseudo_port;
	struct afe_param_id_device_hw_delay_cfg   hw_delay;
	struct afe_param_id_spdif_cfg             spdif;
	struct afe_param_id_set_topology_cfg      topology;
	struct afe_param_id_tdm_cfg               tdm;
} __packed;

struct afe_audioif_config_command_no_payload {
	struct apr_hdr			hdr;
	struct afe_port_cmd_set_param_v2 param;
} __packed;

struct afe_audioif_config_command {
	struct apr_hdr			hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	union afe_port_config            port;
} __packed;

#define AFE_PORT_CMD_DEVICE_START 0x000100E5

struct afe_port_cmd_device_start {
	struct apr_hdr hdr;
	u16                  port_id;


	u16                  reserved;

} __packed;

#define AFE_PORT_CMD_DEVICE_STOP  0x000100E6

struct afe_port_cmd_device_stop {
	struct apr_hdr hdr;
	u16                  port_id;

	u16                  reserved;
} __packed;

#define AFE_SERVICE_CMD_SHARED_MEM_MAP_REGIONS 0x000100EA

struct afe_service_cmd_shared_mem_map_regions {
	struct apr_hdr hdr;
u16                  mem_pool_id;


	u16                  num_regions;

	u32                  property_flag;


} __packed;
struct afe_service_shared_map_region_payload {
	u32                  shm_addr_lsw;


	u32                  shm_addr_msw;


	u32                  mem_size_bytes;

} __packed;

#define AFE_SERVICE_CMDRSP_SHARED_MEM_MAP_REGIONS 0x000100EB
struct afe_service_cmdrsp_shared_mem_map_regions {
	u32                  mem_map_handle;

} __packed;
#define AFE_SERVICE_CMD_SHARED_MEM_UNMAP_REGIONS 0x000100EC


struct afe_service_cmd_shared_mem_unmap_regions {
	struct apr_hdr hdr;
u32                  mem_map_handle;
} __packed;

#define  AFE_PORT_CMD_GET_PARAM_V2 0x000100F0

struct afe_port_cmd_get_param_v2 {
	u16 port_id;

	u16 payload_size;

	u32 payload_address_lsw;


	u32 payload_address_msw;

	u32 mem_map_handle;


	u32 module_id;

	u32 param_id;
} __packed;

#define AFE_PORT_CMDRSP_GET_PARAM_V2 0x00010106



struct afe_port_cmdrsp_get_param_v2 {
	u32                  status;
} __packed;

#define AFE_PARAM_ID_LPASS_CORE_SHARED_CLOCK_CONFIG	0x0001028C
#define AFE_API_VERSION_LPASS_CORE_SHARED_CLK_CONFIG	0x1
struct afe_param_id_lpass_core_shared_clk_cfg {
	u32	lpass_core_shared_clk_cfg_minor_version;
	u32	enable;
} __packed;

struct afe_lpass_core_shared_clk_config_command {
	struct apr_hdr		   hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	struct afe_param_id_lpass_core_shared_clk_cfg clk_cfg;
} __packed;


#define ADSP_MEMORY_MAP_EBI_POOL      0

#define ADSP_MEMORY_MAP_SMI_POOL      1
#define ADSP_MEMORY_MAP_IMEM_POOL      2
#define ADSP_MEMORY_MAP_SHMEM8_4K_POOL      3
#define ADSP_MEMORY_MAP_VIRTUAL_MEMORY 1

#define ADSP_MEMORY_MAP_PHYSICAL_MEMORY 0

#define NULL_POPP_TOPOLOGY				0x00010C68
#define NULL_COPP_TOPOLOGY				0x00010312
#define DEFAULT_COPP_TOPOLOGY				0x00010314
#define DEFAULT_POPP_TOPOLOGY				0x00010BE4
#define COMPRESSED_PASSTHROUGH_DEFAULT_TOPOLOGY         0x0001076B
#define VPM_TX_SM_ECNS_COPP_TOPOLOGY			0x00010F71
#define VPM_TX_DM_FLUENCE_COPP_TOPOLOGY			0x00010F72
#define VPM_TX_QMIC_FLUENCE_COPP_TOPOLOGY		0x00010F75
#define VPM_TX_DM_RFECNS_COPP_TOPOLOGY			0x00010F86
#define ADM_CMD_COPP_OPEN_TOPOLOGY_ID_DTS_HPX		0x10015002
#define ADM_CMD_COPP_OPEN_TOPOLOGY_ID_AUDIOSPHERE	0x10028000



struct avs_cmd_shared_mem_map_regions {
	struct apr_hdr hdr;
	u16                  mem_pool_id;


	u16                  num_regions;
	

	u32                  property_flag;

} __packed;

struct avs_shared_map_region_payload {
	u32                  shm_addr_lsw;

	u32                  shm_addr_msw;

	u32                  mem_size_bytes;

} __packed;

struct avs_cmd_shared_mem_unmap_regions {
	struct apr_hdr       hdr;
	u32                  mem_map_handle;

} __packed;



struct avs_cmdrsp_shared_mem_map_regions {
	u32                  mem_map_handle;

} __packed;


struct asm_wma_cfg {
	u16 format_tag;
	u16 ch_cfg;
	u32 sample_rate;
	u32 avg_bytes_per_sec;
	u16 block_align;
	u16 valid_bits_per_sample;
	u32 ch_mask;
	u16 encode_opt;
	u16 adv_encode_opt;
	u32 adv_encode_opt2;
	u32 drc_peak_ref;
	u32 drc_peak_target;
	u32 drc_ave_ref;
	u32 drc_ave_target;
} __packed;

struct asm_wmapro_cfg {
	u16 format_tag;
	u16 ch_cfg;
	u32 sample_rate;
	u32 avg_bytes_per_sec;
	u16 block_align;
	u16 valid_bits_per_sample;
	u32 ch_mask;
	u16 encode_opt;
	u16 adv_encode_opt;
	u32 adv_encode_opt2;
	u32 drc_peak_ref;
	u32 drc_peak_target;
	u32 drc_ave_ref;
	u32 drc_ave_target;
} __packed;

struct asm_aac_cfg {
	u16 format;
	u16 aot;
	u16 ep_config;
	u16 section_data_resilience;
	u16 scalefactor_data_resilience;
	u16 spectral_data_resilience;
	u16 ch_cfg;
	u16 reserved;
	u32 sample_rate;
} __packed;

struct asm_amrwbplus_cfg {
	u32  size_bytes;
	u32  version;
	u32  num_channels;
	u32  amr_band_mode;
	u32  amr_dtx_mode;
	u32  amr_frame_fmt;
	u32  amr_lsf_idx;
} __packed;

struct asm_flac_cfg {
	u32 sample_rate;
	u32 ext_sample_rate;
	u32 min_frame_size;
	u32 max_frame_size;
	u16 stream_info_present;
	u16 min_blk_size;
	u16 max_blk_size;
	u16 ch_cfg;
	u16 sample_size;
	u16 md5_sum;
};

struct asm_alac_cfg {
	u32 frame_length;
	u8 compatible_version;
	u8 bit_depth;
	u8 pb;
	u8 mb;
	u8 kb;
	u8 num_channels;
	u16 max_run;
	u32 max_frame_bytes;
	u32 avg_bit_rate;
	u32 sample_rate;
	u32 channel_layout_tag;
};

struct asm_vorbis_cfg {
	u32 bit_stream_fmt;
};

struct asm_ape_cfg {
	u16 compatible_version;
	u16 compression_level;
	u32 format_flags;
	u32 blocks_per_frame;
	u32 final_frame_blocks;
	u32 total_frames;
	u16 bits_per_sample;
	u16 num_channels;
	u32 sample_rate;
	u32 seek_table_present;
};

struct asm_softpause_params {
	u32 enable;
	u32 period;
	u32 step;
	u32 rampingcurve;
} __packed;

struct asm_softvolume_params {
	u32 period;
	u32 step;
	u32 rampingcurve;
} __packed;

#define ASM_END_POINT_DEVICE_MATRIX     0

#define PCM_CHANNEL_NULL 0

#define PCM_CHANNEL_FL    1

#define PCM_CHANNEL_FR    2

#define PCM_CHANNEL_FC    3

#define PCM_CHANNEL_LS   4

#define PCM_CHANNEL_RS   5

#define PCM_CHANNEL_LFE  6

#define PCM_CHANNEL_CS   7

#define PCM_CHANNEL_LB   8

#define PCM_CHANNEL_RB   9

#define PCM_CHANNELS   10

#define PCM_CHANNEL_CVH  11

#define PCM_CHANNEL_MS   12

#define PCM_CHANNEL_FLC  13

#define PCM_CHANNEL_FRC  14

#define PCM_CHANNEL_RLC  15

#define PCM_CHANNEL_RRC  16

#define PCM_FORMAT_MAX_NUM_CHANNEL  8

#define ASM_MEDIA_FMT_MULTI_CHANNEL_PCM_V2 0x00010DA5

#define ASM_MEDIA_FMT_MULTI_CHANNEL_PCM_V3 0x00010DDC

#define ASM_MEDIA_FMT_EVRCB_FS 0x00010BEF

#define ASM_MEDIA_FMT_EVRCWB_FS 0x00010BF0

#define ASM_MAX_EQ_BANDS 12

#define ASM_DATA_CMD_MEDIA_FMT_UPDATE_V2 0x00010D98

struct asm_data_cmd_media_fmt_update_v2 {
u32                    fmt_blk_size;
	
}  __packed;

struct asm_multi_channel_pcm_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmt_blk;

	u16  num_channels;
	
	u16  bits_per_sample;


	u32  sample_rate;

	u16  is_signed;
	

	u16  reserved;
	

	u8   channel_mapping[8];
} __packed;

struct asm_multi_channel_pcm_fmt_blk_v3 {
	uint16_t                num_channels;

	uint16_t                bits_per_sample;

	uint32_t                sample_rate;

	uint16_t                is_signed;

	uint16_t                sample_word_size;

	uint8_t                 channel_mapping[8];
} __packed;

struct asm_multi_channel_pcm_fmt_blk_param_v3 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmt_blk;
	struct asm_multi_channel_pcm_fmt_blk_v3 param;
} __packed;

struct asm_stream_cmd_set_encdec_param {
	u32                  param_id;
	

	u32                  param_size;

} __packed;

struct asm_enc_cfg_blk_param_v2 {
	u32                  frames_per_buf;

	u32                  enc_cfg_blk_size;

} __packed;

struct asm_dec_ddp_endp_param_v2 {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	int endp_param_value;
} __packed;



struct asm_multi_channel_pcm_enc_cfg_v3 {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param encdec;
	struct asm_enc_cfg_blk_param_v2 encblk;
	uint16_t num_channels;
	uint16_t  bits_per_sample;
	uint32_t  sample_rate;
	uint16_t  is_signed;
	uint16_t    sample_word_size;
	uint8_t   channel_mapping[8];
};


struct asm_multi_channel_pcm_enc_cfg_v2 {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;
	uint16_t  num_channels;

	uint16_t  bits_per_sample;

	uint32_t  sample_rate;

	uint16_t  is_signed;

	uint16_t  reserved;


	uint8_t   channel_mapping[8];
} __packed;

#define ASM_MEDIA_FMT_MP3 0x00010BE9
#define ASM_MEDIA_FMT_AAC_V2 0x00010DA6


#define ASM_MEDIA_FMT_DOLBY_AAC 0x00010D86

#define ASM_MEDIA_FMT_AAC_FORMAT_FLAG_ADTS 0

#define ASM_MEDIA_FMT_AAC_FORMAT_FLAG_LOAS                      1

#define ASM_MEDIA_FMT_AAC_FORMAT_FLAG_ADIF   2

#define ASM_MEDIA_FMT_AAC_FORMAT_FLAG_RAW    3

#define ASM_MEDIA_FMT_AAC_AOT_LC             2
#define ASM_MEDIA_FMT_AAC_AOT_SBR            5
#define ASM_MEDIA_FMT_AAC_AOT_PS             29
#define ASM_MEDIA_FMT_AAC_AOT_BSAC           22

struct asm_aac_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmt_blk;

		u16          aac_fmt_flag;

	u16          audio_objype;

	u16          channel_config;

	u16          total_size_of_PCE_bits;

	u32          sample_rate;

} __packed;

struct asm_aac_enc_cfg_v2 {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;

	u32          bit_rate;
	
	u32          enc_mode;
	u16          aac_fmt_flag;
	u16          channel_cfg;

	u32          sample_rate;

} __packed;

#define ASM_MEDIA_FMT_G711_ALAW_FS 0x00010BF7
#define ASM_MEDIA_FMT_G711_MLAW_FS 0x00010C2E

struct asm_g711_enc_cfg_v2 {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param encdec;
	struct asm_enc_cfg_blk_param_v2 encblk;

	u32          sample_rate;

} __packed;

struct asm_vorbis_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;
	u32          bit_stream_fmt;

} __packed;

struct asm_flac_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;

	u16 is_stream_info_present;

	u16 num_channels;

	u16 min_blk_size;

	u16 max_blk_size;

	u16 md5_sum[8];

	u32 sample_rate;

	u32 min_frame_size;

	u32 max_frame_size;

	u16 sample_size;

	u16 reserved;

} __packed;

struct asm_alac_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;

	u32 frame_length;
	u8 compatible_version;
	u8 bit_depth;
	u8 pb;
	u8 mb;
	u8 kb;
	u8 num_channels;
	u16 max_run;
	u32 max_frame_bytes;
	u32 avg_bit_rate;
	u32 sample_rate;
	u32 channel_layout_tag;

} __packed;

struct asm_ape_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;

	u16 compatible_version;
	u16 compression_level;
	u32 format_flags;
	u32 blocks_per_frame;
	u32 final_frame_blocks;
	u32 total_frames;
	u16 bits_per_sample;
	u16 num_channels;
	u32 sample_rate;
	u32 seek_table_present;

} __packed;

#define ASM_MEDIA_FMT_AMRNB_FS                  0x00010BEB

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MR475                0

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MR515                1

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR59                2

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR67                3

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR74                4

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR795               5

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR102               6

#define ASM_MEDIA_FMT_AMRNB_FS_ENCODE_MODE_MMR122               7

#define ASM_MEDIA_FMT_AMRNB_FS_DTX_MODE_OFF                     0

#define ASM_MEDIA_FMT_AMRNB_FS_DTX_MODE_VAD1                    1

#define ASM_MEDIA_FMT_AMRNB_FS_DTX_MODE_VAD2                    2

#define ASM_MEDIA_FMT_AMRNB_FS_DTX_MODE_AUTO                    3

struct asm_amrnb_enc_cfg {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;

	u16          enc_mode;

	u16          dtx_mode;
} __packed;

#define ASM_MEDIA_FMT_AMRWB_FS                  0x00010BEC

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR66                 0

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR885                1

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR1265               2

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR1425               3

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR1585               4

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR1825               5

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR1985               6

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR2305               7

#define ASM_MEDIA_FMT_AMRWB_FS_ENCODE_MODE_MR2385               8

struct asm_amrwb_enc_cfg {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;

	u16          enc_mode;

	u16          dtx_mode;
} __packed;

#define ASM_MEDIA_FMT_V13K_FS                      0x00010BED

#define ASM_MEDIA_FMT_V13K_FS_ENCODE_MODE_MR1440                0

#define ASM_MEDIA_FMT_V13K_FS_ENCODE_MODE_MR1220                1

#define ASM_MEDIA_FMT_V13K_FS_ENCODE_MODE_MR1120                2

#define ASM_MEDIA_FMT_V13K_FS_ENCODE_MODE_MR90                  3

#define ASM_MEDIA_FMT_V13K_FS_ENCODE_MODE_MR720                 4

#define ASM_MEDIA_FMT_VOC_ONE_EIGHTH_RATE          1

#define ASM_MEDIA_FMT_VOC_ONE_FOURTH_RATE       2

#define ASM_MEDIA_FMT_VOC_HALF_RATE             3

#define ASM_MEDIA_FMT_VOC_FULL_RATE             4

struct asm_v13k_enc_cfg {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;
		u16          max_rate;

	u16          min_rate;

	u16          reduced_rate_cmd;

	u16          rate_mod_cmd;

} __packed;

#define ASM_MEDIA_FMT_EVRC_FS                   0x00010BEE

struct asm_evrc_enc_cfg {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;
	u16          max_rate;

	u16          min_rate;

	u16          rate_mod_cmd;

	u16          reserved;
	
} __packed;

#define ASM_MEDIA_FMT_WMA_V10PRO_V2                0x00010DA7

struct asm_wmaprov10_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;

	u16          fmtag;

	u16          num_channels;

	u32          sample_rate;

	u32          avg_bytes_per_sec;

	u16          blk_align;

	u16          bits_per_sample;

	u32          channel_mask;

	u16          enc_options;


	u16          usAdvancedEncodeOpt;
	

	u32          advanced_enc_options2;
	

} __packed;

#define ASM_MEDIA_FMT_WMA_V9_V2                    0x00010DA8
struct asm_wmastdv9_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;
	u16          fmtag;

	u16          num_channels;

	u32          sample_rate;

	u32          avg_bytes_per_sec;
	

	u16          blk_align;


	u16          bits_per_sample;

	u32          channel_mask;

	u16          enc_options;
	

	u16          reserved;

} __packed;

#define ASM_MEDIA_FMT_WMA_V8                    0x00010D91

struct asm_wmastdv8_enc_cfg {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;
	u32          bit_rate;
	

	u32          sample_rate;

	u16          channel_cfg;

	u16          reserved;
	
	} __packed;

#define ASM_MEDIA_FMT_AMR_WB_PLUS_V2               0x00010DA9

struct asm_amrwbplus_fmt_blk_v2 {
	struct apr_hdr hdr;
	struct asm_data_cmd_media_fmt_update_v2 fmtblk;
	u32          amr_frame_fmt;

} __packed;

#define ASM_MEDIA_FMT_AC3			0x00010DEE
#define ASM_MEDIA_FMT_EAC3			0x00010DEF
#define ASM_MEDIA_FMT_DTS                    0x00010D88
#define ASM_MEDIA_FMT_MP2                    0x00010DE9
#define ASM_MEDIA_FMT_FLAC                   0x00010C16
#define ASM_MEDIA_FMT_ALAC                   0x00012F31
#define ASM_MEDIA_FMT_VORBIS                 0x00010C15
#define ASM_MEDIA_FMT_APE                    0x00012F32



#define ASM_MEDIA_FMT_ATRAC                  0x00010D89


#define ASM_MEDIA_FMT_MAT                    0x00010D8A


#define ASM_DATA_CMD_WRITE_V2 0x00010DAB

struct asm_data_cmd_write_v2 {
	struct apr_hdr hdr;
	u32                  buf_addr_lsw;

	u32                  buf_addr_msw;
	u32                  mem_map_handle;
	u32                  buf_size;

	u32                  seq_id;
	

	u32                  timestamp_lsw;

	u32                  timestamp_msw;

	u32                  flags;

} __packed;

#define ASM_DATA_CMD_READ_V2 0x00010DAC

struct asm_data_cmd_read_v2 {
	struct apr_hdr       hdr;
	u32                  buf_addr_lsw;


	u32                  buf_addr_msw;
	u32                  mem_map_handle;

	u32                  buf_size;

	u32                  seq_id;
} __packed;

#define ASM_DATA_CMD_EOS               0x00010BDB
#define ASM_DATA_EVENT_RENDERED_EOS    0x00010C1C
#define ASM_DATA_EVENT_EOS             0x00010BDD

#define ASM_DATA_EVENT_WRITE_DONE_V2 0x00010D99
struct asm_data_event_write_done_v2 {
	u32                  buf_addr_lsw;
	
	u32                  buf_addr_msw;
	u32                  mem_map_handle;
	

	u32                  status;
} __packed;

#define ASM_DATA_EVENT_READ_DONE_V2 0x00010D9A

#define ASM_BIT_MASK_FRAME_METADATA_FLAG (0x40000000UL)

#define ASM_SHIFT_FRAME_METADATA_FLAG 30

struct asm_data_event_read_done_v2 {
	u32                  status;

u32                  buf_addr_lsw;

u32                  buf_addr_msw;

u32                  mem_map_handle;

u32                  enc_framesotal_size;

u32                  offset;

u32                  timestamp_lsw;


u32                  timestamp_msw;


u32                  flags;

u32                  num_frames;

u32                  seq_id;
} __packed;

struct asm_data_read_buf_metadata_v2 {
	u32          offset;

u32          frm_size;

u32          num_encoded_pcm_samples;

u32          timestamp_lsw;


u32          timestamp_msw;

u32          flags;
} __packed;


#define ASM_DATA_EVENT_SR_CM_CHANGE_NOTIFY 0x00010C65



struct asm_data_event_sr_cm_change_notify {
	u32                  sample_rate;

	u16                  num_channels;


	u16                  reserved;
	

	u8                   channel_mapping[8];

} __packed;

#define ASM_DATA_EVENT_ENC_SR_CM_CHANGE_NOTIFY 0x00010BDE

struct asm_data_event_enc_sr_cm_change_notify {
	u32                  sample_rate;


	u16                  num_channels;


	u16                  bits_per_sample;


	u8                   channel_mapping[8];

} __packed;
#define ASM_DATA_CMD_IEC_60958_FRAME_RATE 0x00010D87



struct asm_data_cmd_iec_60958_frame_rate {
	u32                  frame_rate;
} __packed;

#define ASM_BIT_MASK_STREAM_ID                 (0x000000FFUL)

#define ASM_SHIFT_STREAM_ID                    0

#define ASM_BIT_MASK_SESSION_ID                (0x0000FF00UL)

#define ASM_SHIFT_SESSION_ID                   8

#define ASM_BIT_MASK_SERVICE_ID                (0x00FF0000UL)

#define ASM_SHIFT_SERVICE_ID                   16

#define ASM_BIT_MASK_DOMAIN_ID                (0xFF000000UL)

#define ASM_SHIFT_DOMAIN_ID                    24

#define ASM_CMD_SHARED_MEM_MAP_REGIONS               0x00010D92
#define ASM_CMDRSP_SHARED_MEM_MAP_REGIONS     0x00010D93
#define ASM_CMD_SHARED_MEM_UNMAP_REGIONS              0x00010D94


#define ASM_MAX_SESSION_ID  (15)

#define ASM_MAX_NUM_SESSIONS                ASM_MAX_SESSION_ID

#define ASM_MAX_STREAMS_PER_SESSION (8)
#define ASM_SESSION_CMD_RUN_V2                   0x00010DAA
#define ASM_SESSION_CMD_RUN_STARTIME_RUN_IMMEDIATE  0
#define ASM_SESSION_CMD_RUN_STARTIME_RUN_AT_ABSOLUTEIME 1
#define ASM_SESSION_CMD_RUN_STARTIME_RUN_AT_RELATIVEIME 2
#define ASM_SESSION_CMD_RUN_STARTIME_RUN_WITH_DELAY     3

#define ASM_BIT_MASK_RUN_STARTIME                 (0x00000003UL)

#define ASM_SHIFT_RUN_STARTIME 0
struct asm_session_cmd_run_v2 {
	struct apr_hdr hdr;
	u32                  flags;

	u32                  time_lsw;

	u32                  time_msw;

} __packed;

#define ASM_SESSION_CMD_PAUSE 0x00010BD3
#define ASM_SESSION_CMD_SUSPEND 0x00010DEC
#define ASM_SESSION_CMD_GET_SESSIONTIME_V3 0x00010D9D
#define ASM_SESSION_CMD_REGISTER_FOR_RX_UNDERFLOW_EVENTS 0x00010BD5

struct asm_session_cmd_rgstr_rx_underflow {
	struct apr_hdr hdr;
	u16                  enable_flag;
	u16                  reserved;
	
} __packed;

#define ASM_SESSION_CMD_REGISTER_FORX_OVERFLOW_EVENTS 0x00010BD6

struct asm_session_cmd_regx_overflow {
	struct apr_hdr hdr;
	u16                  enable_flag;

	u16                  reserved;
	
} __packed;

#define ASM_SESSION_EVENT_RX_UNDERFLOW        0x00010C17
#define ASM_SESSION_EVENTX_OVERFLOW           0x00010C18
#define ASM_SESSION_CMDRSP_GET_SESSIONTIME_V3 0x00010D9E

struct asm_session_cmdrsp_get_sessiontime_v3 {
	u32                  status;

	u32                  sessiontime_lsw;
	

	u32                  sessiontime_msw;
	

	u32                  absolutetime_lsw;


	u32                  absolutetime_msw;

} __packed;

#define ASM_SESSION_CMD_ADJUST_SESSION_CLOCK_V2     0x00010D9F

struct asm_session_cmd_adjust_session_clock_v2 {
	struct apr_hdr hdr;
u32                  adjustime_lsw;


	u32                  adjustime_msw;

} __packed;

#define ASM_SESSION_CMDRSP_ADJUST_SESSION_CLOCK_V2    0x00010DA0

struct asm_session_cmdrsp_adjust_session_clock_v2 {
	u32                  status;


	u32                  actual_adjustime_lsw;


	u32                  actual_adjustime_msw;


	u32                  cmd_latency_lsw;


	u32                  cmd_latency_msw;

} __packed;

#define ASM_SESSION_CMD_GET_PATH_DELAY_V2	 0x00010DAF
#define ASM_SESSION_CMDRSP_GET_PATH_DELAY_V2 0x00010DB0

struct asm_session_cmdrsp_get_path_delay_v2 {
	u32                  status;

	u32                  audio_delay_lsw;
	

	u32                  audio_delay_msw;
	

} __packed;

#define ASM_STREAM_CMD_OPEN_WRITE_V3       0x00010DB3

#define ASM_LOW_LATENCY_STREAM_SESSION				0x10000000

#define ASM_ULTRA_LOW_LATENCY_STREAM_SESSION			0x20000000

#define ASM_ULL_POST_PROCESSING_STREAM_SESSION			0x40000000

#define ASM_LEGACY_STREAM_SESSION                                      0


struct asm_stream_cmd_open_write_v3 {
	struct apr_hdr			hdr;
	uint32_t                    mode_flags;

	uint16_t                    sink_endpointype;

	uint16_t                    bits_per_sample;

	uint32_t                    postprocopo_id;

	uint32_t                    dec_fmt_id;
} __packed;

#define ASM_STREAM_CMD_OPEN_PULL_MODE_WRITE    0x00010DD9

#define ASM_BIT_MASK_STREAM_PERF_FLAG_PULL_MODE_WRITE 0xE0000000UL

#define ASM_SHIFT_STREAM_PERF_FLAG_PULL_MODE_WRITE 29

#define ASM_STREAM_CMD_OPEN_PUSH_MODE_READ  0x00010DDA

#define ASM_BIT_MASK_STREAM_PERF_FLAG_PUSH_MODE_READ 0xE0000000UL

#define ASM_SHIFT_STREAM_PERF_FLAG_PUSH_MODE_READ 29

#define ASM_DATA_EVENT_WATERMARK 0x00010DDB

struct asm_shared_position_buffer {
	volatile uint32_t               frame_counter;

	volatile uint32_t               index;

	volatile uint32_t               wall_clock_us_lsw;

	volatile uint32_t               wall_clock_us_msw;
} __packed;

struct asm_shared_watermark_level {
	uint32_t                watermark_level_bytes;
} __packed;

struct asm_stream_cmd_open_shared_io {
	struct apr_hdr          hdr;
	uint32_t                mode_flags;
	uint16_t                endpoint_type;
	uint16_t                topo_bits_per_sample;
	uint32_t                topo_id;
	uint32_t                fmt_id;
	uint32_t                shared_pos_buf_phy_addr_lsw;
	uint32_t                shared_pos_buf_phy_addr_msw;
	uint16_t                shared_pos_buf_mem_pool_id;
	uint16_t                shared_pos_buf_num_regions;
	uint32_t                shared_pos_buf_property_flag;
	uint32_t                shared_circ_buf_start_phy_addr_lsw;
	uint32_t                shared_circ_buf_start_phy_addr_msw;
	uint32_t                shared_circ_buf_size;
	uint16_t                shared_circ_buf_mem_pool_id;
	uint16_t                shared_circ_buf_num_regions;
	uint32_t                shared_circ_buf_property_flag;
	uint32_t                num_watermark_levels;
	struct asm_multi_channel_pcm_fmt_blk_v3         fmt;
	struct avs_shared_map_region_payload            map_region_pos_buf;
	struct avs_shared_map_region_payload            map_region_circ_buf;
	struct asm_shared_watermark_level watermark[0];
} __packed;

#define ASM_STREAM_CMD_OPEN_READ_V3                 0x00010DB4

#define ASM_BIT_MASKIMESTAMPYPE_FLAG        (0x00000020UL)

#define ASM_SHIFTIMESTAMPYPE_FLAG 5

#define ASM_RELATIVEIMESTAMP      0

#define ASM_ABSOLUTEIMESTAMP      1

#define ASM_LOW_LATENCY_TX_STREAM_SESSION			1

#define ASM_SHIFT_STREAM_PERF_MODE_FLAG_IN_OPEN_READ              29

struct asm_stream_cmd_open_read_v3 {
	struct apr_hdr hdr;
	u32                    mode_flags;

	u32                    src_endpointype;

	u32                    preprocopo_id;

	u32                    enc_cfg_id;

	u16                    bits_per_sample;

	u16                    reserved;
} __packed;

#define ASM_POPP_OUTPUT_SR_NATIVE_RATE                                  0

#define ASM_POPP_OUTPUT_SR_MAX_RATE             48000

#define ASM_STREAM_CMD_OPEN_READWRITE_V2        0x00010D8D
#define ASM_STREAM_CMD_OPEN_READWRITE_V2        0x00010D8D

struct asm_stream_cmd_open_readwrite_v2 {
	struct apr_hdr         hdr;
	u32                    mode_flags;

	u32                    postprocopo_id;

	u32                    dec_fmt_id;

	u32                    enc_cfg_id;

	u16                    bits_per_sample;

	u16                    reserved;

} __packed;

#define ASM_STREAM_CMD_OPEN_LOOPBACK_V2 0x00010D8E
struct asm_stream_cmd_open_loopback_v2 {
	struct apr_hdr         hdr;
	u32                    mode_flags;
	u16                    src_endpointype;
	
	u16                    sink_endpointype;
	
	u32                    postprocopo_id;

	u16                    bits_per_sample;
	u16                    reserved;
} __packed;


#define ASM_STREAM_CMD_OPEN_TRANSCODE_LOOPBACK    0x00010DBA

#define ASM_BIT_MASK_STREAM_PERF_MODE_FLAG_IN_OPEN_TRANSCODE_LOOPBACK \
	(0x70000000UL)

#define ASM_SHIFT_STREAM_PERF_MODE_FLAG_IN_OPEN_TRANSCODE_LOOPBACK    28

#define ASM_BIT_MASK_DECODER_CONVERTER_FLAG    (0x00000078UL)

#define ASM_SHIFT_DECODER_CONVERTER_FLAG                              3

#define ASM_CONVERTER_MODE_NONE                                       0

#define ASM_DDP_DD_CONVERTER_MODE                                     1

#define ASM_POST_PROCESS_CONVERTER_MODE                               2


struct asm_stream_cmd_open_transcode_loopback_t {
	struct apr_hdr         hdr;
	u32                    mode_flags;

	u32                    src_format_id;
	u32                    sink_format_id;

	u32                    audproc_topo_id;

	u16                    src_endpoint_type;

	u16                    sink_endpoint_type;

	u16                    bits_per_sample;

	u16                    reserved;
} __packed;


#define ASM_STREAM_CMD_CLOSE             0x00010BCD
#define ASM_STREAM_CMD_FLUSH             0x00010BCE


#define ASM_STREAM_CMD_FLUSH_READBUFS   0x00010C09
#define ASM_STREAM_CMD_SET_PP_PARAMS_V2 0x00010DA1

struct asm_stream_cmd_set_pp_params_v2 {
	u32                  data_payload_addr_lsw;
	u32                  data_payload_addr_msw;
	u32                  mem_map_handle;

	u32                  data_payload_size;

} __packed;


struct asm_stream_param_data_v2 {
	u32                  module_id;
	

	u32                  param_id;
	

	u16                  param_size;

	u16                  reserved;

} __packed;

#define ASM_STREAM_CMD_GET_PP_PARAMS_V2		0x00010DA2

struct asm_stream_cmd_get_pp_params_v2 {
	u32                  data_payload_addr_lsw;
	
	u32                  data_payload_addr_msw;

	u32                  mem_map_handle;

	u32                  module_id;
	

	u32                  param_id;
	

	u16                  param_max_size;


	u16                  reserved;

} __packed;

#define ASM_STREAM_CMD_SET_ENCDEC_PARAM 0x00010C10

#define ASM_PARAM_ID_ENCDEC_BITRATE     0x00010C13

struct asm_bitrate_param {
	u32                  bitrate;

} __packed;

#define ASM_PARAM_ID_ENCDEC_ENC_CFG_BLK_V2 0x00010DA3
#define ASM_PARAM_ID_AAC_SBR_PS_FLAG		 0x00010C63


#define ASM_AAC_SBR_OFF_PS_OFF (2)


#define ASM_AAC_SBR_ON_PS_OFF  (1)



#define ASM_AAC_SBR_ON_PS_ON   (0)


struct asm_aac_sbr_ps_flag_param {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;

	u32                  sbr_ps_flag;
} __packed;

#define ASM_PARAM_ID_AAC_DUAL_MONO_MAPPING                      0x00010C64

#define ASM_AAC_DUAL_MONO_MAP_SCE_1                                 (1)

#define ASM_AAC_DUAL_MONO_MAP_SCE_2                                 (2)



struct asm_aac_dual_mono_mapping_param {
	struct apr_hdr							hdr;
	struct asm_stream_cmd_set_encdec_param	encdec;
	u16    left_channel_sce;
	u16    right_channel_sce;

} __packed;

#define ASM_STREAM_CMDRSP_GET_PP_PARAMS_V2 0x00010DA4

struct asm_stream_cmdrsp_get_pp_params_v2 {
	u32                  status;
} __packed;

#define ASM_PARAM_ID_AC3_KARAOKE_MODE 0x00010D73

#define AC3_KARAOKE_MODE_NO_VOCAL     (0)

#define AC3_KARAOKE_MODE_LEFT_VOCAL   (1)

#define AC3_KARAOKE_MODE_RIGHT_VOCAL (2)

#define AC3_KARAOKE_MODE_BOTH_VOCAL             (3)
#define ASM_PARAM_ID_AC3_DRC_MODE               0x00010D74
#define AC3_DRC_MODE_CUSTOM_ANALOG              (0)

#define AC3_DRC_MODE_CUSTOM_DIGITAL             (1)
#define AC3_DRC_MODE_LINE_OUT  (2)

#define AC3_DRC_MODE_RF_REMOD                         (3)
#define ASM_PARAM_ID_AC3_DUAL_MONO_MODE               0x00010D75

#define AC3_DUAL_MONO_MODE_STEREO                     (0)

#define AC3_DUAL_MONO_MODE_LEFT_MONO                  (1)

#define AC3_DUAL_MONO_MODE_RIGHT_MONO                 (2)

#define AC3_DUAL_MONO_MODE_MIXED_MONO        (3)
#define ASM_PARAM_ID_AC3_STEREO_DOWNMIX_MODE 0x00010D76


#define AC3_STEREO_DOWNMIX_MODE_AUTO_DETECT  (0)


#define AC3_STEREO_DOWNMIX_MODE_LT_RT        (1)

#define AC3_STEREO_DOWNMIX_MODE_LO_RO (2)

#define ASM_PARAM_ID_AC3_PCM_SCALEFACTOR 0x00010D78

#define ASM_PARAM_ID_AC3_DRC_BOOST_SCALEFACTOR 0x00010D79

#define ASM_PARAM_ID_AC3_DRC_CUT_SCALEFACTOR 0x00010D7A


struct asm_ac3_generic_param {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	struct asm_enc_cfg_blk_param_v2	encblk;
	u32                  generic_parameter;
} __packed;


#define WMAPRO_CHANNEL_MASK_RAW (-1)



#define WMAPRO_CHANNEL_MASK_ZERO 0x0000

#define WMAPRO_CHANNEL_MASK_1_C 0x0004

#define WMAPRO_CHANNEL_MASK_2_L_R 0x0003

#define WMAPRO_CHANNEL_MASK_3_L_C_R 0x0007

#define WMAPRO_CHANNEL_MASK_2_Bl_Br  0x0030

#define WMAPRO_CHANNEL_MASK_4_L_R_Bl_Br 0x0033

#define WMAPRO_CHANNEL_MASK_4_L_R_C_Bc_HT 0x0107
#define WMAPRO_CHANNEL_MASK_5_L_C_R_Bl_Br  0x0037

#define WMAPRO_CHANNEL_MASK_5_L_C_R_Sl_Sr_HT   0x0607
#define WMAPRO_CHANNEL_MASK_5DOT1_L_C_R_Bl_Br_SLF  0x003F
#define WMAPRO_CHANNEL_MASK_5DOT1_L_C_R_Sl_Sr_SLF_HT  0x060F
#define WMAPRO_CHANNEL_MASK_5DOT1_L_C_R_Bl_Br_Bc  0x0137
#define WMAPRO_CHANNEL_MASK_5DOT1_L_C_R_Sl_Sr_Bc_HT   0x0707

#define WMAPRO_CHANNEL_MASK_6DOT1_L_C_R_Bl_Br_Bc_SLF   0x013F

#define WMAPRO_CHANNEL_MASK_6DOT1_L_C_R_Sl_Sr_Bc_SLF_HT 0x070F

#define WMAPRO_CHANNEL_MASK_6DOT1_L_C_R_Bl_Br_SFLOC_SFROC   0x00F7

#define WMAPRO_CHANNEL_MASK_6DOT1_L_C_R_Sl_Sr_SFLOC_SFROC_HT 0x0637

#define WMAPRO_CHANNEL_MASK_7DOT1_L_C_R_Bl_Br_SLF_SFLOC_SFROC \
					0x00FF

#define WMAPRO_CHANNEL_MASK_7DOT1_L_C_R_Sl_Sr_SLF_SFLOC_SFROC_HT \
					0x063F

#define ASM_PARAM_ID_DEC_OUTPUT_CHAN_MAP  0x00010D82

#define MAX_CHAN_MAP_CHANNELS  16


struct asm_dec_out_chan_map_param {
	struct apr_hdr hdr;
	struct asm_stream_cmd_set_encdec_param  encdec;
	u32                 num_channels;
	u8                  channel_mapping[MAX_CHAN_MAP_CHANNELS];
} __packed;

#define ASM_STREAM_CMD_OPEN_WRITE_COMPRESSED  0x00010D84

#define ASM_BIT_MASK_IEC_61937_STREAM_FLAG   (0x00000001UL)

#define ASM_SHIFT_IEC_61937_STREAM_FLAG  0

#define ASM_BIT_MASK_IEC_60958_STREAM_FLAG   (0x00000002UL)

#define ASM_SHIFT_IEC_60958_STREAM_FLAG   1



struct asm_stream_cmd_open_write_compressed {
	struct apr_hdr hdr;
	u32                    flags;


	u32                    fmt_id;

} __packed;


#define ASM_DATA_CMD_REMOVE_INITIAL_SILENCE 0x00010D67
#define ASM_DATA_CMD_REMOVE_TRAILING_SILENCE 0x00010D68
struct asm_data_cmd_remove_silence {
	struct apr_hdr hdr;
	u32	num_samples_to_remove;
} __packed;

#define ASM_STREAM_CMD_OPEN_READ_COMPRESSED                        0x00010D95

struct asm_stream_cmd_open_read_compressed {
	struct apr_hdr hdr;
	u32                    mode_flags;

	u32                    frames_per_buf;

} __packed;



#define ASM_STREAM_POSTPROCOPO_ID_DEFAULT \
								0x00010BE4
#define ASM_STREAM_POSTPROCOPO_ID_PEAKMETER \
								0x00010D83
#define ASM_STREAM_POSTPROCOPO_ID_NONE \
								0x00010C68
#define ASM_STREAM_POSTPROCOPO_ID_MCH_PEAK_VOL \
								0x00010D8B
#define ASM_STREAM_PREPROCOPO_ID_DEFAULT \
			ASM_STREAM_POSTPROCOPO_ID_DEFAULT
#define ASM_STREAM_PREPROCOPO_ID_NONE \
			ASM_STREAM_POSTPROCOPO_ID_NONE
#define ADM_CMD_COPP_OPENOPOLOGY_ID_NONE_AUDIO_COPP \
			0x00010312
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_MONO_AUDIO_COPP \
								0x00010313
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_STEREO_AUDIO_COPP \
								0x00010314
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_STEREO_IIR_AUDIO_COPP\
								0x00010704
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_MONO_AUDIO_COPP_MBDRCV2\
								0x0001070D
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_STEREO_AUDIO_COPP_MBDRCV2\
								0x0001070E
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_STEREO_IIR_AUDIO_COPP_MBDRCV2\
								0x0001070F
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_STEREO_AUDIO_COPP_MBDRC_V3 \
								0x11000000
#define ADM_CMD_COPP_OPENOPOLOGY_ID_SPEAKER_MCH_PEAK_VOL \
								0x0001031B
#define ADM_CMD_COPP_OPENOPOLOGY_ID_MIC_MONO_AUDIO_COPP  0x00010315
#define ADM_CMD_COPP_OPENOPOLOGY_ID_MIC_STEREO_AUDIO_COPP 0x00010316
#define AUDPROC_COPPOPOLOGY_ID_MCHAN_IIR_AUDIO           0x00010715
#define ADM_CMD_COPP_OPENOPOLOGY_ID_DEFAULT_AUDIO_COPP   0x00010BE3
#define ADM_CMD_COPP_OPENOPOLOGY_ID_PEAKMETER_AUDIO_COPP 0x00010317
#define AUDPROC_MODULE_ID_AIG   0x00010716
#define AUDPROC_PARAM_ID_AIG_ENABLE		0x00010717
#define AUDPROC_PARAM_ID_AIG_CONFIG		0x00010718

struct Audio_AigParam {
	uint16_t	mode;
	int16_t		staticGainL16Q12;
	int16_t		initialGainDBL16Q7;
	int16_t		idealRMSDBL16Q7;
	int32_t		noiseGateL32;
	int32_t		minGainL32Q15;
	int32_t		maxGainL32Q15;
	uint32_t		gainAtRtUL32Q31;
	uint32_t		longGainAtRtUL32Q31;

	uint32_t		rmsTavUL32Q32;

	uint32_t		gainUpdateStartTimMsUL32Q0;

} __packed;


#define ADM_MODULE_ID_EANS                            0x00010C4A
#define ADM_PARAM_ID_EANS_ENABLE                      0x00010C4B
#define ADM_PARAM_ID_EANS_PARAMS                      0x00010C4C

struct adm_eans_enable {

	uint32_t                  enable_flag;

} __packed;


struct adm_eans_params {
	int16_t                         eans_mode;

	int16_t                         eans_input_gain;

	int16_t                         eans_output_gain;

	int16_t                         eansarget_ns;

	int16_t                         eans_s_alpha;

	int16_t                         eans_n_alpha;

	int16_t                         eans_n_alphamax;
	int16_t                         eans_e_alpha;

	int16_t                         eans_ns_snrmax;

	int16_t                         eans_sns_block;

	int16_t                         eans_ns_i;
	int16_t                         eans_np_scale;

	int16_t                         eans_n_lambda;

	int16_t                         eans_n_lambdaf;

	int16_t                         eans_gs_bias;

	int16_t                         eans_gs_max;

	int16_t                         eans_s_alpha_hb;

	int16_t                         eans_n_alphamax_hb;

	int16_t                         eans_e_alpha_hb;

	int16_t                         eans_n_lambda0;

	int16_t                         thresh;

	int16_t                         pwr_scale;

	int16_t                         hangover_max;

	int16_t                         alpha_snr;

	int16_t                         snr_diff_max;

	int16_t                         snr_diff_min;

	int16_t                         init_length;

	int16_t                         max_val;

	int16_t                         init_bound;

	int16_t                         reset_bound;

	int16_t                         avar_scale;

	int16_t                         sub_nc;

	int16_t                         spow_min;

	int16_t                         eans_gs_fast;

	int16_t                         eans_gs_med;

	int16_t                         eans_gs_slow;

	int16_t                         eans_swb_salpha;

	int16_t                         eans_swb_nalpha;
} __packed;
#define ADM_MODULE_IDX_MIC_GAIN_CTRL   0x00010C35

#define ADM_PARAM_IDX_MIC_GAIN       0x00010C36



struct admx_mic_gain {
	uint16_t                  tx_mic_gain;
	

	uint16_t                  reserved;
	
} __packed;

struct adm_set_mic_gain_params {
	struct adm_cmd_set_pp_params_v5 params;
	struct adm_param_data_v5 data;
	struct admx_mic_gain mic_gain_data;
} __packed;


#define ADM_MODULE_ID_RX_CODEC_GAIN_CTRL       0x00010C37

#define ADM_PARAM_ID_RX_CODEC_GAIN   0x00010C38





struct adm_rx_codec_gain {
	uint16_t                  rx_codec_gain;
	

	uint16_t                  reserved;
	
} __packed;


#define ADM_MODULE_ID_HPF_IIRX_FILTER    0x00010C3D

#define ADM_PARAM_ID_HPF_IIRX_FILTER_ENABLE_CONFIG   0x00010C3E

#define ADM_PARAM_ID_HPF_IIRX_FILTER_PRE_GAIN   0x00010C3F

#define ADM_PARAM_ID_HPF_IIRX_FILTER_CONFIG_PARAMS  0x00010C40


struct adm_hpfx_iir_filter_enable_cfg {
	uint32_t                  enable_flag;
} __packed;




struct adm_hpfx_iir_filter_pre_gain {
	uint16_t                  pre_gain;
	

	uint16_t                  reserved;
	
} __packed;




struct adm_hpfx_iir_filter_cfg_params {
	uint16_t                  num_biquad_stages;

	uint16_t                  reserved;
	
} __packed;


#define ADM_MODULE_IDX_IIR_FILTER 0x00010C41

#define ADM_MODULE_ID_LEFT_IIRUNING_FILTER      0x00010705

#define ADM_MODULE_ID_RIGHT_IIRUNING_FILTER    0x00010706



#define ADM_PARAM_IDX_IIR_FILTER_ENABLE_CONFIG   0x00010C42

#define ADM_PARAM_IDX_IIR_FILTER_PRE_GAIN    0x00010C43

#define ADM_PARAM_IDX_IIR_FILTER_CONFIG_PARAMS     0x00010C44



struct admx_iir_filter_enable_cfg {
	uint32_t                  enable_flag;

} __packed;





struct admx_iir_filter_pre_gain {
	uint16_t                  pre_gain;
	

	uint16_t                  reserved;
	
} __packed;




struct admx_iir_filter_cfg_params {
	uint16_t                  num_biquad_stages;

	uint16_t                  reserved;
	
} __packed;


#define ADM_MODULE_ID_QENSEMBLE    0x00010C59

#define ADM_PARAM_ID_QENSEMBLE_ENABLE   0x00010C60

#define ADM_PARAM_ID_QENSEMBLE_BACKGAIN   0x00010C61

#define ADM_PARAM_ID_QENSEMBLE_SET_NEW_ANGLE    0x00010C62



struct adm_qensemble_enable {
	uint32_t                  enable_flag;
} __packed;




struct adm_qensemble_param_backgain {
	int16_t                  back_gain;

	uint16_t                 reserved;
	
} __packed;


struct adm_qensemble_param_set_new_angle {
	int16_t                    new_angle;

	int16_t                    time_ms;
} __packed;


#define ADM_CMD_GET_PP_TOPO_MODULE_LIST				0x00010349
#define ADM_CMDRSP_GET_PP_TOPO_MODULE_LIST			0x00010350
#define AUDPROC_PARAM_ID_ENABLE					0x00010904
struct adm_cmd_get_pp_topo_module_list_t {
	struct apr_hdr hdr;
	
	uint32_t                  data_payload_addr_lsw;
	uint32_t                  data_payload_addr_msw;
	uint32_t                  mem_map_handle;
	uint16_t                  param_max_size;
	
	uint16_t                  reserved;
} __packed;

struct adm_cmd_rsp_get_pp_topo_module_list_t {
	
	uint32_t                  status;
} __packed;

struct audproc_topology_module_id_info_t {
	uint32_t	num_modules;
} __packed;


#define ASM_MODULE_ID_VOL_CTRL   0x00010BFE
#define ASM_MODULE_ID_VOL_CTRL2  0x00010910
#define AUDPROC_MODULE_ID_VOL_CTRL ASM_MODULE_ID_VOL_CTRL

#define ASM_PARAM_ID_VOL_CTRL_MASTER_GAIN    0x00010BFF
#define AUDPROC_PARAM_ID_VOL_CTRL_MASTER_GAIN ASM_PARAM_ID_VOL_CTRL_MASTER_GAIN

#define ASM_PARAM_ID_VOL_CTRL_LR_CHANNEL_GAIN     0x00010C00

#define ASM_PARAM_ID_VOL_CTRL_MUTE_CONFIG   0x00010C01

#define ASM_PARAM_ID_SOFT_VOL_STEPPING_PARAMETERS  0x00010C29
#define AUDPROC_PARAM_ID_SOFT_VOL_STEPPING_PARAMETERS\
			ASM_PARAM_ID_SOFT_VOL_STEPPING_PARAMETERS

#define ASM_PARAM_ID_SOFT_PAUSE_PARAMETERS   0x00010D6A

#define ASM_PARAM_ID_MULTICHANNEL_GAIN  0x00010713


#define ASM_PARAM_ID_MULTICHANNEL_MUTE  0x00010714






struct asm_volume_ctrl_master_gain {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint16_t                  master_gain;
	

	uint16_t                  reserved;
} __packed;


struct asm_volume_ctrl_lr_chan_gain {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;

	uint16_t                  l_chan_gain;
	

	uint16_t                  r_chan_gain;
	
} __packed;






struct asm_volume_ctrl_mute_config {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint32_t                  mute_flag;

} __packed;

#define ASM_PARAM_SVC_RAMPINGCURVE_LINEAR  0

#define ASM_PARAM_SVC_RAMPINGCURVE_EXP    1

#define ASM_PARAM_SVC_RAMPINGCURVE_LOG    2



struct asm_soft_step_volume_params {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint32_t                  period;

	uint32_t                  step;

	uint32_t                  ramping_curve;
} __packed;






struct asm_soft_pause_params {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint32_t                  enable_flag;



	uint32_t                  period;

	uint32_t                  step;

	uint32_t                  ramping_curve;
} __packed;


#define VOLUME_CONTROL_MAX_CHANNELS                       8





struct asm_volume_ctrl_channeltype_gain_pair {
	uint8_t                   channeltype;

	uint8_t                   reserved1;
	

	uint8_t                   reserved2;
	

	uint8_t                   reserved3;
	

	uint32_t                  gain;
} __packed;






struct asm_volume_ctrl_multichannel_gain {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint32_t                  num_channels;

	struct asm_volume_ctrl_channeltype_gain_pair
		gain_data[VOLUME_CONTROL_MAX_CHANNELS];
	
} __packed;






struct asm_volume_ctrl_channelype_mute_pair {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint8_t                   channelype;

	uint8_t                   reserved1;
	

	uint8_t                   reserved2;
	

	uint8_t                   reserved3;
	

	uint32_t                  mute;
} __packed;






struct asm_volume_ctrl_multichannel_mute {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
	uint32_t                  num_channels;

struct asm_volume_ctrl_channelype_mute_pair
				mute_data[VOLUME_CONTROL_MAX_CHANNELS];
	
} __packed;

#define ASM_MODULE_ID_IIRUNING_FILTER   0x00010C02

#define ASM_PARAM_ID_IIRUNING_FILTER_ENABLE_CONFIG   0x00010C03

#define ASM_PARAM_ID_IIRUNING_FILTER_PRE_GAIN  0x00010C04

#define ASM_PARAM_ID_IIRUNING_FILTER_CONFIG_PARAMS  0x00010C05



struct asm_iiruning_filter_enable {
	uint32_t                  enable_flag;
} __packed;



struct asm_iiruning_filter_pregain {
	uint16_t                  pregain;
	

	uint16_t                  reserved;
	
} __packed;



struct asm_iir_filter_config_params {
	uint16_t                  num_biquad_stages;

	uint16_t                  reserved;
	
} __packed;

#define ASM_MODULE_ID_MBDRC   0x00010C06

#define ASM_PARAM_ID_MBDRC_ENABLE   0x00010C07

#define ASM_PARAM_ID_MBDRC_CONFIG_PARAMS  0x00010C08


#define ASM_MODULE_ID_MBDRCV2                                0x0001070B

#define ASM_PARAM_ID_MBDRC_CONFIG_PARAMS_IMPROVED_FILTBANK_V2 \
								0x0001070C

#define ASM_MODULE_ID_MBDRCV3					0x0001090B



struct asm_mbdrc_enable {
	uint32_t                  enable_flag;
} __packed;





struct asm_mbdrc_config_params {
	uint16_t                  num_bands;

	int16_t                   limiterhreshold;

	int16_t                   limiter_makeup_gain;

	int16_t                   limiter_gc;

	int16_t                   limiter_delay;

	int16_t                   limiter_max_wait;
} __packed;



struct asm_subband_drc_config_params {
	int16_t                   drc_stereo_linked_flag;

	int16_t                   drc_mode;

	int16_t                   drc_down_sample_level;

	int16_t                   drc_delay;

	uint16_t                  drc_rmsime_avg_const;

	uint16_t                  drc_makeup_gain;
	
	int16_t                   down_expdrhreshold;

	int16_t                   down_expdr_slope;

	uint32_t                  down_expdr_attack;

	uint32_t                  down_expdr_release;

	uint16_t                  down_expdr_hysteresis;

	uint16_t                  reserved;
	

	int32_t                   down_expdr_min_gain_db;

	

	int16_t                   up_cmpsrhreshold;

	uint16_t                  up_cmpsr_slope;

	uint32_t                  up_cmpsr_attack;

	uint32_t                  up_cmpsr_release;

	uint16_t                  up_cmpsr_hysteresis;

	

	int16_t                   down_cmpsrhreshold;

	uint16_t                  down_cmpsr_slope;

	uint16_t                  reserved1;

	uint32_t                  down_cmpsr_attack;

	uint32_t                  down_cmpsr_release;

	uint16_t                  down_cmpsr_hysteresis;

	uint16_t                  reserved2;
} __packed;

#define ASM_MODULE_ID_EQUALIZER            0x00010C27
#define ASM_PARAM_ID_EQUALIZER_PARAMETERS  0x00010C28

#define ASM_MAX_EQ_BANDS 12

struct asm_eq_per_band_params {
	uint32_t                  band_idx;

	uint32_t                  filterype;

	uint32_t                  center_freq_hz;
	

	int32_t                   filter_gain;

	int32_t                   q_factor;
} __packed;

struct asm_eq_params {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
		uint32_t                  enable_flag;

		uint32_t                  num_bands;
	struct asm_eq_per_band_params eq_bands[ASM_MAX_EQ_BANDS];

} __packed;

#define ASM_PARAM_EQYPE_NONE      0

#define ASM_PARAM_EQ_BASS_BOOST     1

#define ASM_PARAM_EQ_BASS_CUT       2

#define ASM_PARAM_EQREBLE_BOOST   3

#define ASM_PARAM_EQREBLE_CUT     4

#define ASM_PARAM_EQ_BAND_BOOST     5

#define ASM_PARAM_EQ_BAND_CUT       6

#define VOICE_CMD_SET_PARAM				0x0001133D
#define VOICE_CMD_GET_PARAM				0x0001133E
#define VOICE_EVT_GET_PARAM_ACK				0x00011008


#define AUDPROC_MODULE_ID_BASS_BOOST                             0x000108A1
#define AUDPROC_PARAM_ID_BASS_BOOST_ENABLE                       0x000108A2
#define AUDPROC_PARAM_ID_BASS_BOOST_MODE                         0x000108A3
#define AUDPROC_PARAM_ID_BASS_BOOST_STRENGTH                     0x000108A4

#define AUDPROC_MODULE_ID_PBE                                    0x00010C2A
#define AUDPROC_PARAM_ID_PBE_ENABLE                              0x00010C2B
#define AUDPROC_PARAM_ID_PBE_PARAM_CONFIG                        0x00010C49

#define AUDPROC_MODULE_ID_VIRTUALIZER                            0x000108A5
#define AUDPROC_PARAM_ID_VIRTUALIZER_ENABLE                      0x000108A6
#define AUDPROC_PARAM_ID_VIRTUALIZER_STRENGTH                    0x000108A7
#define AUDPROC_PARAM_ID_VIRTUALIZER_OUT_TYPE                    0x000108A8
#define AUDPROC_PARAM_ID_VIRTUALIZER_GAIN_ADJUST                 0x000108A9

#define AUDPROC_MODULE_ID_REVERB                          0x000108AA
#define AUDPROC_PARAM_ID_REVERB_ENABLE                    0x000108AB
#define AUDPROC_PARAM_ID_REVERB_MODE                      0x000108AC
#define AUDPROC_PARAM_ID_REVERB_PRESET                    0x000108AD
#define AUDPROC_PARAM_ID_REVERB_WET_MIX                   0x000108AE
#define AUDPROC_PARAM_ID_REVERB_GAIN_ADJUST               0x000108AF
#define AUDPROC_PARAM_ID_REVERB_ROOM_LEVEL                0x000108B0
#define AUDPROC_PARAM_ID_REVERB_ROOM_HF_LEVEL             0x000108B1
#define AUDPROC_PARAM_ID_REVERB_DECAY_TIME                0x000108B2
#define AUDPROC_PARAM_ID_REVERB_DECAY_HF_RATIO            0x000108B3
#define AUDPROC_PARAM_ID_REVERB_REFLECTIONS_LEVEL         0x000108B4
#define AUDPROC_PARAM_ID_REVERB_REFLECTIONS_DELAY         0x000108B5
#define AUDPROC_PARAM_ID_REVERB_LEVEL                      0x000108B6
#define AUDPROC_PARAM_ID_REVERB_DELAY                      0x000108B7
#define AUDPROC_PARAM_ID_REVERB_DIFFUSION                  0x000108B8
#define AUDPROC_PARAM_ID_REVERB_DENSITY                    0x000108B9

#define AUDPROC_MODULE_ID_POPLESS_EQUALIZER                    0x000108BA
#define AUDPROC_PARAM_ID_EQ_ENABLE                             0x000108BB
#define AUDPROC_PARAM_ID_EQ_CONFIG                             0x000108BC
#define AUDPROC_PARAM_ID_EQ_NUM_BANDS                          0x000108BD
#define AUDPROC_PARAM_ID_EQ_BAND_LEVELS                        0x000108BE
#define AUDPROC_PARAM_ID_EQ_BAND_LEVEL_RANGE                   0x000108BF
#define AUDPROC_PARAM_ID_EQ_BAND_FREQS                         0x000108C0
#define AUDPROC_PARAM_ID_EQ_SINGLE_BAND_FREQ_RANGE             0x000108C1
#define AUDPROC_PARAM_ID_EQ_SINGLE_BAND_FREQ                   0x000108C2
#define AUDPROC_PARAM_ID_EQ_BAND_INDEX                         0x000108C3
#define AUDPROC_PARAM_ID_EQ_PRESET_ID                          0x000108C4
#define AUDPROC_PARAM_ID_EQ_NUM_PRESETS                        0x000108C5
#define AUDPROC_PARAM_ID_EQ_PRESET_NAME                        0x000108C6

#define ASM_CMD_ADD_TOPOLOGIES				0x00010DBE
#define ADM_CMD_ADD_TOPOLOGIES				0x00010335
#define AFE_CMD_ADD_TOPOLOGIES				0x000100f8
struct cmd_set_topologies {
	struct apr_hdr hdr;
	u32		payload_addr_lsw;
	
	u32		payload_addr_msw;
	
	u32		mem_map_handle;
	
	u32		payload_size;
	
} __packed;


#define AFE_MODULE_FB_SPKR_PROT_RX 0x0001021C
#define AFE_MODULE_FB_SPKR_PROT_V2_RX 0x0001025F

#define AFE_PARAM_ID_FBSP_MODE_RX_CFG 0x0001021D
#define AFE_PARAM_ID_FBSP_PTONE_RAMP_CFG 0x00010260

struct asm_fbsp_mode_rx_cfg {
	uint32_t minor_version;
	uint32_t mode;
} __packed;


#define AFE_MODULE_FB_SPKR_PROT_VI_PROC 0x00010226
#define AFE_MODULE_FB_SPKR_PROT_VI_PROC_V2 0x0001026A

#define AFE_PARAM_ID_SPKR_CALIB_VI_PROC_CFG 0x0001022A
#define AFE_PARAM_ID_SPKR_CALIB_VI_PROC_CFG_V2  0x0001026B

struct asm_spkr_calib_vi_proc_cfg {
	uint32_t minor_version;
	uint32_t operation_mode;
	uint32_t r0_t0_selection_flag[SP_V2_NUM_MAX_SPKR];
	int32_t r0_cali_q24[SP_V2_NUM_MAX_SPKR];
	int16_t	t0_cali_q6[SP_V2_NUM_MAX_SPKR];
	uint32_t quick_calib_flag;
} __packed;

#define AFE_PARAM_ID_CALIB_RES_CFG 0x0001022B
#define AFE_PARAM_ID_CALIB_RES_CFG_V2 0x0001026E

struct asm_calib_res_cfg {
	uint32_t minor_version;
	int32_t	r0_cali_q24[SP_V2_NUM_MAX_SPKR];
	uint32_t th_vi_ca_state;
} __packed;

#define AFE_PARAM_ID_FEEDBACK_PATH_CFG 0x0001022C
#define AFE_MODULE_FEEDBACK 0x00010257

struct asm_feedback_path_cfg {
	uint32_t minor_version;
	int32_t	dst_portid;
	int32_t	num_channels;
	int32_t	chan_info[4];
} __packed;

#define AFE_PARAM_ID_MODE_VI_PROC_CFG 0x00010227

struct asm_mode_vi_proc_cfg {
	uint32_t minor_version;
	uint32_t cal_mode;
} __packed;

#define AFE_MODULE_SPEAKER_PROTECTION_V2_TH_VI	0x0001026A
#define AFE_PARAM_ID_SP_V2_TH_VI_MODE_CFG	0x0001026B
#define AFE_PARAM_ID_SP_V2_TH_VI_FTM_CFG	0x0001029F
#define AFE_PARAM_ID_SP_V2_TH_VI_FTM_PARAMS	0x000102A0

struct afe_sp_th_vi_mode_cfg {
	uint32_t minor_version;
	uint32_t operation_mode;
	uint32_t r0t0_selection_flag[SP_V2_NUM_MAX_SPKR];
	int32_t r0_cali_q24[SP_V2_NUM_MAX_SPKR];
	int16_t t0_cali_q6[SP_V2_NUM_MAX_SPKR];
	uint32_t quick_calib_flag;
} __packed;

struct afe_sp_th_vi_ftm_cfg {
	uint32_t minor_version;
	uint32_t wait_time_ms[SP_V2_NUM_MAX_SPKR];
	uint32_t ftm_time_ms[SP_V2_NUM_MAX_SPKR];
} __packed;

struct afe_sp_th_vi_ftm_params {
	uint32_t minor_version;
	int32_t dc_res_q24[SP_V2_NUM_MAX_SPKR];
	int32_t temp_q22[SP_V2_NUM_MAX_SPKR];
	uint32_t status[SP_V2_NUM_MAX_SPKR];
} __packed;

struct afe_sp_th_vi_get_param {
	struct apr_hdr hdr;
	struct afe_port_cmd_get_param_v2 get_param;
	struct afe_port_param_data_v2 pdata;
	struct afe_sp_th_vi_ftm_params param;
} __packed;

struct afe_sp_th_vi_get_param_resp {
	uint32_t status;
	struct afe_port_param_data_v2 pdata;
	struct afe_sp_th_vi_ftm_params param;
} __packed;


#define AFE_MODULE_SPEAKER_PROTECTION_V2_EX_VI	0x0001026F
#define AFE_PARAM_ID_SP_V2_EX_VI_MODE_CFG	0x000102A1
#define AFE_PARAM_ID_SP_V2_EX_VI_FTM_CFG	0x000102A2
#define AFE_PARAM_ID_SP_V2_EX_VI_FTM_PARAMS	0x000102A3

struct afe_sp_ex_vi_mode_cfg {
	uint32_t minor_version;
	uint32_t operation_mode;
} __packed;

struct afe_sp_ex_vi_ftm_cfg {
	uint32_t minor_version;
	uint32_t wait_time_ms[SP_V2_NUM_MAX_SPKR];
	uint32_t ftm_time_ms[SP_V2_NUM_MAX_SPKR];
} __packed;

struct afe_sp_ex_vi_ftm_params {
	uint32_t minor_version;
	int32_t freq_q20[SP_V2_NUM_MAX_SPKR];
	int32_t resis_q24[SP_V2_NUM_MAX_SPKR];
	int32_t qmct_q24[SP_V2_NUM_MAX_SPKR];
	uint32_t status[SP_V2_NUM_MAX_SPKR];
} __packed;

struct afe_sp_ex_vi_get_param {
	struct apr_hdr hdr;
	struct afe_port_cmd_get_param_v2 get_param;
	struct afe_port_param_data_v2 pdata;
	struct afe_sp_ex_vi_ftm_params param;
} __packed;

struct afe_sp_ex_vi_get_param_resp {
	uint32_t status;
	struct afe_port_param_data_v2 pdata;
	struct afe_sp_ex_vi_ftm_params param;
} __packed;

union afe_spkr_prot_config {
	struct asm_fbsp_mode_rx_cfg mode_rx_cfg;
	struct asm_spkr_calib_vi_proc_cfg vi_proc_cfg;
	struct asm_feedback_path_cfg feedback_path_cfg;
	struct asm_mode_vi_proc_cfg mode_vi_proc_cfg;
	struct afe_sp_th_vi_mode_cfg th_vi_mode_cfg;
	struct afe_sp_th_vi_ftm_cfg th_vi_ftm_cfg;
	struct afe_sp_ex_vi_mode_cfg ex_vi_mode_cfg;
	struct afe_sp_ex_vi_ftm_cfg ex_vi_ftm_cfg;
} __packed;

struct afe_spkr_prot_config_command {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2 pdata;
	union afe_spkr_prot_config prot_config;
} __packed;

struct afe_spkr_prot_get_vi_calib {
	struct apr_hdr hdr;
	struct afe_port_cmd_get_param_v2 get_param;
	struct afe_port_param_data_v2 pdata;
	struct asm_calib_res_cfg res_cfg;
} __packed;

struct afe_spkr_prot_calib_get_resp {
	uint32_t status;
	struct afe_port_param_data_v2 pdata;
	struct asm_calib_res_cfg res_cfg;
} __packed;


#define SRS_TRUMEDIA_TOPOLOGY_ID			0x00010D90
#define HTC_SPK_SRS_COPP_TOPOLOGY_ID			0x10000006
#define HTC_HS_SRS_COPP_TOPOLOGY_ID			0x10000007
#define SRS_TRUMEDIA_MODULE_ID				0x10005010
#define SRS_TRUMEDIA_PARAMS				0x10005011
#define SRS_TRUMEDIA_PARAMS_WOWHD			0x10005012
#define SRS_TRUMEDIA_PARAMS_CSHP			0x10005013
#define SRS_TRUMEDIA_PARAMS_HPF				0x10005014
#define SRS_TRUMEDIA_PARAMS_AEQ				0x10005015
#define SRS_TRUMEDIA_PARAMS_HL				0x10005016
#define SRS_TRUMEDIA_PARAMS_GEQ				0x10005017

#define SRS_ID_GLOBAL	0x00000001
#define SRS_ID_WOWHD	0x00000002
#define SRS_ID_CSHP	0x00000003
#define SRS_ID_HPF	0x00000004
#define SRS_ID_AEQ	0x00000005
#define SRS_ID_HL		0x00000006
#define SRS_ID_GEQ	0x00000007

#define SRS_CMD_UPLOAD		0x7FFF0000
#define SRS_PARAM_OFFSET_MASK	0x3FFF0000
#define SRS_PARAM_VALUE_MASK	0x0000FFFF

struct srs_trumedia_params_GLOBAL {
	uint8_t                  v1;
	uint8_t                  v2;
	uint8_t                  v3;
	uint8_t                  v4;
	uint8_t                  v5;
	uint8_t                  v6;
	uint8_t                  v7;
	uint8_t                  v8;
	uint16_t                 v9;
} __packed;

struct srs_trumedia_params_WOWHD {
	uint32_t				v1;
	uint16_t				v2;
	uint16_t				v3;
	uint16_t				v4;
	uint16_t				v5;
	uint16_t				v6;
	uint16_t				v7;
	uint16_t				v8;
	uint16_t				v____A1;
	uint32_t				v9;
	uint16_t				v10;
	uint16_t				v11;
	uint32_t				v12[16];
	uint32_t	v13[16];
	uint32_t	v14[16];
	uint32_t	v15[16];
	uint32_t	v16;
	uint16_t	v17;
	uint16_t	v18;
} __packed;

struct srs_trumedia_params_CSHP {
	uint32_t		v1;
	uint16_t		v2;
	uint16_t		v3;
	uint16_t		v4;
	uint16_t		v5;
	uint16_t		v6;
	uint16_t		v____A1;
	uint32_t		v7;
	uint16_t		v8;
	uint16_t		v9;
	uint32_t		v10[16];
} __packed;

struct srs_trumedia_params_HPF {
	uint32_t		v1;
	uint32_t		v2[26];
} __packed;

struct srs_trumedia_params_AEQ {
	uint32_t		v1;
	uint16_t		v2;
	uint16_t		v3;
	uint16_t		v4;
	uint16_t		v____A1;
	uint32_t	v5[74];
	uint32_t	v6[74];
	uint16_t	v7[2048];
} __packed;

struct srs_trumedia_params_HL {
	uint16_t		v1;
	uint16_t		v2;
	uint16_t		v3;
	uint16_t		v____A1;
	int32_t			v4;
	uint32_t		v5;
	uint16_t		v6;
	uint16_t		v____A2;
	uint32_t		v7;
} __packed;

struct srs_trumedia_params_GEQ {
	int16_t		v1[10];
} __packed;
struct srs_trumedia_params {
	struct srs_trumedia_params_GLOBAL	global;
	struct srs_trumedia_params_WOWHD	wowhd;
	struct srs_trumedia_params_CSHP		cshp;
	struct srs_trumedia_params_HPF		hpf;
	struct srs_trumedia_params_AEQ		aeq;
	struct srs_trumedia_params_HL		hl;
	struct srs_trumedia_params_GEQ		geq;
} __packed;

#define AUDPROC_PARAM_ID_ENABLE		0x00010904
#define ASM_STREAM_POSTPROC_TOPO_ID_SA_PLUS 0x1000FFFF
#define AUDPROC_MODULE_ID_DTS_HPX_PREMIX 0x0001077C
#define AUDPROC_MODULE_ID_DTS_HPX_POSTMIX 0x0001077B
#define ASM_STREAM_POSTPROC_TOPO_ID_DTS_HPX 0x00010DED
#define ASM_STREAM_POSTPROC_TOPO_ID_HPX_PLUS  0x10015000
#define ASM_STREAM_POSTPROC_TOPO_ID_HPX_MASTER  0x10015001
struct asm_dts_eagle_param {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
} __packed;

struct asm_dts_eagle_param_get {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_get_pp_params_v2 param;
} __packed;

#define VW_FEAT_DIM					(39)

#define APRV2_IDS_SERVICE_ID_ADSP_LSM_V			(0xD)
#define APRV2_IDS_DOMAIN_ID_ADSP_V			(0x4)
#define APRV2_IDS_DOMAIN_ID_APPS_V			(0x5)

#define LSM_SESSION_CMD_SHARED_MEM_MAP_REGIONS		(0x00012A7F)
#define LSM_SESSION_CMDRSP_SHARED_MEM_MAP_REGIONS	(0x00012A80)
#define LSM_SESSION_CMD_SHARED_MEM_UNMAP_REGIONS	(0x00012A81)
#define LSM_SESSION_CMD_OPEN_TX				(0x00012A82)
#define LSM_SESSION_CMD_CLOSE_TX			(0x00012A88)
#define LSM_SESSION_CMD_SET_PARAMS			(0x00012A83)
#define LSM_SESSION_CMD_SET_PARAMS_V2			(0x00012A8F)
#define LSM_SESSION_CMD_REGISTER_SOUND_MODEL		(0x00012A84)
#define LSM_SESSION_CMD_DEREGISTER_SOUND_MODEL		(0x00012A85)
#define LSM_SESSION_CMD_START				(0x00012A86)
#define LSM_SESSION_CMD_STOP				(0x00012A87)
#define LSM_SESSION_CMD_EOB				(0x00012A89)
#define LSM_SESSION_CMD_READ				(0x00012A8A)
#define LSM_SESSION_CMD_OPEN_TX_V2			(0x00012A8B)
#define LSM_CMD_ADD_TOPOLOGIES				(0x00012A8C)

#define LSM_SESSION_EVENT_DETECTION_STATUS		(0x00012B00)
#define LSM_SESSION_EVENT_DETECTION_STATUS_V2		(0x00012B01)
#define LSM_DATA_EVENT_READ_DONE			(0x00012B02)
#define LSM_DATA_EVENT_STATUS				(0x00012B03)

#define LSM_MODULE_ID_VOICE_WAKEUP			(0x00012C00)
#define LSM_PARAM_ID_ENDPOINT_DETECT_THRESHOLD		(0x00012C01)
#define LSM_PARAM_ID_OPERATION_MODE			(0x00012C02)
#define LSM_PARAM_ID_GAIN				(0x00012C03)
#define LSM_PARAM_ID_CONNECT_TO_PORT			(0x00012C04)
#define LSM_PARAM_ID_FEATURE_COMPENSATION_DATA		(0x00012C07)
#define LSM_PARAM_ID_MIN_CONFIDENCE_LEVELS		(0x00012C07)
#define LSM_MODULE_ID_LAB				(0x00012C08)
#define LSM_PARAM_ID_LAB_ENABLE				(0x00012C09)
#define LSM_PARAM_ID_LAB_CONFIG				(0x00012C0A)
#define LSM_MODULE_ID_FRAMEWORK				(0x00012C0E)

#define AFE_MODULE_HW_MAD				(0x00010230)
#define AFE_PARAM_ID_HW_MAD_CFG				(0x00010231)
#define AFE_PARAM_ID_HW_MAD_CTRL			(0x00010232)
#define AFE_PARAM_ID_SLIMBUS_SLAVE_PORT_CFG		(0x00010233)

#define AFE_MODULE_SW_MAD				(0x0001022D)
#define AFE_PARAM_ID_SW_MAD_CFG				(0x0001022E)
#define AFE_PARAM_ID_SVM_MODEL				(0x0001022F)

#define AFE_SVC_CMD_SET_PARAM				(0x000100f3)
#define AFE_MODULE_CDC_DEV_CFG				(0x00010234)
#define AFE_PARAM_ID_CDC_SLIMBUS_SLAVE_CFG		(0x00010235)
#define AFE_PARAM_ID_CDC_REG_CFG			(0x00010236)
#define AFE_PARAM_ID_CDC_REG_CFG_INIT			(0x00010237)
#define AFE_PARAM_ID_CDC_REG_PAGE_CFG                   (0x00010296)

#define AFE_MAX_CDC_REGISTERS_TO_CONFIG			(20)

#define AFE_PARAM_ID_AANC_PORT_CONFIG			(0x00010215)
#define AFE_API_VERSION_AANC_PORT_CONFIG		(0x1)
#define AANC_TX_MIC_UNUSED				(0)
#define AANC_TX_VOICE_MIC				(1)
#define AANC_TX_ERROR_MIC				(2)
#define AANC_TX_NOISE_MIC				(3)
#define AFE_PORT_MAX_CHANNEL_CNT			(8)
#define AFE_MODULE_AANC					(0x00010214)
#define AFE_PARAM_ID_CDC_AANC_VERSION			(0x0001023A)
#define AFE_API_VERSION_CDC_AANC_VERSION		(0x1)
#define AANC_HW_BLOCK_VERSION_1				(1)
#define AANC_HW_BLOCK_VERSION_2				(2)

#define AFE_API_VERSION_CLIP_BANK_SEL_CFG 0x1
#define AFE_CLIP_MAX_BANKS		4
#define AFE_PARAM_ID_CLIP_BANK_SEL_CFG 0x00010242

struct afe_param_aanc_port_cfg {
	uint32_t aanc_port_cfg_minor_version;

	
	uint32_t tx_port_sample_rate;

	uint8_t tx_port_channel_map[AFE_PORT_MAX_CHANNEL_CNT];

	
	uint16_t tx_port_num_channels;

	
	uint16_t rx_path_ref_port_id;

	
	uint32_t ref_port_sample_rate;
} __packed;

struct afe_param_id_cdc_aanc_version {
	uint32_t cdc_aanc_minor_version;

	
	uint32_t aanc_hw_version;
} __packed;

struct afe_param_id_clip_bank_sel {
	uint32_t minor_version;

	
	uint32_t num_banks;

	uint32_t bank_map[AFE_CLIP_MAX_BANKS];
} __packed;

#define ADSP_EOK          0x00000000
#define ADSP_EFAILED      0x00000001
#define ADSP_EBADPARAM    0x00000002
#define ADSP_EUNSUPPORTED 0x00000003
#define ADSP_EVERSION     0x00000004
#define ADSP_EUNEXPECTED  0x00000005
#define ADSP_EPANIC       0x00000006
#define ADSP_ENORESOURCE  0x00000007
#define ADSP_EHANDLE      0x00000008
#define ADSP_EALREADY     0x00000009
#define ADSP_ENOTREADY    0x0000000A
#define ADSP_EPENDING     0x0000000B
#define ADSP_EBUSY        0x0000000C
#define ADSP_EABORTED     0x0000000D
#define ADSP_EPREEMPTED   0x0000000E
#define ADSP_ECONTINUE    0x0000000F
#define ADSP_EIMMEDIATE   0x00000010
#define ADSP_ENOTIMPL     0x00000011
#define ADSP_ENEEDMORE    0x00000012
#define ADSP_ENOMEMORY    0x00000014
#define ADSP_ENOTEXIST    0x00000015
#define ADSP_ERR_MAX      (ADSP_ENOTEXIST + 1)
#define ADSP_ETERMINATED    0x00011174



#define Q6AFE_LPASS_OSR_CLK_12_P288_MHZ		0xBB8000
#define Q6AFE_LPASS_OSR_CLK_9_P600_MHZ		0x927C00
#define Q6AFE_LPASS_OSR_CLK_8_P192_MHZ		0x7D0000
#define Q6AFE_LPASS_OSR_CLK_6_P144_MHZ		0x5DC000
#define Q6AFE_LPASS_OSR_CLK_4_P096_MHZ		0x3E8000
#define Q6AFE_LPASS_OSR_CLK_3_P072_MHZ		0x2EE000
#define Q6AFE_LPASS_OSR_CLK_2_P048_MHZ		0x1F4000
#define Q6AFE_LPASS_OSR_CLK_1_P536_MHZ		0x177000
#define Q6AFE_LPASS_OSR_CLK_1_P024_MHZ		 0xFA000
#define Q6AFE_LPASS_OSR_CLK_768_kHZ		 0xBB800
#define Q6AFE_LPASS_OSR_CLK_512_kHZ		 0x7D000
#define Q6AFE_LPASS_OSR_CLK_DISABLE		     0x0

#define Q6AFE_LPASS_IBIT_CLK_12_P288_MHZ	0xBB8000
#define Q6AFE_LPASS_IBIT_CLK_11_P2896_MHZ	0xAC4400
#define Q6AFE_LPASS_IBIT_CLK_8_P192_MHZ		0x7D0000
#define Q6AFE_LPASS_IBIT_CLK_6_P144_MHZ		0x5DC000
#define Q6AFE_LPASS_IBIT_CLK_4_P096_MHZ		0x3E8000
#define Q6AFE_LPASS_IBIT_CLK_3_P072_MHZ		0x2EE000
#define Q6AFE_LPASS_IBIT_CLK_2_P8224_MHZ		0x2b1100
#define Q6AFE_LPASS_IBIT_CLK_2_P048_MHZ		0x1F4000
#define Q6AFE_LPASS_IBIT_CLK_1_P536_MHZ		0x177000
#define Q6AFE_LPASS_IBIT_CLK_1_P4112_MHZ		0x158880
#define Q6AFE_LPASS_IBIT_CLK_1_P024_MHZ		 0xFA000
#define Q6AFE_LPASS_IBIT_CLK_768_KHZ		 0xBB800
#define Q6AFE_LPASS_IBIT_CLK_512_KHZ		 0x7D000
#define Q6AFE_LPASS_IBIT_CLK_256_KHZ		 0x3E800
#define Q6AFE_LPASS_IBIT_CLK_DISABLE		     0x0

#define Q6AFE_LPASS_CLK_SRC_EXTERNAL 0
#define Q6AFE_LPASS_CLK_SRC_INTERNAL 1

#define Q6AFE_LPASS_CLK_ROOT_DEFAULT 0

enum afe_lpass_clk_mode {
	Q6AFE_LPASS_MODE_BOTH_INVALID,
	Q6AFE_LPASS_MODE_CLK1_VALID,
	Q6AFE_LPASS_MODE_CLK2_VALID,
	Q6AFE_LPASS_MODE_BOTH_VALID,
} __packed;

#define Q6AFE_LPASS_CLK_ID_PRI_MI2S_IBIT                          0x100
#define Q6AFE_LPASS_CLK_ID_PRI_MI2S_EBIT                          0x101
#define Q6AFE_LPASS_CLK_ID_SEC_MI2S_IBIT                          0x102
#define Q6AFE_LPASS_CLK_ID_SEC_MI2S_EBIT                          0x103
#define Q6AFE_LPASS_CLK_ID_TER_MI2S_IBIT                          0x104
#define Q6AFE_LPASS_CLK_ID_TER_MI2S_EBIT                          0x105
#define Q6AFE_LPASS_CLK_ID_QUAD_MI2S_IBIT                         0x106
#define Q6AFE_LPASS_CLK_ID_QUAD_MI2S_EBIT                         0x107
#define Q6AFE_LPASS_CLK_ID_SPEAKER_I2S_IBIT                       0x108
#define Q6AFE_LPASS_CLK_ID_SPEAKER_I2S_EBIT                       0x109
#define Q6AFE_LPASS_CLK_ID_SPEAKER_I2S_OSR                        0x10A

#define Q6AFE_LPASS_CLK_ID_QUI_MI2S_IBIT			0x10B
#define Q6AFE_LPASS_CLK_ID_QUI_MI2S_EBIT			0x10C
#define Q6AFE_LPASS_CLK_ID_SEN_MI2S_IBIT			0x10D
#define Q6AFE_LPASS_CLK_ID_SEN_MI2S_EBIT			0x10E

#define Q6AFE_LPASS_CLK_ID_PRI_PCM_IBIT                           0x200
#define Q6AFE_LPASS_CLK_ID_PRI_PCM_EBIT                           0x201
#define Q6AFE_LPASS_CLK_ID_SEC_PCM_IBIT                           0x202
#define Q6AFE_LPASS_CLK_ID_SEC_PCM_EBIT                           0x203
#define Q6AFE_LPASS_CLK_ID_TER_PCM_IBIT                           0x204
#define Q6AFE_LPASS_CLK_ID_TER_PCM_EBIT                           0x205
#define Q6AFE_LPASS_CLK_ID_QUAD_PCM_IBIT                          0x206
#define Q6AFE_LPASS_CLK_ID_QUAD_PCM_EBIT                          0x207

#define Q6AFE_LPASS_CLK_ID_PRI_TDM_IBIT                           0x200
#define Q6AFE_LPASS_CLK_ID_PRI_TDM_EBIT                           0x201
#define Q6AFE_LPASS_CLK_ID_SEC_TDM_IBIT                           0x202
#define Q6AFE_LPASS_CLK_ID_SEC_TDM_EBIT                           0x203
#define Q6AFE_LPASS_CLK_ID_TER_TDM_IBIT                           0x204
#define Q6AFE_LPASS_CLK_ID_TER_TDM_EBIT                           0x205
#define Q6AFE_LPASS_CLK_ID_QUAD_TDM_IBIT                          0x206
#define Q6AFE_LPASS_CLK_ID_QUAD_TDM_EBIT                          0x207

#define Q6AFE_LPASS_CLK_ID_MCLK_1                                 0x300
#define Q6AFE_LPASS_CLK_ID_MCLK_2                                 0x301
#define Q6AFE_LPASS_CLK_ID_MCLK_3                                 0x302
#define Q6AFE_LPASS_CLK_ID_INTERNAL_DIGITAL_CODEC_CORE            0x303

#define Q6AFE_LPASS_CLK_ID_AHB_HDMI_INPUT                         0x400

#define Q6AFE_LPASS_CLK_ID_SPDIF_CORE                             0x500


#define Q6AFE_LPASS_CLK_ATTRIBUTE_INVALID		0x0
#define Q6AFE_LPASS_CLK_ATTRIBUTE_COUPLE_NO		0x1
#define Q6AFE_LPASS_CLK_ATTRIBUTE_COUPLE_DIVIDEND	0x2
#define Q6AFE_LPASS_CLK_ATTRIBUTE_COUPLE_DIVISOR	0x3
#define Q6AFE_LPASS_CLK_ATTRIBUTE_INVERT_COUPLE_NO	0x4
#define Q6AFE_LPASS_CLK_CONFIG_API_VERSION		0x1

struct afe_clk_set {
	uint32_t clk_set_minor_version;

	uint32_t clk_id;

	uint32_t clk_freq_in_hz;

	uint16_t clk_attri;

	uint16_t clk_root;

	uint32_t enable;
};

struct afe_clk_cfg {
	u32                  i2s_cfg_minor_version;

	u32                  clk_val1;

	u32                  clk_val2;


	u16                  clk_src;

	u16                  clk_root;

	u16                  clk_set_mode;

	u16                  reserved;
} __packed;

#define AFE_PARAM_ID_LPAIF_CLK_CONFIG	0x00010238
#define AFE_MODULE_CLOCK_SET		0x0001028F
#define AFE_PARAM_ID_CLOCK_SET		0x00010290

struct afe_lpass_clk_config_command {
	struct apr_hdr			 hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	struct afe_clk_cfg clk_cfg;
} __packed;

enum afe_lpass_digital_clk_src {
	Q6AFE_LPASS_DIGITAL_ROOT_INVALID,
	Q6AFE_LPASS_DIGITAL_ROOT_PRI_MI2S_OSR,
	Q6AFE_LPASS_DIGITAL_ROOT_SEC_MI2S_OSR,
	Q6AFE_LPASS_DIGITAL_ROOT_TER_MI2S_OSR,
	Q6AFE_LPASS_DIGITAL_ROOT_QUAD_MI2S_OSR,
	Q6AFE_LPASS_DIGITAL_ROOT_CDC_ROOT_CLK,
} __packed;

#define AFE_PARAM_ID_INTERNAL_DIGIATL_CDC_CLK_CONFIG	0x00010239

struct afe_digital_clk_cfg {
	u32                  i2s_cfg_minor_version;

	u32                  clk_val;

	u16                  clk_root;

	u16                  reserved;
} __packed;


struct afe_lpass_digital_clk_config_command {
	struct apr_hdr			 hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2    pdata;
	struct afe_digital_clk_cfg clk_cfg;
} __packed;

#define AFE_PORTS_CMD_DTMF_CTL	0x00010102

struct afe_dtmf_generation_command {
	struct apr_hdr hdr;

	int64_t                   duration_in_ms;

	uint16_t                  high_freq;

	uint16_t                  low_freq;

	uint16_t                  gain;

	uint16_t                  num_ports;

	uint16_t                  port_ids;

	uint16_t                  reserved;
} __packed;

enum afe_config_type {
	AFE_SLIMBUS_SLAVE_PORT_CONFIG,
	AFE_SLIMBUS_SLAVE_CONFIG,
	AFE_CDC_REGISTERS_CONFIG,
	AFE_AANC_VERSION,
	AFE_CDC_CLIP_REGISTERS_CONFIG,
	AFE_CLIP_BANK_SEL,
	AFE_CDC_REGISTER_PAGE_CONFIG,
	AFE_MAX_CONFIG_TYPES,
};

struct afe_param_slimbus_slave_port_cfg {
	uint32_t minor_version;
	uint16_t slimbus_dev_id;
	uint16_t slave_dev_pgd_la;
	uint16_t slave_dev_intfdev_la;
	uint16_t bit_width;
	uint16_t data_format;
	uint16_t num_channels;
	uint16_t slave_port_mapping[AFE_PORT_MAX_AUDIO_CHAN_CNT];
} __packed;

struct afe_param_cdc_slimbus_slave_cfg {
	uint32_t minor_version;
	uint32_t device_enum_addr_lsw;
	uint32_t device_enum_addr_msw;
	uint16_t tx_slave_port_offset;
	uint16_t rx_slave_port_offset;
} __packed;

struct afe_param_cdc_reg_cfg {
	uint32_t minor_version;
	uint32_t reg_logical_addr;
	uint32_t reg_field_type;
	uint32_t reg_field_bit_mask;
	uint16_t reg_bit_width;
	uint16_t reg_offset_scale;
} __packed;

#define AFE_API_VERSION_CDC_REG_PAGE_CFG   1

enum {
	AFE_CDC_REG_PAGE_ASSIGN_PROC_ID_0 = 0,
	AFE_CDC_REG_PAGE_ASSIGN_PROC_ID_1,
	AFE_CDC_REG_PAGE_ASSIGN_PROC_ID_2,
	AFE_CDC_REG_PAGE_ASSIGN_PROC_ID_3,
};

struct afe_param_cdc_reg_page_cfg {
	uint32_t minor_version;
	uint32_t enable;
	uint32_t proc_id;
} __packed;

struct afe_param_cdc_reg_cfg_data {
	uint32_t num_registers;
	struct afe_param_cdc_reg_cfg *reg_data;
} __packed;

struct afe_svc_cmd_set_param {
	uint32_t payload_size;
	uint32_t payload_address_lsw;
	uint32_t payload_address_msw;
	uint32_t mem_map_handle;
} __packed;

struct afe_svc_param_data {
	uint32_t module_id;
	uint32_t param_id;
	uint16_t param_size;
	uint16_t reserved;
} __packed;

struct afe_param_hw_mad_ctrl {
	uint32_t minor_version;
	uint16_t mad_type;
	uint16_t mad_enable;
} __packed;

struct afe_cmd_hw_mad_ctrl {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_hw_mad_ctrl payload;
} __packed;

struct afe_cmd_hw_mad_slimbus_slave_port_cfg {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_slimbus_slave_port_cfg sb_port_cfg;
} __packed;

struct afe_cmd_sw_mad_enable {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2 pdata;
} __packed;

struct afe_param_cdc_reg_cfg_payload {
	struct afe_svc_param_data     common;
	struct afe_param_cdc_reg_cfg  reg_cfg;
} __packed;

struct afe_lpass_clk_config_command_v2 {
	struct apr_hdr			hdr;
	struct afe_svc_cmd_set_param	param;
	struct afe_svc_param_data	pdata;
	struct afe_clk_set		clk_cfg;
} __packed;

struct afe_svc_cmd_cdc_reg_cfg {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_param_cdc_reg_cfg_payload reg_data[0];
} __packed;

struct afe_svc_cmd_init_cdc_reg_cfg {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 init;
} __packed;

struct afe_svc_cmd_sb_slave_cfg {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_cdc_slimbus_slave_cfg sb_slave_cfg;
} __packed;

struct afe_svc_cmd_cdc_reg_page_cfg {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_cdc_reg_page_cfg cdc_reg_page_cfg;
} __packed;

struct afe_svc_cmd_cdc_aanc_version {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_id_cdc_aanc_version version;
} __packed;

struct afe_port_cmd_set_aanc_param {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
	struct afe_port_param_data_v2 pdata;
	union {
		struct afe_param_aanc_port_cfg aanc_port_cfg;
		struct afe_mod_enable_param    mod_enable;
	} __packed data;
} __packed;

struct afe_port_cmd_set_aanc_acdb_table {
	struct apr_hdr hdr;
	struct afe_port_cmd_set_param_v2 param;
} __packed;

#define DOLBY_ADM_COPP_TOPOLOGY_ID	0x0001033B
#define DS2_ADM_COPP_TOPOLOGY_ID	0x1301033B

#define RMS_MODULEID_APPI_PASSTHRU  0x10009011
#define RMS_PARAM_FIRST_SAMPLE 0x10009012
#define RMS_PAYLOAD_LEN 4

#define MTMX_MODULE_ID_DEFAULT_CHMIXER  0x00010341
#define DEFAULT_CHMIXER_PARAM_ID_COEFF  0x00010342
#define CUSTOM_STEREO_PAYLOAD_SIZE	9
#define CUSTOM_STEREO_CMD_PARAM_SIZE	24
#define CUSTOM_STEREO_NUM_OUT_CH	0x0002
#define CUSTOM_STEREO_NUM_IN_CH		0x0002
#define CUSTOM_STEREO_INDEX_PARAM	0x0002
#define Q14_GAIN_ZERO_POINT_FIVE	0x2000
#define Q14_GAIN_UNITY			0x4000

struct afe_svc_cmd_set_clip_bank_selection {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 pdata;
	struct afe_param_id_clip_bank_sel bank_sel;
} __packed;

#define US_POINT_EPOS_FORMAT_V2 0x0001272D
#define US_RAW_FORMAT_V2        0x0001272C
#define US_PROX_FORMAT_V4       0x0001273B
#define US_RAW_SYNC_FORMAT      0x0001272F
#define US_GES_SYNC_FORMAT      0x00012730

#define AFE_MODULE_GROUP_DEVICE	0x00010254
#define AFE_PARAM_ID_GROUP_DEVICE_CFG	0x00010255
#define AFE_PARAM_ID_GROUP_DEVICE_ENABLE 0x00010256
#define AFE_GROUP_DEVICE_ID_SECONDARY_MI2S_RX	0x1102

#define AFE_MODULE_ADAPTIVE_AUDIO_M1     0x10000030
#define AFE_MODULE_ADAPTIVE_AUDIO_M2     0x1000002A
#define AFE_MODULE_ONEDOTONE_AUDIO       0x10000135
#define AFE_MODULE_LIMITERCOPP           0x1000012A
#define AFE_MODULE_ID_MISC_EFFECT        0x10030001


#define AFE_PARAM_ID_ADAPTIVE_AUDIO_M1_EN     0x10000032
#define AFE_PARAM_ID_ADAPTIVE_AUDIO_M1_CONF_L 0x10000033
#define AFE_PARAM_ID_ADAPTIVE_AUDIO_M1_CONF_R 0x10000034
#define AFE_PARAM_ID_ADAPTIVE_AUDIO_M2_EN     0x1000002C
#define AFE_PARAM_ID_ADAPTIVE_AUDIO_M2_CONF   0x1000002D
#define AFE_PARAM_ID_ONEDOTONE_AUDIO_EN       0x10000137
#define AFE_PARAM_ID_LIMITERCOPP_AUDIO_ENABLE 0x1000012C
#define AFE_PARAM_ID_MISC_SET_ACOUSTIC_SHOCK_RAMP 0x10030101
#define AFE_PARAM_ID_MISC_SET_ACOUSTIC_SHOCK_MUTE 0x10030111


#define AFE_COPP_ID_ONEDOTONE_AUDIO           0x10000009
#define AFE_COPP_ID_ADAPTIVE_AUDIO            0x10000004
#ifdef CONFIG_USE_AS_HS
#define AFE_COPP_ID_ADAPTIVE_AUDIO_20            0x10000007
#endif

#define HTC_POPP_TOPOLOGY				0x10000002
#define HTC_POPP_HD_TOPOLOGY				0x10000003
struct asm_params {
	struct apr_hdr	hdr;
	struct asm_stream_cmd_set_pp_params_v2 param;
	struct asm_stream_param_data_v2 data;
} __packed;

struct afe_group_device_group_cfg {
	u32 minor_version;
	u16 group_id;
	u16 num_channels;
	u16 port_id[8];
} __packed;

#define AFE_GROUP_DEVICE_ID_PRIMARY_TDM_RX \
	(AFE_PORT_ID_PRIMARY_TDM_RX + 0x100)
#define AFE_GROUP_DEVICE_ID_PRIMARY_TDM_TX \
	(AFE_PORT_ID_PRIMARY_TDM_TX + 0x100)
#define AFE_GROUP_DEVICE_ID_SECONDARY_TDM_RX \
	(AFE_PORT_ID_SECONDARY_TDM_RX + 0x100)
#define AFE_GROUP_DEVICE_ID_SECONDARY_TDM_TX \
	(AFE_PORT_ID_SECONDARY_TDM_TX + 0x100)
#define AFE_GROUP_DEVICE_ID_TERTIARY_TDM_RX \
	(AFE_PORT_ID_TERTIARY_TDM_RX + 0x100)
#define AFE_GROUP_DEVICE_ID_TERTIARY_TDM_TX \
	(AFE_PORT_ID_TERTIARY_TDM_TX + 0x100)
#define AFE_GROUP_DEVICE_ID_QUATERNARY_TDM_RX \
	(AFE_PORT_ID_QUATERNARY_TDM_RX + 0x100)
#define AFE_GROUP_DEVICE_ID_QUATERNARY_TDM_TX \
	(AFE_PORT_ID_QUATERNARY_TDM_TX + 0x100)

#define AFE_PARAM_ID_GROUP_DEVICE_TDM_CONFIG	0x0001029E

#define AFE_API_VERSION_GROUP_DEVICE_TDM_CONFIG	0x1

#define AFE_GROUP_DEVICE_NUM_PORTS					8

struct afe_param_id_group_device_tdm_cfg {
	u32	group_device_cfg_minor_version;

	u16	group_id;

	u16	reserved;
	

	u16	port_id[AFE_GROUP_DEVICE_NUM_PORTS];

	u32	num_channels;

	u32	sample_rate;

	u32	bit_width;

	u16	nslots_per_frame;

	u16	slot_width;

	u32	slot_mask;
} __packed;


struct afe_group_device_enable {
	u16 group_id;
	
	u16 enable;
	
} __packed;

union afe_port_group_config {
	struct afe_group_device_group_cfg group_cfg;
	struct afe_group_device_enable group_enable;
	struct afe_param_id_group_device_tdm_cfg tdm_cfg;
} __packed;

struct afe_port_group_create {
	struct apr_hdr hdr;
	struct afe_svc_cmd_set_param param;
	struct afe_port_param_data_v2 pdata;
	union afe_port_group_config data;
} __packed;

#define ASM_SESSION_CMD_SET_MTMX_STRTR_PARAMS_V2    0x00010DCE
#define ASM_SESSION_MTMX_STRTR_MODULE_ID_AVSYNC    0x00010DC6

#define ASM_SESSION_MTMX_STRTR_PARAM_RENDER_WINDOW_START_V2 0x00010DD1

#define ASM_SESSION_MTMX_STRTR_PARAM_RENDER_WINDOW_END_V2   0x00010DD2

struct asm_session_mtmx_strtr_param_window_v2_t {
	u32    window_lsw;
	

	u32    window_msw;
};

struct asm_session_cmd_set_mtmx_strstr_params_v2 {
	uint32_t                  data_payload_addr_lsw;
	

	uint32_t                  data_payload_addr_msw;

	uint32_t                  mem_map_handle;

	uint32_t                  data_payload_size;

	uint32_t                  direction;
};

struct asm_mtmx_strtr_params {
	struct apr_hdr  hdr;
	struct asm_session_cmd_set_mtmx_strstr_params_v2 param;
	struct asm_stream_param_data_v2 data;
	u32 window_lsw;
	u32 window_msw;
} __packed;

#define ASM_SESSION_CMD_GET_MTMX_STRTR_PARAMS_V2 0x00010DCF
#define ASM_SESSION_CMDRSP_GET_MTMX_STRTR_PARAMS_V2 0x00010DD0

#define ASM_SESSION_MTMX_STRTR_PARAM_SESSION_TIME_V3 0x00012F0B
#define ASM_SESSION_MTMX_STRTR_PARAM_STIME_TSTMP_FLG_BMASK (0x80000000UL)

struct asm_session_cmd_get_mtmx_strstr_params_v2 {
	uint32_t                  data_payload_addr_lsw;
	

	uint32_t                  data_payload_addr_msw;

	uint32_t                  mem_map_handle;
	uint32_t                  direction;
	uint32_t                  module_id;
	

	uint32_t                  param_id;
	

	uint32_t                  param_max_size;
};

struct asm_session_mtmx_strtr_param_session_time_v3_t {
	uint32_t                  session_time_lsw;
	

	uint32_t                  session_time_msw;

	uint32_t                  absolute_time_lsw;

	uint32_t                  absolute_time_msw;

	uint32_t                  time_stamp_lsw;
	

	uint32_t                  time_stamp_msw;

	uint32_t                  flags;
};

union asm_session_mtmx_strtr_data_type {
	struct asm_session_mtmx_strtr_param_session_time_v3_t session_time;
};

struct asm_mtmx_strtr_get_params {
	struct apr_hdr hdr;
	struct asm_session_cmd_get_mtmx_strstr_params_v2 param_info;
} __packed;

struct asm_mtmx_strtr_get_params_cmdrsp {
	uint32_t err_code;
	struct asm_stream_param_data_v2 param_info;
	union asm_session_mtmx_strtr_data_type param_data;
} __packed;

#define AUDPROC_MODULE_ID_RESAMPLER 0x00010719

enum {
	LEGACY_PCM = 0,
	COMPRESSED_PASSTHROUGH,
	COMPRESSED_PASSTHROUGH_CONVERT,
};

#define AUDPROC_MODULE_ID_COMPRESSED_MUTE                0x00010770
#define AUDPROC_PARAM_ID_COMPRESSED_MUTE                 0x00010771

struct adm_set_compressed_device_mute {
	struct adm_cmd_set_pp_params_v5 command;
	struct adm_param_data_v5 params;
	u32    mute_on;
} __packed;

#define AUDPROC_MODULE_ID_COMPRESSED_LATENCY             0x0001076E
#define AUDPROC_PARAM_ID_COMPRESSED_LATENCY              0x0001076F

struct adm_set_compressed_device_latency {
	struct adm_cmd_set_pp_params_v5 command;
	struct adm_param_data_v5 params;
	u32    latency;
} __packed;

#define VOICEPROC_MODULE_ID_GENERIC_TX                      0x00010EF6
#define VOICEPROC_PARAM_ID_FLUENCE_SOUNDFOCUS               0x00010E37
#define VOICEPROC_PARAM_ID_FLUENCE_SOURCETRACKING           0x00010E38
#define MAX_SECTORS                                         8
#define MAX_NOISE_SOURCE_INDICATORS                         3
#define MAX_POLAR_ACTIVITY_INDICATORS                       360

struct sound_focus_param {
	uint16_t start_angle[MAX_SECTORS];
	uint8_t enable[MAX_SECTORS];
	uint16_t gain_step;
} __packed;

struct source_tracking_param {
	uint8_t vad[MAX_SECTORS];
	uint16_t doa_speech;
	uint16_t doa_noise[MAX_NOISE_SOURCE_INDICATORS];
	uint8_t polar_activity[MAX_POLAR_ACTIVITY_INDICATORS];
} __packed;

struct adm_param_fluence_soundfocus_t {
	uint16_t start_angles[MAX_SECTORS];
	uint8_t enables[MAX_SECTORS];
	uint16_t gain_step;
	uint16_t reserved;
} __packed;

struct adm_set_fluence_soundfocus_param {
	struct adm_cmd_set_pp_params_v5 params;
	struct adm_param_data_v5 data;
	struct adm_param_fluence_soundfocus_t soundfocus_data;
} __packed;

struct adm_param_fluence_sourcetracking_t {
	uint8_t vad[MAX_SECTORS];
	uint16_t doa_speech;
	uint16_t doa_noise[MAX_NOISE_SOURCE_INDICATORS];
	uint8_t polar_activity[MAX_POLAR_ACTIVITY_INDICATORS];
} __packed;

#define AUDPROC_MODULE_ID_AUDIOSPHERE               0x00010916
#define AUDPROC_PARAM_ID_AUDIOSPHERE_ENABLE         0x00010917
#define AUDPROC_PARAM_ID_AUDIOSPHERE_STRENGTH       0x00010918
#define AUDPROC_PARAM_ID_AUDIOSPHERE_CONFIG_MODE    0x00010919

#define AUDPROC_PARAM_ID_AUDIOSPHERE_COEFFS_STEREO_INPUT         0x0001091A
#define AUDPROC_PARAM_ID_AUDIOSPHERE_COEFFS_MULTICHANNEL_INPUT   0x0001091B
#define AUDPROC_PARAM_ID_AUDIOSPHERE_DESIGN_STEREO_INPUT         0x0001091C
#define AUDPROC_PARAM_ID_AUDIOSPHERE_DESIGN_MULTICHANNEL_INPUT   0x0001091D

#define AUDPROC_PARAM_ID_AUDIOSPHERE_OPERATING_INPUT_MEDIA_INFO  0x0001091E
#endif 
