#ifndef CLIENTE_H
#define CLIENTE_H 1

//Macros de emojis
#define PESSOA "\U0001F3AC"
#define CODIGO "\U0001F511"
#define ENDERECO ""
#define TELEFONE ""
#define DATA "\U0001F4C5"
#define ADEUS "\U0001F44B"

#include "Locacao.h"

#define HI_WHITE "\e[0;97m"
#define ANSI_COLOR_RESET "\x1b[0m"      


typedef struct cliente {
    char nome[200];
    char codcliente [10];
    char codfuncionario [10];
    char codadmin[10];
    char telefone [20]; 
    char endereco[400]; 
    char data_nascimento[15];
    char valorpago;
    struct cliente *proximo;
} Cliente;

typedef struct lista Lista;
struct lista{
    Cliente *inicio;
    Cliente *fim;
};

//Funções para cadastrar os clientes e funcionários
Lista *lista_cria();
Cliente *pessoa_cria();
//void pessoa_libera(Cliente *cliente);
void liberar_cliente(Cliente *cliente);
//int pessoa_cadastra(Lista *lista);
int cadastrar_cliente(Lista *lista);
void inserir_cliente(Lista *lista);
void listar_clientes(Lista *lista);
void remover_cliente(Lista *lista);
void pesquisar_cliente(Lista *lista);
void alterar_clientes(const char *codigo_cliente);
void menu_clientes();

#endif 
