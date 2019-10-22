#ifndef _MEXTI_INTERFACE_H
#define _MEXTI_INTERFACE_H



#define EXTI_Mode_Rising   1
#define EXTI_Mode_Falling  2
#define EXTI_Mode_IOC  3



void EXTI_Initialization(void );

void EXTI_Enable(u8 id   );
void EXTI_Disable(u8 id   );

void EXTI_Clr_PR_Flag( u8 id );


void Set_EXTIMode (u8 id , u8 mode );
void EXTI0_SetCallBack (void (*ptr)(void));
void (*EXTI0_Callback)(void );
void EXTI0_IRQHandler(void);

void EXTI1_SetCallBack (void (*ptr)(void));
void (*EXTI1_Callback)(void );
void EXTI1_IRQHandler(void);
#endif
