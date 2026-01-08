//PB7 SW1 -> PB14 LED3,
#include<stdint.h>
#include"stm32f405xx.h"	//cmsis file
int main()
{
	RCC->AHB1ENR |=(1<<1);	//to enable clock, port B

	GPIOB->MODER |=(1<<28);		//PB14 LED (01- OUTPUT)
	GPIOB->MODER &=~(1<<29);

	GPIOB->MODER &=~(3<<14);	//PB7 SWITCH (00- INPUT)
	//GPIOB->MODER &=~(1<<15);

	while(1)
	{
		if((GPIOB->IDR & (1<<7))==0)
		{

			GPIOB->ODR ^=(1<<14);	//LED ON
			while((GPIOB->IDR & (1<<7))==0);	//DEBOUNCE WAIT UNTIL BUTTON IS RELEASED
		}
	}
}

