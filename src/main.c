/*
******************************************************************************
@author Marcos Zuccolotto & 4324
@date Jul/2018
@brief Rotina de debounce de botao
*************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"

/* Private macro */
#define Led GPIO_ODR_ODR_5
#define LedPort GPIOA

#define Button	GPIO_IDR_IDR_13
#define ButtonPort GPIOC
#define BUTTONPRESSED 0



#define TEMPO_LED 25 //! Temmpo de troca de estdo do led

/* Private variables */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{

	uint16_t timerLed=0;//! Contador do timer do led
	uint8_t  FtimerLed=0, //! Flag do timer do led
			 ledOn=0;

	uint8_t  botao[2],botPress=0;



	// Habilitando clock GPIOs
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN|RCC_AHB1ENR_GPIOBEN|RCC_AHB1ENR_GPIOCEN|RCC_AHB1ENR_GPIODEN|RCC_AHB1ENR_GPIOHEN;

		// Configura PA5 como saida
		GPIOA->MODER&=~(GPIO_MODER_MODER5);
		GPIOA->MODER|=(GPIO_MODER_MODER5_0);
		// configura PC13 como entrada
		GPIOC->MODER&=~(GPIO_MODER_MODER13);

   // Habilitando o clock do TIM10
		RCC->APB2ENR|=RCC_APB2ENR_TIM10EN;

  // Configurando o tempo de estouro do UIF
  // estouro do UIF a cada 5ms
		TIM10->PSC=1599;
		TIM10->ARR=49;
		TIM10->CR1|=TIM_CR1_CEN; // liga o contador

		botao[0]=botao[1]=0;

  /* Infinite loop */
  while (1)
  {
	if(TIM10->SR&TIM_SR_UIF)
	  {
		TIM10->SR&=~TIM_SR_UIF; // Ok, já vi que estourou


		timerLed++;
		if (timerLed==TEMPO_LED)
		{
			timerLed=0;
			FtimerLed=1;
		}

		// Identificacao do apertar no botao
			if ((ButtonPort->IDR&Button)==BUTTONPRESSED)
				botao[0]=1;
			else
				botao[0]=0;

			if (botao[0]==1 && botao[1]==0)
				botPress=1;
			else
				botPress=0;
			botao[1]=botao[0];


	  }






	if (botPress==1)
		ledOn^=1;


	//PiscaLed
	if (FtimerLed)
		{
		FtimerLed=0;
		if (ledOn)
			LedPort->ODR^=Led; 		// troca valor do pino
		else
			LedPort->ODR&=~Led; 		// desliga o led

		}


  }// fim laco
}// fim main
