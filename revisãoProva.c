/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


#define SIZED 50

typedef struct{
	int codigo;
	char nome[100];
	int periodo;
	int matriculas[50];
	char alunosMatriculados[50][100];
	int contAM;
	int matricula_cont;
}Disciplina;

typedef struct{
	char nome[100];
	int periodo;
}historicD;

typedef struct{
	int id;
	char nome[100];
	historicD disciplinas[50]; 
	int cont_diciplina;
}Aluno;

//datasets
typedef struct{
	Disciplina materias[100];
	int cont;
}dsDisciplinas;

//datasets
typedef struct {
	Aluno list[100];
	int cont;
}dsAlunos;

int interface(); 

void next();

void cadastrarAluno(Aluno a, dsAlunos* qtd);

void cadastrarDisciplina(Disciplina d, dsDisciplinas* qtd);

Aluno setAluno();

Disciplina setDisciplina(dsDisciplinas* qtd);

dsAlunos criarListaA();

dsDisciplinas criarListaD();

void matricularAluno(dsAlunos* qtdA, dsDisciplinas* qtdD);

Aluno* buscarAluno(char nome[], dsAlunos* qtd);

void chamada(dsDisciplinas* d);

int alunoRepet(int id, Disciplina* qtd);

void cancelarMatricula(Aluno* a, Disciplina* d);

void excluir(dsAlunos* a, dsDisciplinas* d);

void ordenarAlunos(Disciplina* d);

void ordenarDisciplina(Aluno* a);

void historico(dsAlunos* a, dsDisciplinas* d);

int main() {
	
	dsAlunos listaA = criarListaA();
	dsDisciplinas listaD = criarListaD();
   
   do {
		switch(interface()) {
			case 1:
				Aluno a = setAluno();
				cadastrarAluno(a, &listaA);
				break;
			case 2:
				Disciplina d = setDisciplina(&listaD);
				cadastrarDisciplina(d, &listaD);
				break;
			case 3: 
				matricularAluno(&listaA, &listaD);
				break;
			case 4: 
				excluir(&listaA, &listaD);
				break;
			case 5: 
				chamada(&listaD);
				break;
			case 6: 
				historico(&listaA, &listaD);
				break;
			case 0:
				printf("==========Programa encerrado=========");
				return 0;
			default: 
				printf("Digite uma opção valida!");
				break;
		}
	}while(1);
}


void next(){
	while(getchar() != '\n');
	getchar();
	system("clear");
}

int interface(){
	printf("\n==============Menu==============\n");
	printf("==== 1 - cadastrar Aluno ====\n");
	printf("==== 2 - cadastrar Disciplina ====\n");
	printf("==== 3 - Matricular Aluno ====\n");
	printf("==== 4 - cancelar matricula ====\n");
	printf("==== 5 - Fazer chamada ====\n");
	printf("==== 6 - Historico do aluno ====\n");
	int opc; 
	
	printf("\nDigite uma opção: ");
	scanf(" %d", &opc);
	
	return opc;
}

Aluno setAluno(){
	Aluno a;
	printf("Nome: ");
	scanf(" %[^\n]", a.nome);
	a.cont_diciplina = 0;
	return a;
}

Disciplina setDisciplina(dsDisciplinas* qtd){
	Disciplina d;
	d.matricula_cont = 0;
	d.contAM = 0;
	input(STR, "Digite o nome da disciplina: ", d.nome);
	input(INT, "Digite o periodo da disciplina: ", &d.periodo);
	return d;
}

dsAlunos criarListaA(){
	dsAlunos novoAluno;
	novoAluno.cont = 0;
	return novoAluno;
}

dsDisciplinas criarListaD(){
	dsDisciplinas novoD;
	novoD.cont = 0;
	return novoD;
}

void cadastrarDisciplina(Disciplina d, dsDisciplinas* qtd){
	d.codigo = qtd->cont+1;
	qtd->materias[qtd->cont] = d;
	qtd->cont++;
}



void cadastrarAluno(Aluno a, dsAlunos* qtd){
	a.id = qtd->cont+1;
	qtd->list[qtd->cont] = a;
	qtd->cont++;
}

Aluno* buscarAluno(char nome[], dsAlunos* qtd){
	for(int i = 0; i < qtd->cont; i++){
		if(strcmp(nome, qtd->list[i].nome) == 0)
			return &qtd->list[i];
	}
	return NULL;
}

Disciplina* buscarDisciplina(char nomeD[], dsDisciplinas* qtd){
	for(int i = 0; i < qtd->cont; i++){
		if(!strcmp(nomeD, qtd->materias[i].nome))
			return &qtd->materias[i];
	}
	return NULL;
}

void chamada(dsDisciplinas* qtd){
	char nomeD[100];
	
	input(STR, "Digite o nome da Disciplina: ", nomeD);
	
	Disciplina* alvoD = buscarDisciplina(nomeD, qtd);
	
	if(!alvoD) {
		printf("Disciplina nao encontrada! Tente novamente... ");
		next();
		return;
	}
	
	ordenarAlunos(alvoD);
	
	for(int i = 0; i < alvoD->contAM; i++) {
			printf("Nome: %s\n", alvoD->alunosMatriculados[i]);
	}
}


