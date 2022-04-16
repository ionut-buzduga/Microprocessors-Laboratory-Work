/*
 * LUT_ROM.c
 *
 * Created: 3/22/2022 10:42:39 AM
 * Author : ionut
 */ 


#include <avr/io.h>
#include <avr/pgmspace.h>

const unsigned char segLUT[] PROGMEM = {
   0b0111111, // 0
   0b0000110, // 1
   0b1011011, // 2
   0b1001111, // 3
   0b1100110, // 4
   0b1101101, // 5
   0b1111101, // 6
   0b0000111  // 7
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
