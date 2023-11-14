/*
 * File:   main.c
 * Author: ASUS
 *
 * Created on 18 August, 2022, 12:58 PM
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE = OFF   //Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) //Write your initialization code here
{
    LED_ARRAY_DDR = 0x00;       //Setting PORTB as output port
    LED_ARRAY = 0x00;       //Keep all LEDs OFF
}

void main(void) //main function
{
    init_config();
    while (1) //Write application code here 
    {
        LED_ARRAY = 0xFF;       //Turn ON all LEDs of PORTB
    }
}
