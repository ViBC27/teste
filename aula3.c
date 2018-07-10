#include <stdio.h>
#include <math.h>

/* void f2(int a, int b)
{

  int m;

  a--; // a=a-1;
  // a++; // a=a+1;

  m= a * b;
  printf("%d * %d = %d\n", a,b, m);
}

void f1(int n){

  printf("%d\n", n);
  f2(n-1, n-2);

} */

int main(){

  //f1(9);


  int raiz;
  printf("Esc. Número:\n");
  scanf("%d", &raiz);

  double res;
  res = sqrt(raiz);
  printf("A Raiz de %d é: %3.lf\n", raiz, res);

/*
  int a;

  printf("Dig. Número:\n");
  scanf("%d", &a);

  if (a<0){
      printf("Negativo\n");
    }
  if (a>=0) {
      printf("Positivo\n");}

  if (a==0) {

    printf("O Número é 0(Zero)! \n");
}
  else{

      if (a<0){
        printf("O Número é Negativo!\n"); }

      else{
        printf("O Número é Positivo!\n"); }
}
*/
return 0;
}
