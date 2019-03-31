/*
 * TimerPractice.c
 *
 * Created: 25-03-2019 00:01:46
 * Author : HP
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int i=0;

void timer_delay()
{
	TCCR1A=0x00;
	TCNT1H=0xC2;
	TCNT1L=0xF6;

	TCCR1B=(1<<CS12)|(1<<CS10);	//1024 Prescalar timer on
	while (!(TIFR & (1<<TOV1)));
	TIFR|=(1<<TOV1);	// overflow flag
	TCCR1B &= ~((1<<CS12)|(1<<CS10)); 
}

void timer_int()
{
	TCCR1A=0x00;
	TCNT1H=0xC2;
	TCNT1L=0xF6;
	TIMSK|=(1<<TOIE1);	// Interrupt Enable
	TCCR1B=(1<<CS12)|(1<<CS10);	//1024 Prescalar timer on
	
}

ISR(TIMER1_OVF_vect)
{
	cli();	//disable interrupt
	//i++;
	PORTC=~PORTC;
	TCNT1H=0xC2;
	TCNT1L=0xF6;
	sei();	//enable interrupt
	
}
int main(void)
{
	DDRC=0xFF;
	PORTC=0xFF;
	timer_int();
	sei();
    while (1) 
    {
		
		
		
									/*PORTC|=(1<<PC5);
									timer_delay();
									PORTC&=~(1<<PC5);
									timer_delay();*/
    }
}

