/**
  *### Copyright (c) 2018, EDD-STC Development Team (eddstc1984@gmail.com). ######
  *### SPDX-License-Identifier: Apache-2.0 ######
  ********************************************************************************************
  * @file board.c
  * @version 0.1.0 
  * @brief none
  * @details none
  * @warning standard input and output library functions are not recommended. (such as printf and scanf fuctions in <stdio.h>)
  * @bug none  
  ********************************************************************************************
  *###Change Logs:
  *     Date        |   Author      |   Notes
  * ----------------|---------------|---------------------------------------------------------
  *     2018-11-18  |   GYC         |   the first version
***/


/* Includes --------------------------------------------------------------------------------*/
#include "drv_uart.h"
/** @addtogroup STC_BSP
  * @{
  */
/* Private typedef -------------------------------------------------------------------------*/
/* Private define --------------------------------------------------------------------------*/
///<No need to set a custom download command on the ISP host computer!
#define SUPPORT_SOFT_ISP        (1)
#define SUPPORT_STDIO_INPUT     (1)
#define SUPPORT_STDIO_OUTPUT    (1)
/* Private macro ---------------------------------------------------------------------------*/
#define STC_ISP_DOWNLOAD_BYTE   0xF8
/* Private variables -----------------------------------------------------------------------*/
static bool txIsOk;
#if SUPPORT_STDIO_INPUT
static bool rxIsOk;
uint8_t rxShadow;
#endif
/* Private function prototypes -------------------------------------------------------------*/
/* Exported functions ----------------------------------------------------------------------*/

///<9600bps@32MHz
void uart1_init(void)		
{
    PCON &= 0x7F;		
    SCON = 0x50;		
    AUXR |= 0x04;		
    BRT = 0x98;			
    AUXR |= 0x01;		
    AUXR |= 0x10;	    
    ES = 1;
    EA = 1;
}

/**
  * @brief send data through uart1
  * @param[in] pd: data address
  * @param[in] length: data length
  * @bug no timeout mechanism, may fall into an infinite loop
  */
void uart1_send(uint8_t *pd, uint16_t length)
{
    while (length--) {      
        txIsOk = false;
        SBUF = *pd++;
        while (!txIsOk);						
    }
}
void uart1_sendString(char *ps)
{
    while (*ps != '\0') {      
        txIsOk = false;
        SBUF = *ps++;
        while (!txIsOk);						
    }
}

void uart1_interrupt() interrupt 4 using 1
{
    static uint8_t cnt=0;
    uint8_t ch;
    
    if (RI) {
        RI = 0; ///<clear receive interrupt flag
        ch = SBUF;
#if SUPPORT_STDIO_INPUT 
        rxIsOk = true;
        rxShadow = ch;
#endif        
#if SUPPORT_SOFT_ISP        
        if (ch == STC_ISP_DOWNLOAD_BYTE) {
            if (++cnt > 20)              
                IAP_CONTR = 0x60;	///<soft reset to ISP monitoring area                
        }
        else {
            cnt = 0;
        }
#endif         
    }
    else {
        TI = 0; ///<clear send interrupt flag
        txIsOk = true;
    }
}

#if SUPPORT_STDIO_INPUT
///rewrite getchar function to use functions such as scanf
char getchar (void)
{
    rxIsOk = false;
    while (!rxIsOk);    
    return rxShadow;
}
#endif 

#if SUPPORT_STDIO_OUTPUT
///rewrite putchar function to use functions such as printf
char putchar (char ch)
{
    txIsOk = false;
    SBUF = ch;
    while (!txIsOk);
    return ch;
}
#endif

/**
  * @}
  */
/************************ (C) COPYRIGHT GYC *****END OF FILE*********************************/
