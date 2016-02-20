/***************************************************************************************************
*                                             EXAMPLE CODE                                         *
*                                                                                                  *
*                             (c) Copyright 2009; Micrium, Inc.; Weston, FL                        *
*                                                                                                  *
*                      All rights reserved.  Protected by international copyright laws.            *
*                      Knowledge of the source code may not be used to write a similar             *
*                      product.  This file may only be used in accordance with a license           *
*                      and should not be redistributed in any way.                                 *
***************************************************************************************************/


/***************************************************************************************************
*                                                                                                  *
*                                    APPLICATION CONFIGURATION                                     *
*                                                                                                  *
*                                    LUMINARY MICRO LM3S8962                                       *
*                                                                                                  *
* Filename      : app_cfg.h                                                                        *
* Version       : V1.02                                                                            *
* Programmer(s) : BAN                                                                              *
***************************************************************************************************/
#ifndef APP_CFG_H
#define APP_CFG_H


/***************************************************************************************************
*                                       STANDARD LIBRARIES                                         *
***************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/***************************************************************************************************
*                                        TASK PRIORITIES                                           *
***************************************************************************************************/
#define TASK_APP_START_PRIO                 4
#define TASK_APP_COMM0_PRIO                 5
#define TASK_APP_COMM1_PRIO                 6
#define TASK_APP_COMM2_PRIO                 7
#define TASK_APP_COMM3_PRIO                 8
#define TASK_APP_COMM4_PRIO                 9
#define TASK_APP_COMM5_PRIO                 10
#define TASK_APP_ESEALBD_PRIO               11
#define TASK_APP_ESEALBD_UPDATA_PRIO        12

#define TASK_APP_COM_PRIO                   22
#define TASK_APP_RF_PRIO                    24

#define OS_TASK_TMR_PRIO                    (OS_LOWEST_PRIO - 2)


/***************************************************************************************************
*                                        TASK STACK SIZES                                          *
***************************************************************************************************/
#define TASK_STK_SIZE                       512
#define TASK_APP_D_SERVICES_STK_SIZE        1024
#define TASK_APP_RF_STK_SIZE                1024
#define TASK_APP_COMM1_SIZE                 1024

                                
/***************************************************************************************************
*                                           MODULE END                                             *
***************************************************************************************************/
#endif
