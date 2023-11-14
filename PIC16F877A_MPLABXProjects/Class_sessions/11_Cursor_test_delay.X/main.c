/*
 * Name: Harsharaj Nath
 * Date of Submission: 00-00-22
 * Description: 


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
    init_clcd();
}

void cursor_blink(unsigned char pos)
{
    static unsigned char toggle_cursor = 0;
    static unsigned int blink_delay = 0;
    
    if (toggle_cursor == 0)
    {
        clcd_putch('_', LINE1(pos));
    }
    else
    {
        clcd_putch(' ', LINE1(pos));
    }
    if (blink_delay++ == 40)
    {
        blink_delay = 0;
        toggle_cursor = !toggle_cursor;
    }
}

void main(void)
{
    unsigned char pos = 0;

    init_config(); /* function call */
    while (1) /*super loop */
    {

        cursor_blink(pos);

    }

    return;
}