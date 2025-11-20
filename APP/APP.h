 /**************************************************************************/
/***********************Name    : Islam Nagi           ************************/
/***********************Date    : 14/11/2025         ************************/
/***********************Version : 1.0              ************************/
/***********************SWC     : APP.h            ************************/
/**************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "../LIB/StdTypes.h"
#include "../LIB/errorStatuse.h"


#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/DIO/DIO_config.h"
#include"../MCAL/DIO/DIO_Prog.c"

#include"../MCAL/EXTI/EXTI_int.h"
#include"../MCAL/EXTI/EXTI_Prog.c"
#include"../MCAL/EXTI/EXTI_Private.h"

#include"../MCAL/TIMER/TIMER_Int.h"
#include"../MCAL/TIMER/TIMER_Prog.c"
#include"../MCAL/TIMER/TIMER_Private.h"


#include"../HAL/LCD/LCD_Config.h"
#include"../HAL/LCD/LCD_int.h"
#include"../HAL/LCD/LCD_prog.c"


#define CMCON   *((volatile u8*)0x1F)


 /**********************************************************************/


                /*Level Zer0*/
#define  level0_Port        DIO_PORTA
#define  level0_Pin         DIO_PIN2

/*********************************************************/

                 /*Level 0NE*/
#define  level1_Port        DIO_PORTA
#define  level1_Pin         DIO_PIN3

/*********************************************************/


                 /*Level TW0*/
#define  level2_Port        DIO_PORTA
#define  level2_Pin         DIO_PIN4

/*********************************************************/


                 /*Level THREE*/

#define  level3_Port    DIO_PORTA
#define  level3_Pin     DIO_PIN7
/*********************************************************/

                 /*EXTI*/


/*********************************************************/


                  /*BLINKED LED FOR LEVEL TW0*/
#define  BLINKEDLED_Port        DIO_PORTB
#define  BLINKEDLED_Pin         DIO_PIN1

/*********************************************************/

                  /*RESET*/
#define  RESET_Port        DIO_PORTA
#define  RESET_Pin         DIO_PIN5

/*********************************************************/


                  /*BUZZER*/
#define  BUZZER_Port        DIO_PORTB
#define  BUZZER_Pin          DIO_PIN3

#define  MuteBuzzer_Port          DIO_PORTB
#define  MuteBuzzer_Pin           DIO_PIN0

/*********************************************************/

#define  LED_indecation_level_Port    DIO_PORTB
#define  LED_indecation_level_Pin     DIO_PIN2



#endif