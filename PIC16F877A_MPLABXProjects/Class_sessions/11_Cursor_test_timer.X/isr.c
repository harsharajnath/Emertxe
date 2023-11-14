#include <xc.h>
#include "clcd.h"

void __interrupt() isr(void) /* isr function() */
{
    /* initialization */
    extern unsigned char cursor_on;
    extern unsigned char toggle_cursor;
    
    static unsigned int count;

    if (TMR0IF == 1) /* Timer0 Module */
    {
        TMR0 = TMR0 + 8; /* 6+2 = 8 */

        if (++count == 20000) // ---------> 0.5 sec
        {
            count = 0;

            toggle_cursor = !toggle_cursor;
            
            cursor_on();
            
            TMR0IF = 0;
        }
    }
}