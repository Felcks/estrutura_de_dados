#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(void){

	Lista *li;

	li = cria_lista();

	struct aluno* aluno1 = criar_aluno(1);
	struct aluno* aluno2 = criar_aluno(5);
	struct aluno* aluno3 = criar_aluno(2);

	insere_lista_inicio(li, *aluno1);
	insere_lista_final(li, *aluno2);
	insere_lista_ordenada(li, *aluno3);

	printa_lista(li);

	struct aluno consulta;
	consulta_lista_mat(li, 2, &consulta);

	printf("%i\n", consulta.matricula);
	return 0;
}