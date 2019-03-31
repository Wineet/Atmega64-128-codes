/*
 * UART_practice.c
 *
 * Created: 24-03-2019 18:21:16
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#define BAUD 9600
#define buff F_CPU/16/BAUD-1
#include <util/delay.h>

void usart_ch(unsigned char ch)
{
		while(!(UCSR1A & (1<<UDRE1))); // CHECK Data empty
		UDR1=ch;
		while(!(UCSR1A &(1<<TXC1)));
}

int usart_rec()
{
	while(!(UCSR1A & (1<<RXC1)));		// check unread Data
	unsigned char data=UDR1;
	return data;
}
int main(void)
{		unsigned int buff1=buff;
	UBRR1H=(unsigned char)(buff1)>>8;	//Baud Rate
	UBRR1L=(unsigned char)(buff1);
	
    UCSR1B|=(1<<RXEN1)|(1<<TXEN1);	//Recieve transmit Enable
	
	UCSR1C|=(1<<UCSZ11)|(1<<UCSZ10);	//8BIT
									//Default Asynchronous mode
									//parity disabled
									// 1stop bit
									// send recieve data
	char data=0;
    while (1) 
    {
		data=usart_rec();
		
			usart_ch(data);
			
    }
}

