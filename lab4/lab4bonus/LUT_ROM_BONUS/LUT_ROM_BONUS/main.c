/*
 * LUT_ROM_BONUS.c
 *
 * Created: 3/22/2022 11:32:28 AM
 * Author : ionut
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>

const unsigned char segLUT[] PROGMEM = {
   0b10111111, // 0 with dp
   0b10000110, // 1 with dp
   0b11011011, // 2 with dp
   0b11001111, // 3 with dp
   0b01100110, // 4
   0b11101101, // 5 with dp
   0b01111101, // 6
   0b00000111  // 7
};

int main(void)
{
   unsigned char inputs;
   DDRA = 0Xff;
   DDRB = 0;

   while (1)
   {
      inputs = PINB & 7;
      PORTA = pgm_read_byte (&segLUT[inputs]);
   }
}