/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : //2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : EXTI_Int.h          ************************/
/*****************************************************************************/



#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"


/* external interrupt*/
#define EXTI_RISING_EDGE                1
#define EXTI_FALLING_EDGE               0
ES_t EXTI_enuEnableEXTI(u8 Copy_u8INTCondition);
ES_t EXTI_enuDisableEXTI(void);

/*Globel interrupt*/

ES_t GIE_enuEnableGIE(void);
ES_t GIE_enuDisableGIE(void);

ES_t INT_enuEnablePeripheralInterrupts(void);
#endif