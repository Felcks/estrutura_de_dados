#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila {
	int inicio, final, qtd;
	struct aluno dados[MAX];
};

Fila* cria_fila(){

	Fila *fi = (Fila*)malloc(sizeof(Fila));
	if(fi != NULL){
		fi->inicio = 0;
		fi->final = 0;
		fi->qtd = 0;
	}

	return fi;
}

void libera_fila(Fila* fi){

	free(fi);
}

int tamanho_fila(Fila* fi){
	
	if(fi == NULL)
		return -1;

	return fi->qtd;
}

int fila_cheia(Fila* fi){

	if(fi == NULL) return -1;

	return fi->qtd == MAX;
}

int fila_vazia(Fila* fi){

	if(fi == NULL) return -1;

	return fi->qtd == 0;
}

int insere_fila(Fila* fi, struct aluno al){

	if(fi == NULL) return 0;

	if(fila_cheia(fi)) return 0;

	fi->dados[fi->final] = al;
	fi->final = (fi->final + 1) % MAX;
	fi->qtd++;
	return 1;
}

int remove_fila(Fila* fi){

	if(fi == NULL) return 0;

	if(fila_vazia(fi)) return 0;

	fi->inicio = (fi->inicio + 1) % MAX;
	fi->qtd--;
	return 1;
}

int consulta_fila(Fila* fi, struct aluno *al){

	if(fi == NULL) return 0;

	if(fila_vazia(fi)) return 0;

	*al = fi->dados[fi->inicio];
	return 1;
}	

void printa_fila(Fila* fi){

	if(fi == NULL) return;

	if(fila_vazia(fi)) return;

	for(int i = fi->inicio; i < fi->final; i++){
		printf("%i\n", fi->dados[i].matricula);
	}
}

struct aluno* cria_aluno(int matricula){
	struct aluno* al = (struct aluno*)malloc(sizeof(struct aluno));
	al->matricula = matricula;

	return al; 
} 
