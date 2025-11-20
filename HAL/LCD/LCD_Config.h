/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : LCD Configuration.h ************************/
/*****************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include"../../MCAL/DIO/DIO_int.h"

#define RS_Port                        DIO_u8PORTA
#define RS_Pin                        DIO_u8PIN0

#define EN_Port         DIO_u8PORTA
#define EN_Pin          DIO_u8PIN1

#define DB4_Port        DIO_u8PORTB
#define DB4_Pin         DIO_u8PIN4
#define DB5_Port        DIO_u8PORTB
#define DB5_Pin         DIO_u8PIN5
#define DB6_Port        DIO_u8PORTB
#define DB6_Pin         DIO_u8PIN6
#define DB7_Port        DIO_u8PORTB
#define DB7_Pin         DIO_u8PIN7

#define EIGHTMODE        8

#define FOURMODE        4

#define LCDMODE  FOURMODE

/*
* EIGHTMODE
* FOURMODE
*/




#endif /* LCD_CONFIG_H_ */