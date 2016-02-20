/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <sha1.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
//static unsigned int STATE[5]; 


/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void SHA1_Init (unsigned int *state)   
{   
    state[0] = 0x67452301;   
    state[1] = 0xefcdab89;   
    state[2] = 0x98badcfe;   
    state[3] = 0x10325476;   
    state[4] = 0xc3d2e1f0;   
}   
  
unsigned int SHA1_f1 (unsigned int B, unsigned int C, unsigned int D)   
{   
    return (B&C)|(~B&D);   
}   
   
unsigned int SHA1_f2 (unsigned int B, unsigned int C, unsigned int D)   
{   
    return B^C^D;   
}   
   
unsigned int SHA1_f3 (unsigned int B, unsigned int C, unsigned int D)   
{   
    return (B&C)|(B&D)|(C&D);   
}   
   
unsigned int SHA1_f4 (unsigned int B, unsigned int C, unsigned int D)   
{   
    return B^C^D;   
}   
   
void SHA1_shaTran (unsigned char * buf,unsigned int * state)   
{   
    int i,j;   
    unsigned int A,B,C,D,E,temp;     
    unsigned int K[4];       
    unsigned int W[80];      
    unsigned char * p = (unsigned char *)W;        
      
    A  = state[0];   
    B  = state[1];   
    C  = state[2];   
    D  = state[3];   
    E  = state[4];      
       
    K[0] = 0x5a827999;   
    K[1] = 0x6ed9eba1;   
    K[2] = 0x8f1bbcdc;   
    K[3] = 0xca62c1d6;   
	
    for(i=0;i<16;i++)   
    {   
        j = 4*i;   
        p[j+3] = buf[j];   
        p[j+2] = buf[j+1];   
        p[j+1] = buf[j+2];   
        p[j] = buf[j+3];   
    }   
     
    for(i=16;i<80;i++)   
    {   
        W[i] = ((W[i-16]^W[i-14]^W[i-8]^W[i-3])<<1) | ((W[i-16]^W[i-14]^W[i-8]^W[i-3])>>31);   
    }   
      
    for(i=0;i<20;i++)   
    {   
        temp = E + SHA1_f1(B,C,D) + ((A<<5)|(A>>27)) + W[i] + K[0];   
        E = D;   
        D = C;   
        C = (B<<30)|(B>>2);   
        B = A;   
        A = temp;   
    }   
    
    for(i=20;i<40;i++)   
    {   
        temp = E + SHA1_f2(B,C,D) + ((A<<5)|(A>>27)) + W[i] + K[1];   
        E = D;   
        D = C;   
        C = (B<<30)|(B>>2);   
        B = A;   
        A = temp;   
    }   
      
    for(i=40;i<60;i++)   
    {   
        temp = E + SHA1_f3(B,C,D) + ((A<<5)|(A>>27)) + W[i] + K[2];   
        E = D;   
        D = C;   
        C = (B<<30)|(B>>2);   
        B = A;   
        A = temp;   
    }   
      
    for(i=60;i<80;i++)   
    {   
        temp = E + SHA1_f4(B,C,D) + ((A<<5)|(A>>27)) + W[i] + K[3];   
        E = D;   
        D = C;   
        C = (B<<30)|(B>>2);   
        B = A;   
        A = temp;   
    }   
      
    state[0] += A;   
    state[1] += B;   
    state[2] += C;   
    state[3] += D;   
    state[4] += E;   
}

void SHA1_sha (unsigned char *buf, int len, unsigned int * state, unsigned int f1,unsigned int f2)   
{   
    int i;   
    unsigned int floop1,floop2;        
    unsigned char flen[8];        
    unsigned char *p1 = (unsigned char *)&floop1;   
    unsigned char *p2 = (unsigned char *)&floop2;   
    floop1 = f1;   
    floop2 = f2;   
    floop2 = floop2 + (unsigned int)(len*8);       
         
    for(i=0; i<4; i++)   
    {   
        flen[3-i] = *p1;   
        flen[7-i] = *p2;   
        p1++;   
        p2++;   
    }   
   
    if(len<56)   
    {      
        buf[len] = 0x80;   
        for(i=len+1; i<56; i++)   
        {   
            buf[i] = 0x00;   
        }   
    
        for(i=56; i<64; i++)   
        {   
            buf[i] = flen[i-56];   
        }   
      
        SHA1_shaTran(buf,state);   
    }   
      
    else   
    {      
        buf[len] = 0x80;   
        for(i=len+1; i<64; i++)   
        {   
            buf[i] = 0x00;   
        }   
 
        SHA1_shaTran(buf,state);   
     
        for(i=0; i<56; i++)   
            buf[i] = 0x00;   
     
        for(i=56; i<64; i++)   
        {   
            buf[i] = flen[i-56];   
        }   
      
        SHA1_shaTran(buf,state);   
    }   
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
