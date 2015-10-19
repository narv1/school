#Include <stdio.h>
#include <stdio.h>

/*******************************/
/* initialisiert ein 'Register */
/*******************************/

struct byte{
  unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
};

/************************************/
/* legt eine Union ueber den struct */
/************************************/ 

typedef union{
  struct byte bit;
  unsigned char byte;     // to show the programm: this is a bunch of bits.
}reg_byte;

/*******************************/
/*  eine Funktion welche die   */
/*     die Ausgabe regelt      */
/*******************************/

void RegValues(reg_byte *ptr){

  printf("Binaere\t\tInteger\t\tHex\n");
  printf("%d%d%d%d%d%d%d%d\t", ptr->bit.b7,  ptr->bit.b6, ptr->bit.b5, ptr->bit.b4,
	 ptr->bit.b3, ptr->bit.b2, ptr->bit.b1, ptr->bit.b0);
  printf("%d\t\t0x%x\n\n", ptr->byte, ptr->byte);
}

/***********************/
/*    HAUPTPROGRAMM    */
/***********************/

int main (void){

  /********************************************************************/
  /*          der neue Typ wird im Hauptprogramm aufgerufen           */
  /* ein beliebiger char wird dann einer speicher adrresses zugewiesen*/
  /********************************************************************/
  
  reg_byte bit;
  bit.byte = 0x00;

  /***********************************/
  /* Begrueszung/Programm erklaerung */
  /***********************************/
  printf("Author: Stefan Hermeter\n\n");
  printf("Willkommen.\nDieses Programm Simuliert ein Register!\nWo es moeglich ist jedes einzelne Bit anzusprechen.\n\n");
  RegValues(&bit);

  /*****************************************************/
  /*         bit1 und bit 5 auf eins gesetzt           */
  /* Ausgabe der Bitwerte ueber die Funktion RegValues */
  /*****************************************************/

  bit.byte = 0x22;        
  RegValues(&bit);

  /**************************/
  /* Einerkomplement bilden */
  /*     plus Ausgabe       */
  /**************************/     

  Bit.byte = ~bit.byte;
  RegValues(&bit);

  /*********************************/
  /* Alle ausser bit0 auf 0 setzen */
  /*         plus Ausgabe          */                       
  /*********************************/     
  
  bit.byte = 0x01;
  RegValues(&bit);

  /***********************************/
  /* verschieben der Bits nach links */
  /*          plus Ausgabe           */
  /***********************************/        
  
  bit.byte = bit.byte << 3;
  RegValues(&bit);

  /**************************************/
  /* Das Byte mit einem XOR verknuepfen */
  /*            Plus Ausgabe            */
  /**************************************/ 
  
  bit.byte = bit.byte ^ 0x00;
  RegValues(&bit);

  /**************************************/
  /* Das Byte mit einem UND verknuepfen */
  /*            Plus Ausgabe            */
  /**************************************/               
  
  bit.byte = bit.byte & 0xff;
  RegValues(&bit);


  /*********************************/
  /* Wenn bit1 auf 1 steht Ausgabe */
  /* Wenn bit1 auf 0 steht Ausgabe */
  /*********************************/
  
  if (bit.bit.b1 == 1){
    printf("Signal ein!\n");
  }else{
    printf("Signal aus!\n");
  }
  
  return 0;
  
}
