#include <stdio.h>
#include "ListaSequencial.h"

int main(void){

	Lista *li = cria_lista();

	struct aluno* aluno = criar_aluno(0);
	struct aluno* aluno2 = criar_aluno(3);
	struct aluno* aluno3 = criar_aluno(5);

	int x = insere_lista_final(li, *aluno);
	int y = insere_lista_final(li, *aluno2);
	int z = insere_lista_final(li, *aluno3);
	int w = insere_lista_ordenada(li, *aluno2);

	//remove_lista_mat(li, 0);

	printa_lista(li);

	struct aluno teste;
	consulta_lista_mat(li, 5, &teste);

	printf("%i\n", teste.matricula);

	libera_lista(li);
	return 0;
}