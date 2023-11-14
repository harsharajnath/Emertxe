/*
 * Name: Harsharaj Nath
 * Date of Submission: 11-09-22
 * Description: Implementation of left scrolling number marquee


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd(); /* initializing ssd */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 0x00, 0x00};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned char i = 0;
    unsigned char wait = 0;
    
    init_config(); /* function call */

    while (1) /*super loop */
    {
        if (wait++ == 80)
        {
            wait = 0;
            if (i++ == 13) /* left scroll */
            {
                i = 0;
            }
        }

        /* displaying */
        ssd[0] = digit[i % 12];
        ssd[1] = digit[(i + 1) % 12];
        ssd[2] = digit[(i + 2) % 12];
        ssd[3] = digit[(i + 3) % 12];

        display(ssd);
    }

    return;
}