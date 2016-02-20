/*************************************************************************************************************
*                                              INCLUDE FILES                                                 *
*************************************************************************************************************/
#include <sha1.h>

#include <encrypt.h>


/*************************************************************************************************************
*                                              LOCAL TABLES                                                  *
*************************************************************************************************************/
static unsigned int STATE[5]; 
static sMACTypeDef MAC;

/*************************************************************************************************************
*                                            FUNCTION PROTOTYPES                                             *
*************************************************************************************************************/
void Decrypt (unsigned int id, unsigned int rn, unsigned int key, unsigned char *pdata, unsigned int len) 
{
    unsigned char buf[64];
    unsigned char mac_data[20];
    unsigned char secret_data[256];
    int buf_data_len;       
    unsigned int floop1, floop2;  
    unsigned int i, j, k;
    
    floop1 = floop2 = 0;       

    MAC.ID = id;
    MAC.RN = rn;
    MAC.KEY = key;
    
    buf_data_len = 12;

    SHA1_Init(STATE);

    for (i = 0; i < 4; i++)
    {
        buf[i] = (unsigned char)(MAC.ID >> 8 * (3 - i));
        buf[i + 4] = (unsigned char)(MAC.RN >> 8 * (3 - i));
        buf[i + 8] = (unsigned char)(MAC.KEY >> 8 * (3 - i));
    }

    SHA1_sha(buf, buf_data_len, STATE, floop1, floop2);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mac_data[j + 4 * i] = (unsigned char)(STATE[i] >> 8 * (3 - j));
        }
    }

    if (len <= 20)
    {
        for (i = 0; i < len; i++)
        {
            secret_data[i] = mac_data[i] ^ pdata[i];
        }
    }
    else
    {
        for (j = 0; j < (len / 20); j++)
        {
            for (k = 0; k < 20; k++)
            {
                secret_data[k + j * 20] = pdata[k + j * 20] ^ mac_data[k];
            }
        }
        for (k = 0; k < (len % 20); k++)
        {
            secret_data[k + j * 20] = pdata[k + j * 20] ^ mac_data[k];
        }
    }

    for (i = 0; i < len; i++)
    {
        pdata[i] = secret_data[i];
    }
}

void Encrypt (unsigned int id, unsigned int rn, unsigned int key, unsigned char *pdata, unsigned int len) 
{
    unsigned char buf[64];
    unsigned char mac_data[20];
    unsigned char secret_data[256];
    int buf_data_len;           
    unsigned int floop1, floop2;  
    unsigned int i, j;
    
    floop1 = floop2 = 0;        
	
    MAC.ID = id;
    MAC.RN = rn;
    MAC.KEY = key;
    
    buf_data_len = 12;

    SHA1_Init(STATE);

    for (i = 0; i < 4; i++)
    {
        buf[i] = (unsigned char)(MAC.ID >> 8 * (3 - i));
        buf[i + 4] = (unsigned char)(MAC.RN >> 8 * (3 - i));
        buf[i + 8] = (unsigned char)(MAC.KEY >> 8 * (3 - i));
    }

    SHA1_sha(buf, buf_data_len, STATE, floop1, floop2);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mac_data[j + 4 * i] = (unsigned char)(STATE[i] >> 8 * (3 - j));
        }
    }

    if (len <= 20)
    {
        for (i = 0; i < len; i++)
        {
            secret_data[i] = pdata[i] ^ mac_data[i];
        }
    }
    else
    {
        for (j = 0; j < (len / 20); j++)
        {
	    for (i = 0; i < 20; i++)
	    {
	        secret_data[i + j * 20] = pdata[i + j * 20] ^ mac_data[i];
	    }
        }
        for (i = 0; i < (len % 20); i++)
        {
            secret_data[i + j * 20] = pdata[i + j * 20] ^ mac_data[i];
        }
    }

    for (i = 0; i < len; i++)
    {
        pdata[i] = secret_data[i];
    }
}


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
