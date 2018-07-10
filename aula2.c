#include <stdio.h>

int soma (int n1, int n2){

   int r;
   r = n1+n2;

  return r; //n1+n2
}

int main(){

  int resultado; //int resultado = soma(2,3);
  resultado = soma(2,3);

  printf("A soma de 2 + 3 = %d\n", resultado);

  printf("A soma de %d + %d = %d\n", 2, 3, resultado);

  resultado = soma(10,567);

  printf("A soma de %d + %d = %d\n", 10, 567, resultado);

return 0;
}

// Pilha de Execução (Paradigma de Programação Estruturada)
