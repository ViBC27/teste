#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

  double ph;
  scanf("%lf", &ph);

  if (ph==7){
    printf("Neutra\n");
  }
  else{
    if(ph>7){
      printf("Basica\n");
    }
    else{
      printf("Acida\n");
    }
  }
return 0;
}
