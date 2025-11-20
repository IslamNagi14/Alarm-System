/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : DIO_Int.h        ************************/
/*****************************************************************************/


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

#define DIO_u8PORTA                0
#define DIO_u8PORTB                1


#define DIO_u8PIN0     0
#define DIO_u8PIN1     1
#define DIO_u8PIN2     2
#define DIO_u8PIN3     3
#define DIO_u8PIN4     4
#define DIO_u8PIN5     5
#define DIO_u8PIN6     6
#define DIO_u8PIN7     7


#define DIO_INPUT      1
#define DIO_OUTPUT     0

#define DIO_LOW        0
#define DIO_HIGH       1



ES_t DIO_enuInit(void);
ES_t DIO_enuSetPortDir(u8 Copy_u8PortID ,u8 Copy_u8PortValue);
ES_t DIO_enuSetPortVAL(u8 Copy_u8PortID ,u8 Copy_u8PortValue);
ES_t DIO_enuToggelPort(u8 Copy_u8PortID);
ES_t DIO_enuGetPortVAL(u8 Copy_u8PortID,u8 * Copy_Pu8Value);


ES_t DIO_enuSetPINDir(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL);
ES_t DIO_enuSetPINVAL(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL);
ES_t DIO_enuToggelPIN(u8 Copy_u8PortID,u8 Copy_u8PINID);
ES_t DIO_enuGetPINVAL(u8 Copy_u8PortID,u8 Copy_u8PINID,u8 * Copy_Pu8Value);
#endif /* DIO_INT_H_ */