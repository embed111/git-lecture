/**
  *### Copyright (c) 2018, EDD-STC Development Team (eddstc1984@gmail.com). ######
  *### SPDX-License-Identifier: Apache-2.0 ######
  ********************************************************************************************
  * @file app.c
  * @version 0.1.0 
  * @brief none
  * @details none
  * @warning none
  * @bug none  
  ********************************************************************************************
  *###Change Logs:
  *     Date        |   Author      |   Notes
  * ----------------|---------------|---------------------------------------------------------
  *     2018-11-18  |   GYC         |   the first version
***/

/* Includes --------------------------------------------------------------------------------*/
#include "board.h"
#include "drv_uart.h"
/** @addtogroup STC_APP
  * @{
  */
/* Private typedef -------------------------------------------------------------------------*/
/* Private define --------------------------------------------------------------------------*/
/* Private macro ---------------------------------------------------------------------------*/
#define WELCOME     "welcome\r\n"
/* Private variables -----------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------*/
/* Exported functions ----------------------------------------------------------------------*/

void main(void)
{       
    uart1_init();   ///<9600
    
    while (1) {
        uart1_send(WELCOME, sizeof(WELCOME)-1);
        uart1_sendString("6b6\r\n");
        printf("system is ok?!\r\n");
        getchar();        
    }
}

/**
  * @}
  */
/************************ (C) COPYRIGHT GYC *****END OF FILE*********************************/
