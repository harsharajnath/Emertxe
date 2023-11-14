/*
 * Name: Harsharaj Nath
 * Date of Submission: 00-00-22
 * Description: 


#########################################_Program_begins_from_here_######################################### */

#include <xc.h>
#include "clcd.h"

/* Watchdog Timer Enable bit (WDT disabled) */
#pragma config WDTE = OFF

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 *              configuration, like setting port directions, initializing port values
 */
static void init_config(void)
{
    init_clcd();
}

void cursor_on(unsigned char cursor_pos)
{
    static unsigned char cursor_flag = 1;

    if (cursor_flag == 1)
    {
        clcd_write(cursor_pos, INST_MODE);
        __delay_us(100);

        clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
        __delay_us(100);

        cursor_flag = 0;
    }
}

void cursor_off(void)
{
    clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
    __delay_us(100);
}

void print_msg(void)
{
    static unsigned char print_flag = 1;

    if (print_flag == 1)
    {
        clcd_print("PRINT HERE", LINE1(0));
        print_flag = 0;
    }
}

void main(void)
{
    //unsigned char cursor_flag = 1;

    init_config(); /* function call */



    while (1) /*super loop */
    {
        print_msg();
        cursor_on(LINE1(4));
        
        //cursor_off();
    }

    return;
}