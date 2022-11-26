/**
  ******************************************************************************
  * @file    main.c
  * @author  Mouadh Dahech
  * @brief   Memory management 
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "GPIO.h"


/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */


 int main(void)
{
  //GPIO_Clock_Enable(GPIOD);
  //GPIO_Config(GPIOD,PIN10,OUTPUT,OUTPUT_OPEN_DRAIN,LOW_SPEED);
  //GPIO_Write_Pin(GPIOD, PIN12, SET);
  //GPIO_Write_Pin(GPIOD, PIN12, RESET);
  
  InputOtputConfig(GPIOD, PIN12, OUTPUT);
  InputOtputConfig(GPIOA, PIN0, INPUT);
  InputOtputConfig(GPIOD, PIN15, OUTPUT);
  ButtonToggleLed(GPIOD, PIN15,SET );
  
  while(1)
  {
    if( GPIO_Read_Pin(GPIOA, PIN0))
	  {ButtonToggleLed(GPIOD, PIN12,SET );}
 
  }
}

/**************************************END OF FILE**************************************/
