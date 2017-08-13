#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(void){
	
	Grafo *gr = cria_grafo(20, 20, 0);

	int x = insere_aresta(gr, 0, 1, 0, 0);
	int y = remove_aresta(gr, 0, 22, 0);
	int z = remove_aresta(gr, 1, 0, 0);
	printf("sucesso: %i\n",x);
	printf("sucesso: %i\n",y);
	printf("sucesso: %i\n",z);

	libera_grafo(gr);

	return 0;
}