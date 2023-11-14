/*
 * Name: Harsharaj Nath
 * Date of Submission: 23-09-22
 * Description: Implementation of a temperature sensor node with CLCD display


#########################################_Program_begins_from_here_######################################### */


#include <xc.h>
#include "clcd.h"
#include "adc.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

void display(unsigned short data) /* displaying in CLCD */
{
    char buff[3];
    int i = 1;
    do
    {
        buff[i] = (data % 10) + '0'; /* 1st iteration: 27 % 10 -> 7 + '0' = '7' 
                                        2nd iteration: 2 % 10 -> 2 + '0' = '2'
                                      */
        data = data / 10; /* data = 2 */

    } while (i--);

    buff[2] = '\0'; /* adding null at the end */

    clcd_print("TEMPRATURE: ", LINE2(0));
    clcd_print(buff, LINE2(12));
    clcd_putch(0xDF, LINE2(14));
    clcd_putch('C', LINE2(15));
}

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd(); /* initializing clcd */
    init_adc(); /* initializing adc */
}

void main(void)
{
    unsigned short analog_value; //0 to 1023
    unsigned short temperature;

    init_config(); /* function call */

    clcd_print("LM35 TEMP SENSOR", LINE1(0));
    
    while (1) /*super loop */
    {
        analog_value = read_adc(CHANNEL2); //10 bits -> 0 to 1023

        /* 
         * Voltage = ADC register value x Step Size
                   = ADC register value x 4.88 mV
         * 
         * LM35 -> 10 mV/degC
         * 
         * Temperature = Voltage (mV) / 10
         * 
         */

        temperature = (unsigned short) ((analog_value * 4.8828125) / 10);

        display(temperature);
    }

    return;
}