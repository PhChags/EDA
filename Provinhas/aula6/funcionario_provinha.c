#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

void insere_5_funcionarios(FILE *out) {
	printf("Inserindo 5 funcionários no arquivo...");

	TFunc *f1 = funcionario(1, "Ana", "000.000.000-00", "01/01/1980", 3000);
	salva(f1, out);
	free(f1);
	TFunc *f2 = funcionario(2, "Carlos", "111.111.111-11", "01/01/1990", 500);
	salva(f2, out);
	free(f2);
	TFunc *f3 = funcionario(3, "Fátima", "222.222.222-22", "02/02/1980", 1000);
	salva(f3, out);
	free(f3);
	TFunc *f4 = funcionario(4, "Marcelo", "333.333.333-33", "03/03/1990", 1500);
	salva(f4, out);
	free(f4);
	TFunc *f5 = funcionario(5, "Silvia", "444.444.444-44", "04/04/1980", 900);
	salva(f5, out);
	free(f5);
}

void le_funcionarios(FILE *in) {
	printf("\n\nLendo funcionários do arquivo...\n\n");
	rewind(in);
	TFunc *f;
	while ((f = le(in)) != NULL) {
		imprime(f);
		free(f);
	}
}

void le_segundo_funcionario(FILE *in) {
	printf("\n\nLendo segundo funcionário do arquivo...\n\n");
	//tamanho() indica quantos bytes vamos pular, o que aqui é igual ao tamanho de um registro
	//(vamos pular o primeiro e nos posicionar no início do segundo)
	//** ATENÇÃO: não usar sizeof(Funcionario), pois ele pode retornar valor maior que o tamanho ocupado em disco,
	//			devido a alinhamento automático (ver https://en.wikipedia.org/wiki/Data_structure_alignment))
	//SEEK_SET indica o início do arquivo
	//ao final, o cursor estará posicionado em 0 + tamanho() +1
	fseek(in, tamanho(), SEEK_SET);
	TFunc *f = le(in);
	if (f != NULL) {
		imprime(f);
		free(f);
	}
}

void adiciona_funcionario(FILE *in) {
	printf("\n\nAdicionando funcionário no final do arquivo...\n\n");
	//pula 5 registros para posicionar no início do final do arquivo
	fseek(in, tamanho() * 5, SEEK_SET);
	TFunc *f = funcionario(6, "Bruna", "666.666.666-66", "06/06/1980", 2500);
	salva(f, in);
	free(f);

	//lê funcionário que acabou de ser gravado
	//posiciona novamente o cursor no início desse registro
	fseek(in, tamanho() * 5, SEEK_SET);
	TFunc *f6 = le(in);
	if (f6 != NULL) {
		imprime(f6);
		free(f6);
	}
}

void sobrescreve_quarto_funcionario(FILE *in) {
	printf("\n\nSobrescrevendo quarto funcionário do arquivo...\n\n");
	//pula primeiros 3 registros para posicionar no início do quarto registro
	fseek(in, tamanho() * 3, SEEK_SET);
	TFunc *f4 = funcionario(7, "Catarina", "777.777.777-77", "07/07/1990", 5000);
	salva(f4, in);
	free(f4);

	//lê funcionário que acabou de ser gravado
	//posiciona novamente o cursor no início desse registro
	fseek(in, tamanho() * 3, SEEK_SET);
	TFunc *f = le(in);
	if (f != NULL) {
		imprime(f);
		free(f);
	}
}

//COPIAR A SUA SOLUCAO FEITA EM AULA AQUI!
//Essa funcao deve receber o numero i do registro a ser alterado
void altera_nome(FILE *in, int i, char* novo_nome) {
		//garante que o novo campo nome tenha tamanho de 50 char
		char nome[50];
		memset(nome, 0, sizeof(char)*50);
		strcpy(nome, novo_nome);

		printf("\n\nSobrescrevendo funcionário %d...\n\n", i);

		//recupera registro da posicao i
		//posicionar o cursor
		fseek(in, tamanho() * (i-1), SEEK_SET);

		//ler o registro
		TFunc *f = le(in);

		//substitui o nome e salva no mesmo lugar que leu
		//reposicionar o cursor antes de salvar
		if (f != NULL) {
			strcpy(f->nome, nome);
			imprime(f);
			fseek(in, tamanho() * (i - 1), SEEK_SET);
			salva(f, in);
			free(f);
		}
}

//Essa funcao deve receber o numero i do registro a ser alterado
void altera_ultimo_nome(FILE *in, char* novo_nome) {
	char nome[50];
	memset(nome, 0, sizeof(char)*50);
	strcpy(nome, novo_nome);
	printf("%s\n", nome);

	printf("\n\nSobrescrevendo ultimo funcionário...\n\n");

  	fseek(in, -tamanho(), SEEK_END);
	
	TFunc *f = le(in);

	if (f != NULL) {
		strcpy(f->nome, nome);
		imprime(f);
		fseek(in, -tamanho(), SEEK_END);
		salva(f, in);
		free(f);
	}
}

int main(int argc, char** argv) {
	//declara ponteiro para arquivo
	FILE *out;
	//abre arquivo
	if ((out = fopen("funcionario.dat", "w+b")) == NULL) {
		printf("Erro ao abrir arquivo\n");
		exit(1);
	}
	else {
		//insere funcionários
		insere_5_funcionarios(out);
		//volta ao início do arquivo e lê os funcionários inseridos
		le_funcionarios(out);
		//volta ao início do arquivo e lê o segundo funcionário
		le_segundo_funcionario(out);
		//grava mais um funcionário no final do arquivo
		adiciona_funcionario(out);
		//sobrescreve quarto funcionário
		sobrescreve_quarto_funcionario(out);
		//lendo o arquivo todo novamente
		le_funcionarios(out);
		altera_nome(out, 1, "Pedro");
		altera_ultimo_nome(out, "Gabriel");
		le_funcionarios(out);
		//fecha arquivo
		fclose(out);
	}
}

