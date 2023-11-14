#include <xc.h>
#include "main.h"

extern unsigned short duty_cycle;
int loop_counter;

void __interrupt() isr(void)
{    
    if (TMR0IF == 1)
    {
        if (loop_counter <= duty_cycle)
        {
            LED1 = ON;
        }
        else
        {
            LED1 = OFF;
        }

        if (loop_counter == PERIOD)
        {
            loop_counter = 0;
        }

        loop_counter++;

        TMR0IF = 0;
    }
}