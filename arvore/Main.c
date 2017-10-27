#include <stdio.h>
#include "Arvore.h"

int main(void){
	
	Arvore* arvore = cria_arvore();
	int dado = 10;
	int a = inserir_arvore(arvore, dado);
	int b = inserir_arvore(arvore, 5);
	int c = inserir_arvore(arvore, 15);

	int d = inserir_arvore(arvore, 4);
	int e = inserir_arvore(arvore, 3);
	int f = inserir_arvore(arvore, 2);

	//printf("%i\n", altura_arvore(arvore));
	printf("%i", consulta_arvore(arvore, 3));
	return 0;
}