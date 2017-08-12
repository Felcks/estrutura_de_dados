#include <stdio.h>
#include "FilaDinamica.h"

int main(void){

	Fila* fi = cria_fila();

	struct aluno* al = cria_aluno(10);
	struct aluno* al2 = cria_aluno(15);
	struct aluno* al3 = cria_aluno(20);

	insere_fila(fi, *al);
	insere_fila(fi, *al2);
	insere_fila(fi, *al3);

	printa_fila(fi);

	libera_fila(fi);
	
	return 0;
}