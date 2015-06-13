#include <stdio.h>

int main(void)
{
	char url_alunos[]="alunos.txt", url_avaliacao[]="avaliacao.txt", nome[10], sobrenome[10];
	int n_alunos, n_notas;
	float nota1, nota2, nota3, peso1, peso2, peso3, media_aprovacao, media_obtida;
	FILE *alunos, *avaliacao;

	alunos = fopen(url_alunos, "r");
	avaliacao = fopen(url_avaliacao, "w");

	if(alunos == NULL || avaliacao == NULL) {
		printf("Erro, não foi possível abrir o arquivo!!");	
	} else {
		fscanf(alunos,"%d\n", &n_alunos);
		printf("Quantidade de alunos: %d\n", n_alunos);
		fscanf(alunos,"%d\n", &n_notas);
		printf("Quantidade de notas por aluno: %d\n", n_notas);
		fscanf(alunos,"%f %f %f\n", &peso1, &peso2, &peso3);
		printf("Peso das notas: %f %f %f\n", peso1, peso2, peso3);
		fscanf(alunos,"%f\n", &media_aprovacao);
		printf("Média de aprovação: %f\n", media_aprovacao);
		printf("--------------------------------------\n");
		while( (fscanf(alunos,"%s %s,%f,%f,%f\n", nome, sobrenome, &nota1, &nota2, &nota3)) != EOF ) {
			media_obtida = ( (nota1*peso1) + (nota2*peso2) + (nota3*peso3) ) / 8.0;
			printf("Nome: %s %s\n", nome, sobrenome);
			printf("Notas: %f %f %f\n", nota1, nota2, nota3);
			printf("Média: %f\n", media_obtida);
			printf("--------------------------------------\n");	
			fprintf(avaliacao, "%s %s,%.2f\n", nome, sobrenome, media_obtida);
			//fprintf(avaliacao, "%.2f\n",  media_obtida);	
		}
		fclose(alunos);
		fclose(avaliacao);
	}
}