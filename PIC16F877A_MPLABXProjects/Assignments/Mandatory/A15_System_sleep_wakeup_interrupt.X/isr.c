#include <xc.h>
#include "main.h"

extern unsigned short sec;
extern unsigned short led_state;
extern unsigned short toggle_flag;

void __interrupt() isr(void) /* isr function() */
{
    /* initialization */
    static unsigned int count = 0;

    if (TMR0IF == 1) /* Timer0 Module */
    {
        TMR0 = TMR0 + 8; /* 6+2 = 8 */

        if (++count == 20000) /* 1 sec */
        {
            count = 0;
            sec++;

            if (toggle_flag == 1) /* toggle the LED if flag is set */
            {
                LED1 = !LED1; /* toggling the LED */
                led_state = LED1; /* storing the LED state */
            }
        }

        TMR0IF = 0;
    }

    if (INTF == 1) /* external interrupt */
    {
        toggle_flag = 1; /* set the toggle field again */
        sec = 0; /* reset sec value to 0 */
        LED1 = 1; /* turn on the LED */
        
        INTF = 0;
    }
}