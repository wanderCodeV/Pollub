#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000L

#include <stdbool.h>

const uint8_t dig[] = {
    0b11000000, 
    0b11111001, 
    0b10100100, 
    0b10110000, 
    0b10011001, 
    0b10010010, 
    0b10000010, 
    0b11111000, 
    0b10000000, 
    0b10010000  
};

volatile long answer = 0;

int getkey()
{
    int i, cnt_key = 0, nr_key = 0;
    for(i = 0; i < 4; i++)
    {
        PORTA = ~(1 << (i+4));
        if((PORTA & 0xF0) ^ (PINA & 0xF0))
            return 0xFF;
        
        _delay_ms(1);
        char k = PINA & 0x0F;
        switch(k)
        {
            case 0b1111:
                break;
            case 0b1110:
                cnt_key++;
                nr_key = i + 1;
                break;
            case 0b1101:
                cnt_key++;
                nr_key = i + 5;
                break;
            case 0b1011:
                cnt_key++;
                nr_key = i + 9;
                break;
            case 0b0111:
                cnt_key++;
                nr_key = i + 13;
                break;
            default:
                return 0xFF;
        }
        if(cnt_key > 1) return 0xFF;
    }
    return nr_key;
}

void update_segments()
{
    int i;
    long temp = answer;
    if (temp < 0) temp = -temp; 
    
    for(i = 0; i < 4; i++)
    {
        PORTD = 0x0F;
        PORTB = dig[temp % 10];
        PORTD = ~(1<<i);
        _delay_ms(2);
        temp /= 10;
    }
}

int main()
{
    DDRA = 0xF0;
    PORTA = 0x0F;

    DDRB = 0xFF;
    PORTB = 0x00;

    DDRD = 0x0F;
    PORTD = 0x00;

    bool first_num = true;
    bool answer_flag = false;
    int last_key = 0;
    long num1 = 0, num2 = 0;
    char op = 0;

    while(1)
    {
        int curr_symb = getkey();
        
        if (curr_symb >= 1 && curr_symb <= 16 && (last_key == 0 || last_key == 0xFF))
        {
            _delay_ms(20); 
            
            if (curr_symb >= 1 && curr_symb <= 10)
            {
                if (answer_flag)
                {
                    num1 = 0;
                    num2 = 0;
                    first_num = true;
                    answer_flag = false;
                }
                
                int digit = curr_symb - 1;
                if (first_num) {
                    num1 = (num1 * 10 + digit) % 10000;
                    answer = num1;
                }
                else {
                    num2 = (num2 * 10 + digit) % 10000;
                    answer = num2;
                }
            }
            else if (curr_symb == 13 || curr_symb == 14 || curr_symb == 15 || curr_symb == 12)
            {
                if (answer_flag)
                {
                    num1 = answer;
                    num2 = 0;
                    op = curr_symb;
                    first_num = false;
                    answer_flag = false;
                }
                else if (first_num)
                {
                    op = curr_symb;
                    first_num = false;
                }
            }
            else if (curr_symb == 16)
            {
                if (!first_num && !answer_flag)
                {
                    switch(op)
                    {
                        case 13: answer = (num1 + num2) % 10000; break;
                        case 14: answer = (num1 - num2) % 10000; break;
                        case 15: answer = (num1 * num2) % 10000; break;
                        case 12:
                            if (num2 != 0) answer = num1 / num2;
                            else answer = 0;
                            break;
                    }
                    answer_flag = true;
                }
            }
        }
        
        last_key = curr_symb;
        update_segments();
    }
    
    return 0;
}