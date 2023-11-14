/*
 * Name: Harsharaj Nath
 * Date of Submission: 27-09-22
 * Description: Implementation of a 8 field password access to screen


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

unsigned int compare(char *str1, char *str2) /* function definition to compare the passwords */
{
    unsigned int flag;

    while (*str1 != '\0')
    {
        if (*str1 == *str2)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }

        str1++;
        str2++;
    }

    return flag;
}

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
    unsigned char key;

    unsigned char i = 0;
    unsigned int attempt = 5;
    unsigned int match;
    unsigned int cursor_flag = 0;

    unsigned int wait = 0; /* for attempts */
    unsigned int delay = 0; /* for cursor */

    char original_password[] = "10101010"; /* original password */
    char entered_password[8] = {}; /* user entered password */

    init_config(); /* function call */

    while (1) /*super loop */
    {
        if (attempt != 0) /* total 5 attempts */
        {
            if (i < 8) /* read 8 characters */
            {
                clcd_print(" ENTER PASSWORD ", LINE1(0));

                /* for blinking the cursor */
                if (cursor_flag == 0)
                {
                    clcd_putch('_', LINE2(i));
                }
                else if (cursor_flag == 1)
                {
                    clcd_print("                ", LINE2(i));
                }

                if (delay++ == 3)
                {
                    delay = 0;
                    cursor_flag = !cursor_flag; /* toggle the flag */
                }

                /* reading the key */
                key = read_matrix_keypad(STATE);

                if (key == 1) /* for entering 0 */
                {
                    entered_password[i] = '0';
                    clcd_putch('*', LINE2(i));
                    i++;
                }
                else if (key == 2) /* for entering 1 */
                {
                    entered_password[i] = '1';
                    clcd_putch('*', LINE2(i));
                    i++;
                }
            }
            else /* after 8 characters are entered */
            {
                match = compare(original_password, entered_password); /* checking if both password matches or not */

                if (match == 1) /* if matches */
                {
                    clcd_print("EXCELLENT, YOU ", LINE1(0));
                    clcd_print("CRACKED THE CODE", LINE2(0));
                }
                else /* if don't matches */
                {
                    while (wait++ != 10)
                    {
                        clcd_print(" WRONG PASSWORD ", LINE1(0));
                        clcd_putch((unsigned char) (attempt - 1) + '0', LINE2(0)); /* printing remaining attempts */
                        clcd_print(" ATTEMPTS LEFT ", LINE2(1));
                    }

                    /* resetting */
                    wait = 0;
                    i = 0;

                    /* decrementing attempt by 1 */
                    attempt--;
                }
            }
        }
        else /* when 5 attempts are over */
        {
            clcd_print("  PLEASE RESET  ", LINE1(0));
            clcd_print("   THE BOARD    ", LINE2(0));
        }
    }

    return;
}