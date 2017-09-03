#include <stdio.h>
#include <stdlib.h>

int particiona(int* v, int inicio, int fim){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = v[inicio];

	while(esq < dir){
		while(v[esq] <= pivo)
			esq++;
		while(v[dir] > pivo)
			dir--;

		if(esq < dir){
			aux = v[esq];
			v[esq] = v[dir];
			v[dir] = aux;
		}
	}

	v[inicio] = v[dir];
	v[dir] = pivo;

	return dir;
}

void quickSort(int* v, int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona(v, inicio, fim);
		quickSort(v, inicio, pivo - 1);
		quickSort(v, pivo+1, fim);
	}
}

int main(void){
	
	int *v = (int*)malloc(10 * sizeof(int));
	int tamanho = 10;
	int i = 0;

	for(i = 0; i < tamanho; i++){
		v[i] = 100 - (i * 10);
	}

	quickSort(v, 0, tamanho-1);

	for(i = 0; i < tamanho; i++){
		printf("print %i\n", v[i]);
	}

	return 0;
}