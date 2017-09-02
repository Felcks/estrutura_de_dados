#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo {
	int eh_ponderado;
	int nro_vertices;
	int grau_max;
	int** arestas;
	float** pesos;
	int* grau;
};

Grafo* cria_grafo(int nro_vertices, int grau_max, int eh_ponderado){

	Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
	if(gr == NULL)
		return NULL;

	gr->nro_vertices = nro_vertices;
	gr->grau_max = grau_max;
	gr->eh_ponderado = (eh_ponderado == 1 ? 1 : 0);

	int i;
	gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));
	for(i = 0; i < nro_vertices; i++){
		gr->arestas[i] = (int*)malloc(grau_max*sizeof(int*));
	}
	gr->grau = (int*)calloc(nro_vertices, sizeof(int));

	if(eh_ponderado){
		gr->pesos = (float**)malloc(nro_vertices*sizeof(float*));
		for(i = 0; i < nro_vertices; i++){
			gr->pesos[i] = (float*)malloc(grau_max*sizeof(float*));
		}
	}

	return gr;
}

void libera_grafo(Grafo* gr){

	if(gr == NULL)
		return;

	int i;
	for(i = 0; i < gr->nro_vertices; i++){
		free(gr->arestas[i]);
	}
	free(gr->arestas);

	if(gr->eh_ponderado){
		for(i = 0; i < gr->nro_vertices; i++){
			free(gr->pesos[i]);
		}
		free(gr->pesos);
	}

	free(gr->grau);
	free(gr);
}

int insere_aresta(Grafo* gr, int orig, int dest, 
					int eh_digrafo, float peso){

	if(gr == NULL)
		return 0;

	if(orig < 0 || orig >= gr->nro_vertices)
		return 0;

	if(dest < 0 || dest >= gr->nro_vertices)
		return 0;

	gr->arestas[orig][gr->grau[orig]] = dest;
	if(gr->eh_ponderado){
		gr->pesos[orig][gr->grau[orig]] = peso;
	}
	gr->grau[orig]++;

	if(eh_digrafo == 0){
		insere_aresta(gr, dest, orig, 1, peso);
	}

	return 1;
}

int remove_aresta(Grafo* gr, int orig, int dest, int eh_digrafo){

	if(gr == NULL)
		return 0;

	int i = 0;
	while(i < gr->grau[orig] && gr->arestas[orig][i] != dest){
		i++;
	}

	if(i == gr->grau[orig])
		return 0;

	gr->grau[orig]--;
	gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];

	if(gr->eh_ponderado){
		gr->pesos[orig][i] = gr->arestas[orig][gr->grau[orig]];
	}

	if(eh_digrafo == 0){
		remove_aresta(gr, dest, orig, 1);
	}

	return 1;
}

void busca_profundidade_algoritmo(Grafo* gr, int ini, int *visitado, int count){

	int i;
	visitado[ini] = count;
	for(i = 0; i<gr->grau[ini]; i++){
		if(visitado[gr->arestas[ini][i]] > (count+1)){
			busca_profundidade_algoritmo(gr, gr->arestas[ini][i],
										 visitado, count+1);
		}
	}
}


void busca_profundidade(Grafo* gr, int ini, int* visitado){
	int i, count = 1;
	for(i = 0; i < gr->nro_vertices; i++)
		visitado[i] = 99999;

	busca_profundidade_algoritmo(gr, ini, visitado, count);
}

void busca_largura(Grafo* gr, int ini, int* visitado){

	int i, vert, NV, count = 1, qtd, *fila, IF = 0, FF = 0;
	for(i = 0; i<gr->nro_vertices; i++)
		visitado[i] = 0;

	NV = gr->nro_vertices;
	fila  = (int*)malloc(NV * sizeof(int));
	FF++;
	fila[FF] = ini;
	visitado[ini] = count;

	while(IF != FF){
		IF = (IF + 1) % NV;
		vert = fila[IF];
		count++;
		for(i = 0; i < gr->grau[vert]; i++){
			if(!visitado[gr->arestas[vert][i]]){
				FF = (FF + 1) % NV;
				fila[FF] = gr->arestas[vert][i];
				visitado[gr->arestas[vert][i]] = count;
			}
		}
	}
}

int menor_dist(float* dist, int *visitado, int NV){

	int i, menor = -1, primeiro = 1;
	for(i = 0; i < NV; i++){
		if(dist[i] >= 0 && visitado[i] == 0){
			if(primeiro){
				menor = i;
				primeiro = 0;
			}
			else{
				if(dist[menor] > dist[i])
					menor = i;
			}
		}
	}

	return menor;
}

void busca_dijkstra(Grafo *gr, int ini, int *ant, float *dist){

	int i, count, NV, ind, *visitado, u;
	count = NV = gr->nro_vertices;
	visitado = (int*) malloc(NV * sizeof(int));
	for(i = 0; i < NV; i++){
		ant[i] = -1;
		dist[i] = -1;
		visitado[i] = 0;
	}
	dist[ini] = 0;

	while(count > 0){
		u = menor_dist(dist, visitado, NV);
		if(u == -1)
			break;

		visitado[u] = 1;
		count--;

		for(i = 0; i < gr->grau[u]; i++){
			ind = gr->arestas[u][i];
			if(dist[ind] < 0){
				
				dist[ind] = dist[u] + 1;
				ant[ind] = u;
			}
			else if(dist[ind] > dist[u] + 1){

				dist[ind] = dist[u] + 1;
				ant[ind] = u;
			}
		}
	}

	free(visitado);

}