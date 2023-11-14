#include <xc.h>
#include "i2c.h"
#include "at24c04.h"

unsigned char eeprom_at24c04_random_read(unsigned char memory_loc)
{
    unsigned char received_data = 0;

    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(memory_loc);
    i2c_rep_start();
    i2c_write(SLAVE_READ_EE);
    received_data = i2c_read(0);
    i2c_stop();

    return received_data;
}

void eeprom_at24c04_byte_write(unsigned char memory_loc, unsigned char data)
{
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(memory_loc);
    i2c_write(data);
    i2c_stop();

    __delay_ms(3);
}

void eeprom_at24c04_str_write(unsigned char memory_loc, char *data)
{
    while (*data != 0)
    {
        eeprom_at24c04_byte_write(memory_loc, *data);
        data++;
        memory_loc++;
    }
}