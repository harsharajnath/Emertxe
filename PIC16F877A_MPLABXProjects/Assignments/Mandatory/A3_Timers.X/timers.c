#include <xc.h>

void init_timer0(void) /* Timer0 Module */
{
    T0CS = 0; /* Setting the internal clock source */

    PSA = 1; /* Assigning the prescaler to Watchdog Timer */

    TMR0 = 6; /* Preloading TMR0 with 256 - 250 = 6 */

    TMR0IE = 1; /* The timer interrupt is enabled */
}

void init_timer1(void) /* Timer1 Module */
{
    T1OSCEN = 1; /* Timer1 Oscillator Enable Control bit */

    TMR1CS = 0; /* Timer1 Clock Source Select bit */

    TMR1ON = 1; /* Timer1 On bit */

    TMR1IE = 1; /* Timer1 Interrupt Enable */

    /* 16 Bit -> 0 - 65535
     * 65536 - 250 = 65286 = 0xFF06
     * MSB = 0xFF
     * LSB = 0x06
     */

    TMR1H = 0xFF;

    TMR1L = 0x06;
}

void init_timer2(void) /* Timer2 Module */
{
    T2CKPS0 = 0; /* Selecting the scale as 1:1 */
    T2CKPS1 = 0;

    PR2 = 250; /* Loading the Pre Load register with 250 */

    TMR2IE = 1; /* The timer interrupt is enabled */

    TMR2ON = 1; /* Switching on the Timer2 */
}