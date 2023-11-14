/*
 * Name: Harsharaj Nath
 * Date of Submission: 06-09-22
 * Description: Implementation of the time separator with Timer 0, Timer 1 and Timer 2


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "main.h"
#include "timers.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    LED_ARRAY1_DDR = 0x00; /* Configure as Output Port */
    LED_ARRAY1 = 0x00; /* Turn off LEDs initially */

    /* initialization of Timers */
    init_timer0();
    init_timer1();
    init_timer2();

    PEIE = 1; /* Peripheral Interrupt Enable Bit (For Timer2) */
    GIE = 1; /* Enable all the Global Interrupts */
}

void main(void)
{
    init_config(); /* function call */

    while (1) /* super loop */
    {
        ;
    }
    return;
}