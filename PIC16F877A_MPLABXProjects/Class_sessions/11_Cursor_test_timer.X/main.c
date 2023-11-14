#include <xc.h>
#include "timers.h"
#include "clcd.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned char cursor_on = 1;
unsigned char toggle_cursor;
unsigned char pos;

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_timer0(); /* initialization of Timer0 */
    init_clcd();
    GIE = 1; /* Enable all the Global Interrupts */
}

void cursor(void)
{
    if (cursor_on == 1)
    {
        if (toggle_cursor == 0)
        {
            clcd_putch('_', LINE1(pos));
            toggle_cursor = !toggle_cursor;
        }
        else
        {
            clcd_putch(' ', LINE1(pos));
            toggle_cursor = !toggle_cursor;
        }
    }
}

void main(void)
{
    init_config(); /* function call */

    while (1) /* super loop */
    {
        clcd_print("EMERTXE INFOTECH", LINE2(0));

    }

    return;
}