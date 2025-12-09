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


//REVISÃO FINAL PARA A PROVA #02
//---- SISTEMA ACADÊMICO -------

//1 - CADASTRAR ALUNO
	//MATRICULA(I: AUTOINCREMENTO) 
	//NOME(S)

//2 - CADASTRAR DISCIPLINA
	//CODIGO(I: AUTOINCREMENTO)
	//NOME(S)
	//PERIODO(I)
	//MATRICULAS(I[50])

//3 - MATRICULAR ALUNO
	//MATRICULAR UM ALUNO EM UMA DETERMINADA DISCIPLINA
	//BUSCAR DISCIPLINA E ALUNO ATRAVÉS DE NOMES.
	//SOMENTE 1 MATRICULA POR ALUNO/DISCIPLINA (VALIDAR!)

//4 - CANCELAR MATRICULA (EXCLUIR MATRICULA)
	//EXCLUIR A MATRICULA DE UM DETERMINADO ALUNO 
	//EM UMA DISCIPLINA.

//5 - FAZER CHAMADA
	//SOLICITAR NOME DE DISCIPLINA.
	//LISTAR (EM ORDEM ALFABETICA) OS NOMES DOS ALUNOS
	//MATRICULADOS.
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.

//6 - HISTORICO DO ALUNO
	//SOLICITAR NOME DO ALUNO.
	//LISTAR TODAS AS DISCIPLINAS MATRICULADAS
	//(EM ORDEM DE PERIODO)
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.


#define SIZED 50

typedef struct{
	int codigo;
	char nome[100];
	int periodo;
	int matriculas[50];
	int matricula_cont;
}Disciplina;

typedef struct{
	int id;
	char nome[100];
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

void mostrarAluno(Aluno a);

void mostrarDisciplina(Disciplina d);

int alunoRepet(int id, Disciplina* qtd);

void cancelarMatricula(Aluno* a, Disciplina* d);

void excluir(Aluno a);

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
				cancelarMatricula(&a, &d);
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
	return a;
}

Disciplina setDisciplina(dsDisciplinas* qtd){
	Disciplina d;
	d.matricula_cont = 0;
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

void mostrarAluno(Aluno a){
	printf("Numero da matricula: %d", a.id);
	printf("Nome: %s", a.nome);
}

void mostrarDisciplina(Disciplina d){
	printf("Codigo da disciplina: %d", d.codigo);
	printf("nome da disciplina: %s", d.nome);
	printf("Periodo da disciplina: %d", d.periodo);
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

	printf("Retorno: %d\n", alunoRepet(alvoA->id, alvoD));
	if(alunoRepet(alvoA->id, alvoD)){
		printf("Aluno registrado na mesma diciplina!... Tente novamente \n");
		next();
		return;
	}
	
	
	alvoD->matriculas[alvoD->matricula_cont] = alvoA->id;	
	alvoD->matricula_cont++;
	
}

void excluir(dsAlunos qtdA, dsDisciplinas* qtdD){
	input(STR, "Digite o nome para cancelar a matricula: ", nome);
	Aluno* alvoA =
	//termianr
	
	Discip
	
	cancelarMatricula(alvo, dis)
	


}

void cancelarMatricula(Aluno *a, Disciplina* d){
	for(int i = 0; i < d->matricula_cont; i++) {
		if(a->id == d->matriculas[i]) {
			for(int j = i; j < d->matricula_cont - 1; j++) {
				d->matriculas[j] = d->matriculas[j+1];
				d->matricula_cont--;
			}
		}
	}
}



