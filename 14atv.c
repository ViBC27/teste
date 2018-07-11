#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  int qcaixa;
  gets(&qcaixa);

  char tcaixa[3];
  char p[3]= "p";
  char P[3]= "P";
  gets(tcaixa);

  /*if(strcasecmp(tcaixa, p)){

    printf("Diferente\n");

  }else{

  printf("Iguais\n");
  }
*/

  printf("%d e %s\n", qcaixa, tcaixa);

  return 0;
}
