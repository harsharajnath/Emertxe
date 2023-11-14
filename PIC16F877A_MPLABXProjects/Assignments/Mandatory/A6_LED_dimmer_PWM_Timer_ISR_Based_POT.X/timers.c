#include <xc.h>

void init_timer0(void) /* Timer0 Module */
{
    T0CS = 0; /* Setting the internal clock source */

    PSA = 1; /* Assigning the prescaler to Watchdog Timer */

    TMR0IE = 1; /* The timer interrupt is enabled */
}