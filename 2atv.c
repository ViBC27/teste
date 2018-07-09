#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  int aux;
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);

  if(x > z)
  {
    aux = x;
    x = z;
    z = aux;
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

  printf("%d\n%d\n%d\n", x,y,z);

return 0;
}
