#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void merge(int vetor[], int inicio, int meio, int final);
void mergeSort(int vetor[], int inicio, int final);

int main(void){
	
	int vetor[] = { 23, 4, 67, -8, 90, 54, 21 };
	int* v = (int*)malloc(7 * sizeof(int));

	mergeSort(vetor, 0, 6);
	return 0;
}

void mergeSort(int vetor[], int inicio, int final){

	int meio;
	if(inicio < final){
		meio = (final + inicio) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, final);
		merge(vetor, inicio, meio, final);
	}
}

void merge(int vetor[], int inicio, int meio, int final){

	int temp[100];
	int p1 = inicio;
	int p2 = meio+1;
	int tamanho = final - inicio + 1;
	int fim1 = 0, fim2 = 0;

	int i = 0, j = 0;
	for(i = 0; i < tamanho; i++){

		if(!fim1 && !fim2){
			if(vetor[p1] < vetor[p2])
				temp[i] = vetor[p1++];
			else
				temp[i] = vetor[p2++];

			if(p1 > meio) fim1 = 1;
			if(p2 > final) fim2 = 1;
		}
		else{
			if(!fim1)
				temp[i] = vetor[p1++];
			else
				temp[i] = vetor[p2++];
		}
	}

	int k = 0;
	for(j = 0, k = inicio; j < tamanho; j++, k++){
		vetor[k] = temp[j];
		printf("%i ", temp[j]);
	}
	printf("\n");
}
