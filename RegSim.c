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

int main (void){

  reg_byte bit;
  bit.byte = 0x00;
   
  printf("Willkommen.\nDieses Programm Simuliert ein Register, indem man jedes einzelne bit ansprechen kann!\n\n");
  RegValues(&bit);

  // struct byte byte2;
  //ChangeValue(bit);
  bit.byte = 0x22;        //     <--  1.Moeglichkeit
  //bit.bit.b1 = 1;              <--  2.Moeglichkeit                   Es gibt 2 Moeglichkeiten einzelne Bits anzusprechen entweder man spricht das selbst erstellt Byte an od. 
  //Bit.bit.b5 = 1;                                                    man spricht die bits einzeln an. Sow wie links vom diesen Text dargestellt.
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
