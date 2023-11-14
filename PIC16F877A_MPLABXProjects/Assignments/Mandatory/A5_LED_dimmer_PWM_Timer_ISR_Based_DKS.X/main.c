/*
 * Name: Harsharaj Nath
 * Date of Submission: 01-10-22
 * Description: Using Timer based PWM, implementing a LED dimmer application with Digital Keypad Switches
 *              As soon as the board is powered on or reset, The LED should glow with 50% Duty Cycle
 *              - DKS1 as Increase Brightness Input, Level Triggered
 *              - DKS2 as Decrease Brightness Input, Level Triggered


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "digital_keypad.h"
#include "main.h"
#include "timers.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned short duty_cycle = 50; /* 50% duty cycle */

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    /* initializing PORTD and TRISD*/
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;

    init_timer0(); /* initializing timer0 */
    init_digital_keypad(); /* initializing digital keypad */

    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void)
{
    unsigned char key;
    unsigned long int wait = 0;

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key = read_digital_keypad(LEVEL); /* reading the key pressed */

        if (wait-- == 0)
        {
            wait = 250;

            if (key == SW1) /* if SW1 is pressed */
            {
                /* increase duty cycle by 1% */

                if (duty_cycle != PERIOD)
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
    }

    return;
}