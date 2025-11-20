/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : Timer_Prog.c        ************************/
/*****************************************************************************/


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

#include"TIMER_Int.h"
#include"TIMER_Private.h"





ES_t TIM1_enuINIT(void)
{
      ES_t Local_enuErrorState = ES_OK;
                      // Configure Timer1 control register:
   // Bit7–4 = 0011 ? Prescaler 1:8 (T1CKPS1=1, T1CKPS0=1)
   // Bit2    = 0 ? Use internal clock source (Fosc/4)
   // Result: Timer1 runs from internal clock with prescaler 1:8 enabled
    T1CON = 0b00110000;
     return  Local_enuErrorState;
}
ES_t TIM1_enuSetPreload(void)
{
      ES_t Local_enuErrorState = ES_OK;
                      // preload Timer1 for the first interval:
    TMR1H = 0x0B;  // Load the high byte of Timer1 with 0x0B (preload value = 3036 decimal)

    TMR1L = 0xDC;   // Load the low byte of Timer1 with 0xDC
// Together, TMR1H:TMR1L = 0x0BDC ? timer starts from 3036 and overflows after 62 500 counts (~0.5 s at 4 MHz, prescaler 1:8)

     return  Local_enuErrorState;
}

ES_t TIM1_enuEnableTimer1(void)
{
      ES_t Local_enuErrorState = ES_OK;
                   T1CON |=(1<<0);      // Bit0    = 1 ? Turn Timer1 ON
     return  Local_enuErrorState;
}
ES_t TIM1_enuDisableTimer1(void)
{
      ES_t Local_enuErrorState = ES_OK;
                         T1CON &= ~(1<<0);     // Bit0    = 0 ? Turn Timer1 OFF
     return  Local_enuErrorState;
}

ES_t TIM1_enuEnableTimer1OverflowInterrupt(void)
{
      ES_t Local_enuErrorState = ES_OK;
                         PIE1 |=(1<<0);   // Set bit0 (TMR1IE) in PIE1 register ? enable Timer1 overflow interrupt
     return  Local_enuErrorState;
}
ES_t TIM1_enuDisableTimer1OverflowInterrupt(void)
{
      ES_t Local_enuErrorState = ES_OK;
                             PIE1 &= ~(1<<0);   // Clear bit0 (TMR1IE) in PIE1 register ? disable Timer1 overflow interrupt
     return  Local_enuErrorState;
}