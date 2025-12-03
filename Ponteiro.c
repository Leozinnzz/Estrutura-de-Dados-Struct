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

#define MAX 100

//escolher a forma de ordenar, nome, id, crescente, decressente

typedef struct { 
	int id;
	char nome[100];
	int idade;
	float altura;
} Pessoa;

void cadastrarPessoa(Pessoa* p, int* cont){
	p->id = *cont+1;
	*cont += 1;
	input(STR, "Nome: ",p->nome);
	input(INT, "Idade: ",&p->idade);
	input(FLOAT, "Altura: ",&p->altura);
}


int interface() {
	printf("1 - Cadrastar pessoa\n");
	printf("2 - Ordernar pessoa\n");
	printf("3 - Listar pessoa\n");
	int opc; 
	input(INT, "\nOpção desejada: ", &opc);
	return opc;
}

void listarPessoa(Pessoa p[], int cont) {
	for(int i = 0; i < cont; i++) {
		printf("Pessoa: %d\n", p[i].id);
		printf("Nome: %s\n", p[i].nome);
		printf("Idade: %d\n", p[i].idade);
		printf("Altura: %.2f\n", p[i].altura);
		printf("\n");
	}
}

void ordenar(Pessoa* p, int cont) {
	int j;
	for(int i = 0; i < cont; i++) {
		Pessoa key = p[i];
		j = i-1;
	
		while(j >= 0 && strcmp(p[j].nome, key.nome) > 0) {
			p[j + 1] = p[j];
			j--; 
		}
	
		p[j+1] = key;
	}
}

int main() {
	
	Pessoa p[MAX];
	int cont = 0;
	do {
		switch(interface()){
			case 1: 
				cadastrarPessoa(&p[cont], &cont);
				break;
			case 2: 
				ordenar(p, cont);
				break;
			case 3: 
				listarPessoa(p, cont);
				break;
			case 0:
				return 0;
			default:
				printf("\nOpção invalida! Tente uma opção valida.\n");
				break;
		}
	}while(1);
}


