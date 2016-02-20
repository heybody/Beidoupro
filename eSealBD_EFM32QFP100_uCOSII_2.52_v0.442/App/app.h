/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif
  
    
/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

 
#include <queue.h>
#include <crc.h>
#include <util.h>
#include <head.h>
#include <socket.h>
#include <sha1.h>
#include <encrypt.h>
#include <utc.h>
    
#include <bsp.h>

#include <gnss.h>
#include <gprs_ublox.h>
    
#include <esealbd_offline.h>      
#include <esealbd_operation.h>
#include <esealbd_updata.h>
#include <esealbd_sensor.h>
#include <esealbd_gprs.h>
#include <online.h>  
    
#include <esealbd.h>
#include <rf.h>  
#include <sensor.h>  

    
    
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define APP_WATCH_DOG_EN               0
    


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/ 
#ifdef __cplusplus
}
#endif

#endif


