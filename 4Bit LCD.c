/* LCD practice*/

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define rs PA0
#define en	PA2

#define set(a,b) a=a|(1<<b)
#define clear(a,b) a=a & ~(1<<b)

int i=0;

void lcd_cmd(unsigned char x)
{
	PORTA= x & 0xf0;
	clear(PORTA,rs);
	
	set(PORTA,en);
	_delay_ms(10);
	clear(PORTA,en);
	
	PORTA= (x<<4) & 0xf0;
	clear(PORTA,rs);
	
	set(PORTA,en);
	_delay_ms(10);
	clear(PORTA,en);
}

void lcd_dat(unsigned char x)
{
	PORTA= x & 0xf0;
	set(PORTA,rs);
	
	set(PORTA,en);
	_delay_ms(10);
	clear(PORTA,en);
	
	PORTA= (x<<4) & 0xf0;
	set(PORTA,rs);
	
	set(PORTA,en);
	_delay_ms(10);
	clear(PORTA,en);
}

void lcd_str(char *p)
{
	while (*p!='\0')
	{
		lcd_dat(*p);
		p++;
	}

}

	

int main()
{
		DDRA=0xFF;
		lcd_cmd(0x28);
		lcd_cmd(0x0F);
		lcd_cmd(0x01);
		lcd_str("Hello");
	while(1)
		{
       
       	}

}