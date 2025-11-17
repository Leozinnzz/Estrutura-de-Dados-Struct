/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>

#define N 3


typedef struct { 
	char nome[N][20];
	int idade[N];
	float altura[N];
} Dados;


Dados interface() { 
	Dados d;
	
	for(int i = 0; i < N; i++) {
		printf("\nUsuario %d\n", i+1);
		printf("Digite um nome: ");
		scanf(" %[^\n]s", d.nome[i]);
		printf("Digite sua idade: ");
		scanf("%d", &d.idade[i]);
		printf("Digite sua altura: ");
		scanf("%f", &d.altura[i]);
	}

	return d;
}

void escreva(Dados d) { 
	for(int i = 0; i < N; i++) {
		printf("\nDADOS CADRASTADOS\n");
		printf("\nUSUARIO %d\n", i+1);
		printf("Nome Digitado: %s\n", d.nome[i]);
		printf("Idade Digitada %d\n", d.idade[i]);
		printf("Altura Digitada: %.2f\n", d.altura[i]);
	}	
	
}

int main() {
	
	Dados d = interface();
	escreva(d);
	

    //the destroyer of codes
}


