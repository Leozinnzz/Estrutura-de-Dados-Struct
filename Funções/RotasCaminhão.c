/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char origem[100];
	char destino[100];
	int tempo;
	int distancia;
}Rota;

typedef struct{
	Rota lista[100];
	int cont;
}listRotas;

listRotas criarAgenda();

void registrarRota(Rota r, listRotas* numR);

int interface();

Rota setRotas(listRotas* numR);

Rota* buscarRotas(char origem[], listRotas* numR);

void mostarRota(Rota r);

void listarRotas(listRotas numR);

int rotasRepetidas(char origem[], listRotas* numR);

void ConsultarRotas(listRotas* numR);

int main() {
    
    
    listRotas agenda = criarAgenda();
    
	do {
		switch(interface()){
			case 1:
				Rota r = setRotas(&agenda);
				registrarRota(r, &agenda);
				break;
			case 2: 
				ConsultarRotas(&agenda);
				break;
			case 3: 
				listarRotas(agenda);
				break;
			case 0:
				return 0;
			default: 
				printf("\nDigite uma opção valida!\n");
		}
		
	}while(1);
    //the destroyer of codes
}

listRotas criarAgenda(){
	listRotas novaRota;
	novaRota.cont = 0;
	return novaRota;
}

int interface(){
	printf("\n=======-MENU-=======\n");
	printf("0 - encerrar programa\n");
	printf("1 - cadastrar nova rota\n");
	printf("2 - Consultar nova rota\n");
	printf("3 - listar rotas disponiveis\n");
	int opc; 
	printf("\nEscolha uma opção: ");
	scanf(" %d", &opc);
	return opc;
}


Rota setRotas(listRotas* numR){
	Rota r; 
	printf("Cidade de origem: ");
	scanf(" %[^\n]s", r.origem);
	printf("Cidade de destino: ");
	scanf(" %[^\n]s", r.destino);
	printf("Distancia: ");
	scanf(" %d", &r.distancia);
	printf("Tempo de viagem: ");
	scanf(" %d", &r.tempo);
	return r;
}

void registrarRota(Rota r, listRotas* numR){
	if(rotasRepetidas(r.origem, numR)) {
		printf("\nEssa Rota ja existe! Tente novamente... ");
		while(getchar() != '\n');
		getchar();
		return;
	}
	numR->lista[numR->cont] = r;
	numR->cont++;
}

Rota* buscarRotas(char origem[], listRotas* numR){
	for(int i = 0; i < numR->cont; i++){
		if(strcmp(numR->lista[i].origem, origem) == 0) 
			return &numR->lista[i];
	}
	return NULL;
}



void mostarRota(Rota r){
	printf("Orgiem: %s\n", r.origem);
	printf("Destino: %s\n", r.destino);
	printf("Distancia %dkm\n", r.distancia);
	printf("Tempo de viagem %d horas\n", r.tempo);
}

void listarRotas(listRotas numR){
	for(int i = 0; i < numR.cont; i++){
		printf("Rota %d: \n", i+1);
		mostarRota(numR.lista[i]);
	}
}

int rotasRepetidas(char origem[], listRotas* numR){
	for(int i = 0; i < numR->cont; i++) {
		if(strcmp(numR->lista[i].origem, origem) == 0)
			return 1;
	}
	return 0;
}

void ConsultarRotas(listRotas* numR){
	char origem[100];
	char destinoFinal[100];
	
	printf("Digite a origem da sua rota: ");
	scanf(" %[^\n]s", origem);
	
	printf("Digite o destino final da sua rota: ");
	scanf(" %[^\n]s", destinoFinal);
	
	int somaDist = 0;
	int somaTemp = 0;
	int viagens = 0;
	
	char cidadeAtual[100];
	strcpy(cidadeAtual, origem);
	while(strcmp(cidadeAtual, destinoFinal) != 0) {
		Rota* rota = buscarRotas(cidadeAtual, numR);
		
		if(rota == NULL) {
			printf("\nRota impossivel! Nao existe essa rota ");
			while(getchar() != '\n');
			getchar();
			return;
		}
		
		somaDist += rota->distancia;
		somaTemp += rota->tempo;
		viagens++;
		
		strcpy(cidadeAtual, rota->destino);
	}
	printf("\n==== RESULTADO DA CONSULTA ====\n");
	printf("saiu de %s\n", origem);
	printf("Com destino para %s\n", destinoFinal);
	printf("Distancia total %dkm\n", somaDist);
	printf("Tempo total %d\n", somaTemp);
	printf("Total de viagens %d\n", viagens);
}


