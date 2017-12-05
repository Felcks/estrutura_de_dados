#include <stdio.h>
#include <stdlib.h>

void printar_opcoes();

int main(void){
	
	int c = 0;
	do{
		printar_opcoes();
		if(c == 1){
			
			//criar hehe
		}

	}while((c = getchar()) != 'F');


	return 0;
}


void printar_opcoes(){

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