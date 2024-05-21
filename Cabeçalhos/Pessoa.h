#ifndef PESSOA_H
#define PESSOA_H 1
//Macros de emojis
#define PESSOA "\U0001F3AC"
#define CODIGO "\U0001F511"
#define ENDERECO ""
#define TELEFONE ""
#define DATA "\U0001F4C5"
#define ADEUS "\U0001F44B"


typedef struct pessoa {
    char nome[200];
    char codcliente [10];
    char codfuncionario [10];
    char codadmin[10];
    char telefone [20]; 
    char endereco[400]; 
    char data_nascimento[15];
    struct pessoa *proximo;
}Pessoa;

typedef struct lista Lista;
struct lista{
    Pessoa *inicio;
    Pessoa *fim;
};
typedef struct consultacli Consultacli;

//Funções para cadastrar os clientes e funcionários
Lista *lista_cria();
Pessoa *pessoa_cria();
void pessoa_libera(Pessoa *pessoa);
int pessoa_cadastra(Lista *lista);
void inserir_pessoa(Lista *lista);
void listar_clientes(Lista *lista);
void remover_pessoa(Lista *lista);
void pesquisar_pessoa(Lista *lista);
void alterar_clientes(const char *codigo_cliente);
void menu_clientes();
#endif // PESSOA_H
