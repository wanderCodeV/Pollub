#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 4000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_Init(void)
{
    UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
    UCSRB = (1<<RXCIE) | (1<<RXEN) | (1<<TXEN);
    UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1<<UDRE)));
    UDR = data;
}

void Timer0_Init(void)
{
    TCCR0 |= (1<<WGM01) | (1<<CS02) | (1<<CS00);
    OCR0 = 39;
    TIMSK |= (1<<OCIE0);
}

ISR(TIMER0_COMP_vect)
{
    PORTA ^= (1<<PA0);
}

ISR(USART_RXC_vect)
{
    unsigned char odebrany_znak = UDR;
    
    if (odebrany_znak >= '1' && odebrany_znak <= '7') {
        USART_putchar(odebrany_znak);
        PORTA ^= (1 << (odebrany_znak - '0'));
    }
    else if (odebrany_znak == 'c')
        PORTA &= 0x01;
    else if (odebrany_znak == 's')
        PORTA |= 0xFE;
    else
        USART_putchar('E');
}

int main(void)
{
    DDRA = 0xFF;
    PORTA = 0x00;
    
    USART_Init();
    Timer0_Init();
    
    sei();
    
    while(1);
}