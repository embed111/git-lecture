/**
  *### Copyright (c) 2018, EDD-STC Development Team (eddstc1984@gmail.com). ######
  *### SPDX-License-Identifier: Apache-2.0 ######
  ********************************************************************************************
  * @file drv_uart.h
  * @version 0.1.0	
  ********************************************************************************************
  *###Change Logs:
  *     Date        |   Author      |   Notes
  * ----------------|---------------|---------------------------------------------------------
  *     2018-11-23  |   GYC         |   the first version
***/

/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes --------------------------------------------------------------------------------*/   
#include "board.h" 
#include <stdio.h>     
/* Exported types --------------------------------------------------------------------------*/
/* Exported constants ----------------------------------------------------------------------*/
/* Exported macro --------------------------------------------------------------------------*/ 	
/* Exported functions ----------------------------------------------------------------------*/  
void uart1_init(void);		//9600bps@32MHz     
void uart1_send(uint8_t *pd, uint16_t length);
void uart1_sendString(char *ps);
#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT GYC *****END OF FILE*********************************/
