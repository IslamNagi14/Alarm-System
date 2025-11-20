/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : Timer_Int.h         ************************/
/*****************************************************************************/


#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"



ES_t TIM1_enuINIT(void);
ES_t TIM1_enuSetPreload(void);

ES_t TIM1_enuEnableTimer1(void);
ES_t TIM1_enuDisableTimer1(void);

ES_t TIM1_enuEnableTimer1OverflowInterrupt(void);
ES_t TIM1_enuDisableTimer1OverflowInterrupt(void);



#endif