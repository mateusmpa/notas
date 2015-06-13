#include <stdio.h>

int main(void)
{
	char url_alunos[]="alunos.txt", url_avaliacao[]="avaliacao.txt", nome[10], sobrenome[10], *status;
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
		while(!feof(alunos)) { 
			fscanf(alunos,"%s %[^,]", nome, sobrenome);
			fseek(alunos, +1, SEEK_CUR);
			fscanf(alunos, "%f,%f,%f\n", &nota1, &nota2, &nota3);
			media_obtida = ( (nota1*peso1) + (nota2*peso2) + (nota3*peso3) ) / 8.0;
			if(media_obtida >= media_aprovacao) {
				status = "Aprovado";
			} else {
				status = "Reprovado";
			}
			printf("Nome: %s\n", nome);
			printf("Sobrenome: %s\n", sobrenome);
			printf("Notas: %f %f %f\n", nota1, nota2, nota3);
			printf("Média: %f\n", media_obtida);
			printf("Status: %s\n", status);
			printf("--------------------------------------\n");	
			fprintf(avaliacao, "%s %s,%.1f,%s\n", nome, sobrenome, media_obtida, status);
		}
		fclose(alunos);
		fclose(avaliacao);
	}
}
