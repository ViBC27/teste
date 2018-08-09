#include <stdio.h>

int primo_p(int n, int div, int count)
{
	if (count > n)
	{
		if (div == 2)
		{
			return n;
		}

		else
		{
			primo_p(n + 1, 0, 1);
		}
	}

	else
	{
		if (n % count == 0)
		{
			primo_p(n, div + 1, count + 1);
		}
		else
		{
			primo_p(n, div, count + 1);
		}
	}
}
int primo(int n, int div, int count)
{
	if (count > n)
	{
		return div;
	}

	else
	{
		if (n % count == 0)
		{
			primo(n, div + 1, count + 1);
		}

		else
		{
			primo(n, div, count + 1);
		}
	}
}

void verify(int number, int num, int primo_atual)
{
	if (num >= number)
	{

		printf("%d!/%d\n", num, primo_atual);


		return;
	}

	else
	{
		int n_div = primo(num, 0, 1);


		if (n_div == 2)
		{

			primo_atual = num;

			printf("%d!/%d + ", num, primo_atual);


			verify(number, num + 1, primo_atual);
		}

		else
		{
			int aux_primo = primo_p(primo_atual + 1, 0, 1);


			printf("%d!/%d + ", num, aux_primo);


			verify(number, num + 1, aux_primo);
		}
	}
}
int main()
{
	int number;
	scanf("%d", &number);

	verify(number, 1, 1);
}
