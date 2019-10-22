#include "LSTD_TYPES.h"

#include "MEXTI_private.h"
#include "MEXTI_interface.h"



void EXTI_Initialization(void )
{

	MEXTI -> FTSR =1;
	MEXTI -> SWIER =1;
} 

void EXTI_Enable(u8 id   )
{
	if (id <= 18 )
	{
	MEXTI -> IMR |= (1 <<id );
	}

}
void EXTI_Disable(u8 id   )
{
	if (id <= 18 )
	{
		MEXTI -> IMR &= ~(1 <<id) ;
	}

}

void Set_EXTIMode (u8 id ,u8 mode )
{
	if (id <= 18 )
	switch (mode )
	{
	case EXTI_Mode_Rising : MEXTI -> RTSR |= (1 <<id) ;   break  ;
	case EXTI_Mode_Falling : MEXTI -> FTSR |= (1 <<id) ;   break  ;
	case EXTI_Mode_IOC : MEXTI -> RTSR |= (1 <<id) ;
	                     MEXTI -> FTSR |= (1 <<id) ;      break  ;
	default : /* to do report error*/	break;

	}


}

void (*EXTI0_Callback)(void );
void (*EXTI1_Callback)(void );

void EXTI0_IRQHandler(void){

	EXTI0_Callback();
	MEXTI -> PR |=1;
	// while(1);
}

void EXTI1_IRQHandler(void){

	EXTI1_Callback();
	MEXTI -> PR |=2;
	// while(1);
}

void EXTI0_SetCallBack (void (*ptr)(void))
{
	EXTI0_Callback =ptr ;

}
void EXTI1_SetCallBack (void (*ptr)(void))
{
	EXTI1_Callback =ptr ;

}



