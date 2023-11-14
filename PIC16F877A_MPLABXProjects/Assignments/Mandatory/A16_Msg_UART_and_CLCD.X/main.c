/*
 * Name: Harsharaj Nath
 * Date of Submission: 30-09-22
 * Description: Implementing a message display using UART and CLCD


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "clcd.h"
#include "uart.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd(); /* initializing clcd */
    init_uart(9600); /* initializing uart */
}

void main(void)
{
    /* declarations and initializations */
    unsigned char line1_buffer[17];
    unsigned char line2_buffer[17];

    unsigned char ch;

    unsigned int count = 0;

    init_config(); /* function call */

    while (1) /*super loop */
    {
        ch = getchar(); /* reading the character */

        if (ch != '\n') /* if character not equal to new line */
        {
            if (count <= 15)
            {
                line1_buffer[count] = ch; /* storing the character in the array */
                line1_buffer[count + 1] = '\0';
                count++;
            }
            else if (count >= 16 && count <= 31)
            {
                line2_buffer[count % 16] = ch; /* storing the character in the array */
                line2_buffer[(count % 16) + 1] = '\0';
                count++;
            }
            else if (count >= 32)
            {
                for (int i = 0; i < 15; i++)
                {
                    line1_buffer[i] = line1_buffer[i + 1]; /* shifting left by 1 element */
                }

                line1_buffer[15] = line2_buffer[0]; /* storing last element of 1st array with first element of 2nd array */
                line1_buffer[16] = '\0';

                for (int i = 0; i < 15; i++)
                {
                    line2_buffer[i] = line2_buffer[i + 1]; /* shifting left by 1 element */
                }
                line2_buffer[15] = ch; /*storing the character in the last position of the array */
                line2_buffer[16] = '\0';
            }
        }
        else /* for displaying in clcd */
        {
            if (count <= 17)
            {
                clcd_print("                ", LINE1(0));
                clcd_print("                ", LINE2(0));
                clcd_print(line1_buffer, LINE1(0));
            }
            else
            {
                clcd_print("                ", LINE1(0));
                clcd_print("                ", LINE2(0));
                clcd_print(line1_buffer, LINE1(0));
                clcd_print(line2_buffer, LINE2(0));
            }
            
            count = 0; /* resetting the count */
        }
    }

    return;
}