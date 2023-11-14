/*
 * Name: Harsharaj Nath
 * Date of Submission: 07-10-22
 * Description: Implementation of 4 digit key press counter with persistence using external EEPROM


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"
#include "i2c.h"
#include "at24c04.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* global variable */
unsigned int count;

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd(); /* initializing ssd */
    init_digital_keypad(); /* initializing digital keypad */
    init_i2c(100000); /* initializing i2c protocol */
    count = (eeprom_at24c04_random_read(0x01) * 100) + eeprom_at24c04_random_read(0x00); /* restoring saved data into count */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned char wait = 0;
    unsigned char key_inc;
    unsigned char key_lp;

    init_config(); /* function call */

    while (1) /*super loop */
    {
        key_inc = read_digital_keypad(STATE); /* key for state change */
        key_lp = read_digital_keypad(LEVEL); /* key for level trigger */

        if (key_inc == SW1) /* if state change, increment the count */
        {
            count++;

            if (count > 9999)/* if count value reaches 9999, reset to 0 */
            {
                count = 0;
            }
        }

        if (key_lp == SW1) /* if level triggered, increment the wait value */
        {
            wait++;
        }
        else
        {
            wait = 0; /* else reset wait to 0 */
        }

        if (wait == 150) /* when wait value reach 150 (which gives 2sec delay) */
        {
            count = 0; /* reset the count to 0 */
        }

        if (key_inc == SW2) /* SW2 -> write count value to EEPROM */
        {
            eeprom_at24c04_byte_write(0x00, (count % 100)); /* writing LSBs to 0x00 */
            eeprom_at24c04_byte_write(0x01, (unsigned char) (count / 100)); /* writing MSBs to 0x01 */
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