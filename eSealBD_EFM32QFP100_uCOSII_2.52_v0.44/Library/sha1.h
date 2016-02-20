/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef SHA1_H
#define SHA1_H

#ifdef __cplusplus
extern "C" {
#endif
    

/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void SHA1_Init (unsigned int *state); 
unsigned int SHA1_f1 (unsigned int B, unsigned int C, unsigned int D);  
unsigned int SHA1_f2 (unsigned int B, unsigned int C, unsigned int D); 
unsigned int SHA1_f3 (unsigned int B, unsigned int C, unsigned int D); 
unsigned int SHA1_f4 (unsigned int B, unsigned int C, unsigned int D); 
void SHA1_shaTran (unsigned char * buf,unsigned int * state);
void SHA1_sha (unsigned char *buf, int len, unsigned int * state, unsigned int f1,unsigned int f2);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif