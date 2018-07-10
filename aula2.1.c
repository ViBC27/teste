#include <stdio.h>

void imprimir_4(){
  printf("Primeiro Programa com 4 funções\n");
}

void imprimir_3(){
  imprimir_4();
  printf("Primeiro Programa com 3 funções\n");
}

void imprimir_2(){
  imprimir_3();
  printf("Primeiro Programa com 2 funções\n");
}

int main(){
  imprimir_2();
  printf("Primeiro Programa com 1 função\n");

return 0;
}

// Pilha de Execução (Paradigma de Programação Estruturada)
