/*
 * Name: Harsharaj Nath
 * Date of Submission: 22-09-22
 * Description: Implementation of a right scrolling message marquee


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "clcd.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd(); /* initializing clcd */
}

void main(void)
{
    unsigned char temp;

    char msg[] = "Scrolling Demo  "; /* message to display */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        clcd_print(" RIGHT MARQUEE ", LINE1(0));

        /* logic for Right Scrolling */

        temp = msg[15];

        for (unsigned int i = 15; i > 0; i--)
        {
            msg[i] = msg[i - 1];
        }

        msg[0] = temp;

        clcd_print(msg, LINE2(0));

        for (unsigned int j = 50000; j--;); /* delay */
    }

    return;
}