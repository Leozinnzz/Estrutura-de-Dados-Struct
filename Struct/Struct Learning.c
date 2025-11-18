#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
	char Rua[100];
	int numero;
	char bairro[100];
	char cidade[100];
} Endereco;

typedef struct {
	char nome[100];
	char cpf[12];
	int idade;
	float altura,peso;
	Endereco residencia;
}Pessoa;


int main() { 
	
	Pessoa cadrasto[N];
	
	int cont = 0;

	while(cont < N) {
		
		Pessoa p;
		
		//Cadrastar pessoa
		
		printf("\nPessoa %d: \n", cont+1);
	
		printf("Nome: ");
		scanf(" %[^\n]s", p.nome);
		
		if(strcmp(p.nome, "exit") == 0)
			break;
			
		printf("Digite seu cpf: ");
		scanf(" %[^\n]s", p.cpf);
	
		printf("Digite sua idade: ");
		scanf(" %d", &p.idade);
	
	
		printf("Digite o peso: ");
		scanf(" %f", &p.peso);
	
		printf("Digite sua altura: ");
		scanf(" %f", &p.altura);
			
		printf("\n Pessoa %d\n", cont+1);
		
		//endereço de cada pessoa
		
		printf("\nEndereço\n");
		
		printf("Digite a rua: ");
		scanf(" %[^\n]s", p.residencia.Rua);
		
		printf("Digite o numero da Rua: ");
		scanf(" %d", &p.residencia.numero);
		
		printf("Digite o nome do Bairro: ");
		scanf(" %[^\n]s", p.residencia.bairro);
		
		printf("Digite a cidade: ");
		scanf(" %[^\n]s", p.residencia.cidade); 
		
		cadrasto[cont++] = p;
		
	
	}
	
	//ordenar o vetor
	int j;
	for(int i = 0; i < cont; i++) { 
		Pessoa key = cadrasto[i];
		j = i - 1;
		
		while(j >= 0 && strcmp(cadrasto[j].nome, key.nome) > 0) {
			cadrasto[j + 1] = cadrasto[j];
			j--;
		}
		
		cadrasto[j+1] = key;
	}
	
	//pessoas cadrastadas
	printf("\nCADRASTO DE PESSOAS ORDENADASS PELO NOME\n");
	for(int i = 0; i < cont; i++) {
		printf("\nPessoa %d:\n", i+1);
        printf("Nome: %s\n", cadrasto[i].nome);
        printf("CPF: %s\n", cadrasto[i].cpf);
        printf("Idade: %d\n", cadrasto[i].idade);
        printf("Peso: %.2f\n", cadrasto[i].peso);
        printf("Altura: %.2f\n", cadrasto[i].altura);
        printf("Endereço: \n Rua: %s\n Numero: %d\n Bairro: %s\n Cidade: %s\n",
        cadrasto[i].residencia.Rua,
        cadrasto[i].residencia.numero,
        cadrasto[i].residencia.bairro,
        cadrasto[i].residencia.cidade);
	}
	
}
