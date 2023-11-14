/*
 * File:   car_black_box.c
 * Author: Harsharaj Nath
 * Date : 20-10-2022
 * Project : Car Black Box 
 */


#include "main.h"

/* global variables */
extern unsigned int sec;
unsigned char clock_reg[3]; /* HH MM SS */
unsigned char time[7];
unsigned char log[11];
unsigned char return_time = 5;
char *menu[] = {"View log", "Clear log", "Download log", "Change passwrd", "Set time"};
int pos = -1;
int event_count = -1;


/*########################################################################################################################*/

/* function to get time from the rtc, stored as character
 * function called inside display_time() */
static void get_time()
{
    /*get hour value  from ds1037 and assigned clock reg[0] */
    clock_reg[0] = read_ds1307(HOUR_ADDR); // HH -> BCD 

    /*get minute value  from ds1037 and assigned clock reg[1] */
    clock_reg[1] = read_ds1307(MIN_ADDR); // MM -> BCD 

    /*get second value  from ds1037 and assigned clock reg[2] */
    clock_reg[2] = read_ds1307(SEC_ADDR); // SS -> BCD 

    /* storing the hours value in time array -> HH */
    time[0] = ((clock_reg[0] >> 4) & 0x03) + '0';
    time[1] = (clock_reg[0] & 0x0F) + '0';

    /* storing the hours value in time array -> MM */
    time[2] = ((clock_reg[1] >> 4) & 0x07) + '0';
    time[3] = (clock_reg[1] & 0x0F) + '0';

    /* storing the hours value in time array -> SS */
    time[4] = ((clock_reg[2] >> 4) & 0x07) + '0';
    time[5] = (clock_reg[2] & 0x0F) + '0';
    time[6] = '\0';
}


/*########################################################################################################################*/

/* function to display the time on clcd */
void display_time(void)
{
    get_time(); /* get the time */

    /* Displaying the time in HH:MM:SS format */

    /* To display the time in HH format */
    clcd_putch(time[0], LINE2(2));
    clcd_putch(time[1], LINE2(3));
    clcd_putch(':', LINE2(4));

    /* To display the time in MM format */
    clcd_putch(time[2], LINE2(5));
    clcd_putch(time[3], LINE2(6));
    clcd_putch(':', LINE2(7));

    /* To display  the time in SS format */
    clcd_putch(time[4], LINE2(8));
    clcd_putch(time[5], LINE2(9));
}


/*########################################################################################################################*/

/* function to display the dashboard screen */
void display_dashboard(unsigned char event[], unsigned char speed)
{
    clcd_print("  TIME     E  SP", LINE1(0));

    /* display time */
    display_time();

    /* display event */
    clcd_print(event, LINE2(11));

    /* display speed */
    clcd_putch(speed / 10 + '0', LINE2(14));
    clcd_putch(speed % 10 + '0', LINE2(15));
}


/*########################################################################################################################*/

/* function to write log to ext. eeprom 
 * function called inside log_car_event() */
void log_event(void)
{
    char addr = 0x05;
    pos++; /* 0 */
    if (pos == 10)
    {
        pos = 0;
    }
    addr = pos * 10 + 5; /* 5 -> 191545ON00
                          * address is updated to every 10th address starting from 0x05 */

    eeprom_at24c04_str_write(addr, log); /* writing to ext. eeprom */

    if (event_count < 9)
    {
        event_count++;
    }
}


/*########################################################################################################################*/

/* function for collection all log and writing to ext. eeprom */
void log_car_event(char event[], unsigned char speed)
{
    /* HHMMSSEVSP */
    get_time();

    strncpy(log, time, 6); /* HHMMSS */
    strncpy(&log[6], event, 2); /* EV */

    log[8] = (speed / 10) + '0'; /* 1st digit of speed */
    log[9] = (speed % 10) + '0'; /* 1st digit of speed */
    log[10] = '\0';

    log_event(); /* log[] = 191545ON00 */
}


/*########################################################################################################################*/

/* function to clear the screen */
void clear_screen(void)
{
    /*clear screen and wait for 500 us */
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}


