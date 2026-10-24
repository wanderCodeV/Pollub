#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DDR DDRB
#define LCD_PORT PORTB
#define LCD_RS PB1
#define LCD_EN PB0

void LCD_SendNibble(uint8_t b) 
{
    LCD_PORT = (LCD_PORT & 0x0F) | (b & 0xF0);
    LCD_PORT |= _BV(LCD_EN);
    _delay_ms(1);
    LCD_PORT &= ~_BV(LCD_EN);
    _delay_ms(1);
}

void wypisz(uint8_t bajt) 
{
    LCD_SendNibble(bajt);
    LCD_SendNibble(bajt << 4);
}

void LCD_Init() 
{
    LCD_DDR |= 0xF0 | _BV(LCD_RS) | _BV(LCD_EN);
    LCD_PORT &= ~(0xF0 | _BV(LCD_RS) | _BV(LCD_EN));
    _delay_ms(50);
    
    LCD_PORT &= ~_BV(LCD_RS);
    LCD_SendNibble(0x30);
    _delay_ms(5);
    LCD_SendNibble(0x30);
    _delay_ms(150);
    LCD_SendNibble(0x30);
    _delay_ms(150);
    LCD_SendNibble(0x20);
    _delay_ms(50);
    
    wypisz(0x28);
    wypisz(0x0C);
    wypisz(0x01);
    _delay_ms(2);
}

void set_kursor_LCD(uint8_t x, uint8_t y) 
{
    uint8_t adres;
    
    if (x == 2) {
        adres = 0x40 + (y - 1);
    } else {
        adres = 0x00 + (y - 1);
    }
    
    LCD_PORT &= ~_BV(LCD_RS);
    wypisz(0x80 | adres);
    _delay_ms(2);
    LCD_PORT |= _BV(LCD_RS);
}

void LCD_CreateChar(uint8_t numer_znaku, const uint8_t *tablica_znaku) 
{
    numer_znaku &= 0x07; 
    
    LCD_PORT &= ~_BV(LCD_RS); 
    wypisz(0x40 | (numer_znaku << 3)); 
    _delay_ms(2);
    
    LCD_PORT |= _BV(LCD_RS); 
    
    uint8_t i;
    for (i = 0; i < 8; i++) {
        wypisz(tablica_znaku[i]); 
    }
}

const uint8_t choinka[8] = {
    0b00000100,
    0b00000100,
    0b00001110,
    0b00001110,
    0b00011111,
    0b00011111,
    0b00000100,
    0b00000100
};

const uint8_t jelen[8] = {
    0b00010001,
    0b00001110,
    0b00000011,
    0b00001111,
    0b00001111,
    0b00001001,
    0b00001001,
    0b00000000
};

const uint8_t okno[8] = {
    0b00011111,
    0b00010101,
    0b00011111,
    0b00010101,
    0b00010101,
    0b00011111,
    0b00010101,
    0b00011111
};

int main(void) 
{
    LCD_Init();
    
    LCD_CreateChar(0, choinka);
    LCD_CreateChar(1, jelen);
    LCD_CreateChar(2, okno);

    uint8_t klatka;
    while (1) 
    {
        for (klatka = 0; klatka <= 2; klatka++) 
        {
            set_kursor_LCD(1, 1); 
            wypisz(klatka);      
            
            _delay_ms(400);      
        }
    }
    return 0;
}