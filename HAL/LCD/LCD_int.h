/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : LCD_int.h           ************************/
/*****************************************************************************/
#ifndef LCD_INT_H_
#define LCD_INT_H_


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

ES_t LCD_enuINIT(void);

ES_t LCD_enuDispChar(u8 Copy_u8Char);
ES_t LCD_enuDispString(u8 * Copy_u8String);
ES_t LCD_enuClearLCD(void);
ES_t LCD_enuSetCurser(u8 Copy_u8PosX,u8 Copy_u8PosY);
ES_t LCD_enuDispINTNumber(s32  Copy_u8NUM);
ES_t LCD_enuDispFloatNumber(f32  Copy_f32NUM);

#endif /* LCD_INT_H_ */