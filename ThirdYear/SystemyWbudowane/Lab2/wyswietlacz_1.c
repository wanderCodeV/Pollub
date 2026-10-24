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
    _delay_ms(15);
    LCD_PORT &= ~_BV(LCD_EN);
    _delay_ms(15);
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
    _delay_ms(1);
    LCD_PORT |= _BV(LCD_RS);
}

void LCD_Print(char *tekst, int8_t dlugosc, uint8_t wiersz, uint8_t kolumna) 
{
    int8_t i = 0;
    uint8_t akt_wiersz = wiersz;
    uint8_t akt_kol = kolumna;
    
    set_kursor_LCD(akt_wiersz, akt_kol);
    
    while (i < dlugosc) {
        if (akt_kol > 16) {
            if (akt_wiersz == 1) {
                akt_wiersz = 2;
                akt_kol = 1;
                set_kursor_LCD(akt_wiersz, akt_kol);
            } else {
                break;
            }
        }
        wypisz(tekst[i]);
        akt_kol++;
        i++;
    }
}

int getkey() 
{
    int i, licznik = 0, prz = 0;
    
    for(i = 0; i < 4; i++) {
        PORTA = ~(1 << (i + 4));
        if((PORTA & 0xF0) ^ (PINA & 0xF0))
            return 0xFF;
            
        _delay_ms(1);
        char k = PINA & 0x0F;
        
        switch(k) {
            case 0b00001111:
                break;
            case 0b00001110:
                licznik++;
                prz = i + 1;
                break;
            case 0b00001101:
                licznik++;
                prz = i + 5;
                break;
            case 0b00001011:
                licznik++;
                prz = i + 9;
                break;
            case 0b00000111:
                licznik++;
                prz = i + 13;
                break;
            default:
                return 0xFF;
        }
        
        if(licznik > 1) 
            return 0xFF;
    }
    return prz;
}

int main(void) 
{
    char imie[] = "Nyzhnyk Mariia";
	char key_str[] = "Przycisk nr:";
	int size_str = sizeof(key_str);
	DDRA = 0xF0;
    PORTA = 0x0F;

    LCD_Init();
	
    LCD_Print(imie,sizeof(imie)-1, 1, 1);
    LCD_Print(key_str, size_str-1, 2, 1);

    int n;
    char bufor[2];
    
    while (1) {
        n = getkey();
        
        if(n != 0xFF && n != 0x00) {
            if(n >= 10) {
                bufor[0] = (n / 10) + '0';
                bufor[1] = (n % 10) + '0';
            } else {
                bufor[0] = n + '0';
                bufor[1] = ' ';
            }

            LCD_Print(bufor, sizeof(bufor), 2, size_str+1);
        }
    }
    
    return 0;
}