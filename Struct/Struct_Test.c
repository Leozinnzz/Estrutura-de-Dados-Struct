/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char cpf[12];
	char nome[100];
	int idade;
	float peso, altura;
} Pessoa;

Pessoa entrada() {
	Pessoa p;
	
	printf("Digite seu Nome: ");
	scanf(" %[^\n]s", p.nome);
	
	printf("Digite seu CPF: ");
	scanf(" %[^\n]s", p.cpf);
	
	printf("Digite sua idade: ");
	scanf("%d", &p.idade);
	
	printf("Digite seu peso: ");
	scanf("%f", &p.peso);
	
	printf("Digite sua altura: ");
	scanf("%f", &p.altura);
	
	return p;
}

void saida(Pessoa p) { 
	printf("\nDADOS DIGITALIZADOS\n");
	printf("Nome do usuario: %s\n", p.nome);
	printf("Cpf do usuario: %s\n", p.cpf);
	printf("Idade do usuario: %d\n", p.idade);
	printf("Peso do usuario %.2f\n", p.peso);
	printf("Altura do usuario %.2f\n", p.altura);
}

int main() {
    
    Pessoa p = entrada();
    saida(p);

    //the destroyer of codes
}


