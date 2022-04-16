/*
 * PSWITCH.c
 *
 * Created: 3/22/2022 10:46:33 AM
 * Author : ionut
 */ 

#include <avr/io.h>


int main(void)
{
   unsigned char inputs;
   DDRA = 0Xff;
   DDRB = 0;

   while (1)
   {
      inputs = PINB & 7;
       
      switch (inputs){
         case 0:
         PORTA = 0b0111111;
         break;
         case 1:
         PORTA = 0b0000110;
         break;
         case 2:
         PORTA = 0b1011011;
         break;
         case 3:
         PORTA = 0b1001111;
         break;
         case 4:
         PORTA = 0b1100110;
         break;
         case 5:
         PORTA = 0b1101101;
         break;
         case 6:
         PORTA = 0b1111101;
         break;
         case 7:
         PORTA = 0b0000111;
         break;
      }
   }
}
