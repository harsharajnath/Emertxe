#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"
/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned char count;

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd();
    init_digital_keypad();
}

unsigned char eeprom_test(unsigned char key)
{
    if (key == SW1) /* SW1 -> write count value to EEPROM */
    {
        eeprom_write(0x00, count);
    }
    else if (key == SW2) /* SW2 -> read stored count value from EEPROM */
    {
        count = eeprom_read(0x00);
    }
    else if (key == SW3) /* SW3 -> increment the count value from 0 till 9, reset to 0 if limit reached */
    {
        if (count++ == 9)
            count = 0;
    }

    return count;
}

void main(void)
{
    unsigned char ssd[MAX_SSD_CNT];

    /* initialization */
    unsigned char key;

    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key = read_digital_keypad(STATE);
        count = eeprom_test(key);

        ssd[0] = digit[(count / 1000)];
        ssd[1] = digit[((count % 1000) / 100)];
        ssd[2] = digit[((count % 100) / 10)];
        ssd[3] = digit[(count % 10)];

        display(ssd);
    }
    return;
}
