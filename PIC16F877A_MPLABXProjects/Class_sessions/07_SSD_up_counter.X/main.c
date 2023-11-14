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
    init_ssd();
}

void main(void)
{
    unsigned char ssd[MAX_SSD_CNT];

    /* initialization */
    unsigned int count = 0;
    unsigned int wait = 0;

    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        if (wait++ == 100)
        {
            wait = 0;
            count++;
            if (count > 9999)
            {
                count = 0;
            }
        }
        ssd[0] = digit[(count / 1000)];
        ssd[1] = digit[((count % 1000) / 100)];
        ssd[2] = digit[((count % 100) / 10)];
        ssd[3] = digit[(count % 10)];

        display(ssd);
    }
    return;
}
