#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  double salario, salarioat;
  printf("Informe o salario do colaborador:");
  scanf("%lf", &salario);

  if (salario <= 280.00)
  {
    salarioat = salario * 1.2;
  }

  if(salario > 280.00 && salario <= 700.00)
  {
    salarioat = salario * 1.15;
  }

  if(salario > 700.00 && salario <= 1500)
  {
    salarioat = salario * 1.1;
  }

  if(salario > 1500.00){
    salarioat = salario * 1.05;
  }

  printf("Salario antes do reajuste: %.1lf\n", salario);
  printf("Percentual de aumento aplicado: %.0lf%%\n", ((salarioat/salario)-1)*100);
  printf("Valor do aumento: %lf\n", salarioat-salario);
  printf("Salario com reajuste: %.2lf\n", salarioat);

return 0;
}
