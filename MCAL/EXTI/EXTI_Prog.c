/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : //2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : EXTI_Prog.c         ************************/
/*****************************************************************************/



#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

#include"EXTI_Private.h"
#include"EXTI_int.h"

ES_t EXTI_enuEnableEXTI(u8 Copy_u8INTCondition)
{
     ES_t Local_enuErrorState = ES_OK;
     if(Copy_u8INTCondition <= RISING_EDGE)
     {
          OPTION_REG &= ~(1<<6); // mask INTEDG BIT
          OPTION_REG |= (Copy_u8INTCondition<<6);
     }
     INTCON |= (1<<4); // Enable EXTI on B0
     return  Local_enuErrorState;
}
ES_t EXTI_enuDisableEXTI(void)
{
     ES_t Local_enuErrorState = ES_OK;
            INTCON &= ~(1<<4); // Disable EXTI on B0
     return  Local_enuErrorState;
}

/*Globel interrupt*/

ES_t GIE_enuEnableGIE(void)
{
     ES_t Local_enuErrorState = ES_OK;
                INTCON |= (1<<7);   //enable GIE
     return  Local_enuErrorState;
}
ES_t GIE_enuDisableGIE(void)
{
     ES_t Local_enuErrorState = ES_OK;
                  INTCON &= ~(1<<7);   //disable GIE
     return  Local_enuErrorState;
}

ES_t INT_enuEnablePeripheralInterrupts(void)
{
      ES_t Local_enuErrorState = ES_OK;
                  INTCON |= (1<<6);  // Set bit6 (PEIE) in INTCON ? enable peripheral interrupts (allows Timer1 interrupt to propagate)
     return  Local_enuErrorState;
}

ES_t INT_enuDisablePeripheralInterrupts(void)
{
      ES_t Local_enuErrorState = ES_OK;
                  INTCON &= ~(1<<6);  // Clear bit6 (PEIE) in INTCON ? disable peripheral interrupts (not allows Timer1 interrupt to propagate)
     return  Local_enuErrorState;
}