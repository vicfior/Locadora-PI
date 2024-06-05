#ifndef FILME_H
#define FILME_H 1
//Macros de emojis
#define CLAQUETE "\U0001F3AC"
#define CODIGO "\U0001F511"
#define ATORP "\U0001F464"
#define ATORC "\U0001F465"
#define DIRETOR "\U0001F3A5"
#define ANO "\U0001F4C5"
#define GENERO "\U0001F4FD"
#define ADEUS "\U0001F44B"

typedef struct filme {
    char titulo [200];
	char codfilme [20];
	char ator_principal[200];
	char ator_coadjuvante[200];
	char diretor [200];
	char ano[10];
	char genero[20];
    struct filme *proximo;
} Filme;

typedef struct lista_filme Lista_filme;
struct lista_filme{
    Filme *inicio;
    Filme *fim;
};

typedef struct consulta {
	char valor[100];
} Consulta;

void limpar_buffer();
Lista_filme *lista_cria_filme();
Filme *filme_cria();
void filme_cadastra(Lista_filme *listaf);
void filme_libera(Filme *filme);
void listar_filme();
void remover_filme(Lista_filme *listaf);
void pesquisar_filme(Lista_filme *listaf);
void menu_filmes();

#endif 
