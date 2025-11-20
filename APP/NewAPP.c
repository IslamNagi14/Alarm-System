/**************************************************************************/
/***********************Name    : Islam Nagi       ************************/
/***********************Date    : //2025           ************************/
/***********************Version : 1.0              ************************/
/***********************SWC     : APP.c            ************************/
/**************************************************************************/


#include"APP.h"
u8 Global_u8Tim1NumOverFlows = 0;
//u8 Global_u8BuzzerFLAG = 0;  // 0 deactevate -- 1 activate
void LedToggel(u8 Copy_u8PortID,u8 Copy_u8PINID)
{
DIO_enuToggelPIN(Copy_u8PortID,Copy_u8PINID);
}
void interrupt()
{
    // Timer1 interrupt
    if ((PIR1>>0)&1)
    {      // preload Timer1 for the first interval:
    TMR1H = 0x0B;  // Load the high byte of Timer1 with 0x0B (preload value = 3036 decimal)

    TMR1L = 0xDC;   // Load the low byte of Timer1 with 0xDC
// Together, TMR1H:TMR1L = 0x0BDC ? timer starts from 3036 and overflows after 62 500 counts (~0.5 s at 4 MHz, prescaler 1:8)

        // count overflows: two overflows => 1 second
        Global_u8Tim1NumOverFlows++;
        if (Global_u8Tim1NumOverFlows >= 2)
        {
            Global_u8Tim1NumOverFlows = 0;
           LedToggel(BLINKEDLED_Port,BLINKEDLED_Pin);         // signal main loop: 1 second passed
        }

        PIR1 &=~(1<<0);          // clear Timer1 interrupt flag
    }

       // --- External Interrupt Service Routine ---
   /*
    if ((INTCON>>1)&1)  // Check if RB0 external interrupt flag is set
    {
       if(Global_u8BuzzerFLAG)
       {
           //write the needed function here
           //LedToggel(BUZZER_Port,BUZZER_Pin);
           Global_u8BuzzerFLAG  = 0;
        }
        else
        {
             Global_u8BuzzerFLAG  = 1;
        }
       INTCON &= ~(1<<1);        // Clear the interrupt flag manually
    }
    */
}



