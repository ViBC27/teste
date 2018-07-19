#include  <stdio.h>

int result(int a, int b, int n, int count)
{

  if(n > 1)
  {

      if(n % 2 == 0){

        n = n/2;

        printf("%d\n", n);

        return result(a, b, n, count + 1);

      }

      else{

        n = (n * 3) + 1;

        printf("%d\n", n);

        return result(a, b, n, count + 1);

      }
  }

  else
  {

    printf("%d %d %d\n", a,b, count + 1);

    return 0;

  }

}


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int n = b - a;

    result(a, b, n, 0);

    return 0;
}
