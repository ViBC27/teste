#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  double a, b, c, media;
  scanf("%lf %lf %lf", &a, &b, &c);

  int ra, rb ,rc, acima;

  if((a>0 && a<=10) && (b>0 && b<=10) && (c>0 && c<=10))
  {
    media = (a+b+c)/3;
  }
  if (a > media)
  {
    ra = 1;
  }
  else
  {
    ra = 0;
  }
  if (b > media)
  {
    rb = 1;
  }
  else
  {
   rb = 0;
  }
  if (c > media)
  {
    rc = 1;
  }
  else
  {
    rc = 0;
  }

  acima = ra + rb + rc;

  printf("%d\n", acima);

return 0;
}
