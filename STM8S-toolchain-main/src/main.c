#include <stdbool.h>
#include <stm8s.h>
#include <stdio.h>
#include "main.h"
#include "milis.h"
#include "delay.h"
#include "uart1.h"
#include "daughterboard.h"
#include "adc_helper.h"


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    init_uart1();

// na pinech vypneme vstupní buffer
ADC2_SchmittTriggerConfig(ADC2_SCHMITTTRIG_CHANNEL14, DISABLE);
ADC2_SchmittTriggerConfig(ADC2_SCHMITTTRIG_CHANNEL15, DISABLE);
//nastavíme CLOCK pro ADC2 (16Mhz / 4 = 4 Mhz)
ADC2_PrescalerConfig(ADC2_PRESSEL_FCPU_D4);
//zvolím zarovnání výsledku -- většinou doprava
ADC2_AlignConfig(ADC2_ALIGN_RIGHT);
//nastavíme multiplexer na **některý** kanál
ADC2_Select_Channel(ADC2_CHANNEL_14);
//rozběhnu ADC2
ADC2_Cmd(ENABLE);
//počkáme až se rozběhne
ADC2_Startup_Wait();

}

int main(void)
{
  
    uint32_t time = 0;
    uint16_t vref, vtemp;

    init();

    while (1) 
        if (milis() - time > 1111) {
            time = milis(); 

            vtemp = ADC_get(CHANNEL_VTEMP) * 5000 / 1024;
            vref = ADC_get(CHANNEL_VREF) * 5000 / 1024;
            printf("%u %u\n", vtemp, vref);
        }
       
    
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
