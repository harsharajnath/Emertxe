#include "i2c.h"
#include"eeprom_ext.h"

unsigned char eeprom_ext_read(unsigned int addr)
{
    unsigned char ret;
    unsigned char ah;
    unsigned char al;

    ah = (addr & 0x0100) >> 8;
    al = addr & 0x00FF;

    i2c_start();
    if (ah)
    {
        i2c_write(0xA2);
    }
    else
    {
        i2c_write(0xA0);
    }
    i2c_write(al);

    i2c_start();
    if (ah)
    {
        i2c_write(0xA3);
    }
    else
    {
        i2c_write(0xA1);
    }
    ret = i2c_read(1);
    i2c_stop();

    return ret;
}

void eeprom_ext_write(unsigned int addr, unsigned char val)
{
    unsigned int tmp;
    unsigned char ah;
    unsigned char al;
    unsigned char nt;

    tmp = val;
    ah = (addr & 0x0100) >> 8;
    al = addr & 0x00FF;
    nt = 0;

    do
    {
        i2c_start();
        if (ah)
        {
            i2c_write(0xA2);
        }
        else
        {
            i2c_write(0xA0);
        }
        i2c_write(al);
        i2c_write((unsigned char) tmp);
        i2c_stop();

        nt++;
    } while ((tmp != eeprom_ext_read(addr))&&(nt < 10));
}