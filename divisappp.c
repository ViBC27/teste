#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void verify(int number, int resto, int quociente, int count_par)
{
  quociente = number/10;
  resto = number % 10;

  if (resto < 10){

    if (resto % 2 == 0)
    {
      count_par += 1;
    }

    if(quociente % 2 == 0)
    {
      count_par += 1;
    }

    printf("%d\n", count_par);

    return;
  }

  if(resto > 10){

    if(quociente % 2 == 0)
    {

      count_par += 1;

    }

    verify(resto, resto, quociente, count_par);

  }
}

int main()
{
  int number;
  scanf("%d", &number);

  verify(number, 0, 0, 0);

  return 0;
}
