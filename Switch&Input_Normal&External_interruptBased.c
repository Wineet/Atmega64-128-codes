/*
 * Switches_EXT_INTE.c
 *
 * Created: 14-03-2019 05:37:19
 * Author : desd
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000
#include <util/delay.h>

ISR(INT7_vect)		// External Sub Routine for Interrupt
{
 cli();					// Clear Global Interrupt
 PORTA|=(1<<PA3);		// PA3=1 In interrupt 
 sei();					// Enable Global Interrupt
}

int main(void)
{
	
      DDRC=0xff;	//output
      DDRE=0x00;	// Port D as Input
      PORTE=0xFF;	// Activate PUllUp
	  
	  DDRA|=(1<<PA3);
	  PORTA&=~(1<<PA3);
	  
      DDRD=0x00;	// Port D as Input
      PORTD=0xFF;	// Activate PUllUp
	  EICRB=0x00;
	  EIMSK=0xC0;
    // cli();	// Disable Interrupt
      sei();
	
	while (1) 
    {
		/* Continues Port Toggle 
		* when Interrupt Occure Extenal Jump to routine*/
		 PORTA&=~(1<<PA3);	
		PORTC=0x00;
		_delay_ms(1000);
		PORTC=0xFF;
		_delay_ms(1000);
		
		
		
		/* For poll Scanning Use Below Method */
		
									/*if (PIND & 1<<PD7)
									{
									PORTC=0xFF;	
									}
									else{
									PORTC=0x00;		
									}*/
    }
}

