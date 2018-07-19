#include  <stdio.h>

void result(int q_caixas, char t_caixa, int total_caps, int count)
{

  int caps;

  if(count == 7)
  {

    printf("%d\n%d\n", total_caps, (total_caps * 2)/7);

    return;

  }

  if(t_caixa == 'p' || t_caixa == 'P')
  {

    caps = 10 * q_caixas;

    scanf("%d %c", &q_caixas, &t_caixa);

    return result(q_caixas, t_caixa, (caps + total_caps), count + 1);

  }

  if(t_caixa == 'g' || t_caixa == 'G')
  {

    caps = 16 * q_caixas;

    scanf("%d %c", &q_caixas, &t_caixa);

    return result(q_caixas, t_caixa, (caps + total_caps), count + 1);

  }

}


int main()
{
  int q_caixas;
  char t_caixa;
  scanf("%d %c", &q_caixas, &t_caixa);

  result(q_caixas, t_caixa, 0, 0);

  return 0;
}
