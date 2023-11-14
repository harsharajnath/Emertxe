#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void)                                                  //set Keypad Port as Input
{
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;                            //TRISB = TRISB | 0x3F
}

unsigned char read_digital_keypad(unsigned char mode)
{
    static unsigned char once = 1;                                              //flag
    
    if(mode == LEVEL)                                                           //for Level Triggering
    {
        return (KEYPAD_PORT & INPUT_LINES);                                     //PORTB & 0x3F
    }
    else                                                                        //for Edge/State Change Triggering
    {
        if(((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;                                                           //set flag as 0 so that only one time action is taken
            return (KEYPAD_PORT & INPUT_LINES);                                 //PORTB & 0x3F
        }
        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)                   //No key pressed
        {
            once = 1;                                                           //reset the flag as 1
        }
    }
    return ALL_RELEASED;                                                        //No key pressed
}