/*
 * Name: Harsharaj Nath
 * Date of Submission: 11-09-22
 * Description: Self counter using SSDs with storage on key press


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned int count;

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd(); /* initializing ssd */
    init_digital_keypad(); /* initializing digital keypad */
    //eeprom_write(0x00, 0x00);
    //eeprom_write(0x01, 0x00);
    count = (eeprom_read(0x01)*100) + eeprom_read(0x00); /* restoring saved data into count */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned char wait = 0;
    unsigned char key;

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key = read_digital_keypad(STATE); /* reading key pressed */

        if (key == SW2) /* SW2 -> write count value to EEPROM */
        {
            eeprom_write(0x00, (count % 100)); /* writing LSBs to 0x00 */
            eeprom_write(0x01, (unsigned char) (count / 100)); /* writing MSBs to 0x01 */
        }

        if (wait++ == 80)
        {
            wait = 0;

            if (count++ > 9999) /* incrementing count till 9999 */
            {
                count = 0;
            }
        }

        /* displaying */
        ssd[0] = digit[(count / 1000)];
        ssd[1] = digit[((count % 1000) / 100)];
        ssd[2] = digit[((count % 100) / 10)];
        ssd[3] = digit[(count % 10)];

        display(ssd);
    }

    return;
}