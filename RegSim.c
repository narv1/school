#include <stdio.h>
#include <stdio.h>

/***************************/
/* register initialisieren */
/***************************/

struct byte8{
  unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
};

/**********************/
/* register summarize */
/**********************/ 

typedef union{
  struct byte8 b;
  unsigned char byte;     // to show the programm: this is a bunch of bits.
}byte8;

byte8 in1, in2, out;

void RegValues(){
  printf("Binaer\tInteger\tHex");
  printf("cool");
}

int main (void){

  byte8 bit;
  
  printf("Willkommen.\nDieses Programm Simuliert ein Register, indem man jedes einzelne bit ansprechen kann!\n\n");
  printf("%x",bit);
  RegValues();

  return 0;
  
}
