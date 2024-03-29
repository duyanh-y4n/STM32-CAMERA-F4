/**
 * File              : var_interface.h
 * Author            : Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 * Date              : 08.10.2019
 * Last Modified Date: 08.10.2019
 * Last Modified By  : Duy Anh Pham <duyanh.y4n.pham@gmail.com>
 */
#ifndef INC_VAR_INTERFACE_H_
#define INC_VAR_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm_hal_userconfig.h"

/* Image mem size in bytes */
#define CAMERA_R160x120_COLOR_MEMSIZE 0x9600
#define CAMERA_R320x240_COLOR_MEMSIZE 0x25800
#define CAMERA_R480x272_COLOR_MEMSIZE 0x3FC00
#define CAMERA_R640x480_COLOR_MEMSIZE 0x96000
#define CAMERA_R160x120_MONOC_MEMSIZE 0x4B00
#define CAMERA_R320x240_MONOC_MEMSIZE 0x12C00
#define CAMERA_R480x272_MONOC_MEMSIZE 0x1FE00
#define CAMERA_R640x480_MONOC_MEMSIZE 0x4B000

extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_dcmi;
extern DCMI_HandleTypeDef hdcmi;
extern UART_HandleTypeDef huart4;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel1;
extern TIM_HandleTypeDef htim2;

extern uint8_t image_data[];
static uint32_t lineNum;

/* CAMERA GLOBAL SETTING */
/* -------Troublesshooting---------:
 * no output image? -> increase CAMERA_INIT_DELAY_MULTIPLICATOR or CAMERA_DELAY_INTERVAL
 * bad image -> increase CAMERA_DELAY_INTERVAL
 * */
#define CAMERA_DELAY_INTERVAL 200 // in us -  NO OUTPUT or BAD IMAGE if this is too low
#define CAMERA_INIT_DELAY_MULTIPLICATOR 200 // increase this value if NO OUTPUT picture received
#define CAMERA_LIGHTROOM_CALIBRATION_DELAY 891500 // in us


#define IMAGE_MEM_SIZE CAMERA_R160x120_COLOR_MEMSIZE
#define IMAGE_RESOLUTION CAMERA_R160x120
#define IMAGE_BANDFILTER_ENABLE 1
#define IMAGE_DEFAULT_FORMAT IMAGE_OUTPUT_FORMAT_YUV422
#define CAMERA_DEFAULT_COLORMODE CAMERA_BLACK_WHITE_NORMAL


// TODO: remove these adresss after Found way to reserved Memory in SRAM
#define CAMERA_BUFFER_EXTERN (uint8_t *)0x68000800 // data address for external sram
#define CAMERA_BUFFER_INTERN (uint8_t*) 0x20008000  // data address for internal sram

/*RTT debug activation*/

// comment this line to disable debug

#define CAMERA_DEBUG_RTT


#define CAMERA_COMMON_DEBUG_RTT_DISABLE 0
#define CAMERA_I2C_DEBUG_RTT_DISABLE 0
#define CAMERA_EVENT_DEBUG_RTT_DISABLE 0
#define CAMERA_TIME_MEASURE_DEBUG_RTT_DISABLE 0



#define DMA_MAX_TRANFER_DATA 0xFFFF
#define NUM_IMG 3

extern uint32_t measured_time;

#ifdef __cplusplus
}
#endif

#endif /* INC_VAR_INTERFACE_H_ */
