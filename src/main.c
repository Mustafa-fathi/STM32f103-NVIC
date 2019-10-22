
#include "LSTD_TYPES.h"

#include "MDIO_interface.h"
#include "MRCC_interface.h"
#include "MNVK_interface.h"
#include "MEXTI_interface.h"



void func (void)
{
	MDIO_set_pin(MDIO_PORTA   , 2);

}

void toggle (void)
{
		MDIO_clr_pin(MDIO_PORTA,2);


}


void main ()
{



	 MRCC_Initialize();
	 MRCC_EnableClock( BUS_ABP2 , PERIPHERAL_GPIOA );
	 MRCC_EnableClock( BUS_ABP2 , PERIPHERAL_AFIO );
	 //asm ("MOV r0 , #1 ");
	// asm ("MSR PRIMASK  , r0 ");

	 MDIO_Initialize();
	//MDIO_set_pin(MDIO_PORTA   , 0);  //we make pin0 as input but in this line we make it pull-up
	//MDIO_set_pin(MDIO_PORTA   , 1);  //we make pin0 as input but in this line we make it pull-up



	 MDIO_SetPinValue(MDIO_PORTA , 0 , MDIO_HIGH);
	 MDIO_SetPinValue(MDIO_PORTA , 1 , MDIO_HIGH);

	 MNVK_EnableInt( 6 );  //external interrupt 0
	//  MNVK_Set_Pending_Flag(6) ;
	 MNVK_EnableInt( 7 );  //external inturrupe 1
	 EXTI0_SetCallBack (func);
	 EXTI1_SetCallBack (toggle);
	 Set_EXTIMode (0 , EXTI_Mode_Falling );
	 Set_EXTIMode (1, EXTI_Mode_Falling );


	 EXTI_Enable( 0 );
	 EXTI_Enable( 1 );






while (1){

}

}



/*

// we make this method after making set_pending to external interrupt to check if NVIC is working or not
  void  EXTI0_IRQHandler(void)
{

	MDIO_set_pin(MDIO_PORTA   , 2);   // we make pin2 as output and now we make it to turn on a led
	for(int i=0;i<30;i++)
	{

	}

	MDIO_clr_pin(MDIO_PORTA   , 2);   // we make pin2 as output and now we make it to turn on a led
}

*/