/*########################################################################################################################*/

/* function for login screen */
unsigned char login(unsigned char key, unsigned char reset_flag)
{
    static char npassword[4]; /*to store new password  */
    char spassword[4]; /*to store system password  */
    static char i;
    static unsigned char attempts_rem = 3;


    if (reset_flag == RESET_PASSWORD) /* reset the user entered password */
    {
        attempts_rem = 3; /* giving fresh 3 attempts */

        /* storing password with null */
        npassword[0] = '\0';
        npassword[1] = '\0';
        npassword[2] = '\0';
        npassword[3] = '\0';

        i = 0;
        key = 0xFF; /* updating key value with some value other than SW1-SW6 */
        return_time = 5; /* waiting 5 sec for each password character entry */
    }

    /*____________________________________________________________________*/

    if (return_time == 0)
    {
        return RETURN_BACK; /* return back to dashboard */
    }

    /*____________________________________________________________________*/

    /* entering the password
     * SW4 = 1
     * SW5 = 0
     */

    __delay_ms(50);

    if (key == SW4 && i < 4) /*storing new password as 1*/
    {
        npassword[i] = '1';
        clcd_putch('*', LINE2(6 + i)); // display star(*)
        i++;
        return_time = 5;
    }
    else if (key == SW5 && i < 4) /* storing new password as 0*/
    {
        npassword[i] = '0';
        clcd_putch('*', LINE2(6 + i)); // display star(*)
        i++;
        return_time = 5;
    }

    /*____________________________________________________________________*/

    if (i == 4) /* done entering the password */
    {
        /* read the system password */
        for (int j = 0; j < 4; j++)
        {
            spassword[j] = eeprom_at24c04_random_read(j);
        }

        /* comparing the password with the system password */
        if (strncmp(spassword, npassword, 4) == 0)
        {
            return LOGIN_SUCCESS; /* go to login menu screen */
        }
        else
        {
            attempts_rem--; /* reducing the remaining attempts */

            if (attempts_rem == 0) /* when no attempts remain */
            {
                sec = 900; /*lock user for 15 mins --> 60 x 15 = 900 */

                clear_screen();
                clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
                __delay_us(100);
                clcd_print("You Are  Blocked", LINE1(0));
                clcd_print("Wait for...15min", LINE2(0));

                while (sec) /* printing the countdown */
                {
                    /* printing the mins */
                    clcd_putch(((sec / 60) / 10) + '0', LINE2(11));
                    clcd_putch(((sec / 60) % 10) + '0', LINE2(12));
                }
                attempts_rem = 3; /* giving fresh 3 attempts again */
            }
            else /* giving another attempt */
            {

                clear_screen();
                clcd_print(" Wrong Password ", LINE1(0));
                clcd_putch(attempts_rem + '0', LINE2(0));
                clcd_print(" Attempt Remain", LINE2(1));
                __delay_ms(4000);
            }

            /* if no key is pressed for 5 sec */
            clear_screen();
            clcd_print(" Enter Password ", LINE1(0));
            i = 0;
            return_time = 5;
            clcd_write(CURSOR_POS, INST_MODE);
            clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
            __delay_us(100);
        }
    }

    return 0xFF;
}


/*########################################################################################################################*/

/* function for login menu screen */
unsigned char login_menu(unsigned char key, unsigned char reset_flag)
{
    static char menu_pos;

    /*____________________________________________________________________*/

    if (return_time == 0)
    {
        return RETURN_BACK; /* return back to dashboard */
    }

    /*____________________________________________________________________*/

    if (reset_flag == RESET_MENU) /* default login menu screen position */
    {
        return_time = 15;
        menu_pos = 0;
        clear_screen();
    }

    /*____________________________________________________________________*/

    if (key == SW4 && menu_pos > 0) /* scrolling up */
    {
        return_time = 15;
        menu_pos--;
        clear_screen();
    }

    else if (key == SW5 && menu_pos <= 3)/* scrolling down */
    {
        return_time = 15;
        menu_pos++;
        clear_screen();
    }

    /*____________________________________________________________________*/

    /* displaying the star(*) in front of the menu options */

    if (menu_pos < 4)
    {
        clcd_putch('*', LINE1(0));
        clcd_print(menu[menu_pos], LINE1(2));
        clcd_print(menu[menu_pos + 1], LINE2(2));
    }

    else if (menu_pos == 4)
    {

        clcd_print(menu[menu_pos - 1], LINE1(2));
        clcd_print(menu[menu_pos], LINE2(2));
        clcd_putch('*', LINE2(0));
    }

    return menu_pos;
}


