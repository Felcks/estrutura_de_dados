#include <stdio.h>
#include "FilaEstatica.h"

int main(void){

	Fila *fila = cria_fila();

	struct aluno* al = cria_aluno(10);
	struct aluno* al2 = cria_aluno(15);
	struct aluno* al3 = cria_aluno(20);

	insere_fila(fila, *al);
	insere_fila(fila, *al2);
	insere_fila(fila, *al3);

	remove_fila(fila);
	remove_fila(fila);

	printa_fila(fila);

	libera_fila(fila);

	return 0;
}