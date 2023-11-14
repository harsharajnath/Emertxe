#include <xc.h>

void init_ext_int(void)
{
    /* Selecting Falling Edge Trigger */
    INTEDG = 0;
    /* Enable the External Interrupt */
    INTE = 1;
}