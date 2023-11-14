/*
 * Name: Harsharaj Nath
 * Date of Submission: 11-09-22
 * Description: Implementation of static clock on SSD using internal timer


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"
#include "timers.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

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
    init_timer0(); /* initializing Timer0 */

    GIE = 1; /* Enable all the Global Interrupts */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned char hour = 12;
    unsigned char min = 0;

    init_config(); /* function call */

    while (1) /*super loop */
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

        /* displaying */
        ssd[0] = digit[hour / 10];

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

    return;
}