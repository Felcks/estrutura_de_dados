#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncDesc.h"

int main(void){
	
	Lista* li = cria_lista();

	struct aluno* al = cria_aluno(10);
	struct aluno* al2 = cria_aluno(15);
	struct aluno* al3 = cria_aluno(20);

	insere_lista_inicio(li, *al);
	insere_lista_final(li, *al2);
	insere_lista_final(li, *al3);
	
	printa_lista(li);

	libera_lista(li);

	return 0;
}