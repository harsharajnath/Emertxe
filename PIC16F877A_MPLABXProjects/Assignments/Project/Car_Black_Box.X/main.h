/* 
 * File:   main.h
 * Author: ASUS
 *
 * Created on 6 October, 2022, 6:22 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include <string.h>
#include "clcd.h"
#include "adc.h"
#include "ds1307.h"
#include "i2c.h"
#include "car_black_box.h"
#include "digital_keypad.h"
#include "at24c04.h"
#include "timers.h"
#include "uart.h"

#define DASHBOARD_FLAG          0x01    /* when in dashboard screen */
#define LOGIN_FLAG              0x02    /* when in login screen */
#define LOGIN_MENU_FLAG         0x03    /* when in login menu screen */
#define VIEW_LOG_FLAG           0x08    /* when in view log screen */
#define CLEAR_LOG_FLAG          0x09    /* when in clear log screen */
#define DOWNLOAD_LOG_FLAG       0x10    /* when in download log screen */
#define CHANGE_PASSWORD_FLAG 	0x11    /* when in change password screen */
#define SET_TIME_FLAG	 		0x12    /* when in set time screen */



#define RESET_DOWNLOAD_LOG      0x10    /* reset the download log */
#define RESET_VIEW_LOG_POS      0x20    /* reset the view log */
#define RESET_TIME				0x30    /* reset the time */
#define RESET_MEMORY            0x40    /* reset the memory */
#define RESET_LOGIN_MENU        0x50    /* reset to login menu */
#define RESET_PASSWORD          0x60    /* reset the user entered password */
#define RESET_MENU              0x70    /* default position of login menu screen */
#define RESET_NOTHING           0x80



#define RETURN_BACK             0x0A    /* login failed, return back to dashboard */
#define LOGIN_SUCCESS           0x0B    /* password matched , login successful */
#define TASK_SUCCESS            0x0C    /* when task successful */
#define TASK_FAILURE            0x0D    /* when task failed */

#endif	/* MAIN_H */