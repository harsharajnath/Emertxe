#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF

static void init_config(void)
{
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();  
}

void main(void)
{
    init_config();
    
    unsigned char key;
    
    while (1) 
    {
        key = read_digital_keypad(STATE);
        
        if(key == SW1)
        {
            LED1 = !LED1;
            for(unsigned int wait =50000; wait--; );
        }
    }
    return;
}