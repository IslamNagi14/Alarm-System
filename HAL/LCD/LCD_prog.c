/*****************************************************************************/
/***********************Name    : Islam Nagi	      ************************/
/***********************Date    : 14/11/2025              ************************/
/***********************Version : 1.0                 ************************/
/***********************SWC     : LCD_prog.c          ************************/
/*****************************************************************************/


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"


#include"LCD_private.h"
#include"LCD_Config.h"

#include"../../MCAL/DIO/DIO_int.h"
u8 static const Global_U8Rows_address[4]={0x00,0x40,0x10,0x50};
u8 static Global_U8address = Global_U8Rows_address[0] + SET_DDRAM_ADDRESS ;

ES_t LCD_enuINIT(void)
{
        //ES_t Local_enuErrorState = ES_NOK;
        Delay_ms(40);
        /* Set Control pins as output */
        DIO_enuSetPINDir(RS_Port,RS_Pin,DIO_OUTPUT);
        //DIO_enuSetPINDir(RW_Port,RW_Pin,DIO_OUTPUT);
        DIO_enuSetPINDir(EN_Port,EN_Pin,DIO_OUTPUT);
        
        
        DIO_enuSetPINDir(DB4_Port,DB4_Pin,DIO_OUTPUT);
        DIO_enuSetPINDir(DB5_Port,DB5_Pin,DIO_OUTPUT);
        DIO_enuSetPINDir(DB6_Port,DB6_Pin,DIO_OUTPUT);
        DIO_enuSetPINDir(DB7_Port,DB7_Pin,DIO_OUTPUT);

        /* Return Home */
        LCD_VidDOPRVTask(RETURN_HOME);
        /* Configure as 4-bit data mode*/
        LCD_VidDOPRVTask(FUNCTION_SET_4BIT_2LINES_5X7_DOTS);
        /*Display ON OFF Control */
        LCD_VidDOPRVTask(DISPLAY_ON_CURSOR_OFF);

        /* Clear Display */
        LCD_VidDOPRVTask(DISPLAY_CLEAR);

        /*ENTRY MODE*/
        LCD_VidDOPRVTask(ENTRY_MODE_SET);
        return 0;//Local_enuErrorState;
}

static inline void LCD_VidDOPRVTask(u8 Copy_u8Commnd)
{

                
                /*prepare 4 bits MSB to send */
                DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>4)&1);
                DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>5)&1);
                DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>6)&1);
                DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>7)&1);
                
                /* open EN--> make it high --- then after 10m close EN -->make it low*/
                DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
                Delay_ms(2);
                DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
                
                /*prepare 4 bits LSB to send */
                DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>0)&1);
                DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>1)&1);
                DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>2)&1);
                DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>3)&1);
                
                /* open EN--> make it high --- then after 10m -- close EN -->make it low*/
                DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
                Delay_ms(2);
                DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


}



ES_t LCD_enuSetCurser(u8 Copy_u8PosX,u8 Copy_u8PosY)
{
        ES_t Local_enuErrorState = ES_NOK;
        
        /* 0x00 --> address row 0
         * 0x40 --> address row 1
         * 0x14 --> address row 2
         * 0x54 --> address row 3
         * copy_u8col --> col num
         * */
        DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
                DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
         Global_U8address = ( Global_U8Rows_address[Copy_u8PosX]  + Copy_u8PosY ) + SET_DDRAM_ADDRESS ;
        LCD_VidDOPRVTask(Global_U8address);


        return Local_enuErrorState;
}
ES_t LCD_enuClearLCD(void)
{
        ES_t Local_enuErrorState = ES_NOK;
        
        /*Set RS to low */
        DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
        LCD_VidDOPRVTask( DISPLAY_CLEAR);
        

                return Local_enuErrorState;
}
ES_t LCD_enuDispChar(u8 Copy_u8Char)
{
        ES_t Local_enuErrorState = ES_NOK;

// /*Set RS to HIGH */
// DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
// LCD_VidDOPRVTask(Copy_u8Char);
        
        switch(Global_U8address)
        {
                case 0x0F + SET_DDRAM_ADDRESS:
                /*Set RS to HIGH */
            DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
            LCD_VidDOPRVTask(Copy_u8Char);
                
                LCD_enuSetCurser(1,0);break;
        case 0x4F + SET_DDRAM_ADDRESS:
            DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
            LCD_VidDOPRVTask(Copy_u8Char);
                LCD_enuSetCurser(2,0);break;
        case 0x1F + SET_DDRAM_ADDRESS:
            DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
            LCD_VidDOPRVTask(Copy_u8Char);
                LCD_enuSetCurser(3,0);break;
        case 0x5F + SET_DDRAM_ADDRESS:
            DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
            LCD_VidDOPRVTask(Copy_u8Char);
                LCD_enuSetCurser(0,0);break;
                default:
                DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
            LCD_VidDOPRVTask(Copy_u8Char);
                Global_U8address++;
        }        

        return Local_enuErrorState;
}

ES_t LCD_enuDispString(u8 * Copy_u8String)
{
        ES_t Local_enuErrorState = ES_NOK;

        u16 Local_iterator = 0;
                while(Copy_u8String[Local_iterator] != '\0')
                {
                        LCD_enuDispChar(Copy_u8String[Local_iterator]);
                        Local_iterator++;
                }
        return Local_enuErrorState;
}

ES_t LCD_enuDispINTNumber(s32  Copy_u8NUM)
{
        ES_t Local_enuErrorState = ES_NOK;
        
        s32 Local_s32Tempvar = 0,Local_s32iterator = 0;
        DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);

        while(Copy_u8NUM)
        {
                Local_s32Tempvar = (Local_s32Tempvar*10)+(Copy_u8NUM%10);
                if(Copy_u8NUM % 10 == 0 && Local_s32Tempvar == 0)
                        Local_s32iterator++;
                Copy_u8NUM/=10;
        }
        while(Local_s32Tempvar)
        {
                switch(Local_s32Tempvar % 10)
                {
                case 0:
                        LCD_VidDOPRVTask('0');break;
                case 1:
                        LCD_VidDOPRVTask('1');break;
                case 2:
                        LCD_VidDOPRVTask('2');break;
                case 3:
                        LCD_VidDOPRVTask('3');break;
                case 4:
                        LCD_VidDOPRVTask('4');break;
                case 5:
                        LCD_VidDOPRVTask('5');break;
                case 6:
                        LCD_VidDOPRVTask('6');break;
                case 7:
                        LCD_VidDOPRVTask('7');break;
                case 8:
                        LCD_VidDOPRVTask('8');break;
                case 9:
                        LCD_VidDOPRVTask('9');break;
                }
                Local_s32Tempvar/=10;
        }
        while(Local_s32iterator)
        {
                LCD_VidDOPRVTask('0');
                Local_s32iterator--;
        }


        return Local_enuErrorState;
}

ES_t LCD_enuDispFloatNumber(f32  Copy_f32NUM)
{
        ES_t Local_enuErrorState = ES_NOK;
        LCD_enuDispINTNumber((s32)Copy_f32NUM);
        LCD_enuDispString(".");
        LCD_enuDispINTNumber((s32)((Copy_f32NUM - (s32)Copy_f32NUM)*1000));
        return Local_enuErrorState;
}