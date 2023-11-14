#include <xc.h>

void __interrupt() isr(void) /* isr function() */
{
    /* initialization */
    extern unsigned int count;
    extern unsigned int count_dp;
    extern unsigned char sec_flag;
    extern unsigned char sec;


    if (TMR0IF == 1) /* Timer0 Module */
    {
        TMR0 = TMR0 + 8; /* 6+2 = 8 */
        
        if (count++ == 20000) /* 1 sec */
        {
            sec++;
            count = 0;
        }

        if (count_dp++ == 10000) /* 0.5 sec */
        {
            sec_flag = !sec_flag;
            count_dp = 0;
        }

        TMR0IF = 0;
    }
}