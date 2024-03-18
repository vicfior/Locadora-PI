#ifndef FILME_H
#define FILME_H 1

typedef struct filme {
char titulo [100];
char codfilme [10];
char ator_principal[100];
char ator_coadjuvante[100];
char diretor [100];
int ano;
char genero[20];
} Filme;

//funções
Filme* filme_criar();
Filme* cadastrar_filme(Filme *f);
void remover_filme(Filme *f);
void pesquisar_filme(Filme *f, char* codfilme, char *nome_pesquisado);
void listar_filme();
void alterar_filme(Filme *f, char *codfilme, char *novo_titulo, char *novo_ator_principal, char *novo_ator_coadjuvante, char *novo_diretor, int novo_ano, char *novo_genero);

#endif
