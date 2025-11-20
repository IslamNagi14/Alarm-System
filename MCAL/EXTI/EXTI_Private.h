/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : //2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : EXTI_Private.h      ************************/
/*****************************************************************************/



#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

#define RISING_EDGE                1
#define FALLING_EDGE               0

#define INTCON      (*(volatile u8*)0x0B)

#define OPTION_REG  (*(volatile u8*)0x81)

#endif