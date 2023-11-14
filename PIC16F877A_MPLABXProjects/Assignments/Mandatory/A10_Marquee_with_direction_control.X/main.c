/*
 * Name: Harsharaj Nath
 * Date of Submission: 11-09-22
 * Description: Implementation of scrolling number marquee with direction control


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_ssd(); /* initializing ssd */
    init_digital_keypad();  /* initializing digital keypad */
}

void main(void)
{
    /* initialization */
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 0x00, 0x00};
    /*                          0    1    2      3     4     5    6      7      8     9 */
    unsigned int i = 0;
    unsigned char wait = 0;
    unsigned char direction_flag = 0; /* by default left scroll */
    unsigned char freeze_flag = 0;
    unsigned int index;
    unsigned char key;
    
    init_config(); /* function call */
    while (1) /*super loop */
    {
        key = read_digital_keypad(STATE); /* reading the key pressed */


        if (key == SW1) /* if SW1 is pressed */
        {
            direction_flag = 0; /* left scroll */
        }

        else if (key == SW2) /* if SW2 is pressed */
        {
            direction_flag = 1; /* right scroll */
        }

        if (key == SW3) /* if SW3 is pressed */
        {
            freeze_flag = !freeze_flag; /* toggle the freeze_flag */
            index = i; /* store the value of i in index variable */
        }


        if (wait++ == 80)
        {
            wait = 0;
            if (freeze_flag == 0) /* if freeze flag is not set */
            {
                if (direction_flag == 0) /* left scroll */
                {
                    if (i++ == 13)
                    {
                        i = 0;
                    }
                }
                else if (direction_flag == 1) /* right scroll */
                {
                    if (i-- == -1)
                    {
                        i = 12;
                    }
                }
            }
            else if (freeze_flag == 1) /* if freeze flag is set */
            {
                i = index; /* assign the value stored in index variable to i */
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