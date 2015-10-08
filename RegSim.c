#include <stdio.h>
#include <sdtio.h>

/***************************/
/* register initialisieren */
/***************************/

struct byte8{
  unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
}:

/**********************/
/* register summarize */
/**********************/ 

typedef union{
  struct 8bit b;
  unsigned char byte;     // to show the programm: this is a bunch of bits.
}byte8;

void RegValues(){
  printf("Binaer\tInteger\tHex");
  printf("");
}

int main (void){

}
