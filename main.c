/*
 * File:   main.c
 * Author: User
 *
 * Created on 08 February 2025, 12:30
 */


#include "constVar.h"
#include "deviceConfigBits.h"
#include "configOsc.h"
#include "configPins.h"
#include "putch.h"
#include "configEUSART.h"
#include "configIOC.h"
#include "resetRC5.h"
#include "stateMachine.h"

void main(void) 
{
    configOsc();
    configPins();
    configEUSART();
    configIOC();
    
    printf("RC5 protocol\n");
    while(1)
    {
       while(IR == HI && has_run !=1);    // wait for first button press on RC5 handset
            while(IR == LO && has_run !=1);
            if(IR == HI && has_run !=1)
            {
                bits--;
                has_run = 1;                // this block only runs once until system is reset
                INTCONbits.IOCIE = 0;       // master switch disable for interrupt on change   
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S1 of 0x2000
                bits--;
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S2 of 0x1000
                bits--;                        // keep track of how many of the 14 RC5 bits have been consumed
                state = MID1;
                TMR1H = 0x00;
                TMR1L = 0x00;
                INTCONbits.IOCIE = 1;       // master switch enable for interrupt on change     
                IOCBPbits.IOCBP5 = 0;       // disable interrupt on rising edge
                IOCBNbits.IOCBN5 = 1;       // enable interrupt on falling edge
            }   
            
            else if(IOCIF !=1 && (bits + 1) == 0)  // if no interrupt and all 14 RC5 bits have been consumed by state machine
            {
                printf("RC5 code = %x\n", RC5_code);
               
                
                resetRC5();
              
                T1CONbits.TMR1ON = 0;
            
        }
        
    }
                
    return;
}