int main()
{

    u8 Local_u8Level0Val = 1;
    u8 Local_u8Level1Val = 1;
    u8 Local_u8Level2Val = 1;
    u8 Local_u8Level3Val = 1;

    u8 buzzerState   = 0; //(0--> low , 1 -->high)
    u8 buzzerMuted   = 0;
    u8 lastInputs[4] = {0,0,0,0};
    u8 signalsInputs[4] = {0,0,0,0};
    u8 MuteButton = 0;
    u8 newSignal = 0;
    u8 iterator = 0;
    // Initialize DIO first
    DIO_enuInit();
     CMCON = 0x07;
    //Delay_ms(100);

    // Initialize LCD
    LCD_enuINIT();
    //Delay_ms(100);

    DIO_enuSetPINDir(level0_Port,level0_Pin,DIO_INPUT);  //level0

    DIO_enuSetPINDir(level1_Port,level1_Pin,DIO_INPUT);  //level1

    DIO_enuSetPINDir(level2_Port,level2_Pin,DIO_INPUT);  //level2

    DIO_enuSetPINDir(level3_Port,level2_Pin,DIO_INPUT);  //level3

    DIO_enuSetPINDir(LED_indecation_level_Port,LED_indecation_level_Pin,DIO_OUTPUT);  //indecation led

    DIO_enuSetPINDir(MuteBuzzer_Port,MuteBuzzer_Pin,DIO_INPUT);  //mute pin


    // Test 2: Character by character
    LCD_enuClearLCD();
    LCD_enuSetCurser(1,4);      // row, column
    LCD_enuDispString((u8*)"Welcome");
    Delay_ms(1000);
    LCD_enuClearLCD();

    /*Line Zero OXYGEN*/
    LCD_enuSetCurser(0,0);      // row, column
    LCD_enuDispString((u8*)"OXYGEN");
    LCD_enuSetCurser(0,10);      // row, column
    LCD_enuDispString((u8*)"NORMAL");
     /*Line ONE VACCUM*/
    LCD_enuSetCurser(1,0);      // row, column
    LCD_enuDispString((u8*)"VACCUM");
    LCD_enuSetCurser(1,10);      // row, column
    LCD_enuDispString((u8*)"NORMAL");
     /*Line TWO  AIR_4_BAR*/
    LCD_enuSetCurser(2,0);      // row, column
    LCD_enuDispString((u8*)"AIR_4_BAR");
    LCD_enuSetCurser(2,10);      // row, column
    LCD_enuDispString((u8*)"NORMAL");
     /*Line TWO  AIR_7_BAR*/
    LCD_enuSetCurser(3,0);      // row, column
    LCD_enuDispString((u8*)"AIR_7_BAR");
    LCD_enuSetCurser(3,10);      // row, column
    LCD_enuDispString((u8*)"NORMAL");

    DIO_enuSetPINDir(BLINKEDLED_Port,BLINKEDLED_Pin,DIO_OUTPUT);
    DIO_enuSetPINVAL(BLINKEDLED_Port,BLINKEDLED_Pin,DIO_LOW);

    DIO_enuSetPINDir(BUZZER_Port,BUZZER_Pin,DIO_OUTPUT);
    DIO_enuSetPINVAL(BUZZER_Port,BUZZER_Pin,DIO_LOW);

   /*TIMER1 preperation*/
   TIM1_enuINIT();
   TIM1_enuSetPreload();
   TIM1_enuEnableTimer1OverflowInterrupt();
   PIR1 &= ~(1<<0);  // Clear bit0 (TMR1IF) in PIR1 register ? ensure Timer1 interrupt flag is reset before starting
   INT_enuEnablePeripheralInterrupts();
   //TIM1_enuEnableTimer1();
   /*EXTI preperation*/
   // DIO_enuSetPINDir(EXTI_Port,EXTI_Pin,DIO_INPUT);
   //EXTI_enuEnableEXTI(EXTI_RISING_EDGE);

   GIE_enuEnableGIE(); // enable global interrupt system

    while(1)
    {
         DIO_enuGetPINVAL(level0_Port,level0_Pin,&Local_u8Level0Val);
         if(Local_u8Level0Val)
         {
            LCD_enuSetCurser(0,10);      // row, column
            LCD_enuDispString((u8*)"   LOW");
         }
         else
         {
            LCD_enuSetCurser(0,10);      // row, column
            LCD_enuDispString((u8*)"NORMAL");
         }

         DIO_enuGetPINVAL(level1_Port,level1_Pin,&Local_u8Level1Val);
         if(Local_u8Level1Val)
         {
            LCD_enuSetCurser(1,10);      // row, column
             LCD_enuDispString((u8*)"   LOW");
         }
         else
         {
            LCD_enuSetCurser(1,10);      // row, column
            LCD_enuDispString((u8*)"NORMAL");
         }

         DIO_enuGetPINVAL(level2_Port,level2_Pin,&Local_u8Level2Val);
         if(Local_u8Level2Val)
         {
            LCD_enuSetCurser(2,10);      // row, column
             LCD_enuDispString((u8*)"   LOW");

         }
         else
         {
            LCD_enuSetCurser(2,10);      // row, column
            LCD_enuDispString((u8*)"NORMAL");

         }

         DIO_enuGetPINVAL(level3_Port,level3_Pin,&Local_u8Level3Val);
         if(Local_u8Level3Val)
         {
            LCD_enuSetCurser(3,10);      // row, column
           LCD_enuDispString((u8*)"   LOW");

         }
         else
         {
            LCD_enuSetCurser(3,10);      // row, column
            LCD_enuDispString((u8*)"NORMAL");
         }
            /************************Buzzer mutting****************************/
            signalsInputs[0] =  Local_u8Level0Val ;
            signalsInputs[1] =  Local_u8Level1Val ;
            signalsInputs[2] =  Local_u8Level2Val ;
            signalsInputs[3] =  Local_u8Level3Val ;
            DIO_enuGetPINVAL(MuteBuzzer_Port,MuteBuzzer_Pin,&MuteButton);
            if(MuteButton) buzzerMuted = 1;

            newSignal = 0;
            for(iterator = 0;iterator<4;iterator++)
            {
             if(signalsInputs[iterator] == 1 && lastInputs[iterator] == 0)
             {
                newSignal = 1;
             }
             lastInputs[iterator] = signalsInputs[iterator];
            }
            if(newSignal) buzzerMuted = 0;

            if(!buzzerMuted && (signalsInputs[0]||signalsInputs[1]||signalsInputs[2]||signalsInputs[3]))
            {
               buzzerState = 1;
            }
            else
            {
                buzzerState = 0;
            }
            DIO_enuSetPINVAL(BUZZER_Port,BUZZER_Pin,buzzerState);
             /**************************************************************/
         if(Local_u8Level0Val || Local_u8Level1Val || Local_u8Level2Val || Local_u8Level3Val)
         {
            DIO_enuSetPINVAL(LED_indecation_level_Port,LED_indecation_level_Pin,DIO_HIGH);
            TIM1_enuEnableTimer1();
         }
         else
         {
            DIO_enuSetPINVAL(LED_indecation_level_Port,LED_indecation_level_Pin,DIO_LOW);
            TIM1_enuDisableTimer1();
            DIO_enuSetPINVAL(BLINKEDLED_Port,BLINKEDLED_Pin,DIO_LOW);
           // DIO_enuSetPINVAL (BUZZER_Port,BUZZER_Pin,DIO_LOW);
         }


    }

    return 0;
}