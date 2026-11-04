# Zadanie 1

Napisać program, który spowoduje wysłanie ciągu znaków "Imię i Nazwisko" (indywidualnie studenta) na terminal z wykorzystaniem USART. W tym celu należy odpowiednio skonfigurować ustawienia transmisji szeregowej: (baud rate = 9600, ramka: 8 bitów danych, brak kontroli parzystości, 1 bit stopu) oraz, w oparciu o funkcję przesyłania znaku, napisać funkcję wysyłającą ciąg znaków.

```c
#define F_CPU 800000UL // ustawienie częstotliwości zegara – proponowane 8MHz
#define BAUDRATE 9600 //określenie prędkości przesyłania
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) //wyznaczenie za wartości rejestru UBRR ze wzoru

void USART_Init(void)
{
    /* ustawienie baud */
    UBRRH = (uint8_t)(BAUD_PRESCALLER>>8);
    UBRRL = (uint8_t)(BAUD_PRESCALLER);

    //konfiguracja… (baud rate = 9600, ramka: 8 bitów danych, brak kontroli parzystości, 1 bit stopu)
}

void USART_putchar(unsigned char data)
{
    while (!(UCSRA & (1<<UDRE)));
    UDR = data;
}
```

# Zadanie 2

Do programu z zadania 1 dodać funkcję odbioru danych. Na terminal należy wysłać wiadomość: "Nacisnij klawisz [x]" (student wybiera indywidualnie znak). Następnie program powinien oczekiwać na wprowadzenie wybranego znaku z poziomu klawiatury komputera PC, a po jego podaniu nadać wiadomość potwierdzającą odbiór (np.. “znak prawidlowy”).

W przypadku podania złego znaku (litery) należy wygenerować kod błędu (np. "błędny znak").

**Tip:**

```c
unsigned char UART_RxChar()
{
    while ((UCSRA & (1<<RXC))==0); /* Wait till data is received */
    return UDR;/* Return the byte */
}
```

# Zadanie 3

Należy podłączyć diody przewodami łączeniowymi według schematu:

- LED_0 → (PA0)
- LED_1 → (PA1)
- LED_2 → (PA2)
- LED_3 → (PA3)
- LED_4 → (PA4)
- LED_5 → (PA5)
- LED_6 → (PA6)
- LED_7 → (PA7)

W układzie jak powyżej (baud rate = 9600, ramka: 8 bitów danych, brak kontroli parzystości, 1 bit stopu) napisać program, który:

**a)** będzie powodował cykliczne miganie diodą LED_0 z wykorzystaniem przerwania od porównania Timera 0,

**b)** umożliwi sterowanie pozostałymi diodami z klawiatury komputera PC ([1] – LED_1, [2] – LED_2, itd.) z wykorzystaniem transmisji szeregowej. Po wciśnięciu klawisza [x], jego wartość powinna zostać wyświetlona na terminalu komputera PC, a wybrana dioda powinna zostać przełączona w stan przeciwny. Dodatkowo przyciski [c] i [s] powinny odpowiednio wyłączać (clear) i włączać (set) wszystkie diody od LED_1 do LED_7. Wciśnięcie jakiegokolwiek innego klawisza powinno zwrócić wiadomość o błędzie. Do realizacji odbioru danych można w tym zadaniu wykorzystać obsługę przerwania od zakończenia odbioru przez USART (USART_RXC_vect).

**Tip:**

Załączenie obsługi przerwań od odbioru danych następuje w rejestrze UCSRB.
