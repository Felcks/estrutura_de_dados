
typedef struct elemento {
	int dados;
	struct elemento* esq;
	struct elemento* dir;
	struct elemento* pai;
} Elemento;

typedef Elemento* Arvore;

Arvore* criar_arvore();

Elemento* inserir(Arvore* arvore, Elemento* elem, int dados, int* dir);

int inserir_arvore(Arvore* arvore, int dados);