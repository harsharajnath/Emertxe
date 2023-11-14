#include <xc.h>

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    TRISB = 0x00;
    PORTB = 0x00;
}

void main(void)
{
    unsigned long int period = 100000;
    unsigned long int duty_cycle = 50000;
    unsigned int loop_counter = 0;

    init_config(); /* function call */

    while (1) /*super loop */
    {
        if (loop_counter < duty_cycle)
        {
            RB0 = 1;
        }
        else
        {
            RB0 = 0;
        }

        if (++loop_counter == period)
        {
            loop_counter = 0;
        }
    }
}
