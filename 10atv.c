#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  double salario, bonus;
  scanf("%lf", &salario);

  bonus = salario * 0.75;

  if (bonus < 2000){

    printf("ARGENTINA\n");

  }else if(bonus >= 2000 && bonus < 3000){

    printf("ESPANHA\n");

  } else {

      printf("ALEMANHA\n");

  }
return 0;
}
