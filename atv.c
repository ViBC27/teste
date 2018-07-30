#include <stdio.h>

void verify(int number, int count, int count_primo)
{

  if(number == -1){

    return;

  }

  if (number > count)
  {
      if(number % count == 0)
      {

        verify(number, count + 1, count_primo + 1);

      }

      if(number % count != 0)
      {

        verify(number, count + 1, count_primo);

      }
  }

  else{

    if(count_primo == 1) { printf("1\n"); }
    else{ printf("0\n"); }

  }

  scanf("%d", &number);
  verify(number, 1, 0);

}

int main(){

  int number;
  scanf("%d", &number);

  verify(number, 1, 0);

  return 0;
}
