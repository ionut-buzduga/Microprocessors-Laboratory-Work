#include <avr/io.h>

int main(){
   
   unsigned char inputs;

  
   unsigned char vx2, vx1, vx0;
   
 
   unsigned char outs;
   unsigned char temp;
   DDRA = 0xff;
   DDRB = 0x00;
   
   while(1){
     
      inputs=PINB;
      inputs=inputs & 0x07;
      
      vx0=inputs & 1 << 0;
      vx1 = inputs >>1 & 1<< 0;
      vx2=  inputs >>2 & 1<< 0;
      outs=0;
      
      //f0
      temp=vx2^vx1^vx0;
      if(temp & 1<<0)
         outs=outs | 1<<0;

      //f1
      if(inputs <3)
         outs=outs | 1<<1;
      
      //f2
      if(inputs == 2 || inputs == 3 || inputs == 5 || inputs ==7)    
         outs=outs | 1<<2;    
     
      
    /*  temp=(~vx2&vx1) | (vx2&vx0);
      if(temp & 1<<0)
        outs=outs | 1<<2;
        */
      
      PORTA = outs;
   }

}