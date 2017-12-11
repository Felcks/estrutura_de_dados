#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Arvore.h"

void cria_conjunto(Lista* lista);
void destroi_conjunto(Lista* lista);
void pesquisa_elemento(Lista* lista);
void unir_conjuntos(Lista* lista);
void interseccao(Lista* lista);
void exibe_lista(Lista* lista);
void exibe_arvore(Lista* lista);
void exibe_altura_arvore(Lista* lista);
void printar_opcoes();

unsigned int current_list_indice = 1;
unsigned int indice_arvore = 1;

int main(void){


	srand(time(NULL)); 
	Lista* lista = cria_lista();

	char c[256];
	do{
		printar_opcoes();
		scanf("%s", c);
		
		if(strcmp(c, "1") == 0){
			cria_conjunto(lista);
		}
		else if(strcmp(c, "2") == 0){
			destroi_conjunto(lista);
		}
		else if(strcmp(c, "3") == 0){
			pesquisa_elemento(lista);
		}	
		else if(strcmp(c, "4") == 0){
			unir_conjuntos(lista);
		}
		else if(strcmp(c, "5") == 0){
			interseccao(lista);
		}	
		else if(strcmp(c, "6") == 0){
			exibe_lista(lista);
		}
		else if(strcmp(c, "7") == 0){
			exibe_arvore(lista);
		}
		else if(strcmp(c, "8") == 0){
			exibe_altura_arvore(lista);
		}

	} while(strcmp(c, "F") != 0);


	return 0;
}

//Opção 1 - Criar Conjunto
void cria_conjunto(Lista* lista){

	ElementoLista* elementoLista = cria_elemento_lista(current_list_indice);
	printf("Conjunto de indice %i criada com sucesso!\n",current_list_indice);
	current_list_indice++;

	Arvore* arvore = cria_arvore();

	char site[256];
	char c[256];
	do{
		printf("Insira o nome do site: ");
		scanf("%s", site);
		inserir_arvore(arvore, indice_arvore, site);
		indice_arvore++;

		printf("Site %s inserido com sucesso\nDigite F+ENTER para voltar ao menu ou A+ENTER para continuar.\n", site);
		scanf("%s", c);
	} while(strcmp(c, "F") != 0);


	indice_arvore = 1;
	elementoLista->arvore = arvore;
	insere_lista_final(lista, elementoLista);
}

//Opção 2 - Destruir Conjunto
void destroi_conjunto(Lista* lista){

	int indice = -1;
	int sucess = 0;
	do{
		printf("Digite -1 para cancelar operação ou digite o indice do conjunto a ser destruido: ");
		scanf("%i", &indice);

		if(indice == -1)
			break;

		sucess = remove_lista(lista, indice);
		if(sucess == 0){
			printf("Ocorreu um erro na remocao do conjunto\n");
		}
		else{
			printf("Conjunto de indíce %i removido com sucesso!\n", indice);
		}
		
	}while(sucess == 0);
}

//Opção 3 - Pesquisa Elemento
void pesquisa_elemento(Lista* lista){

	printf("\nPESQUISA DE ELEMENTO\n");

	int indice = -1;
	int sucess = 0;
	Arvore* arvore = NULL;
	do{
		printf("Digite -1 para cancelar operacao ou digite o indice do conjunto a ser pesquisado: ");
		scanf("%i", &indice);

		if(indice > 0){
			ElementoLista* elementoLista = *lista;
			while(elementoLista != NULL){

				if(elementoLista->indice == indice){
					sucess = 1;
					arvore = elementoLista->arvore;
					break;
				}
				elementoLista = elementoLista->prox;
			}
		}
		else if(indice == -1){
			break;
			printf("Operação cancelada!\n");
			return;
		}

		if(sucess == 0)
			printf("Conjunto de indice %i inexistente.\n\n", indice);
	} while(sucess != 1);


	if(arvore == NULL){
		printf("Ocorreu um erro inesperado.\n");
		return;
	}

	int indice_arvore = 0;
	printf("Digite o elemento a ser pesquisado: ");
	scanf("%i", &indice_arvore);


	Elemento* elemento = consulta_arvore(arvore, indice_arvore);
	if(elemento != NULL){
		printf("Elemento %i encontrado. Site: %s\n", elemento->indice, elemento->site);
	}
	else{
		printf("Elemento nao encontrado\n");
	}
}

//Opção 4 - Uniao de dois Conjuntos
void unir_conjuntos(Lista* lista){

	printf("\nUNIR CONJUNTOS\n");

	int indice_A = -1;
	int indice_B = -1;
	int sucess = 0;
	Arvore* arvore_A = NULL;
	Arvore* arvore_B = NULL;

	do{
		printf("Digite -1 para cancelar operacao ou digite o indice dos dois conjuntos a serem unidos: ");
		scanf("%i %i", &indice_A, &indice_B);

		if(indice_A == -1 || indice_B == -1)
		{
			return;
		}

		ElementoLista* elemento_A = consulta_lista(lista, indice_A);
		ElementoLista* elemento_B = consulta_lista(lista, indice_B);

		if(elemento_A != NULL && elemento_B != NULL){
			arvore_A = elemento_A->arvore;
			arvore_B = elemento_B->arvore;
			sucess = 1;
			break;
		}
		else if(elemento_A == NULL && elemento_B == NULL){
			printf("Conjuntos %i e %i inexistentes\n\n", indice_A, indice_B);
		}
		else if(elemento_A == NULL){
			printf("Conjunto de indice %i inexistente\n\n", indice_A);
		}
		else if(elemento_B == NULL){
			printf("Conjunto de indice %i inexistente\n\n", indice_B);
		}

	}while(sucess != 1);

	ElementoLista* elementoLista = cria_elemento_lista(current_list_indice);
	printf("Conjunto uniao de indice %i criado com sucesso!\n",current_list_indice);
	current_list_indice++;

	Arvore* arvore = cria_arvore();
	copia_arvore(arvore_A, arvore);
	copia_arvore(arvore_B, arvore);
	elementoLista->arvore = arvore;
	insere_lista_final(lista, elementoLista);
}