/*########################################################################################################################*/

/* function for viewing the logs */
void view_log(unsigned char key, char reset_index)
{
    static int index;
    char log[11];
    log[10] = 0;
    int position;
    unsigned char add;

    /*____________________________________________________________________*/

    if (event_count == -1) /* if no logs available */
    {
        clcd_print("                ", LINE1(0));
        clcd_print("    No logs     ", LINE2(0));
    }
    else
    {
        if (reset_index == RESET_VIEW_LOG_POS)
        {
            index = 0;
        }

        /*____________________________________________________________________*/

        if (key == SW4 && index < event_count) /* SW4 for moving upward */
        {
            index++; /*increment in position */
            clcd_print("                ", LINE2(0));
        }
        else if (key == SW5 && index > 0) /* SW5 for moving downward */
        {
            index--; /*decrement  in position */
            clcd_print("                ", LINE2(0));
        }

        /*____________________________________________________________________*/

        position = index;

        /*____________________________________________________________________*/

        /*reading recent 10 event from external eeprom */
        for (int i = 0; i < 10; i++)
        {

            add = position * 10 + 5 + i; /* updating the address */
            log[i] = eeprom_at24c04_random_read(add); /*reading the data */
        }

        /*____________________________________________________________________*/
        /*printing logs on clcd */

        /* displaying index */
        clcd_putch(index + '0', LINE2(0));

        /*displaying hours value */
        clcd_putch(log[0], LINE2(2));
        clcd_putch(log[1], LINE2(3));
        clcd_putch(':', LINE2(4));

        /*displaying minutes  value */
        clcd_putch(log[2], LINE2(5));
        clcd_putch(log[3], LINE2(6));
        clcd_putch(':', LINE2(7));

        /*displaying seconds  value */
        clcd_putch(log[4], LINE2(8));
        clcd_putch(log[5], LINE2(9));

        /*displaying event character */
        clcd_putch(log[6], LINE2(11));
        clcd_putch(log[7], LINE2(12));

        /*displaying speed value */
        clcd_putch(log[8], LINE2(14));
        clcd_putch(log[9], LINE2(15));

        __delay_us(500);
    }
}


/*########################################################################################################################*/

/* function for clearing the logs */
char clear_log(char reset_memory)
{
    clcd_print("Logs cleared", LINE1(2));
    clcd_print("successfully", LINE2(2));

    /*clearing all the logs*/
    if (reset_memory == RESET_MEMORY)
    {
        /* updating the flags */
        pos = -1;
        event_count = -1;

        return TASK_SUCCESS;
    }

    return TASK_FAILURE;
}


/*########################################################################################################################*/

/* function for downloading the logs */
void download_log(void)
{
    int index = -1;
    char log[11];
    log[10] = 0;
    int position = 0;
    unsigned char add;

    if (event_count == -1) /* if no logs available */
    {
        puts("No logs available");
    }
    else /* displaying all logs available */
    {
        puts("Logs :");
        putchar('\n');
        puts("#     Time        Event       Speed");
        putchar('\n');
        putchar('\r');

        while (index < event_count)
        {
            position = index + 1;
            index++; /*incrementing to next log */

            for (int i = 0; i < 10; i++)
            {

                add = position * 10 + 5 + i; /* updating the address with that of event data */
                log[i] = eeprom_at24c04_random_read(add); /* reading the event data */
            }

            /* printing all logs in cutecom */

            /* printing index */
            putchar(index + '0');
            puts("   ");

            /*printing hours value */
            putchar(log[0]);
            putchar(log[1]);
            putchar(':');

            /*printing minute  value */
            putchar(log[2]);
            putchar(log[3]);
            putchar(':');

            /*printing second  value */
            putchar(log[4]);
            putchar(log[5]);
            puts("      ");

            /*printing event  character  */
            putchar(log[6]);
            putchar(log[7]);
            puts("            ");

            /*printing speed value */
            putchar(log[8]);
            putchar(log[9]);
            putchar('\n');
            putchar('\r');
        }
    }
}


