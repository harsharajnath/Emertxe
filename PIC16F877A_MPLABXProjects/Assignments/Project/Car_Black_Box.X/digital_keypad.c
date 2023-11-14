#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad()
{
    static char once;
    static int long_pressed;
    static unsigned char pre_key;
    unsigned char key = KEYPAD_PORT & INPUT_LINES;


    if (key != ALL_RELEASED && once == 0) /* when any key is pressed */
    {
        once = 1; /* set the flag indicating a key is pressed for the 1st time */
        long_pressed = 0; /* rest the flag */
        pre_key = key; /* storing the key in another variable */
    }
    else if (key == ALL_RELEASED && once == 1) /* when that key is released */
    {
        once = 0; /* reset the flag */

        if (long_pressed < 15) /* if key is pressed less than the given value */
        {
            return pre_key; /* return the previous key value */
        }
    }

    /*________________________________________________________________________*/

    if (once == 1 && long_pressed < 16)
    {
        long_pressed++;
    }

    else if (once == 1 && long_pressed == 16 && key == SW4)
    {
        long_pressed++;
        return SW4_LP;
    }

    else if (once == 1 && long_pressed == 16 && key == SW5)
    {
        long_pressed++;
        return SW5_LP;
    }

    return ALL_RELEASED;
}