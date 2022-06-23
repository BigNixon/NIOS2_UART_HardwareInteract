#include <stdio.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

int main()
{
  printf("Hello from Nios II!\n\r");
  int op=-1;
  do{
	  printf("seleccione una ocion\n\r");
	  printf("1)Blink period 1   s	\n\r");
	  printf("2)Blink period 500 ms	\n\r");
	  printf("3)Blink period 200 ms	\n\r");
	  printf("4)Blink period 100 ms	\n\r");
	  printf("5)Salir 				\n\r");
	  scanf("%d",&op);


	  if(op==1){
		  printf("Seleccionaste 1s \n\r");
		  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0b00);
	  }else if(op==2){
		  printf("Seleccionaste 500 ms \n\r");
		  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0b01);
	  }else if(op==3){
		  printf("Seleccionaste 200 ms \n\r");
		  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0b10);
	  }else if(op==4){
		  printf("Seleccionaste 100 ms \n\r");
		  IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 0b11);
	  }else if(op!=5){
		  printf("Opcion invalida!!\n\r");
	  }

  }while(op!=5);

  printf("Saliendo\n\r");
  return 0;
}
