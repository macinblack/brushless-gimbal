/*
 * ADC.cpp
 *
 * Created: 7/16/2017 10:33:23 PM
 *  Author: rafa
 */ 
#include "ADC.h"
#include "defines.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

void ADC_Init()
{
	//enable interrupts
	//10 bit resolution
	//enable a prescaler , which is 128 , so ADC clock is 125khz
	//turn on the adc feature
	
	//start the first conversion
	//enable the global interrupts
	
	ADMUX  = (1<<REFS0)|(1<<ADLAR);//adlar is direction bit for ADCL , ADCH distribution 
	ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);//control and status register
	//ADSC is ADC start register maybe after sei() ????
	ADCSRB = 0;
	DIDR0 = 0xFE;
	DIDR2 = 0xFF;
}

unsigned int ADC_read()
{
	while(ADCSRA & (1<<ADSC));
	return ADC;
}

