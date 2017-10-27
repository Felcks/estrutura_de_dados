#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* v, int tamanho){

	int i = 0, j = 0;
	for(i = 0; i < tamanho - 1; i++){
		for(j = i + 1; j < tamanho; j++){
			if(v[i] > v[j]){
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}	
		}
	}
}

void bubbleSort2(int* v, int tamanho){

	int i, continua, aux, fim = tamanho;
	do{
		continua = 0;
		for(i = 0; i < fim-1; i++){
			if(v[i] > v[i + 1]){
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				continua = 1;
			}
		}
		fim--;
	} while(continua != 0);
}

int main(void){
	
	int *v = (int*)malloc(10 * sizeof(int));
	int tamanho = 10;
	int i = 0;

	for(i = 0; i < tamanho; i++){
		v[i] = 100 - (i * 10);
	}

	bubbleSort2(v, tamanho);

	for(i = 0; i < tamanho; i++){
		printf("print %i\n", v[i]);
	}

	return 0;
}