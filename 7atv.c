#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  int qdia; // Quantidade de dias
  scanf("%d", &qdia);
  double dia = 90.00; // Valor da diária
  double dt = qdia * dia; // Valor das diárias totais

  int qkm; // Quantidade de Quilomêtros
  scanf("%d", &qkm);
  int km = qdia * 100; // Valor de Km disponível, dia = 100;
  int kmt = 0;

  if(qkm > 100){

    kmt = qkm - km;
  }

  printf("%.2lf\n", dt+(kmt*12));

return 0;
}
