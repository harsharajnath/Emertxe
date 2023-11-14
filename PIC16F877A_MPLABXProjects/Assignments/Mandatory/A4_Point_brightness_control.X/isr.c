#include <xc.h>
#include "main.h"

extern unsigned short sec;

void __interrupt() isr(void)
{
    /* initialization */
    static unsigned int count = 0;

    if (TMR0IF == 1) /* Timer0 Module */
    {
        TMR0 = TMR0 + 8; /* 6+2 = 8 */
        if (++count == 20000)
        {
            count = 0;
            sec++;
        }

        TMR0IF = 0;
    }
}