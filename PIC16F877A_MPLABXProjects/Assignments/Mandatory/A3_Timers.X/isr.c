#include <xc.h>
#include "main.h"

void __interrupt() isr(void) /* isr function() */
{
    /* initialization */
    static unsigned int count0 = 0;
    static unsigned int count1 = 0;
    static unsigned int count2 = 0;

    if (TMR0IF == 1) /* Timer0 Module */
    {
        TMR0 = TMR0 + 8; /* 6+2 = 8 */
        if (++count0 == 10000)
        {
            count0 = 0;
            LED1 = !LED1;
        }

        TMR0IF = 0;
    }

    if (TMR1IF == 1) /* Timer1 Module */
    {
        TMR1L = TMR1L + 0x08; /* 0x06 + 0x02 = 0x08 */
        TMR1H = 0xFF;

        if (++count1 == 10000)
        {
            count1 = 0;
            LED2 = !LED2;
        }

        TMR1IF = 0;
    }

    if (TMR2IF == 1) /* Timer2 Module */
    {
        TMR2 = TMR2 + 2;
        if (++count2 == 10000)
        {
            count2 = 0;
            LED3 = !LED3;
        }

        TMR2IF = 0;
    }
}