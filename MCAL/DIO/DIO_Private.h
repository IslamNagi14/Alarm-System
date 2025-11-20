/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : DIO_Private.h       ************************/
/*****************************************************************************/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_MASK_BIT 1

#define INPUT                   1
#define OUTPUT           0

#define HIGH              1
#define LOW                   0
#define PULLUP                 1
#define FLOAT                   0

#define DIO_PORTA    0
#define DIO_PORTB    1

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7




#define TRISA        (*(volatile unsigned char*)0x85)
#define PORTA        (*(volatile unsigned char*)0x05)


#define TRISB        (*(volatile unsigned char*)0x86)
#define PORTB        (*(volatile unsigned char*)0x06)





#define HELP_CONC(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                 HELP_CONC(b7,b6,b5,b4,b3,b2,b1,b0)


#endif /* DIO_PRIVATE_H_ */