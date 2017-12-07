#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Arvore.h"

void printar_opcoes();
void cria_conjunto(Lista* lista);
void exibe_arvores_lista(Lista* lista);

unsigned int current_list_indice = 1;
unsigned int indice_arvore = 1;

int main(void){

	Lista* lista = cria_lista();

	int c = 0;
	do{
		printar_opcoes();
		switch(c = getchar()){

			case '1':
				cria_conjunto(lista);
				break;
			case '6':
				exibe_arvores_lista(lista);
				break;
			default:
				getchar();
				break;
		}
	} while(c != 'F');


	return 0;
}

//Opção 1 - Criar Conjunto
void cria_conjunto(Lista* lista){

	ElementoLista* elementoLista = cria_elemento_lista(current_list_indice);
	printf("Lista de indice %i criada com sucesso!\n",current_list_indice);
	current_list_indice++;

	Arvore* arvore = cria_arvore();

	char site[256];
	char c[256];
	do{
		printf("Insira o nome do site: ");
		scanf("%s", site);
		inserir_arvore(arvore, indice_arvore, site);
		indice_arvore++;

		printf("Site %s inserido com sucesso\nDigite F para voltar ao menu ou ENTER para continuar.\n", site);
		c = getchar();
	} while(strcmp(c, "F") != 1);


	elementoLista->arvore = arvore;
	insere_lista_final(lista, elementoLista);
}

//Opção 6 - Exibir listas
void exibe_arvores_lista(Lista* lista){

	printf("aa\n");
	if(lista == NULL)
		return;

	ElementoLista* elementoLista = *lista;
	while(elementoLista != NULL){

		printf("Arvore associada ao indice %i da lista:\n", elementoLista->indice);
		Arvore* arvore = elementoLista->arvore;
		while(arvore != NULL){

			printa_arvore(arvore);
		}

		elementoLista = elementoLista->prox;
	}
}

void printar_opcoes(){

	printf("\n");
	printf("MENU PRINCIPAL\n");
	printf("1 -- Criar Conjunto.\n");
	printf("2 -- Destruir Conjunto.\n");
	printf("3 -- Pesquisar Elemento em um Conjunto.\n");
	printf("4 -- União de dois conjuntos.\n");
	printf("5 -- Intersecção de dois conjuntos.\n");
	printf("6 -- Exibir árvores.\n");
	printf("7 -- Exibir todos os elementos de um conjunto em ordem.\n");
	printf("8 -- Exibir altura da árvore/árvore balanceada.\n");
	printf("F -- Fim do programa.\n");
}