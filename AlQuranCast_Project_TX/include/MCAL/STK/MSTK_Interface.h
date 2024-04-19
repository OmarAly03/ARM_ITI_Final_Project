#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/**************** Functions Prototypes ********************/
void MSTK_voidInit(void);
void MSTK_voidClearCurrentValue(void);
void MSTK_voidSetPreloadValue(u32 copy_u32PreloadValue);
void MSTK_voidGetFlagValue(u8 *p_Read);
void MSTK_voidEnableSTK(void);
void MSTK_voidDisableSTK(void);
void MSTK_voidGetElapsedTime(u8 *p_Read);
void MSTK_voidGetRemainingTime(u8 *p_Read);
void MSTK_voidEnableInterrupt(void);
void MSTK_voidDisableInterrupt(void);
void MSTK_voidDelayms(u32 copy_u32Delayms);
void MSTK_voidDelayus(u32 copy_u32Delayus);

#endif /* MSTK_INTERFACE_H_ */
