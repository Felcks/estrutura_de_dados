
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

<<<<<<< HEAD
int fator_balanceamento(Elemento* no);

void rotacao_esquerda(Arvore* arvore, Elemento* no);

void rotacao_direita(Arvore* arvore, Elemento* no);

=======
>>>>>>> 45440e339fee773582ba5629a64e289dcc7cafad
void printa_arvore(Arvore* arvore);