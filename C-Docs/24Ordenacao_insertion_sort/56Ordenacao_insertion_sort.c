#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tamanho = 5; //Variavel global

int preencher_vetor(int v[]) { //Preenche vetor com numeros aleatorios
	srand(time(NULL));
	for (int cont = 0; cont < tamanho; cont++) {
		v[cont] = rand()%9;
	}
	return 0;
}


int ord_insertion(int v[]) {    
	int aux = 0;
	for (int i = 1; i < tamanho; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] < v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	return 0;
}


int mostra_vetor(int v[]) {
	for (int cont = 0; cont < tamanho; cont++) {
		printf(" (%d)", v[cont]);
	}
	printf("\n");
	return 0;
}


int main() { //Programa principal
	int vet[tamanho];
	preencher_vetor(vet);
	printf(" - Antes: ");
	mostra_vetor(vet);
	ord_insertion(vet); //Ordena jogando os menores pra esquerda
	printf(" - Depois: ");
	mostra_vetor(vet);
	return 0;
}
