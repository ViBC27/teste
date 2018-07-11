#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int aprovado(int certasp, int certasm, double red, int ap, int am)
{
  if(certasp < 0) return 0; // Parada Completa
  else
  {
    if(certasp >= ap && certasm >= am && red >= 7) //Aprovado
    {
      scanf("%d %d %lf", &certasp, &certasm, &red);
      return 1 + aprovado(certasp, certasm, red, ap, am);
    }
    else // Reprovado
    {
      scanf("%d %d %lf", &certasp, &certasm, &red);
      return 0 + aprovado(certasp, certasm, red, ap, am);
    }
  }
}

int main(){

  int p = 50;
  int m = 35;

  double ap = 0.8 * p;
  double am = 0.6 * m;
  double red;

  int certasp, certasm;

  scanf("%d %d %lf", &certasp, &certasm, &red);
  printf("%d\n", aprovado(certasp, certasm, red, ap, am));

  return 0;
}
