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
    LED_ARRAY_DDR = 0x00;       //Setting PORTD as output port
    LED_ARRAY = 0x00;       //Keep all LEDs OFF
}
/*
void main(void) //main function
{
    unsigned long int wait = 0;
    unsigned char i;
    init_config();

    while (1) //Write application code here 
    {                                                                           //Using BLOCKING LOOP
        for( i = 0; i < 8; i++)
        {
            LED_ARRAY = (LED_ARRAY << 1) | 0x01;
            for(wait = 100000; wait--; );
        }
        
        if(LED_ARRAY == 0xFF)
        {
            LED_ARRAY = 0x00;
            for(wait = 100000; wait--; );
        }
    }
}
*/

void main(void) //main function
{
    init_config();
    unsigned long int wait = 0;
    unsigned char i = 0;
    while (1) //Write application code here
    {                                                                           //Using NON-BLOCKING LOOP
        if(wait-- == 0)
        {
            if( i++ != 8)
            {
                LED_ARRAY = (unsigned char)((LED_ARRAY << 1) | 0x01);
            }
            else
            {
                LED_ARRAY = 0x00;
                i = 0;
            }         
            wait = 100000;
        }         
    }
}