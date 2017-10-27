
typedef struct elemento {
	int dados;
	struct elemento* esq;
	struct elemento* dir;
	struct elemento* pai;
} Elemento;

typedef Elemento* Arvore;

Arvore* cria_arvore();

void libera_arvore(Arvore* arvore);

int arvore_vazia(Arvore* arvore);

int altura_arvore(Arvore* arvore);

int qtd_nos_arvore(Arvore* arvore);

Elemento* inserir(Arvore* arvore, Elemento* elem, int dados, int* dir);

int inserir_arvore(Arvore* arvore, int dados);

int remove_arvore(Arvore* arvore, int dados);

int consulta_arvore(Arvore* arvore, int dados);

void printa_arvore(Arvore* arvore);