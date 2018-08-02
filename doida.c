
#include <stdio.h>
#include <stdlib.h>

void result(int matricula2[], char nome2[], double nota2[], int position, double media, int al_pass)
{
	if (position > al_pass - 1)
	{
		printf("Media = %.2lf\n", media);

	}

	else
	{
		printf("Matricula: %d Nome: %c Nota: %.1lf\n", matricula2[position], nome2[position], nota2[position]);

		result(matricula2, nome2, nota2, position + 1, media, al_pass);

	}
}
void verify_order(int matricula2[], char nome2[], double nota2[], int position, double media, int al_pass, int count)
{
	if (position < al_pass - 1)
	{
		if (nota2[position] > nota2[position + 1])
		{
			double aux_nota2 = nota2[position];
			nota2[position] = nota2[position + 1];
			nota2[position + 1] = aux_nota2;

			char aux_nome2 = nome2[position];
			nome2[position] = nome2[position + 1];
			nome2[position + 1] = aux_nome2;

			int aux_matricula2 = matricula2[position];
			matricula2[position] = matricula2[position + 1];
			matricula2[position + 1] = aux_matricula2;

			verify_order(matricula2, nome2, nota2, position + 1, media, al_pass, count);
		}

		else

		{
			if (nota2[position] == nota2[position + 1])

			{
				if (matricula2[position] > matricula2[position + 1])

				{
					double aux2_nota2 = nota2[position];
					nota2[position] = nota2[position + 1];
					nota2[position + 1] = aux2_nota2;

					char aux2_nome2 = nome2[position];
					nome2[position] = nome2[position + 1];
					nome2[position + 1] = aux2_nome2;

					int aux2_matricula2 = matricula2[position];
					matricula2[position] = matricula2[position + 1];
					matricula2[position + 1] = aux2_matricula2;
				}

				else
				{
					verify_order(matricula2, nome2, nota2, position + 1, media, al_pass, count);
				}
			}

			if (nota2[position] < nota2[position + 1])
			{
				verify_order(matricula2, nome2, nota2, position + 1, media, al_pass, count);
			}
		}
	}

	if (count <= al_pass - 1)
	{
		verify_order(matricula2, nome2, nota2, 0, media, al_pass, count + 1);
	}

}

void verify_pass(int matricula[], int matricula2[], char nome[], char nome2[], double nota[], double nota2[], int position, int position2, double media, int al_pass)
{
	if (position < 0)
	{
		verify_order(matricula2, nome2, nota2, 0, media, al_pass, 0);

		result(matricula2, nome2, nota2, 0, media, al_pass);

		return;
	}

	if (nota[position] > media)
	{
		nota2[position2] = nota[position];
		nome2[position2] = nome[position];
		matricula2[position2] = matricula[position];

		verify_pass(matricula, matricula2, nome, nome2, nota, nota2, position - 1, position2 + 1, media, al_pass);
	}

	else

	{
		verify_pass(matricula, matricula2, nome, nome2, nota, nota2, position - 1, position2, media, al_pass);
	}
}

void verify_media(int q_alunos, int matricula[], char nome[], double nota[], int position, double media, int al_pass)
{
	if (position < 0)
	{
		int matricula2[al_pass];
		char nome2[128];
		double nota2[al_pass];

		verify_pass(matricula, matricula2, nome, nome2, nota, nota2, q_alunos - 1, 0, media, al_pass);
	}

	else
	{
		if (nota[position] > media)
		{
			verify_media(q_alunos, matricula, nome, nota, position - 1, media, al_pass + 1);
		}

		else
		{
			verify_media(q_alunos, matricula, nome, nota, position - 1, media, al_pass);
		}
	}

}

void verify_alunos(int q_alunos, int matricula[], char nome[], double nota[], int position, double total_nota)
{
	if (q_alunos > position)
	{
		scanf("%d", &matricula[position]);
		scanf(" %c", &nome[position]);
		scanf("%lf", &nota[position]);

		verify_alunos(q_alunos, matricula, nome, nota, position + 1, nota[position] + total_nota);
	}

	else
	{
		verify_media(q_alunos, matricula, nome, nota, position - 1, total_nota / q_alunos, 0);

	}
}

int main()
{
	int q_alunos;
	scanf("%d", &q_alunos);

	int matricula[q_alunos];
	char nome[128];
	double nota[q_alunos];

	verify_alunos(q_alunos, matricula, nome, nota, 0, 0);

	return 0;
}
