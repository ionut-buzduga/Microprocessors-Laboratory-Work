#include <avr/io.h>
#include "LCD.h"
#define NOKEY 0x7f
#define DELAY 200

char kbscan(){
   unsigned char temp;
   unsigned char cols = ' ';
   unsigned char lina = 0; // active line
   unsigned char cola = 0; // active column
   unsigned char internal_code;
   char code2return;
   char LUT[] = "123A456B789C*0#D";
   
   for( DDRA = 1<<4; DDRA !=0; DDRA <<=1 ) { //shift left DDRA by 1 bit each time where DDRA=00010000 at start until DDRA=0
      _delay_us(4);
      cols=~PINA;
      cols=cols & 0b00001111;   //we mask bits 7:4 to 0 
      if(cols){         //test whether there is at least one '1' in cols
         break;
      }
   }
   
   if(cols == 0){
      return NOKEY;
   }
   
   temp = DDRA;
   
   while((temp & 1<<4) == 0 ){   //we determine active line (shift right temp until 1 is on bit 4 and count the lines)
      lina++;
      temp >>= 1;
   }
   
   temp = cols;
   
   while((temp & 1<<0) == 0){    //we determine active column (shift right temp until there is a 1 on bit 0 and count the columns)
      cola++;
      temp >>= 1;
   }
   
   internal_code= lina * 4 + cola; 
   
   code2return= LUT[internal_code];
   return code2return;
}


//int main(){
//char temp;
//
//PORTA = 0;
//initLCD();
//while(1){
//temp=kbscan();
//if(NOKEY != temp){
//clrLCD();
//putchLCD(temp);
//}
//}
//}

int main(){
   char code_ante = NOKEY;
   char code_now = NOKEY;
   
   unsigned char kbhit = 0;
   char kbcode;
   
   unsigned char loop_cnt=0;
   
   PORTA = 0;
   initLCD();
   
   //sysinit(); // it is not in the lecture notes, but it is necessary
   
   while(1){ //main loop
      // …
      if(loop_cnt==DELAY){ // read from 15 ms to 15 ms
         loop_cnt=0;
         
         code_ante = code_now;
         code_now = kbscan();
         if( code_ante == NOKEY && code_now != NOKEY){
            kbhit=1;
            kbcode=code_now;
         }
      }
      // ……
      //use the key code
      if(kbhit){
         kbhit=0;
         //process kbcode; for example, display it
         putchLCD(kbcode);
      }
      //……
      loop_cnt++;
   } //end while
} //end main