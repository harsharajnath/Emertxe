#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd();
    init_matrix_keypad();
}

void main(void)
{
    unsigned char key, key_copy;
    unsigned char temp;

    char msg[] = "CLCD Test Code  "; /* message to display */

    init_config(); /* function call */

    clcd_print("Select MKP SW", LINE1(0)); /* 0x80 + 0 */
    clcd_print("S1-Left S2-Right", LINE2(0)); /* 0xC0 + 0 */

    while (1) /*super loop */
    {
        key = read_matrix_keypad(STATE);

        if (key != ALL_RELEASED) /* when S1 or S2 is pressed */
        {
            key_copy = key; /* storing the value of key in key_copy */
        }

        if (key_copy == 1)
        {
            clcd_print("Left Scrolling ", LINE1(0));

            /* logic for Left Scrolling */

            temp = msg[0];
            for (unsigned int i = 0; i < 16; i++)
            {
                msg[i] = msg[i + 1];
            }
            msg[15] = temp;

            clcd_print(msg, LINE2(0));

            for (unsigned int j = 50000; j--;); /* delay */
        }
        else if (key_copy == 2)
        {
            clcd_print("Right Scrolling ", LINE1(0));

            /* logic for Right Scrolling */

            temp = msg[15];

            for (unsigned int i = 15; i > 0; i--)
            {
                msg[i] = msg[i - 1];
            }

            msg[0] = temp;

            clcd_print(msg, LINE2(0));

            for (unsigned int j = 50000; j--;); /* delay */
        }
    }

    return;
}
