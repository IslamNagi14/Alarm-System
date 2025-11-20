/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : DIO_Prog.c          ************************/
/*****************************************************************************/

 
 #include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"
#include "DIO_config.h"
#include "DIO_Private.h"


ES_t DIO_enuInit(void)
{
        ES_t Local_enuErrorStates = ES_NOK;

        TRISA = CONC(PA_PIN7_DIR, PA_PIN6_DIR, PA_PIN5_DIR, PA_PIN4_DIR, PA_PIN3_DIR, PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);

        TRISB = CONC(PB_PIN7_DIR, PB_PIN6_DIR, PB_PIN5_DIR, PB_PIN4_DIR, PB_PIN3_DIR, PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);

        

        PORTA = CONC(PA_PIN7_VAL, PA_PIN6_VAL, PA_PIN5_VAL, PA_PIN4_VAL, PA_PIN3_VAL, PA_PIN2_VAL, PA_PIN1_VAL, PA_PIN0_VAL);

        PORTB = CONC(PB_PIN7_VAL, PB_PIN6_VAL, PB_PIN5_VAL, PB_PIN4_VAL, PB_PIN3_VAL, PB_PIN2_VAL, PB_PIN1_VAL, PB_PIN0_VAL);

        

        Local_enuErrorStates = ES_OK;
        return Local_enuErrorStates;
}





ES_t DIO_enuSetPortDir(u8 Copy_u8PortID ,u8 Copy_u8PortValue)
{
        ES_t Local_enuErrorStates = ES_NOK;

        if(Copy_u8PortID <= DIO_PORTB)
        {
                switch(Copy_u8PortID)
                {
                case DIO_PORTA:
                                        TRISA = Copy_u8PortValue;break;
                case DIO_PORTB:
                                        TRISB = Copy_u8PortValue;break;
                }
                Local_enuErrorStates = ES_OK;
        }
        else
        {
                Local_enuErrorStates = ES_Out_Of_Range;
        }

        return Local_enuErrorStates;
}
ES_t DIO_enuSetPortVAL(u8 Copy_u8PortID ,u8 Copy_u8PortValue)
{
        ES_t Local_enuErrorStates = ES_NOK;

                if(Copy_u8PortID <= DIO_PORTB)
                {
                        switch(Copy_u8PortID)
                        {
                        case DIO_PORTA:
                                                PORTA = Copy_u8PortValue;break;
                        case DIO_PORTB:
                                                PORTB = Copy_u8PortValue;break;
                        }
                        Local_enuErrorStates = ES_OK;
                }
                else
                {
                        Local_enuErrorStates = ES_Out_Of_Range;
                }

                return Local_enuErrorStates;
}
//ES_t DIO_enuToggelPort(u8 Copy_u8PortID)
//{
//        ES_t Local_enuErrorStates = ES_NOK;
//
//        if(Copy_u8PortID <= DIO_PORTB)
//                        {
//                                switch(Copy_u8PortID)
//                                {
//                                case DIO_PORTA:
//                                                        PORTA = ~PORTA ;break;
//                                case DIO_PORTB:
//                                                        PORTB = ~PORTB ;break;
//                                Local_enuErrorStates = ES_OK;
//                        }
//                        else
//                        {
//                                Local_enuErrorStates = ES_Out_Of_Range;
//                        }
//        return Local_enuErrorStates;
//}
ES_t DIO_enuGetPortVAL(u8 Copy_u8PortID,u8 * Copy_Pu8Value)
{
        ES_t Local_enuErrorStates = ES_NOK;
        if(Copy_Pu8Value)
        {
                if(Copy_u8PortID <= DIO_PORTB)
                {
                        switch(Copy_u8PortID)
                        {
                                case DIO_PORTA:
                                        *Copy_Pu8Value = PORTA ;break;
                                case DIO_PORTB:
                                        *Copy_Pu8Value = PORTB ;break;
                        }
                        Local_enuErrorStates = ES_OK;
                }
                else
                {
                        Local_enuErrorStates = ES_Out_Of_Range;
                }

        }
        else
        {
                 Local_enuErrorStates = ES_NULLPOINTER;
        }

        return Local_enuErrorStates;
}









