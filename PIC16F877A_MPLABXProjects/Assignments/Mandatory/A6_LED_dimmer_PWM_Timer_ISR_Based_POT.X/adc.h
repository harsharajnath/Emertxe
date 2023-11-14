/* 
 * File:   adc.h
 */

#ifndef ADC_H
#define	ADC_H

#define CHANNEL0        0x00 //0b000
void init_adc(void);
unsigned short read_adc(unsigned char channel);

#endif	/* ADC_H */