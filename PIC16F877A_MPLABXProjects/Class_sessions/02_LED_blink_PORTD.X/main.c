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

/*void main(void) //main function
{
    init_config();
    unsigned int wait;      //  --> int is 2 Bytes --> 16 bits --> 0 to 65535
    while (1) //Write application code here 
    {
        LED_ARRAY = 0xFF;       //Turn ON all LEDs of PORTD
        for(wait = 50000; wait > 0; wait--);
        
        LED_ARRAY = 0x00;       //Turn OFF all LEDs of PORTD
        for(wait = 50000; wait > 0; wait--);
    }
}*/


/*void main(void) //main function
{
    init_config();
    unsigned long int wait;      //  --> uinsigned long int is 4 Bytes --> 32 bits
    while (1) //Write application code here 
    {
        LED_ARRAY = 0xFF;       //Turn ON all LEDs of PORTD
        for(wait = 100000; wait > 0; wait--);
        
        LED_ARRAY = 0x00;       //Turn OFF all LEDs of PORTD
        for(wait = 100000; wait > 0; wait--);
    }
}*/


/*void main(void) //main function
{
    init_config();
    unsigned long int wait;      //  --> uinsigned long int is 4 Bytes --> 32 bits
    while (1) //Write application code here 
    {
        LED_ARRAY = ~LED_ARRAY;       //Toggle all LEDs of PORTD
        for(wait = 100000; wait > 0; wait--);                                   //REMEMBER: for loop is BLOCKING DELAY
    }
}*/


/*void main(void) //main function
{
    init_config();
    unsigned long int wait;      //  --> uinsigned long int is 4 Bytes --> 32 bits
    while (1) //Write application code here 
    {
        LED_ARRAY = ~LED_ARRAY;       //Toggle all LEDs of PORTD
        for(wait = 100000; wait--; );                                           //for loop is written like this in embedded programming
    }
}*/


void main(void) //main function
{
    init_config();
    unsigned long int wait = 0;      //  --> uinsigned long int is 4 Bytes --> 32 bits
    while (1) //Write application code here 
    {
        if(wait-- == 0)                                                         //This is NON-BLOCKING DELAY     
        {
            LED_ARRAY = ~LED_ARRAY;       //Toggle all LEDs of PORTD
            wait = 100000;
        }
    }
}