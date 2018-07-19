#include  <stdio.h>

void result(int n_v, int v_m, int count)
{

  int aux;

  if (n_v == 999) // Parada do programa.
  {

    double multas = 12.89 * v_m;
    printf("%.2lf\n%d\n", multas, count);

    return;

  }

  if (n_v > 2) // Condição para multar as casas.
  {

    aux = (n_v - 2);

    scanf("%d", &n_v);

    return result(n_v, aux + v_m, count + 1);

  }

  if(n_v >= 0 && n_v <= 2) // Condição para não multar as casas.
  {

    aux = 0;

    scanf("%d", &n_v);

    return result(n_v, aux + v_m, count + 0);

  }

}

int main()
{

  int n_v; // Números de veículos.
  scanf("%d", &n_v);

  result(n_v, 0, 0);

  return 0;
}
