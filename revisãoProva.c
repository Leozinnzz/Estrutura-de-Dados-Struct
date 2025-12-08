/*
============= Leozinzz =================
============= CachyOS --%d/%m/%Y-- =================
============= LI4ever ======================
============= Made-by-Leozinzz-Desktop ===============
*/

#include <stdio.h>
#include <stdlib.h>

void func(int alvo, int v[],int c){
	for(int i=0; i<c; i++)
		if(alvo == v[i])
			for(int j=i; j<c-1; j++)
				v[j] = v[j+1];
}

int main() {
	
	int vet[6] = {11, 75, 82, 92, 2, 7};
	
	
	for(int i = 0; i < 6; i++) {
		printf(" %d ", vet[i]);
	}
	//ordenar  
	for(int i = 0; i < 6; i++) {
		int j, key;
		key = vet[i];
		j = i - 1;
		
		while(j >= 0 && vet[j] > key) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = key;
	} 
	
	printf("\n");
	for(int i = 0; i < 6; i++) {
		printf(" %d ", vet[i]);
	}
	
	//remover ultimo elemento
	
	printf("\n");
	for(int i = 0; i < 6; i++) {
		printf(" %d ", vet[i]);
	}
	

    //the destroyer of codes
}


