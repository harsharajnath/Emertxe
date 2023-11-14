/*
 * Name: Harsharaj Nath
 * Date of Submission: 06-09-22
 * Description: Implementation of pattern generator on LEDs controlled by switches


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

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
    init_digital_keypad(); /* Initialize digital keypad */
}

void main(void)
{
    /* initialization */
    unsigned long int wait = 0;
    unsigned char i = 0;
    unsigned char key;
    unsigned char LED_no = 0;

    /* flags initialization */
    unsigned char direction = 0;
    unsigned char direction_changed = 0;

    init_config(); /* function call */

    while (1) /* super loop */
    {
        /* read digital keypad value store it in variable called key */
        key = read_digital_keypad(STATE);

        if (key == SW1)
        {
            direction = !direction;
            direction_changed = !direction_changed;
            LED_no = i; /* storing value of i in the variable */
        }

        if (wait++ == 25000) /* Non-blocking delay */
        {
            wait = 0;

            if (direction == 0) /* Direction is Top to Bottom */
            {
                if (direction_changed == 1) /* if direction is changed */
                {
                    i = 15 - LED_no + 1; /* load i with this value */
                    direction_changed = 0; /* resetting the flag */
                }

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
                else
                {
                    i = 0;
                }
            }

            if (direction == 1) /* Direction is Bottom to Top */
            {
                if (direction_changed == 1) /* if direction is changed */
                {
                    i = 15 - LED_no + 1; /* load i with this value */
                    direction_changed = 0; /* resetting the flag */
                }
                if (i <= 7) /* condition for Turn ON LEDs from Bottom to Top */
                {
                    LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 >> 1) | 0x80);
                    i++;
                }
                else if (i > 7 && i <= 15) /* condition for Turn OFF LEDs from Bottom to Top */
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
    }
    return;
}