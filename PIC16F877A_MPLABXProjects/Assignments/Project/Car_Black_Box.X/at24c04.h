#include "main.h"

#ifndef AT24C04_H
#define	AT24C04_H

#define SLAVE_READ_EE               0xA1
#define SLAVE_WRITE_EE              0xA0
//#define _XTAL_FREQ                  20000000

unsigned char eeprom_at24c04_random_read(unsigned char memory_loc);
void eeprom_at24c04_byte_write(unsigned char memory_loc, unsigned char data);
void eeprom_at24c04_str_write(unsigned char memory_loc, char *data);

#endif	/* AT24C04_H */