#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;


LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

void loop(){ 

    byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
    byte bigheart[8]= {0x00,0x66,0xFF,0xFF,0xFF,0x7E,0x3C,0x18,};
    byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
    byte frown[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
    byte smallheart[8]= {0x00,0x00,0x24,0x7E,0x7E,0x3C,0x18,0x00,};

    printByte(smile);
     
    delay(1000);
    
    printByte(bigheart);
     
    delay(1000);

    printByte(neutral);
    
    delay(1000);

    printByte(frown);    

    delay(1000);

    printByte(smallheart);
     
    delay(1000);
   
   
}


void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

