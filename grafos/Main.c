#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(void){
	
	Grafo *gr = cria_grafo(5, 5, 0);

	//Busca em profundidade
	int eh_digrafo = 1;
	insere_aresta(gr, 0, 1, eh_digrafo, 0);
	insere_aresta(gr, 1, 2, eh_digrafo, 0);
	insere_aresta(gr, 1, 3, eh_digrafo, 0);
	insere_aresta(gr, 2, 4, eh_digrafo, 0);
	insere_aresta(gr, 3, 0, eh_digrafo, 0);
	insere_aresta(gr, 3, 4, eh_digrafo, 0);
	insere_aresta(gr, 4, 1, eh_digrafo, 0);
	insere_aresta(gr, 4, 3, eh_digrafo, 0);

	float dist[5];
	int ant[5];
	busca_dijkstra(gr, 0, ant, dist);
	for(int i = 0; i < 5; i++){
		printf("%i = %f -- %i\n",i, dist[i], ant[i]);
	}

	libera_grafo(gr);

	return 0;
}