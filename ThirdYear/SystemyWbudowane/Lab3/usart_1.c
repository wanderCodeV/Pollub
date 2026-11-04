#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 4000000UL // Częstotliwość 4MHz (zgodnie ze schematem z Proteusa)
#define BAUDRATE 9600 // Prędkość transmisji
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) // Obliczenie wartości dla rejestrów UBRR

void USART_Init(void)
{
    // Ustawienie prędkości (Baud Rate)
    UBRRH = (uint8_t)(BAUD_PRESCALLER >> 8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);
    
    // Włączenie nadajnika (TX)
    UCSRB = (1 << TXEN);
    
    // Ustawienie ramki: asynchroniczna, 8 bitów danych, 1 bit stopu, brak parzystości
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}

void USART_putchar(unsigned char data)
{
    // Czekaj, aż bufor nadawczy (UDR) będzie pusty (flaga UDRE)
    while (!(UCSRA & (1 << UDRE)));
    
    // Umieść znak w buforze, co rozpocznie wysyłanie
    UDR = data;
}

void USART_putstring(const char* str)
{
    // Wysyłaj kolejne znaki, aż natrafisz na znak końca łańcucha ('\0')
    while (*str != '\0') {
        USART_putchar(*str);
        str++;
    }
}

int main(void)
{
    // Konfiguracja sprzętowa USART
    USART_Init();
    
    // Główna pętla programu
    while(1)
    {
        // Wysłanie danych do terminala (znak \r\n oznacza nową linię)
        USART_putstring("Mariia Nyzhnyk\r\n");
        
        // Odczekaj 1 sekundę przed kolejnym wysłaniem
        _delay_ms(1000);
    }
    
    return 0;
}