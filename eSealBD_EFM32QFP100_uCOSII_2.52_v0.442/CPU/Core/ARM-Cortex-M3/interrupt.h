/*************************************************************************************************************
*                                                  MODULE                                                    *
*************************************************************************************************************/
#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************************************************
*                                                 DEFINES                                                    *
*************************************************************************************************************/
#define INT_VECT_TABLE_OFFSET_ADDR              0x100UL
#define INT_VECT_TABLE_ADDR                     (CM3_DATA_BASE + INT_VECT_TABLE_OFFSET_ADDR)

#define CORE_INT_SRC_NBR                        16u    
#define PERIPH_INT_SRC_NBR                      240u
    
#define PERIPH_INT_ID0                          (CORE_INT_SRC_NBR + 0u)
#define PERIPH_INT_ID1                          (CORE_INT_SRC_NBR + 1u)
#define PERIPH_INT_ID2                          (CORE_INT_SRC_NBR + 2u)
#define PERIPH_INT_ID3                          (CORE_INT_SRC_NBR + 3u)
#define PERIPH_INT_ID4                          (CORE_INT_SRC_NBR + 4u)
#define PERIPH_INT_ID5                          (CORE_INT_SRC_NBR + 5u)
#define PERIPH_INT_ID6                          (CORE_INT_SRC_NBR + 6u)
#define PERIPH_INT_ID7                          (CORE_INT_SRC_NBR + 7u)
#define PERIPH_INT_ID8                          (CORE_INT_SRC_NBR + 8u)
#define PERIPH_INT_ID9                          (CORE_INT_SRC_NBR + 9u)
#define PERIPH_INT_ID10                         (CORE_INT_SRC_NBR + 10u)
#define PERIPH_INT_ID11                         (CORE_INT_SRC_NBR + 11u)
#define PERIPH_INT_ID12                         (CORE_INT_SRC_NBR + 12u)
#define PERIPH_INT_ID13                         (CORE_INT_SRC_NBR + 13u)
#define PERIPH_INT_ID14                         (CORE_INT_SRC_NBR + 14u)
#define PERIPH_INT_ID15                         (CORE_INT_SRC_NBR + 15u)
#define PERIPH_INT_ID16                         (CORE_INT_SRC_NBR + 16u)
#define PERIPH_INT_ID17                         (CORE_INT_SRC_NBR + 17u)
#define PERIPH_INT_ID18                         (CORE_INT_SRC_NBR + 18u)
#define PERIPH_INT_ID19                         (CORE_INT_SRC_NBR + 19u)
#define PERIPH_INT_ID20                         (CORE_INT_SRC_NBR + 20u)
#define PERIPH_INT_ID21                         (CORE_INT_SRC_NBR + 21u)
#define PERIPH_INT_ID22                         (CORE_INT_SRC_NBR + 22u)
#define PERIPH_INT_ID23                         (CORE_INT_SRC_NBR + 23u)
#define PERIPH_INT_ID24                         (CORE_INT_SRC_NBR + 24u)
#define PERIPH_INT_ID25                         (CORE_INT_SRC_NBR + 25u)
#define PERIPH_INT_ID26                         (CORE_INT_SRC_NBR + 26u)
#define PERIPH_INT_ID27                         (CORE_INT_SRC_NBR + 27u)
#define PERIPH_INT_ID28                         (CORE_INT_SRC_NBR + 28u)
#define PERIPH_INT_ID29                         (CORE_INT_SRC_NBR + 29u)
#define PERIPH_INT_ID30                         (CORE_INT_SRC_NBR + 30u)
#define PERIPH_INT_ID31                         (CORE_INT_SRC_NBR + 31u)
#define PERIPH_INT_ID32                         (CORE_INT_SRC_NBR + 32u)
#define PERIPH_INT_ID33                         (CORE_INT_SRC_NBR + 33u)
#define PERIPH_INT_ID34                         (CORE_INT_SRC_NBR + 34u)
#define PERIPH_INT_ID35                         (CORE_INT_SRC_NBR + 35u)
#define PERIPH_INT_ID36                         (CORE_INT_SRC_NBR + 36u)
#define PERIPH_INT_ID37                         (CORE_INT_SRC_NBR + 37u)
#define PERIPH_INT_ID38                         (CORE_INT_SRC_NBR + 38u)
#define PERIPH_INT_ID39                         (CORE_INT_SRC_NBR + 39u)
#define PERIPH_INT_ID40                         (CORE_INT_SRC_NBR + 40u)
#define PERIPH_INT_ID41                         (CORE_INT_SRC_NBR + 41u)
#define PERIPH_INT_ID42                         (CORE_INT_SRC_NBR + 42u)
#define PERIPH_INT_ID43                         (CORE_INT_SRC_NBR + 43u)
#define PERIPH_INT_ID44                         (CORE_INT_SRC_NBR + 44u)
#define PERIPH_INT_ID45                         (CORE_INT_SRC_NBR + 45u)
#define PERIPH_INT_ID46                         (CORE_INT_SRC_NBR + 46u)
#define PERIPH_INT_ID47                         (CORE_INT_SRC_NBR + 47u)
#define PERIPH_INT_ID48                         (CORE_INT_SRC_NBR + 48u)
#define PERIPH_INT_ID49                         (CORE_INT_SRC_NBR + 49u)
#define PERIPH_INT_ID50                         (CORE_INT_SRC_NBR + 50u)
#define PERIPH_INT_ID51                         (CORE_INT_SRC_NBR + 51u)
#define PERIPH_INT_ID52                         (CORE_INT_SRC_NBR + 52u)
#define PERIPH_INT_ID53                         (CORE_INT_SRC_NBR + 53u)
#define PERIPH_INT_ID54                         (CORE_INT_SRC_NBR + 54u)
#define PERIPH_INT_ID55                         (CORE_INT_SRC_NBR + 55u)
#define PERIPH_INT_ID56                         (CORE_INT_SRC_NBR + 56u)
#define PERIPH_INT_ID57                         (CORE_INT_SRC_NBR + 57u)
#define PERIPH_INT_ID58                         (CORE_INT_SRC_NBR + 58u)
#define PERIPH_INT_ID59                         (CORE_INT_SRC_NBR + 59u)
#define PERIPH_INT_ID60                         (CORE_INT_SRC_NBR + 60u)
#define PERIPH_INT_ID61                         (CORE_INT_SRC_NBR + 61u)
#define PERIPH_INT_ID62                         (CORE_INT_SRC_NBR + 62u)
#define PERIPH_INT_ID63                         (CORE_INT_SRC_NBR + 63u)
#define PERIPH_INT_ID64                         (CORE_INT_SRC_NBR + 64u)
#define PERIPH_INT_ID65                         (CORE_INT_SRC_NBR + 65u)
#define PERIPH_INT_ID66                         (CORE_INT_SRC_NBR + 66u)
#define PERIPH_INT_ID67                         (CORE_INT_SRC_NBR + 67u)
#define PERIPH_INT_ID68                         (CORE_INT_SRC_NBR + 68u)
#define PERIPH_INT_ID69                         (CORE_INT_SRC_NBR + 69u)
#define PERIPH_INT_ID70                         (CORE_INT_SRC_NBR + 70u)
#define PERIPH_INT_ID71                         (CORE_INT_SRC_NBR + 71u)
#define PERIPH_INT_ID72                         (CORE_INT_SRC_NBR + 72u)
#define PERIPH_INT_ID73                         (CORE_INT_SRC_NBR + 73u)
#define PERIPH_INT_ID74                         (CORE_INT_SRC_NBR + 74u)
#define PERIPH_INT_ID75                         (CORE_INT_SRC_NBR + 75u)
#define PERIPH_INT_ID76                         (CORE_INT_SRC_NBR + 76u)
#define PERIPH_INT_ID77                         (CORE_INT_SRC_NBR + 77u)
#define PERIPH_INT_ID78                         (CORE_INT_SRC_NBR + 78u)
#define PERIPH_INT_ID79                         (CORE_INT_SRC_NBR + 79u)
#define PERIPH_INT_ID80                         (CORE_INT_SRC_NBR + 80u)
#define PERIPH_INT_ID81                         (CORE_INT_SRC_NBR + 81u)
#define PERIPH_INT_ID82                         (CORE_INT_SRC_NBR + 82u)
#define PERIPH_INT_ID83                         (CORE_INT_SRC_NBR + 83u)
#define PERIPH_INT_ID84                         (CORE_INT_SRC_NBR + 84u)
#define PERIPH_INT_ID85                         (CORE_INT_SRC_NBR + 85u)
#define PERIPH_INT_ID86                         (CORE_INT_SRC_NBR + 86u)
#define PERIPH_INT_ID87                         (CORE_INT_SRC_NBR + 87u)
#define PERIPH_INT_ID88                         (CORE_INT_SRC_NBR + 88u)
#define PERIPH_INT_ID89                         (CORE_INT_SRC_NBR + 89u)
#define PERIPH_INT_ID90                         (CORE_INT_SRC_NBR + 90u)
#define PERIPH_INT_ID91                         (CORE_INT_SRC_NBR + 91u)
#define PERIPH_INT_ID92                         (CORE_INT_SRC_NBR + 92u)
#define PERIPH_INT_ID93                         (CORE_INT_SRC_NBR + 93u)
#define PERIPH_INT_ID94                         (CORE_INT_SRC_NBR + 94u)
#define PERIPH_INT_ID95                         (CORE_INT_SRC_NBR + 95u)
#define PERIPH_INT_ID96                         (CORE_INT_SRC_NBR + 96u)
#define PERIPH_INT_ID97                         (CORE_INT_SRC_NBR + 97u)
#define PERIPH_INT_ID98                         (CORE_INT_SRC_NBR + 98u)
#define PERIPH_INT_ID99                         (CORE_INT_SRC_NBR + 99u)
#define PERIPH_INT_ID100                        (CORE_INT_SRC_NBR + 100u)
#define PERIPH_INT_ID101                        (CORE_INT_SRC_NBR + 101u)
#define PERIPH_INT_ID102                        (CORE_INT_SRC_NBR + 102u)
#define PERIPH_INT_ID103                        (CORE_INT_SRC_NBR + 103u)
#define PERIPH_INT_ID104                        (CORE_INT_SRC_NBR + 104u)
#define PERIPH_INT_ID105                        (CORE_INT_SRC_NBR + 105u)
#define PERIPH_INT_ID106                        (CORE_INT_SRC_NBR + 106u)
#define PERIPH_INT_ID107                        (CORE_INT_SRC_NBR + 107u)
#define PERIPH_INT_ID108                        (CORE_INT_SRC_NBR + 108u)
#define PERIPH_INT_ID109                        (CORE_INT_SRC_NBR + 109u)
#define PERIPH_INT_ID110                        (CORE_INT_SRC_NBR + 110u)
#define PERIPH_INT_ID111                        (CORE_INT_SRC_NBR + 111u)
#define PERIPH_INT_ID112                        (CORE_INT_SRC_NBR + 112u)
#define PERIPH_INT_ID113                        (CORE_INT_SRC_NBR + 113u)
#define PERIPH_INT_ID114                        (CORE_INT_SRC_NBR + 114u)
#define PERIPH_INT_ID115                        (CORE_INT_SRC_NBR + 115u)
#define PERIPH_INT_ID116                        (CORE_INT_SRC_NBR + 116u)
#define PERIPH_INT_ID117                        (CORE_INT_SRC_NBR + 117u)
#define PERIPH_INT_ID118                        (CORE_INT_SRC_NBR + 118u)
#define PERIPH_INT_ID119                        (CORE_INT_SRC_NBR + 119u)
#define PERIPH_INT_ID120                        (CORE_INT_SRC_NBR + 120u)
#define PERIPH_INT_ID121                        (CORE_INT_SRC_NBR + 121u)
#define PERIPH_INT_ID122                        (CORE_INT_SRC_NBR + 122u)
#define PERIPH_INT_ID123                        (CORE_INT_SRC_NBR + 123u)
#define PERIPH_INT_ID124                        (CORE_INT_SRC_NBR + 124u)
#define PERIPH_INT_ID125                        (CORE_INT_SRC_NBR + 125u)
#define PERIPH_INT_ID126                        (CORE_INT_SRC_NBR + 126u)
#define PERIPH_INT_ID127                        (CORE_INT_SRC_NBR + 127u)
#define PERIPH_INT_ID128                        (CORE_INT_SRC_NBR + 128u)
#define PERIPH_INT_ID129                        (CORE_INT_SRC_NBR + 129u)
#define PERIPH_INT_ID130                        (CORE_INT_SRC_NBR + 130u)
#define PERIPH_INT_ID131                        (CORE_INT_SRC_NBR + 131u)
#define PERIPH_INT_ID132                        (CORE_INT_SRC_NBR + 132u)
#define PERIPH_INT_ID133                        (CORE_INT_SRC_NBR + 133u)
#define PERIPH_INT_ID134                        (CORE_INT_SRC_NBR + 134u)
#define PERIPH_INT_ID135                        (CORE_INT_SRC_NBR + 135u)
#define PERIPH_INT_ID136                        (CORE_INT_SRC_NBR + 136u)
#define PERIPH_INT_ID137                        (CORE_INT_SRC_NBR + 137u)
#define PERIPH_INT_ID138                        (CORE_INT_SRC_NBR + 138u)
#define PERIPH_INT_ID139                        (CORE_INT_SRC_NBR + 139u)
#define PERIPH_INT_ID140                        (CORE_INT_SRC_NBR + 140u)
#define PERIPH_INT_ID141                        (CORE_INT_SRC_NBR + 141u)
#define PERIPH_INT_ID142                        (CORE_INT_SRC_NBR + 142u)
#define PERIPH_INT_ID143                        (CORE_INT_SRC_NBR + 143u)
#define PERIPH_INT_ID144                        (CORE_INT_SRC_NBR + 144u)
#define PERIPH_INT_ID145                        (CORE_INT_SRC_NBR + 145u)
#define PERIPH_INT_ID146                        (CORE_INT_SRC_NBR + 146u)
#define PERIPH_INT_ID147                        (CORE_INT_SRC_NBR + 147u)
#define PERIPH_INT_ID148                        (CORE_INT_SRC_NBR + 148u)
#define PERIPH_INT_ID149                        (CORE_INT_SRC_NBR + 149u)
#define PERIPH_INT_ID150                        (CORE_INT_SRC_NBR + 150u)
#define PERIPH_INT_ID151                        (CORE_INT_SRC_NBR + 151u)
#define PERIPH_INT_ID152                        (CORE_INT_SRC_NBR + 152u)
#define PERIPH_INT_ID153                        (CORE_INT_SRC_NBR + 153u)
#define PERIPH_INT_ID154                        (CORE_INT_SRC_NBR + 154u)
#define PERIPH_INT_ID155                        (CORE_INT_SRC_NBR + 155u)
#define PERIPH_INT_ID156                        (CORE_INT_SRC_NBR + 156u)
#define PERIPH_INT_ID157                        (CORE_INT_SRC_NBR + 157u)
#define PERIPH_INT_ID158                        (CORE_INT_SRC_NBR + 158u)
#define PERIPH_INT_ID159                        (CORE_INT_SRC_NBR + 159u)
#define PERIPH_INT_ID160                        (CORE_INT_SRC_NBR + 160u)
#define PERIPH_INT_ID161                        (CORE_INT_SRC_NBR + 161u)
#define PERIPH_INT_ID162                        (CORE_INT_SRC_NBR + 162u)
#define PERIPH_INT_ID163                        (CORE_INT_SRC_NBR + 163u)
#define PERIPH_INT_ID164                        (CORE_INT_SRC_NBR + 164u)
#define PERIPH_INT_ID165                        (CORE_INT_SRC_NBR + 165u)
#define PERIPH_INT_ID166                        (CORE_INT_SRC_NBR + 166u)
#define PERIPH_INT_ID167                        (CORE_INT_SRC_NBR + 167u)
#define PERIPH_INT_ID168                        (CORE_INT_SRC_NBR + 168u)
#define PERIPH_INT_ID169                        (CORE_INT_SRC_NBR + 169u)
#define PERIPH_INT_ID170                        (CORE_INT_SRC_NBR + 170u)
#define PERIPH_INT_ID171                        (CORE_INT_SRC_NBR + 171u)
#define PERIPH_INT_ID172                        (CORE_INT_SRC_NBR + 172u)
#define PERIPH_INT_ID173                        (CORE_INT_SRC_NBR + 173u)
#define PERIPH_INT_ID174                        (CORE_INT_SRC_NBR + 174u)
#define PERIPH_INT_ID175                        (CORE_INT_SRC_NBR + 175u)
#define PERIPH_INT_ID176                        (CORE_INT_SRC_NBR + 176u)
#define PERIPH_INT_ID177                        (CORE_INT_SRC_NBR + 177u)
#define PERIPH_INT_ID178                        (CORE_INT_SRC_NBR + 178u)
#define PERIPH_INT_ID179                        (CORE_INT_SRC_NBR + 179u)
#define PERIPH_INT_ID180                        (CORE_INT_SRC_NBR + 180u)
#define PERIPH_INT_ID181                        (CORE_INT_SRC_NBR + 181u)
#define PERIPH_INT_ID182                        (CORE_INT_SRC_NBR + 182u)
#define PERIPH_INT_ID183                        (CORE_INT_SRC_NBR + 183u)
#define PERIPH_INT_ID184                        (CORE_INT_SRC_NBR + 184u)
#define PERIPH_INT_ID185                        (CORE_INT_SRC_NBR + 185u)
#define PERIPH_INT_ID186                        (CORE_INT_SRC_NBR + 186u)
#define PERIPH_INT_ID187                        (CORE_INT_SRC_NBR + 187u)
#define PERIPH_INT_ID188                        (CORE_INT_SRC_NBR + 188u)
#define PERIPH_INT_ID189                        (CORE_INT_SRC_NBR + 189u)
#define PERIPH_INT_ID190                        (CORE_INT_SRC_NBR + 190u)
#define PERIPH_INT_ID191                        (CORE_INT_SRC_NBR + 191u)
#define PERIPH_INT_ID192                        (CORE_INT_SRC_NBR + 192u)
#define PERIPH_INT_ID193                        (CORE_INT_SRC_NBR + 193u)
#define PERIPH_INT_ID194                        (CORE_INT_SRC_NBR + 194u)
#define PERIPH_INT_ID195                        (CORE_INT_SRC_NBR + 195u)
#define PERIPH_INT_ID196                        (CORE_INT_SRC_NBR + 196u)
#define PERIPH_INT_ID197                        (CORE_INT_SRC_NBR + 197u)
#define PERIPH_INT_ID198                        (CORE_INT_SRC_NBR + 198u)
#define PERIPH_INT_ID199                        (CORE_INT_SRC_NBR + 199u)
#define PERIPH_INT_ID200                        (CORE_INT_SRC_NBR + 200u)
#define PERIPH_INT_ID201                        (CORE_INT_SRC_NBR + 201u)
#define PERIPH_INT_ID202                        (CORE_INT_SRC_NBR + 202u)
#define PERIPH_INT_ID203                        (CORE_INT_SRC_NBR + 203u)
#define PERIPH_INT_ID204                        (CORE_INT_SRC_NBR + 204u)
#define PERIPH_INT_ID205                        (CORE_INT_SRC_NBR + 205u)
#define PERIPH_INT_ID206                        (CORE_INT_SRC_NBR + 206u)
#define PERIPH_INT_ID207                        (CORE_INT_SRC_NBR + 207u)
#define PERIPH_INT_ID208                        (CORE_INT_SRC_NBR + 208u)
#define PERIPH_INT_ID209                        (CORE_INT_SRC_NBR + 209u)
#define PERIPH_INT_ID210                        (CORE_INT_SRC_NBR + 210u)
#define PERIPH_INT_ID211                        (CORE_INT_SRC_NBR + 211u)
#define PERIPH_INT_ID212                        (CORE_INT_SRC_NBR + 212u)
#define PERIPH_INT_ID213                        (CORE_INT_SRC_NBR + 213u)
#define PERIPH_INT_ID214                        (CORE_INT_SRC_NBR + 214u)
#define PERIPH_INT_ID215                        (CORE_INT_SRC_NBR + 215u)
#define PERIPH_INT_ID216                        (CORE_INT_SRC_NBR + 216u)
#define PERIPH_INT_ID217                        (CORE_INT_SRC_NBR + 217u)
#define PERIPH_INT_ID218                        (CORE_INT_SRC_NBR + 218u)
#define PERIPH_INT_ID219                        (CORE_INT_SRC_NBR + 219u)
#define PERIPH_INT_ID220                        (CORE_INT_SRC_NBR + 220u)
#define PERIPH_INT_ID221                        (CORE_INT_SRC_NBR + 221u)
#define PERIPH_INT_ID222                        (CORE_INT_SRC_NBR + 222u)
#define PERIPH_INT_ID223                        (CORE_INT_SRC_NBR + 223u)
#define PERIPH_INT_ID224                        (CORE_INT_SRC_NBR + 224u)
#define PERIPH_INT_ID225                        (CORE_INT_SRC_NBR + 225u)
#define PERIPH_INT_ID226                        (CORE_INT_SRC_NBR + 226u)
#define PERIPH_INT_ID227                        (CORE_INT_SRC_NBR + 227u)
#define PERIPH_INT_ID228                        (CORE_INT_SRC_NBR + 228u)
#define PERIPH_INT_ID229                        (CORE_INT_SRC_NBR + 229u)
#define PERIPH_INT_ID230                        (CORE_INT_SRC_NBR + 230u)
#define PERIPH_INT_ID231                        (CORE_INT_SRC_NBR + 231u)
#define PERIPH_INT_ID232                        (CORE_INT_SRC_NBR + 232u)
#define PERIPH_INT_ID233                        (CORE_INT_SRC_NBR + 233u)
#define PERIPH_INT_ID234                        (CORE_INT_SRC_NBR + 234u)
#define PERIPH_INT_ID235                        (CORE_INT_SRC_NBR + 235u)
#define PERIPH_INT_ID236                        (CORE_INT_SRC_NBR + 236u)
#define PERIPH_INT_ID237                        (CORE_INT_SRC_NBR + 237u)
#define PERIPH_INT_ID238                        (CORE_INT_SRC_NBR + 238u)
#define PERIPH_INT_ID239                        (CORE_INT_SRC_NBR + 239u)

    
/*************************************************************************************************************
*                                            FUNCTION STATEMENT                                              *
*************************************************************************************************************/
void IntInit (void);
void IntVectRegister (CPU_INT32U vect, FNCT_VOID isr);
void IntVectUnregister (CPU_INT32U vect);
void IntEnable (CPU_INT32U vect);
void IntDisable (CPU_INT32U vect);
void IntHandlerDefault (void);

void NMIISR (void);
void FaultISR (void);
void MemFaultISR (void);
void BusFaultISR (void);
void UsageFaultISR (void);
void ReservedISR (void);
void PendSVISR (void);
void SysTickISR (void);


/*************************************************************************************************************
*                                               MODULE END                                                   *
*************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
