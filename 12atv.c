#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  char comida[15];
  //printf("Escolha a comida: \n");
  gets(comida);

  char liquido[15];
  //printf("Escolha o liquido: \n");
  gets(liquido);

  char ls[15]= "Lasanha";
  char es[15]= "Estrogonofe";
  char rf[15]= "Refrigerante";
  char sc[15]= "Suco";

  double pls, pes, prf, psc, pc, pl; // Preços das comidas pc(ls,es) e das líquidos pl(rf,sc).

  if(strcasecmp (comida, ls)) //  if(comida[0] == 'l' || comida[0] == '')
  {
    pls = 0.0;
  }
  else
  {
    pls = 8.0;
  }

  if(strcasecmp (comida, es))
  {
    pes = 0.0;
  }
  else
  {
    pes = 11.0;
  }

  if(strcasecmp (liquido, rf))
  {
    prf = 0.0;
  }
  else
  {
    prf = 3.0;
  }

  if(strcasecmp (liquido, sc))
  {
    psc = 0.0;
  }
  else
  {
    psc = 2.50;
  }

  pc = pls + pes;
  pl = prf + psc;

  printf("%.2lf\n", pc + pl);

  return 0;
}
