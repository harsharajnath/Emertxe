#include <xc.h>
#include "digital_keypad.h"

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad(unsigned char mode) /* function to read key */
{
    static unsigned char once = 1;

    if (mode == LEVEL_DETECTION) /* for Level Trigger */
    {
        return KEYPAD_PORT & INPUT_LINES;
    }
    else /* for Edge Trigger / State Change */
    {
        if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;

            return KEYPAD_PORT & INPUT_LINES;
        }
        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)
        {
            once = 1;
        }
    }
    return ALL_RELEASED;
}