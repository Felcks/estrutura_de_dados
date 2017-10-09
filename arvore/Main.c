#include <stdio.h>
#include "Arvore.h"

int main(void){
	
	Arvore* arvore = criar_arvore();
	int dado = 10;
	int a = inserir_arvore(arvore, dado);
	
	int b = inserir_arvore(arvore, 5);
	int c = inserir_arvore(arvore, 15);

	return 0;
}