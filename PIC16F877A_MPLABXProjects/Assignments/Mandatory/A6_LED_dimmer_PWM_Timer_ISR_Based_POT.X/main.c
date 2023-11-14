/*
 * Name: Harsharaj Nath
 * Date of Submission: 01-10-22
 * Description: Implementing a LED dimmer application using PWM (Timer ISR Based)


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "adc.h"
#include "main.h"
#include "timers.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned short duty_cycle; /* global variable */

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
    init_adc(); /* initializing adc */

    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void)
{
    init_config(); /* function call */

    while (1) /*super loop */
    {
        duty_cycle = read_adc(CHANNEL0); //10 bits -> 0 to 1023
    }

    return;
}