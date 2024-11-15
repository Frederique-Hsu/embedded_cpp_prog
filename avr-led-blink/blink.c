/*!
 *  \file       blink.c
 *  \brief      
 *  
 */


#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    // set built-in LED pin as output

    DDRB |= (1 << DDB5);

    while (1)
    {
        PORTB |= (1 << PB5);    // LED ON
        _delay_ms(500);
        PORTB &= ~(1 << PB5);   // LED OFF
        _delay_ms(500);
    }
    return 0;
}