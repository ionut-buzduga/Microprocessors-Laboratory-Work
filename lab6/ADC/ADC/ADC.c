#include "LCD.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  unsigned int val;
  char buf[20];
  initLCD();
  
  //1 ADMUX register
  //2 REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0
  //3 |       |     |     0    0   0    0    0        Vin = ADC0
  //4 |       |     1  aliniere la stânga
  //5 0       1  VREF = AVCC
  ADMUX =0b01100000;
  
  // ADCSRA register.
  // ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0
  //  |     |    |     |    |    1     1    1     factor divizare=128
  //  |     |    0     |    0  ADIE si ADATE se seteaza la ‚0’ si nu se mai modifica
  //  |     |          0
  //  |     0  ADSC si ADIF =0 => ADC initial in stare de repaus
  //  1  enable pentru ADC
  ADCSRA = 0b10000111;
  
  while(1){
     // daca ADC este în repaus adica nu exista conversie în curs
     if(testbit(ADCSRA, ADSC) == 0 && testbit(ADCSRA, ADIF) == 0){
        setbit(ADCSRA, ADSC);
     }
     
     //daca s-a terminat conversia
     if(testbit(ADCSRA, ADSC) == 0 && testbit(ADCSRA, ADIF)){
        //sterge bitul care indica sfârsitul conversiei
        clrbit(ADCSRA, ADIF);
        
        //citeste rezultatul conversiei din portul de date conform setarii ADLAR
        val= ADCH;
        //sprintf(buf, "%03d", val);
        int converted_val = val * 500UL/255;
        int hundreds_val = converted_val / 100 % 10;
        int tens_val = converted_val / 10 % 10;
        int units_val = converted_val % 10;
        buf[0]='V';
        buf[1]='=';
        buf[2]='0' + hundreds_val;
        buf[3]='.';
        buf[4]='0' + tens_val;
        buf[5]='0' + units_val;
        buf[6]='\0';
        gotoLC(1, 1);
        putsLCD(buf);
       
     }
  }//end while(1)
}//end main()