/*
 * FanLED.c
 *
 * Created: 9/23/2019 11:47:40 PM
 * Author : 18521
 */ 
//d1 b3 b4 b5 b6 b7 d0
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/sfr_defs.h>
#define cbi(port, pin) ({port &= ~(1<<pin);})
#define sbi(port, pin) ({port |= (1<<pin);})
char charHello[] ="HELLO UIT";
void addColum(uint8_t b){
  PORTD = (b<<2);
  PORTB = ((b<<1)|1)&(b>>6);
  _delay_us(300);
}
void CharCheck(char a){
  if(a == 'U')
  {
    addColum(0b10000000);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b10000000);
  }
  else if(a == 'I')
  {
    addColum(0b11111100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b11111100);
  }
  else if(a == 'i')
  {
    addColum(0b11111100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b11111100);
  }
  else if(a == 'T')
  {
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
  }
  else if(a == 't')
  {
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
    addColum(0b10011111);
  }
  else if(a == ' ')
  {
    addColum(0b11111111);
    addColum(0b11111111);
    addColum(0b11111111);
    addColum(0b11111111);
  }
  else if(a== 'H')
  {
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b11110111);
    addColum(0b10000000);
    addColum(0b10000000);
  }
  else if(a== 'E')
  {
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b11110110);
    addColum(0b11111110);
  }
  else if(a== 'e')
  {
    addColum(0b10111111);
    addColum(0b10110111);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10110110);
    addColum(0b10000000);
    addColum(0b10000000);
  }
  else if(a == 'L')
  {
    addColum(0b10000000);
    addColum(0b10000000);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
    addColum(0b11111100);
  }
  else if(a == 'O')
  {
    addColum(0b11000001);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b10011100);
    addColum(0b11000001);
  }
}

void setup()
{
    /* Replace with your application code */
  // put your setup code here to run once:
  DDRD = 0b11111011;
  sbi(DDRB,0);
  sbi(DDRB,1);
  PORTD = 0xFF;
  sbi(PORTB,0);
  sbi(PORTB,1);
}
void loop(){
  if(bit_is_clear(PIND,2)){
      while(bit_is_clear(PIND,2));
      for(int i = 0; i < strlen(charHello); i++)
      {
        CharCheck(charHello[i]);
        CharCheck(' ');
      }
  }
   
}
