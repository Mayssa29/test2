#include "led.h"


#define GPIO_OTYPE_OFFSET    (0x04/4)
#define OSPEED_OFFSET        (0X08/4)
#define OFFSET_ODR           (0x14/4)
#define OFFSET_IDR           (0X10/4)
#define OFFSET_BSRR          (0x18/4)

/*void AssertValid(void)
{
  __asm("NOP");
}

void AssertFailed(void)
{
  while(1){}
}
#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())*/

void InputOtputConfig(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode)
{
 // EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
  
  if(GPIOx == GPIOA)
  {
    *RCCAHB1 |= (1<<0);
  }
 
  else if(GPIOx == GPIOD)
  {
    *RCCAHB1 |= (1<<3);
  }

 // EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  //EMB_ASSERT(Mode >= INPUT && Mode <= ANALOG_INPUT);
  
  *GPIOx &= ~(0x3 << Pin*2);
  *GPIOx |= (Mode << Pin*2);
  
}


void ButtonToggleLed(uint32_t *GPIOx, uint8_t Pin, uint8_t PinValue)
{
 // EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  //EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  //EMB_ASSERT(PinValue == 0 || PinValue == 1);
  
  *(GPIOx + OFFSET_ODR) &= ~(1<<Pin);
  *(GPIOx + OFFSET_ODR) |=  (PinValue<<Pin);
  
}
  