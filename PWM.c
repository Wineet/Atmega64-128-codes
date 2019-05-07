/*
 * PWM_int.c
 *
 * Created: 14-03-2019 09:33:02
 * Author : desd
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void timer_init();

int i=0;

int main(void)
{
	DDRA|=(1<<PA3);

	
	timer_init();
	while(1)
	{
             /*
		PORTA|=(1<<PA3);
		_delay_us(100);
		PORTA&=~(1<<PA3);
		_delay_us(100);
		*/
		/* Intensity Will Increase And Decrease Delay is for observation only*/
		for(int i=0;i<=255;i++)
		{
			OCR3C=i;
			_delay_ms(20);
		}
		for(int i=255;i>=0;i--)
		{
			OCR3C=i;
			_delay_ms(20);
		}
	}
}

void timer_init()
{
	
	TCCR3A|=(1<<WGM30)|(1<<WGM31)|(1<<COM3C1)|(1<<COM3C0);		//Timer Initialise IN PWM MODE
	TCCR3B|=(1<<CS30)|(1<<WGM32);
	DDRE|=(1<<PE5);							// Enable PWM Output Pin
	TCNT3=0;							//Initial VAlue

}
