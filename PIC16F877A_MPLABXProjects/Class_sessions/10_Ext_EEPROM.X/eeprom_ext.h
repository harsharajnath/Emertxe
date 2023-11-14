#ifndef EEPROM_EXT_H
#define	EEPROM_EXT_H

unsigned char eeprom_ext_read(unsigned int addr);
void eeprom_ext_write(unsigned int addr, unsigned char val);

#endif	/* EEPROM_EXT_H */