/*########################################################################################################################*/

/* function for changing the password */
char change_password(unsigned char key, char reset_pwd)
{
    static char new_pwd[9];
    static int pwd_pos = 0;
    static char pwd_changed = 0;
    static unsigned char toggle_cursor = 0;
    static unsigned int blink_delay = 0;

    /*____________________________________________________________________*/
    /* for cursor blinking */
    if (blink_delay++ == 5)
    {
        blink_delay = 0;
        toggle_cursor = !toggle_cursor;
    }

    /*____________________________________________________________________*/

    /*checking reset flag and rest change password */
    if (reset_pwd == RESET_PASSWORD)
    {
        strncpy(new_pwd, "    ", 4);
        pwd_pos = 0;
        pwd_changed = 0;
        return_time = 5;
    }

    /*____________________________________________________________________*/

    if (!return_time)
        return RETURN_BACK;

    /*____________________________________________________________________*/

    if (pwd_changed)
        return TASK_FAILURE;

    /*____________________________________________________________________*/

    if (pwd_pos < 4)
    {
        clcd_print("Enter new pwd:  ", LINE1(0));

        /* blinking the cursor */
        if (toggle_cursor == 0)
        {
            clcd_putch((unsigned char) 0xFF, LINE2(pwd_pos));
        }
        else
        {
            clcd_putch(' ', LINE2(pwd_pos));
        }
    }
    else if (pwd_pos > 3 && pwd_pos < 8)
    {
        clcd_print("Re-enter new pwd", LINE1(0));

        /* blinking the cursor */
        if (toggle_cursor == 0)
        {
            clcd_putch((unsigned char) 0xFF, LINE2(pwd_pos));
        }
        else
        {
            clcd_putch(' ', LINE2(pwd_pos));
        }
    }

    /*____________________________________________________________________*/

    switch (key)
    {
        case SW5: /* storing new password as 0*/
            new_pwd[pwd_pos] = '0';
            clcd_putch('*', LINE2(pwd_pos));
            pwd_pos++;
            return_time = 5;
            if (pwd_pos == 4)
                clcd_print("                 ", LINE2(0));
            break;

        case SW4: /* storing new password as 1 */
            new_pwd[pwd_pos] = '1';
            clcd_putch('*', LINE2(pwd_pos));
            pwd_pos++;
            return_time = 5;
            if (pwd_pos == 4)
                clcd_print("                 ", LINE2(0));
            break;
    }

    /*____________________________________________________________________*/

    if (pwd_pos == 8)
    {
        if (strncmp(new_pwd, &new_pwd[4], 4) == 0) /* if both entered password matched */
        {
            /* successfully changing password */
            new_pwd[8] = 0;
            eeprom_at24c04_str_write(0x00, &new_pwd[4]); /* storing new password */
            pwd_pos++;
            clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
            clcd_print("Password changed", LINE1(0));
            clcd_print("successfully ", LINE2(2));
            pwd_changed = 1;
            __delay_ms(1000);
            return TASK_SUCCESS;
        }
        else
        {
            /* displaying password change fail */
            clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
            clcd_print("Password  change", LINE1(0));
            clcd_print("failed", LINE2(5));
            pwd_changed = 1;
            __delay_ms(1000);

            return TASK_SUCCESS;
        }
    }

    return TASK_FAILURE;
}


/*########################################################################################################################*/

