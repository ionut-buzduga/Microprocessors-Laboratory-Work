#include "LCD.h"
#include <avr/io.h>

int main(){
   
   initLCD();
   char message[] = "0123456789abcdef";
   
   while(1){
      putchLCD('H');
      _delay_ms(1000);
      clrLCD();
      _delay_ms(500);
      gotoLC(1,1);
      putsLCD("Hello");
      gotoLC(2,7);
      putsLCD("micro!");
      _delay_ms(1000);
      clrLCD();
      _delay_ms(500);    
      
      for(int i = 0; i <= 15; i++){
         putchLCD(message[i]);
         _delay_ms(500);
      }
      
      gotoLC(2,1);
      putsLCD("ghijklmnopqrstuv");
      _delay_ms(500);
      
      gotoLC(2,16);
      _delay_ms(500);
      for(int i = 15; i > 0; i--){
         gotoLC(2,i);
         _delay_ms(500);
      }
      
      gotoLC(1,16);
      _delay_ms(500);
      for(int i = 15; i > 0; i--){
         gotoLC(1,i);
         _delay_ms(500);
      }
      
      clrLCD();
      _delay_ms(500);  
   }
}