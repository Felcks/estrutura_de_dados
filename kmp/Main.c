#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* kmp(char* padrao, int tam){

	int* vetor = calloc(tam, sizeof(int));
	vetor[0] = -1;

	int x = 0;
	for(int i = 1; i < tam; i++){
		if(padrao[i] == padrao[x]){
			x++;
			vetor[i] = x;
		}
		else{
			x = 0;
			vetor[i] = x;
		}
	}

	return vetor;
}

int search(char* txt, char* padrao, int* v){
	
	int i = 0;
	int j = 0;

	int tam = strlen(txt);
	int tamP = strlen(padrao);

	for(i = 0, j = 0; i < tam && j < tamP; i++, j++){
		while( (j > 0) && txt[i] != padrao[j])
			j = v[j];

	}

	if(j == tamP){
		return i - tamP;
	}
	else
		return -1;
}

int main(int argc, char const *argv[])
{
	char* txt = "BBBBBBBBBBBBBBB";
	char* padrao = "ABCDABD";
	int* v = kmp(padrao, 7);

	// for(int i = 0; i < 7; i++){
	// 	printf("%i ", v[i]);
	// }

	// printf("\n");

	int a = search(txt, padrao, v);
	printf("a %i\n", a);
	return 0;
}