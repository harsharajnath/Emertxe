/* 
 * File:   adc.h
 */

#ifndef ADC_H
#define	ADC_H

#define CHANNEL2        0x02 //0b010
void init_adc(void);
unsigned short read_adc(unsigned char channel);

#endif	/* ADC_H */