int alunoRepet(int id, Disciplina* d){
	for(int i = 0; i < d->matricula_cont; i++) {
		if(d->matriculas[i] == id)
			return 1;
	}
	return 0;
}


void matricularAluno(dsAlunos* qtdA, dsDisciplinas* qtdD){
	char nome[100];
	char nomeD[100];
	
	input(STR, "Digite o nome do aluno: ", nome);
	
	Aluno* alvoA = buscarAluno(nome, qtdA);
	if(!alvoA){ 
		printf("Nome do aluno não encontrado! Tente novamente... ");
		next();
		return;
	}

	input(STR, "Digite o nome da disciplina:  ", nomeD);
	
	Disciplina* alvoD = buscarDisciplina(nomeD, qtdD);
	
	if(!alvoD) {
		printf("Nome da disciplina não encontrada\n");
		next();
		return;
	}

	if(alunoRepet(alvoA->id, alvoD)){
		printf("Aluno registrado na mesma diciplina!... Tente novamente \n");
		next();
		return;
	}
	
	
	alvoD->matriculas[alvoD->matricula_cont] = alvoA->id;
	
	strcpy(alvoD->alunosMatriculados[alvoD->contAM], alvoA->nome);
	
	alvoD->matricula_cont++;
	
	alvoD->contAM++;
	strcpy(alvoA->disciplinas[alvoA->cont_diciplina].nome, alvoD->nome);
	
	alvoA->disciplinas[alvoA->cont_diciplina].periodo = alvoD->periodo;
	
	alvoA->cont_diciplina++;
	
}

void excluir(dsAlunos* qtdA, dsDisciplinas* qtdD){
	char nome[100];
	char nomeD[100];
	
	input(STR, "Digite o nome para cancelar a matricula: ", nome);
	
	Aluno* alvoA = buscarAluno(nome, qtdA);
	
	if(!alvoA){ 
		printf("Nome do aluno não encontrado! Tente novamente... ");
		next();
		return;
	}
	
	input(STR, "Digite a Disciplina que voce quer remove-lo: ", nomeD);
	
	Disciplina* alvoD = buscarDisciplina(nomeD, qtdD);
	
	if(!alvoD){ 
		printf("Discipçina nao encontrada! Tente novamente... ");
		next();
		return;
	}
	
	printf("matricula cancelada do aluno %s! Pressione enter para continuar... ", alvoA->nome);
	next();
	cancelarMatricula(alvoA, alvoD);

}

void ordenarAlunos(Disciplina* d){ 
	int j;
	char key[100];
	for(int i = 0; i < d->contAM; i++) {
		strcpy(key, d->alunosMatriculados[i]);
		j = i-1;
		
		while( j >= 0 && strcmp(d->alunosMatriculados[j], key) > 0){
			strcpy(d->alunosMatriculados[j+1], d->alunosMatriculados[j]);
			j--;
		}
		strcpy(d->alunosMatriculados[j+1], key);
	}
}


void ordenarDisciplina(Aluno* a){
	int j;
	historicD key;
	for(int i = 0; i < a->cont_diciplina; i++) {
		key = a->disciplinas[i];
		j = i-1;
		
		while( j >= 0 && a->disciplinas[j].periodo > key.periodo) {
			a->disciplinas[j+1] = a->disciplinas[j];
			j--;
		}
		a->disciplinas[j+1] = key;
	}
}


void historico(dsAlunos* qtdA, dsDisciplinas* qtdD){
	char nome[100];
	
	input(STR, "Digite o nome para o historico: ", nome);
	
	Aluno* alunoH = buscarAluno(nome, qtdA);
	
	
	if(!alunoH) {
		printf("O nome desse aluno nao existe! Tente novamente...");
		next();
		return;
	}
	
	ordenarDisciplina(alunoH);
	
	for(int i = 0; i < alunoH->cont_diciplina; i++) {
		printf("Nome da disciplina: %s", alunoH->disciplinas[i].nome);
		printf("Periodo: %d\n", alunoH->disciplinas[i].periodo);
	}
}

void cancelarMatricula(Aluno *a, Disciplina* d){
	//remover da disciplina
	for(int i = 0; i < d->matricula_cont; i++) {
		if(a->id == d->matriculas[i]) {
			for(int j = i; j < d->matricula_cont - 1; j++) {
				d->matriculas[j] = d->matriculas[j+1];
				strcpy(d->alunosMatriculados[j], d->alunosMatriculados[j+1]);
			}
			
			d->matricula_cont--;
			d->contAM--;
			break;
		}
	}
	//remover do historico
	for(int i = 0; i < a->cont_diciplina; i++) {
		if(!strcmp(a->disciplinas[i].nome, d->nome)) {
			
			for(int j = i; j < a->cont_diciplina - 1; j++) {
				a ->disciplinas[j] = a->disciplinas[j+1];
			}
			a->cont_diciplina--;
			break;
		}
	}
}



