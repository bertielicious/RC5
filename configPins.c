#include "constVar.h"
void configPins(void)
{
     ANSELC = 0x00;
    // RC7 is an output (pin 9) to drive LED
    TRISCbits.TRISC7 = LO;
    
     //********TURN OFF ANALOGUE INPUTS**********************
    ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
    ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
    ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
    
    /* SET DATA DIRECTION FOR GENERAL I/O PINS************************/
    TRISBbits.TRISB5 = 1;           // IR IOC input pin 12
   
}
