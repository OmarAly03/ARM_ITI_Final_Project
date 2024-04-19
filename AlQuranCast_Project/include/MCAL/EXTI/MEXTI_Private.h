#ifndef MEXTI_PRIVATE_H_
#define MEXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS  (0x40013C00)

typedef struct{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

#define EXTI  ((volatile EXTI_t *) EXTI_BASE_ADDRESS)

#define SYSCFG_BASE_ADDRESS  (0x40013800)

typedef struct{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t *) SYSCFG_BASE_ADDRESS)

#define FOUR_BIT_MASK    0b1111




#define MEXTI_TOTAL_NUMBER      16



/******************* MEXTI Configuration Struct **********************/

#endif /* MEXTI_PRIVATE_H_ */
