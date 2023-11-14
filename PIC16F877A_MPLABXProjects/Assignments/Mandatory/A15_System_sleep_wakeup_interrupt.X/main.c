/*
 * Name: Harsharaj Nath
 * Date of Submission: 03-10-22
 * Description: Implementing system sleep and wake up while Interrupt on change


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "main.h"
#include "timers.h"
#include "ssd.h"
#include "external_interrupt.h"

/* global variables */
unsigned short sec;
unsigned short led_state; /* to store the previous state of LED */
unsigned short toggle_flag = 1; /* set by default, LED will toggle by default */

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    LED_ARRAY2_DDR = 0x01; /* Configure RB1-RB7 as Output Port and RB0 as input (interrupt) */
    LED_ARRAY2 = 0x03; /* Turn off all LEDs initially, except RB0 and RB1 */

    init_ssd(); /* initializing ssd */
    init_timer0(); /* initializing timer0*/
    init_ext_int(); /* initializing external interrupt */

    GIE = 1; /* Enable all the Global Interrupts */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */

    init_config(); /* function call */

    while (1) /* super loop */
    {
        if (sec < 5) /* keep SSDs on for 5 sec */
        {
            /* displaying */
            ssd[0] = digit[1];
            ssd[1] = digit[2];
            ssd[2] = digit[3];
            ssd[3] = digit[4];

            display(ssd);
        }
        else
        {
            toggle_flag = 0; /* turn off toggling */
            LED1 = (__bit) led_state; /* load the previous state of LED */
            SSD_CONTROL_PORT = (unsigned char) ((SSD_CONTROL_PORT & 0x03) | 0x00); /* no SSD has been selected, so all are OFF */
            SLEEP(); /* built-in function -> put the system to sleep */
        }
    }
    return;
}