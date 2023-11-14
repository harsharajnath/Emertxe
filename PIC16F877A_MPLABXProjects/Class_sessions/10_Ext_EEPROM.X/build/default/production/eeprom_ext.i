# 1 "eeprom_ext.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.35/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "eeprom_ext.c" 2
# 1 "./i2c.h" 1
# 10 "./i2c.h"
void init_i2c(unsigned long baud);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
unsigned char i2c_read(unsigned char ack);
int i2c_write(unsigned char data);
# 1 "eeprom_ext.c" 2

# 1 "./eeprom_ext.h" 1



unsigned char eeprom_ext_read(unsigned int addr);
void eeprom_ext_write(unsigned int addr, unsigned char val);
# 2 "eeprom_ext.c" 2


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
