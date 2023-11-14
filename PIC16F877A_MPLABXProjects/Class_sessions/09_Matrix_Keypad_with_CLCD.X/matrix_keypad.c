#include <xc.h>
#include "matrix_keypad.h"

void init_matrix_keypad(void)
{
    /* Setting the Columns as Inputs (RB2 - RB0)*/
    //TRISB = TRISB | 0x07
    MATRIX_KEYPAD_COLUMN_PORT_DDR = MATRIX_KEYPAD_COLUMN_PORT_DDR | 0x07;  
   
    
    /* Setting the Rows as Output (RD3 - RD0)*/
    MATRIX_KEYPAD_ROW_PORT_DDR = MATRIX_KEYPAD_ROW_PORT_DDR & 0xF0; // TRISD = TRISD & 0xF0 -> (TRISD0 to TRISD3)
    
    /* Enabling PORTB Pullups */
    nRBPU = 0;
    
    /* Making all the Rows HIGH to start with */
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;
}

static unsigned char scan_keypad(void)
{
    int i;
    
    ROW1 = LOW;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = HI;   
    
    for (i = 100; i--; );
    
    if (COL1 == LOW)
    {
        return 1;
    }
    else if (COL2 == LOW)
    {
        return 2;
    }
    else if (COL3 == LOW)
    {
        return 3;
    }
    
    ROW1 = HI;
    ROW2 = LOW;
    ROW3 = HI;
    ROW4 = HI;   
    
    for (i = 100; i--; );
    
    if (COL1 == LOW)
    {
        return 4;
    }
    else if (COL2 == LOW)
    {
        return 5;
    }
    else if (COL3 == LOW)
    {
        return 6;
    }
    
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = LOW;
    ROW4 = HI;   

    for (i = 100; i--; );
    
    if (COL1 == LOW)
    {
        return 7;
    }
    else if (COL2 == LOW)
    {
        return 8;
    }
    else if (COL3 == LOW)
    {
        return 9;
    }
    
    ROW1 = HI;
    ROW2 = HI;
    ROW3 = HI;
    ROW4 = LOW;   

    for (i = 100; i--; );
    
    if (COL1 == LOW)
    {
        return '*';
    }
    else if (COL2 == LOW)
    {
        return 0;
    }
    else if (COL3 == LOW)
    {
        return '#';
    }
    
    return ALL_RELEASED;
}

unsigned char read_matrix_keypad(unsigned char mode)
{
    static unsigned char once = 1;
    unsigned char key;
    
    key = scan_keypad(); // 0 1 2 3 4 5 6 7 8 9 '*' '#'  ALL_RELEASED
    
    if (mode == LEVEL)
    {
        return key;
    }
    else
    {
        if ((key != ALL_RELEASED) && once)
        {
            once = 0;
             return key;
        }
           
        else if (key == ALL_RELEASED)
        {
            once = 1;
        }
    }
    
    return ALL_RELEASED;
}
