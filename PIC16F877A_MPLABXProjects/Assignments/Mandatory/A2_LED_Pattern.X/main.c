/*
 * Name: Harsharaj Nath
 * Date of Submission: 27-08-22
 * Description: Multiple patterns on LEDs controlled by switches
  
 * Sample Execution:
 
 * Upon giving the power supply, all 8 LEDs should be OFF.
 * press switch-1 on the Digital Keypad, LEDs should glow according to the pattern-1*
 * Press switch-2, LEDs should glow according to the pattern-2*
 * Press switch-3, LEDs should glow according to the pattern-3*
 * Press switch-4, LEDs should glow according to the pattern-4*
    
 *pattern-1: The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.
 *pattern-2: The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change.
 *pattern-3: The LEDs should blink alternately.
 *pattern-4: The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF,
             after first 4 LEDs will be OFF, next 4 LEDs will be ON.
 
 
#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

/* Watchdog Timer Enable bit (WDT enabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    LED_ARRAY1_DDR = 0x00; /* Configure as Output Port */
    LED_ARRAY1 = OFF; /* Turn off LEDs initially */
    init_digital_keypad(); /* Initialize digital keypad */
}

void main(void)
{
    unsigned char key;
    unsigned int delay = 20000;
    unsigned int i;

    /* flags initialization */
    unsigned char pattern1 = 0;
    unsigned char pattern2 = 0;
    unsigned char pattern3 = 0;
    unsigned char pattern4 = 0;

    init_config(); /* function call */

    while (1) /* super loop */
    {
        /* read digital keypad value store it in variable called key */
        key = read_digital_keypad(STATE);

        /* When SW1 is pressed */
        if (key == SW1)
        {
            pattern1 = SET;

            pattern2 = RSET;
            pattern3 = RSET;
            pattern4 = RSET;
            i = RSET;
            LED_ARRAY1 = OFF;
        }

        /* When SW2 is pressed */
        if (key == SW2)
        {
            pattern2 = SET;

            pattern1 = RSET;
            pattern3 = RSET;
            pattern4 = RSET;
            i = RSET;
            LED_ARRAY1 = OFF;
        }

        /* When SW3 is pressed */
        if (key == SW3)
        {
            pattern3 = SET;

            pattern1 = RSET;
            pattern2 = RSET;
            pattern4 = RSET;
            i = RSET;
            LED_ARRAY1 = OFF;
        }

        /* When SW4 is pressed */
        if (key == SW4)
        {
            pattern4 = SET;

            pattern1 = RSET;
            pattern2 = RSET;
            pattern3 = RSET;
            i = RSET;
            LED_ARRAY1 = OFF;
        }

        /* non blocking delay */
        if (delay-- == 0)
        {
            delay = 20000;

            /* When SW1 is pressed */
            if (pattern1)
            {
                if (i <= 7) /* condition for Turn ON LEDs from Top to Bottom */
                {
                    LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 << 1) | 0x01);
                    i++;
                }
                else if (i > 7 && i <= 15) /* condition for Turn OFF LEDs from Top to Bottom */
                {
                    LED_ARRAY1 = (unsigned char) (LED_ARRAY1 << 1);
                    i++;
                }
                else if (i > 15 && i <= 23) /* condition for Turn ON LEDs from Bottom to Top */
                {
                    LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 >> 1) | 0x80);
                    i++;
                }
                else if (i > 23 && i < 32) /* condition for Turn OFF LEDs from Bottom to Top */
                {
                    LED_ARRAY1 = (unsigned char) (LED_ARRAY1 >> 1);
                    i++;
                }
                else
                {
                    i = RSET;
                }
            }

            /* When SW2 is pressed */
            if (pattern2)
            {
                if (i <= 7) /* condition for Turn ON LEDs from Top to Bottom */
                {
                    LED_ARRAY1 = (unsigned char) ((LED_ARRAY1 << 1) | 0x01);
                    i++;
                }
                else if (i > 7 && i <= 15) /* condition for Turn OFF LEDs from Top to Bottom */
                {
                    LED_ARRAY1 = (unsigned char) (LED_ARRAY1 << 1);
                    i++;
                }
                else
                {
                    i = RSET;
                }
            }

            /* When SW3 is pressed */
            if (pattern3)
            {
                if (i == 0)
                {
                    LED_ARRAY1 = 0x55; /* condition to Turn ON 1st set of alternate LEDs */
                    i++;
                }
                else
                {
                    LED_ARRAY1 = 0xAA; /* condition to Turn OFF 2nd set of alternate LEDs */
                    i = RSET;
                }
            }

            /* When SW4 is pressed */
            if (pattern4)
            {
                if (i == 0)
                {
                    LED_ARRAY1 = 0x0F; /* condition to Turn ON first Nibble */
                    i++;
                }
                else
                {
                    LED_ARRAY1 = 0xF0; /* condition to Turn ON second Nibble */
                    i = RSET;
                }
            }
        }
    }

    return;

}