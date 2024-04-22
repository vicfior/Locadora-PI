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


typedef struct filme {
    char titulo [100];
	char codfilme [10];
	char ator_principal[100];
	char ator_coadjuvante[100];
	char diretor [100];
	char ano[10];
	char genero[20];
} Filme;

//funções
Filme* filme_criar();
void cadastrar_filme(char *caminho);
void remover_filme(char *caminho);
void pesquisar_filme(char *caminho);
void listar_filme();
void listar_tudo(char *caminho);
void listar_genero(char *caminho);
void listar_atorp(char *caminho);
void alterar_filme(Filme *f, char *codfilme, char *novo_titulo, char *novo_ator_principal, char *novo_ator_coadjuvante, char *novo_diretor, int novo_ano, char *novo_genero);

#endif
// .h
typedef struct no_filme NoFilme;
// .c
typedef struct no_filme {
	Filme filme;
	struct NoFilme *prox;
} no_filme;

// .h
typedef struct lista_filme ListaFilme ;
// .c

enum propriedades_filme {
	titulo,
	codfilme,
	ator_principal,
	ator_coadjuvante,
	diretor,
	ano,
	genero
};

struct consulta {
	char *propriedades[] = {
		"titulo",
		"codfilme",
		"ator_principal",
		"ator_coadjuvante",
		"diretor",
		"ano",
		"genero"
	};
	enum propriedades_filme propriedade;
};

typedef struct lista_filme {
	NoFilme *inicio;
	struct consulta consulta;
} lista_filme;
