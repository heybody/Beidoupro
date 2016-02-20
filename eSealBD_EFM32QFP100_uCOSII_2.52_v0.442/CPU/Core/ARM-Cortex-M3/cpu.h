/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef CPU_H
#define CPU_H

#ifdef __cplusplus
extern "C" {
#endif
    
      
/*************************************************************************************************************
*                                                  DATA TYPES                                                *
*************************************************************************************************************/
typedef unsigned char  CPU_BOOL;
typedef unsigned char  CPU_INT8U;              
typedef signed   char  CPU_INT8S;               
typedef unsigned short CPU_INT16U;             
typedef signed   short CPU_INT16S;            
typedef unsigned int   CPU_INT32U;             
typedef signed   int   CPU_INT32S;
typedef unsigned long  CPU_LON32U;             
typedef signed   long  CPU_LON32S;
typedef float          CPU_F32;           
typedef double         CPU_F64;

typedef void (*FNCT_VOID)(void);            
typedef void (*FNCT_PTR )(void *);

typedef union
{
    void (*pfnHandler)(void);
    CPU_LON32U ulPtr;
}
uVectorEntry;

  
/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/   
#define DEF_ON                                  1u     
#define DEF_OFF                                 0u

#define DEF_TRUE                                1u     
#define DEF_FALSE                               0u

#define DEF_HIGH                                1u     
#define DEF_LOW                                 0u

#define DEF_ZERO                                0u

#define DEF_NULL                                (void *)0
    
#ifdef __cplusplus
#define DEF_I                                   volatile        /* defines 'read only' permissions          */
#else
#define DEF_I                                   volatile const  /* defines 'read only' permissions          */
#endif
#define DEF_O                                   volatile        /* defines 'write only' permissions         */
#define DEF_IO                                  volatile        /* defines 'read / write' permissions       */
    
#define DEF_BYTE                                8u                       
    
#define DEF_BIT0                                0x01u
#define DEF_BIT1                                0x02u
#define DEF_BIT2                                0x04u
#define DEF_BIT3                                0x08u
#define DEF_BIT4                                0x10u
#define DEF_BIT5                                0x20u
#define DEF_BIT6                                0x40u
#define DEF_BIT7                                0x80u
#define DEF_BIT8                                0x0100u
#define DEF_BIT9                                0x0200u
#define DEF_BIT10                               0x0400u
#define DEF_BIT11                               0x0800u
#define DEF_BIT12                               0x1000u
#define DEF_BIT13                               0x2000u
#define DEF_BIT14                               0x4000u
#define DEF_BIT15                               0x8000u
#define DEF_BIT16                               0x010000u
#define DEF_BIT17                               0x020000u
#define DEF_BIT18                               0x040000u
#define DEF_BIT19                               0x080000u
#define DEF_BIT20                               0x100000u
#define DEF_BIT21                               0x200000u
#define DEF_BIT22                               0x400000u
#define DEF_BIT23                               0x800000u
#define DEF_BIT24                               0x01000000u
#define DEF_BIT25                               0x02000000u
#define DEF_BIT26                               0x04000000u
#define DEF_BIT27                               0x08000000u
#define DEF_BIT28                               0x10000000u
#define DEF_BIT29                               0x20000000u
#define DEF_BIT30                               0x40000000u
#define DEF_BIT31                               0x80000000u


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif


