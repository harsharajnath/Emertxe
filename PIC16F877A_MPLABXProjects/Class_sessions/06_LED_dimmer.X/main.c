#include <xc.h>
#include "digital_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    TRISD = 0x00;
    PORTD = 0x00;

    init_digital_keypad();
}

void main(void)
{
    unsigned long int period = 100;
    unsigned long int duty_cycle = 50;
    unsigned long int wait = 0;
    unsigned int loop_counter = 0;
    unsigned char key;


    init_config(); /* function call */

    while (1) /*super loop */
    {

        key = read_digital_keypad(LEVEL);

        if (wait-- == 0)
        {
            wait = 250;

            if (key == SW1) /* if SW1 is pressed */
            {
                /* increase duty cycle by 1% */

                if (duty_cycle != period)
                {
                    duty_cycle++; /* till 99 */
                }
            }
            else if (key == SW2) /* if SW2 is pressed */
            {
                /* decrease duty cycle by 1% */

                if (duty_cycle != 0)
                {
                    duty_cycle--; /* till 1 */
                }
            }
        }


        /* PWM -> Bit Banging */
        if (loop_counter < duty_cycle)
        {
            RD0 = 1;
        }
        else
        {
            RD0 = 0;
        }

        if (++loop_counter == period)
        {
            loop_counter = 0;
        }
    }
}
