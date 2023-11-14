/*
 * Name: Harsharaj Nath
 * Date of Submission: 02-10-22
 * Description: Implementing a point brightness control


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "digital_keypad.h"
#include "main.h"
#include "timers.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* global variables */
unsigned short duty_cycle;
unsigned short sec = 5; /* default value is 5, so that until SW1 key is pressed,
                         * duty cycle remains 10% */

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

void software_pwm()
{
    static unsigned char loop_counter;

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
}

void main(void)
{
    unsigned char key; /* declaration */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key = read_digital_keypad(STATE); /* reading the key pressed */

        if (key == SW1) /* if SW1 is pressed */
        {
            sec = 0; /* resetting seconds */
        }

        if (sec < 5) /* if sec is less than 5, set duty cycle as 100% */
        {
            duty_cycle = 100;
        }
        else /* set duty cycle is 10% */
        {
            duty_cycle = 10;
        }

        software_pwm(); /* for controlling the LED brightness */
    }

    return;
}