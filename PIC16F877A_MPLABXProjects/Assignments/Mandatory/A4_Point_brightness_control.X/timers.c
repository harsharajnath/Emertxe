#include <xc.h>

void init_timer0(void) /* Timer0 Module */
{
    T0CS = 0; /* Setting the internal clock source */

    PSA = 1; /* Assigning the prescaler to Watchdog Timer */
    
    TMR0 = 6; /* Preloading TMR0 with 256 - 250 = 6 */

    TMR0IE = 1; /* The timer interrupt is enabled */
}