/* function for changing the time */
char change_time(unsigned char key, unsigned char reset_time)
{
    static unsigned int new_time[3];
    static unsigned int blink_pos;
    static unsigned char wait;
    static unsigned char blink;
    static char t_done = 0;
    char buffer;

    /*____________________________________________________________________*/

    if (reset_time == RESET_TIME)
    {
        get_time(); /* get the time */

        /*Storing values of new time hours */
        new_time[0] = (time[0] & 0x0F) * 10 + (time[1] & 0x0F);

        /*Storing values of new time minute*/
        new_time[1] = (time[2] & 0x0F) * 10 + (time[3] & 0x0F);

        /*Storing values of new time second */
        new_time[2] = (time[4] & 0x0F) * 10 + (time[5] & 0x0F);

        clcd_print("Time (HH:MM:SS)", LINE1(0));

        /* updating the flags */
        blink_pos = 2;
        wait = 0;
        blink = 0;
        t_done = 0;
        key = ALL_RELEASED;
    }

    /*____________________________________________________________________*/

    if (t_done)
        return TASK_FAILURE;

    /*____________________________________________________________________*/

    switch (key)
    {
        case SW4: /* incrementing the value */
            new_time[blink_pos]++;
            break;

        case SW5: /* changing the field */
            blink_pos = (blink_pos + 1) % 3;
            break;

        case SW4_LP: /* storing the new time */

            get_time(); /* get the time */

            buffer = ((new_time[0] / 10) << 4) | new_time[0] % 10; /*set time fetching from rtc */
            clock_reg[0] = (clock_reg[0] & 0xC0) | buffer; /*assigned fetched time to clock register */
            write_ds1307(HOUR_ADDR, clock_reg[0]); /*storing time in ds1307 */


            buffer = ((new_time[1] / 10) << 4) | new_time[1] % 10; /*set time fetching from rtc */
            clock_reg[1] = (clock_reg[1] & 0x80) | buffer; /*assigned fetched time to clock register */
            write_ds1307(MIN_ADDR, clock_reg[1]); /*storing time in ds1307 */


            buffer = ((new_time[2] / 10) << 4) | new_time[2] % 10; /*set time fetching from rtc */
            clock_reg[2] = (clock_reg[2] & 0x80) | buffer; /*assigned fetched time to clock register */
            write_ds1307(SEC_ADDR, clock_reg[2]); /*storing time in ds1307 */


            clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
            clcd_print("Time changed", LINE1(2));
            clcd_print("Successfully", LINE2(2));

            t_done = 1;
            __delay_ms(1000);
            return TASK_SUCCESS;
    }

    /*____________________________________________________________________*/

    /* conditions for roll over */
    if (new_time[0] > 23)
        new_time[0] = 0;
    if (new_time[1] > 59)
        new_time[1] = 0;
    if (new_time[2] > 59)
        new_time[2] = 0;

    /*____________________________________________________________________*/

    if (wait++ == 1)
    {
        wait = 0;
        blink = !blink;

        /*logic to blink at the current pos*/
        if (blink)
        {
            switch (blink_pos)
            {
                case 0:
                    clcd_print("  ", LINE2(0));
                    __delay_ms(160);
                    break;
                case 1:
                    clcd_print("  ", LINE2(3));
                    __delay_ms(160);
                    break;
                case 2:
                    clcd_print("  ", LINE2(6));
                    __delay_ms(160);
                    break;
            }
        }
    }

    /*____________________________________________________________________*/

    /* Displaying hours field */
    clcd_putch(new_time[0] / 10 + '0', LINE2(0));
    clcd_putch(new_time[0] % 10 + '0', LINE2(1));
    clcd_putch(':', LINE2(2));

    /* Displaying mins field */
    clcd_putch(new_time[1] / 10 + '0', LINE2(3));
    clcd_putch(new_time[1] % 10 + '0', LINE2(4));
    clcd_putch(':', LINE2(5));

    /* Displaying secs field */
    clcd_putch(new_time[2] / 10 + '0', LINE2(6));
    clcd_putch(new_time[2] % 10 + '0', LINE2(7));

    return TASK_FAILURE;
}