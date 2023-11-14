/*
 * Name: Harsharaj Nath
 * Date of Submission: 11-09-22
 * Description: Implementation of dynamic clock on SSD using internal timer


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"
#include "timers.h"
#include "digital_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* global variables */
unsigned int count = 0;
unsigned int count_dp = 0;
unsigned char sec = 0;
unsigned char sec_flag = 0;

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd(); /* initializing ssd */
    init_digital_keypad(); /* initializing digital keypad */
    init_timer0(); /* initializing Timer0 */

    GIE = 1; /* Enable all the Global Interrupts */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned char hour = 0;
    unsigned char min = 0;
    unsigned char key;
    unsigned char edit_flag = 1; /* by default in edit mode  */
    unsigned char edit_field = 0; /* for selecting hour or min field */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key = read_digital_keypad(STATE); /* reading key pressed */

        if (key == SW4) /* if SW4 is pressed */
        {
            /* start or stop the clock */

            edit_flag = !edit_flag; /* toggle the flag */
            edit_field = 0; /* by default min field is selected every time */
        }

        if (edit_flag == 1) /* enter into edit mode */
        {
            if (key == SW1) /* incrementing the values */
            {
                /* increment the value of minute field*/
                if (edit_field == 0)
                {
                    min++;
                    if (min >= 60)
                    {
                        min = 0;
                    }
                }

                /* increment the value of hour field*/
                if (edit_field == 1)
                {
                    hour++;
                    if (hour >= 24)
                    {
                        hour = 0;
                    }
                }
            }

            if (key == SW2) /* decrementing the values */
            {
                /* decrement the value of minute field */
                if (edit_field == 0)
                {
                    min--;
                    if (min >= 60)
                    {
                        min = 59;
                    }
                }

                /* decrement the value of hour field */
                if (edit_field == 1)
                {
                    hour--;
                    if (hour >= 24)
                    {
                        hour = 23;
                    }
                }
            }
            if (key == SW3) /* toggle from minute field to hour field and vice-versa */
            {
                edit_field = !edit_field; /* toggle the flag */
            }
        }
        else /*  in running mode */
        {
            /* condition for Hour and Minute */
            if (sec == 60)
            {
                min++;
                sec = 0;
            }

            if (min == 60)
            {
                hour++;
                min = 0;
            }

            if (hour == 24)
            {
                hour = 0;
            }
        }

        /* displaying for edit mode */
        if (edit_flag == 1)
        {
            if (edit_field == 0) /* minute field */
            {
                ssd[0] = digit[hour / 10];

                /* blinking minute field and dot every 0.5 sec */
                if (sec_flag == 0)
                {
                    ssd[1] = digit[hour % 10] | DOT;
                    ssd[2] = digit[min / 10];
                    ssd[3] = digit[min % 10];
                }
                else
                {
                    ssd[1] = digit[hour % 10];
                    ssd[2] = 0;
                    ssd[3] = 0;
                }
            }

            if (edit_field == 1) /* hour field */
            {
                /* blinking hour field and dot every 0.5 sec */
                if (sec_flag == 0)
                {
                    ssd[0] = digit[hour / 10];
                    ssd[1] = digit[hour % 10] | DOT;
                }
                else
                {
                    ssd[0] = 0;
                    ssd[1] = 0;
                }

                ssd[2] = digit[min / 10];
                ssd[3] = digit[min % 10];
            }

            display(ssd);
        }

        else /* displaying for running mode */
        {
            ssd[0] = digit[hour / 10];

            /* blinking dot every 0.5 sec */
            if (sec_flag == 1)
            {
                ssd[1] = digit[hour % 10] | DOT;
            }
            else
            {
                ssd[1] = digit[hour % 10];
            }

            ssd[2] = digit[min / 10];
            ssd[3] = digit[min % 10];

            display(ssd);
        }
    }

    return;
}