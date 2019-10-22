#ifndef MDIO_PRIVATE_H
#define MDIO_PRIVATE_H

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_type;


typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;

}AFIO_type;



#define GPIOA  ((volatile GPIO_type*) 0x40010800)
#define GPIOB  ((volatile GPIO_type*) 0x40010C00)
#define GPIOC  ((volatile GPIO_type*) 0x40011000)
#define AFIO  ((volatile AFIO_type*) 0x40010000)



#endif
