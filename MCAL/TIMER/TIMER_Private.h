/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : Timer_Private.h     ************************/
/*****************************************************************************/


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

#define TMR1L      (*(volatile unsigned char*)0x0E)
#define TMR1H      (*(volatile unsigned char*)0x0F)
#define T1CON      (*(volatile unsigned char*)0x10)

#define PIR1       (*(volatile unsigned char*)0x0C)
#define PIE1       (*(volatile unsigned char*)0x8C)

#endif