ES_t DIO_enuSetPINDir(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL)
{
        ES_t Local_enuErrorStates = ES_NOK;
        if(Copy_u8PortID <= DIO_PORTB && Copy_u8PINID <= DIO_PIN7 && Copy_u8PINVAL<=INPUT)
        {

                        switch(Copy_u8PortID)
                        {
                                case DIO_PORTA:
                                      TRISA &= ~(DIO_MASK_BIT<<Copy_u8PINID);
                                      TRISA |= (Copy_u8PINVAL<<Copy_u8PINID);
                                      break;
                                case DIO_PORTB:
                                     TRISB &= ~(DIO_MASK_BIT<<Copy_u8PINID);
                                     TRISB |= (Copy_u8PINVAL<<Copy_u8PINID) ;
                                     break;
                        }
                        Local_enuErrorStates = ES_OK;
        }
        else
        {
                Local_enuErrorStates = ES_Out_Of_Range;
        }

        return Local_enuErrorStates;
}
ES_t DIO_enuSetPINVAL(u8 Copy_u8PortID ,u8 Copy_u8PINID,u8 Copy_u8PINVAL)
{
        ES_t Local_enuErrorStates = ES_NOK;
        if(Copy_u8PortID <= DIO_PORTB && Copy_u8PINID <= DIO_PIN7 && Copy_u8PINVAL<=HIGH)
                {

                                switch(Copy_u8PortID)
                                {
                                        case DIO_PORTA:
                                                                PORTA &= ~(DIO_MASK_BIT<<Copy_u8PINID);
                                                                PORTA |= (Copy_u8PINVAL<<Copy_u8PINID) ;
                                                                break;
                                        case DIO_PORTB:
                                                                PORTB &= ~(DIO_MASK_BIT<<Copy_u8PINID);
                                                                PORTB |= (Copy_u8PINVAL<<Copy_u8PINID) ;
                                                                break;
                                }
                                Local_enuErrorStates = ES_OK;
                }
                else
                {
                        Local_enuErrorStates = ES_Out_Of_Range;
                }

        return Local_enuErrorStates;
}
ES_t DIO_enuToggelPIN(u8 Copy_u8PortID,u8 Copy_u8PINID)
{
        ES_t Local_enuErrorStates = ES_NOK;
        if(Copy_u8PortID <= DIO_PORTB && Copy_u8PINID <= DIO_PIN7)
                        {

                                        switch(Copy_u8PortID)
                                        {
                                                case DIO_PORTA:
                                                                        PORTA ^=(DIO_MASK_BIT<<Copy_u8PINID);
                                                                        break;
                                                case DIO_PORTB:
                                                                        PORTB ^=(DIO_MASK_BIT<<Copy_u8PINID);
                                                                        break;
                                        }
                                        Local_enuErrorStates = ES_OK;
                        }
                        else
                        {
                                Local_enuErrorStates = ES_Out_Of_Range;
                        }

        return Local_enuErrorStates;
}
ES_t DIO_enuGetPINVAL(u8 Copy_u8PortID,u8 Copy_u8PINID,u8 * Copy_Pu8Value)
{
        ES_t Local_enuErrorStates = ES_NOK;
        if(Copy_Pu8Value)
        {
                if(Copy_u8PortID <= DIO_PORTB && Copy_u8PINID <= DIO_PIN7)
                {

                                switch(Copy_u8PortID)
                                {
                                        case DIO_PORTA:
                                                *Copy_Pu8Value = (PORTA>>Copy_u8PINID)&DIO_MASK_BIT;
                                                                break;
                                        case DIO_PORTB:
                                                *Copy_Pu8Value = (PORTB>>Copy_u8PINID)&DIO_MASK_BIT;
                                                                break;
                                }
                                Local_enuErrorStates = ES_OK;
                }
                else
                {
                        Local_enuErrorStates = ES_Out_Of_Range;
                }
        }
        else
        {
                Local_enuErrorStates = ES_NULLPOINTER;
        }

        return Local_enuErrorStates;
}