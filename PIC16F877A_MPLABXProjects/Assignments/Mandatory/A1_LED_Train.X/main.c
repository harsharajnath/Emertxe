/*
 * Name: Harsharaj Nath
 * Date of Submission: 22-08-22
 * Description: Embedded C program to display a pattern on the LEDs.
                This program will toggle the LEDs at PORTD
 
 
#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "main.h"

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
}

void main(void)
{
    unsigned long int wait = 0; /* initialization */
    unsigned char i = 0;

    init_config(); /* function call */

    while (1) /* super loop */
    {
        if (wait++ == 50000) /* Non-blocking delay */
        {
            wait = 0;

            if (i <= 7) /* condition for Turn ON LEDs from Top to Bottom */
            {
                LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 << 1) | 0x01);
                i++;
            }
            else if (i > 7 && i <= 15) /* condition for Turn OFF LEDs from Top to Bottom */
            {
                LED_ARRAY1 = (unsigned char) (LED_ARRAY1 << 1);
                i++;
            }
            else if (i > 15 && i <= 23) /* condition for Turn ON LEDs from Bottom to Top */
            {
                LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 >> 1) | 0x80);
                i++;
            }
            else if (i > 23 && i < 32) /* condition for Turn OFF LEDs from Bottom to Top */
            {
                LED_ARRAY1 = (unsigned char) (LED_ARRAY1 >> 1);
                i++;
            }
            else
            {
                i = 0;
            }
        }
    }
    return;
}