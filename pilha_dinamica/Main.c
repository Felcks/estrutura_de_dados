#include <stdio.h>
#include "PilhaDinamica.h"

int main(void){

	Pilha *pi = cria_pilha();

	struct aluno* al = cria_aluno(10);
	struct aluno* al2 = cria_aluno(15);
	struct aluno* al3 = cria_aluno(20);

	insere_pilha(pi, *al);
	insere_pilha(pi, *al2);
	insere_pilha(pi, *al3);

	printa_pilha(pi);

	return 0;
}