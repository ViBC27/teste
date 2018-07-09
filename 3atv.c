#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  int aux;
  int x, y, z, w;
  scanf("%d %d %d %d", &x, &y, &z, &w);

  if(x > w)
  {
    aux = x;
    x = w;
    w = aux;
  }
  if(x > z)
  {
    aux = x;
    x = z;
    z = aux;
  }

  if(y > w){
    aux = y;
    y = w;
    w = aux;
  }

  if(y > z){
    aux = y;
    y = z;
    z = aux;
  }

  if(x > y){
    aux = x;
    x = y;
    y = aux;
  }

  printf("%d\n%d\n%d\n%d\n", x,y,z,w);

return 0;
}
