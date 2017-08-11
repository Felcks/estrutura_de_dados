#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadDupla.h"

int main(void){
	
	Lista *li = cria_lista();

	struct aluno* al = cria_aluno(100);
	struct aluno* al2 = cria_aluno(50);
	struct aluno* al3 = cria_aluno(120);

	insere_lista_final(li, *al2);
	insere_lista_final(li, *al);
	insere_lista_ordenada(li, *al3);

	printa_lista(li);
	
	return 0;
}