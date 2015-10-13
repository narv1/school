#include <stdio.h>
#include <stdio.h>

/***************************/
/* register initialisieren */
/***************************/

struct byte{
  unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
};

/**********************/
/* register summarize */
/**********************/ 

typedef union{
  struct byte bit;
  unsigned char byte;     // to show the programm: this is a bunch of bits.
}reg_byte;


void RegValues(reg_byte *ptr){

  printf("Binaere\t\tInteger\t\tHex\n");
  
  printf("%d%d%d%d%d%d%d%d\t", ptr->bit.b7,  ptr->bit.b6, ptr->bit.b5, ptr->bit.b4,
	 ptr->bit.b3, ptr->bit.b2, ptr->bit.b1, ptr->bit.b0);

  printf("%d\t\t0x%x\n\n", ptr->byte, ptr->byte);
}
/*
int ChangeValue(struct byte b){
  //b.b1 = 1;
  //b.b5 = 1;
  bit.byte = 0xf0;
  return 0;
  }*/

int main (void){

  reg_byte bit;
  bit.byte = 0x00;
  //struct byte *ptr,p;
  //ptr = &p;
   
  printf("Willkommen.\nDieses Programm Simuliert ein Register, indem man jedes einzelne bit ansprechen kann!\n\n");
  //printf("%d",(*ptr).b0);
  RegValues(&bit);

  // struct byte byte2;
  //ChangeValue(bit);
  bit.byte = 0x22;
  //bit.bit.b1 = 1;
  //bit.bit.b5 = 1;
  RegValues(&bit);

  bit.byte = ~bit.byte;
  RegValues(&bit);
  
  bit.byte = 0x01;
  RegValues(&bit);

  bit.byte = bit.byte << 3;
  RegValues(&bit);

  bit.byte = bit.byte ^ 0x00;
  RegValues(&bit);

  bit.byte = bit.byte & 0xff;
  RegValues(&bit);

  if (bit.bit.b1 == 1){
    printf("Signal ein!\n");
  }else{
    printf("Signal aus!\n");
  }
  
  return 0;
  
}
