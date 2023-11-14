#include <xc.h>

void init_adc(void)
{
    /* Selecting Right Justification */
    ADFM = 1;
    
    /* Starting the ADC Module */
    ADON = 1;
}

unsigned short read_adc(unsigned char channel)
{
    unsigned short adc_reg_val;
    
    /* Selecting the required channel */
    ADCON0 = (ADCON0 & 0xC7) | (channel << 3);
    
    /* Start the ADC conversion */
    GO = 1;
    /* Wait for the conversion to complete */
    while (nDONE);
    
    adc_reg_val = (ADRESH << 8) | ADRESL; // 10bits
    
    return adc_reg_val;
}