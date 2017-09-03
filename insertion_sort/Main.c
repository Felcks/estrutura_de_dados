#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int tamanho){
	int i, j, aux;

	for(i = 1; i < tamanho; i++){
		aux = v[i];
		for(j = i; (j > 0) && (aux < v[j - 1]); j--){
			v[j] = v[j - 1];
		}
		v[j] = aux;
	}
}

int main(void){
	
	int *v = (int*)malloc(10 * sizeof(int));
	int tamanho = 10;
	int i = 0;

	for(i = 0; i < tamanho; i++){
		v[i] = 100 - (i * 10);
	}

	insertionSort(v, tamanho);

	for(i = 0; i < tamanho; i++){
		printf("print %i\n", v[i]);
	}

	return 0;
}