//Opção 5 - Interseccao de dois Conjuntos
void interseccao(Lista* lista){

	printf("\nINTERSECCAO DE DOIS CONJUNTOS\n");

	int indice_A = -1;
	int indice_B = -1;
	int sucess = 0;
	Arvore* arvore_A = NULL;
	Arvore* arvore_B = NULL;

	do{
		printf("Digite -1 para cancelar operacao ou digite o indice dos dois conjuntos a serem unidos: ");
		scanf("%i %i", &indice_A, &indice_B);

		if(indice_A == -1 || indice_B == -1)
		{
			return;
		}

		ElementoLista* elemento_A = consulta_lista(lista, indice_A);
		ElementoLista* elemento_B = consulta_lista(lista, indice_B);

		if(elemento_A != NULL && elemento_B != NULL){
			arvore_A = elemento_A->arvore;
			arvore_B = elemento_B->arvore;
			sucess = 1;
			break;
		}
		else if(elemento_A == NULL && elemento_B == NULL){
			printf("Conjuntos %i e %i inexistentes\n\n", indice_A, indice_B);
		}
		else if(elemento_A == NULL){
			printf("Conjunto de indice %i inexistente\n\n", indice_A);
		}
		else if(elemento_B == NULL){
			printf("Conjunto de indice %i inexistente\n\n", indice_B);
		}

	}while(sucess != 1);

	ElementoLista* elementoLista = cria_elemento_lista(current_list_indice);
	printf("Conjunto uniao de indice %i criado com sucesso!\n",current_list_indice);
	current_list_indice++;

	Arvore* arvore = cria_arvore();
	interseccao_arvore(arvore_A, arvore_B, arvore);
	elementoLista->arvore = arvore;
	insere_lista_final(lista, elementoLista);
}

//Opção 6 - Exibir listas
void exibe_lista(Lista* lista){

	if(lista == NULL)
		return;

	printf("Indices das arvores na lista: ");
	ElementoLista* elementoLista = *lista;
	while(elementoLista != NULL){
		
		printf("%i, ", elementoLista->indice);
		elementoLista = elementoLista->prox;
	}

	printf("\n");
}

//Opção 7 - Exibir arvore
void exibe_arvore(Lista* lista){

	if(lista == NULL)
		return;

	int indice_arvore = -1;
	printf("Digite o indice da arvore a ser exibida: ");
	scanf("%i", &indice_arvore);

	int sucess = 0;
	ElementoLista* elementoLista = *lista;
	while(elementoLista != NULL){

		if(elementoLista->indice == indice_arvore){
			printa_arvore(elementoLista->arvore);
			sucess = 1;
			break;
		}

		elementoLista = elementoLista->prox;
	}

	if(sucess == 0){
		printf("Arvore não encontrada na lista, digite ENTER para continuar: ");
		scanf("%i", indice_arvore);
	}
}

//Opção 8 - Exibe altura arvore
void exibe_altura_arvore(Lista* lista){

	if(lista == NULL)
		return;

	int indice_arvore = -1;
	printf("Digite o indice da arvore a ser exibida: ");
	scanf("%i", &indice_arvore);

	int sucess = 0;
	ElementoLista* elementoLista = *lista;
	while(elementoLista != NULL){

		if(elementoLista->indice == indice_arvore){
			int altura = altura_arvore(elementoLista->arvore);
			int balanceamento = fator_balanceamento(*elementoLista->arvore);

			if(balanceamento == 0 || balanceamento == 1 || balanceamento == -1)
				printf("A arvore tem altura:%i e fator balanceamento:%i. Logo esta balanceada!\n", altura, balanceamento);
			else
				printf("A arvore tem altura:%i e fator balanceamento:%i. Logo esta desbalanceada!\n", altura, balanceamento);
			
			sucess = 1;
			break;
		}

		elementoLista = elementoLista->prox;
	}

	if(sucess == 0){
		printf("Arvore não encontrada na lista, digite ENTER para continuar: ");
		scanf("%i", indice_arvore);
	}
}

void printar_opcoes(){

	printf("\n");
	printf("MENU PRINCIPAL\n");
	printf("1 -- Criar Conjunto.\n");
	printf("2 -- Destruir Conjunto.\n");
	printf("3 -- Pesquisar Elemento em um Conjunto.\n");
	printf("4 -- Uniao de dois conjuntos.\n");
	printf("5 -- Interseccao de dois conjuntos.\n");
	printf("6 -- Exibir arvores.\n");
	printf("7 -- Exibir todos os elementos de um conjunto em ordem.\n");
	printf("8 -- Exibir altura da arvore/arvore balanceada.\n");
	printf("F -- Fim do programa.\n");
	printf("\n");
}