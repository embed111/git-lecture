/**
  *### Copyright (c) 2018, EDD-STC Development Team (eddstc1984@gmail.com). ######
  *### SPDX-License-Identifier: Apache-2.0 ######
  ********************************************************************************************
  * @file eddc51.h
  * @version 0.1.0	
  ********************************************************************************************
  *###Change Logs:
  *     Date        |   Author      |   Notes
  * ----------------|---------------|---------------------------------------------------------
  *     2018-11-18  |   GYC         |   the first version
***/

/* Define to prevent recursive inclusion ---------------------------------------------------*/
#ifndef __EDDC51_H__
#define __EDDC51_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes --------------------------------------------------------------------------------*/
/* Exported types --------------------------------------------------------------------------*/
enum {false = 0, true = !false};
     
typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef bit bool;
     
/* Exported constants ----------------------------------------------------------------------*/
/* Exported macro --------------------------------------------------------------------------*/ 	     
/* Exported functions ----------------------------------------------------------------------*/  


#ifdef __cplusplus
}
#endif

#endif

/************************ (C) COPYRIGHT GYC *****END OF FILE*********************************/
