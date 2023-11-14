/*
 * Name: Harsharaj Nath
 * Date of Submission: 18-10-22
 * Description: Implementing a dynamic scrolling number marquee with rotation control


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned char pos = 4; /* position in the clcd */

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd(); /* initializing clcd */
    init_matrix_keypad(); /* initializing matrix keypad */
}

void main(void)
{
    /* declarations and initializations */
    unsigned char key, key_copy;
    unsigned char temp;
    unsigned char prev_direction; /* to store the previous direction while scrolling is paused */
    int num = 0; /* default is 0 */
    unsigned short index = 0; /* msg[index] */
    char msg[16] = "                "; /* message to display */
    char msg_buffer[16] = "                "; /* message backup */


    /* flags */
    unsigned short edit_mode_flag = 1; /* set as 1, default mode is edit mode */
    unsigned short pause_flag = 0; /* set as 0, default is scrolling */
    unsigned short first_iter_flag = 1; /* for 1st time iteration */
    static unsigned char toggle_cursor = 0;
    static unsigned int blink_delay = 0;


    init_config(); /* function call */


    while (1) /*super loop */
    {
        key = read_matrix_keypad(STATE); /* reading the key pressed */

        /*____________________________________________________________________*/

        if (key != ALL_RELEASED) /* when S1 or S2 is pressed */
        {
            key_copy = key; /* storing the value of key in key_copy */
        }

        /*____________________________________________________________________*/

        /* for cursor toggling */
        if (blink_delay++ == 2)
        {
            blink_delay = 0;
            toggle_cursor = !toggle_cursor;
        }

        /*____________________________________________________________________*/

        if (edit_mode_flag == 1) /* for edit mode */
        {
            clcd_print("ENTER NEW NUMBER", LINE1(0));
            clcd_print("MSG:", LINE2(0));

            /* for cursor toggling */
            switch (toggle_cursor)
            {
                case 0:
                    clcd_putch((unsigned char) 0xFF, LINE2(pos));
                    break;
                case 1:
                    clcd_print(msg, LINE2(4));
                    break;
            }

            /*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

            if (first_iter_flag == 1) /* if 1st time iteration, load with 0 */
            {
                msg[index] = (char) num + '0';
            }

            /*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

            if (key == 1) /* increment the num value */
            {
                num++;

                if (num > 9) /* roll over */
                {
                    num = 0;
                }

                msg[index] = (char) num + '0'; /* storing the value in msg[] array */
                clcd_putch((char) num + '0', (unsigned char) LINE2(pos)); /* displaying the number in clcd */
            }

            else if (key == 2) /* decrement the num value */
            {
                num--;

                if (num < 0) /* roll over */
                {
                    num = 9;
                }

                msg[index] = (char) num + '0'; /* storing the value in msg[] array */
                clcd_putch((char) num + '0', (unsigned char) LINE2(pos)); /* displaying the number in clcd */
            }

            else if (key == 3) /* start scrolling */
            {
                /* clearing the clcd */
                clcd_print("                ", LINE1(0));
                clcd_print("                ", LINE2(0));

                key_copy = 2; /* default set as right scrolling */

                prev_direction = key_copy; /* storing the direction */

                for (int i = 0; i < 16; i++) /* copying all data from msg[] to msg_buffer[] for future use */
                {
                    msg_buffer[i] = msg[i];
                }

                first_iter_flag = 0; /* set as 0, implies 1st iteration is over */
                edit_mode_flag = 0; /* set edit mode OFF */
            }

            else if (key == 5) /* increase the no. of digits */
            {
                if (pos < 15)
                {
                    num = 0; /* default value set to 0 */
                    pos++; /* incrementing the position */
                    index++; /* incrementing the index */

                    msg[index] = (char) num + '0'; /* storing the value in msg[] array */
                    clcd_putch((char) num + '0', (unsigned char) LINE2(pos)); /* displaying the number in clcd */
                }
            }

            else if (key == 6) /* remove the last digit (backspace) */
            {
                if (pos > 4 && pos < 16)
                {
                    clcd_putch(' ', (unsigned char) LINE2(pos)); /* displaying the deleted number with a blank */
                    msg[index] = ' '; /* replacing the deleted number with a blank */

                    num = msg[index - 1] - 48; /* loading num with previous position number value */
                    pos--; /* decrementing the position */
                    index--; /* decrementing the index */
                }
            }
        }

        else /* scrolling mode */
        {
            if (key_copy == 1) /* change direction towards left */
            {
                prev_direction = key_copy; /* storing the direction */

                /* shifting the values towards left */
                temp = msg[0];

                for (unsigned int i = 0; i < 16; i++)
                {
                    msg[i] = msg[i + 1];
                }

                msg[15] = temp;

                clcd_print(msg, LINE2(0)); /* displaying the number in clcd */
                for (unsigned int j = 50000; j--;); /* delay */
            }

            else if (key_copy == 2) /* change direction towards right */
            {
                prev_direction = key_copy; /* storing the direction */

                /* shifting the values towards right */
                temp = msg[15];

                for (unsigned int i = 15; i > 0; i--)
                {
                    msg[i] = msg[i - 1];
                }

                msg[0] = temp;

                clcd_print(msg, LINE2(0)); /* displaying the number in clcd */
                for (unsigned int j = 50000; j--;); /* delay */
            }

            else if (key_copy == 3) /* pause/resume scrolling */
            {
                pause_flag = !pause_flag; /* toggle the flag */

                if (pause_flag == 1) /* pause */
                {
                    key_copy = ' '; /* assign key with a blank */
                }
                else /* scroll */
                {
                    key_copy = prev_direction; /* restoring key value */
                }
            }

            else if (key_copy == 4) /* enter edit mode */
            {
                for (int i = 0; i < 16; i++)/* copying all data from msg_buffer[] to msg[] */
                {
                    msg[i] = msg_buffer[i];
                }

                edit_mode_flag = 1; /* set edit mode ON */
            }
            else if (key_copy == ' ') /* used for pausing purpose */
            {
                ; /* do nothing */
            }

            else /* if any other key is pressed */
            {
                key_copy = prev_direction; /* continue scrolling in previous direction */
            }
        }
    }

    return;
}