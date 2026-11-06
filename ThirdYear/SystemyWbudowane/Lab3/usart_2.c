#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 4000000UL // Częstotliwość 4MHz
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_Init(void)
{
    UBRRH = (uint8_t)(BAUD_PRESCALLER >> 8); // Ustaw prędkość
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
    
    UCSRB = (1 << RXEN) | (1 << TXEN); // Włącz nadajnik i odbiornik
    
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Ramka: 8N1
}

void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1 << UDRE))); // Czekaj na pusty bufor TX
    UDR = data; // Wyślij
}

void USART_putstring(const char* str)
{
    while (*str != '\0') {
        USART_putchar(*str);
        str++;
    }
}

unsigned char UART_RxChar(void)
{
    while ((UCSRA & (1 << RXC)) == 0); // Czekaj na dane
    return UDR; // Zwróć bajt
}

int main(void)
{
    unsigned char odebrany_znak;
    
    USART_Init(); // Inicjalizacja sprzętowa
    
    USART_putstring("Nacisnij klawisz a\r\n"); // Komunikat początkowy
    
    while(1)
    {
        odebrany_znak = UART_RxChar(); // Czekaj na klawisz
        
        if (odebrany_znak == '\r' || odebrany_znak == '\n') continue; // Ignoruj nowe linie

        if (odebrany_znak == 'a') 
            USART_putstring("znak prawidlowy\r\n"); // Znak OK
        else 
            USART_putstring("bledny znak\r\n"); // Zły znak
    }
    return 0;
}