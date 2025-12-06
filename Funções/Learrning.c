#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char origem[100];
	char destino[100];
	int distancia;
	int tempo;
}Rotas; 

typedef struct {
	Rotas agenda[100];
	int cont;
}dsRotas;

Rotas setRotas();

int interface();

dsRotas criarAgenda();

void registrarRotas(Rotas r, dsRotas* qtdRotas);

void mostrarRotas(Rotas r);

void listarRotas(dsRotas numRotas);

int rotasRepet(char origem[], dsRotas* numRotas);

Rotas *buscarRotas(char origem[], dsRotas* numRotas);

void consultarRotas(dsRotas *numRotas);



int main() {
	dsRotas agenda = criarAgenda();
	
	do {
		switch(interface()){ 
			case 1: 
				Rotas r = setRotas();
				registrarRotas(r, &agenda);
				break;
			case 2: 
				consultarRotas(&agenda);
				break;
			case 3:
				listarRotas(agenda);
				break;
			case 0:
				printf("\nPrograma encerrado.\n");
				return 0;
			default:
				printf("Opcao invalida!\n");
				break;
		}
	}while(1);
}

dsRotas criarAgenda(){
	dsRotas novaRota;
	novaRota.cont = 0;
	return novaRota;
}

int interface(){
	printf("\n=============-VIAGEMS-=============\n");
	printf("0 - Sair\n");
	printf("1- Cadastrar Rotas\n");
	printf("2- Consultar Rotas\n");
	printf("3- Listar Rotas\n");
	int opc; 
	
	printf("\nEscolha uma opção desejada: ");
	scanf(" %d", &opc);
	return opc;
}

Rotas setRotas(){
	Rotas r;
	printf("\n====Rotas====\n");
	printf("Cidade de Origem: ");
	scanf(" %[^\n]s", r.origem);
	printf("Cidade de Destino: ");
	scanf(" %[^\n]s", r.destino);
	printf("Distancia (KM): " );
	scanf(" %d", &r.distancia);
	printf("Tempo de viagem em horas: ");
	scanf(" %d", &r.tempo);
	return r;
}

void registrarRotas(Rotas r, dsRotas* qtdRotas){
	if(rotasRepet(r.origem, qtdRotas)) {
		printf("Erro! Essa rota ja esta cadastrada!\n");
		return;
	}
	
	qtdRotas->agenda[qtdRotas->cont] = r;
	qtdRotas->cont++;
}

Rotas *buscarRotas(char origem[], dsRotas* numRotas) {
	for(int i = 0; i < numRotas->cont; i++) {
		if(strcmp(numRotas->agenda[i].origem, origem) == 0) {
			return &numRotas->agenda[i];
		}
	} 
	return NULL;
}

void mostrarRotas(Rotas r){
	printf("\nCidade de Origem %s\n", r.origem);
	printf("Cidade de Destino %s\n", r.destino);
	printf("Distancia da rota: %d Km\n", r.distancia);
	printf("Tempo da viagem: %d horas\n", r.tempo);
}

void listarRotas(dsRotas numRotas){
	for(int i = 0; i < numRotas.cont; i++) {
		printf("Rota %d:", i+1);
		mostrarRotas(numRotas.agenda[i]);
	}
}

void consultarRotas(dsRotas *numRotas) {
	char origem[100];
	char destinoFinal[100];
	
	printf("Digite a origem da rota: ");
	scanf(" %[^\n]s", origem);
	
	printf("Digite a destino final: ");
	scanf(" %[^\n]s", destinoFinal);
	
	int totalDist = 0;
	int totalTemp = 0;
	int viagens = 0;
	
	char cidadeAtual[100];
	strcpy(cidadeAtual, origem);
	
	while(strcmp(cidadeAtual, destinoFinal) != 0) {
		Rotas *rota = buscarRotas(cidadeAtual, numRotas);
		
		if(rota == NULL){ 
			printf("\nRota impossivel! Nao existe saida da cidade %s.\n", cidadeAtual);
			return;
		}
		
		totalDist += rota->distancia;
		totalTemp += rota->tempo;
		viagens++;
		
		
		strcpy(cidadeAtual, rota->destino);
	}
	
	 printf("\n==== RESULTADO DA CONSULTA ====\n");
	 printf("Origem: %s\n", origem);
	 printf("Destino Final: %s\n", destinoFinal);
	 printf("Distancia total em kilometros: %d\n", totalDist);
	 printf("Tempo total de viagem em horas: %d\n", totalTemp);
	 printf("Total de viagens: %d\n", viagens);
}

int rotasRepet(char origem[], dsRotas* numRotas){
	for(int i = 0; i < numRotas->cont; i++) 
		if(strcmp(numRotas->agenda[i].origem, origem) == 0)
			return 1;
	return 0;
}


