#include <stdio.h>

void result(int matricula2[], char nome2[], double nota2[], int position, double media, int al_pass){

	if(position == 0){

		printf("Matricula: %d Nome: %c Nota: %.1lf\n", matricula2[0], nome2[0], nota2[0]);
		printf("Matricula: %d Nome: %c Nota: %.1lf\n", matricula2[1], nome2[1], nota2[1]);
		
		printf("Media = %.2lf\n", media);

		return;

	}

	if(nota2[position] < nota2[position - 1]){


		int aux_nota2 = nota2[position];
		nota2[position] = nota2[position - 1];
		nota2[position - 1] = aux_nota2;

		result(matricula2, nome2, nota2, position - 1, media, al_pass);

	}

	else{

		result(matricula2, nome2, nota2, position - 1, media, al_pass);

	}

	return;
}

void verify_pass(int matricula[], int matricula2[], char nome[], char nome2[], double nota[], double nota2[], int position, int position2, double media, int al_pass){

	
	if(position < 0){

		
		result(matricula2, nome2, nota2, al_pass - 1, media, al_pass);

		return;


	}

	if(nota[position] > media){

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

void verify_media(int q_alunos, int matricula[], char nome[], double nota[], int position, double media, int al_pass){


	if(position < 0){

		int matricula2[al_pass];
		char nome2[128];
		double nota2[al_pass];

		verify_pass(matricula, matricula2, nome, nome2, nota, nota2, q_alunos - 1, 0, media, al_pass);

	}

	else{

		if(nota[position] > media){


			verify_media(q_alunos, matricula, nome, nota, position - 1, media, al_pass + 1);

		}

		else{

			verify_media(q_alunos, matricula, nome, nota, position - 1, media, al_pass);

		}
	}

	return;

}

void verify_alunos(int q_alunos, int matricula[], char nome[], double nota[], int position, double total_nota){


	if(q_alunos > position){

		scanf("%d", &matricula[position]);	
		scanf(" %c", &nome[position]);	
		scanf("%lf", &nota[position]);

		verify_alunos(q_alunos, matricula, nome, nota, position + 1, nota[position] + total_nota);

	}

	else{


		verify_media(q_alunos, matricula, nome, nota, position - 1, total_nota/q_alunos, 0);


		return;
	}
}

int main(){

	int q_alunos;
	scanf("%d", &q_alunos);

	int matricula[q_alunos];
	char nome[128];
	double nota[q_alunos];

	verify_alunos(q_alunos, matricula, nome, nota, 0, 0);

	return 0;

}