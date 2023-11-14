#include <xc.h>
#include "main.h"

unsigned int sec;
extern unsigned char return_time;

void __interrupt() isr(void)
{
    static unsigned int count = 0;

    if (TMR2IF == 1)
    {
        if (++count == 1250)
        {
            count = 0;
            if (sec > 0)
            {
                sec--;
            }
            
            if(sec == 0 && return_time > 0)
            {
                return_time--;
            }
        }

        TMR2IF = 0;
    }
}