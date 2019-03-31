/*
 * AdcPractice.c
 *
 * Created: 24-03-2019 17:37:56
 * Author : HP
 */ 

#include <avr/io.h>

int adc()
{
  ADCSRA|=(1<<ADEN);		//ADC_EN
  ADMUX|=(1<<REFS0)|(1<<ADLAR);	// 5v Referance & Left Adjust
  //Default Channel Zero to change change ADMUX value
  ADCSRA|=((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));	// divide by 128 prescalar
  ADCSRA|=(1<<ADSC);				// Start Of conversion
  while(ADCSRA & (1<<ADSC));		// wait until conversion complete
  int data=ADCH;
  return data;
}
int main(void)
{
	DDRC=0xFF;
	PORTC=0xff;
	
 
	char data;
    while (1) 
    {
		
		PORTC=adc();
    }
}

