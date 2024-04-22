#ifndef PESSOA_H
#define PESSOA_H 1
//Macros de emojis
#define PESSOA "\U0001F3AC"
#define CODIGO "\U0001F511"
#define ENDERECO ""
#define TELEFONE ""
#define DATA "\U0001F4C5"

typedef struct pessoa {
    char nome[100];
    char codcliente [10];
    char codfuncionario [10];
    char codadmin[10];
    char telefone [15]; 
    char endereco[150]; 
    char data_nascimento[11];
}Pessoa;

typedef struct no_pessoa no_pessoa;
typedef struct lista_pessoa ListaPessoa;
typedef struct consultacli Consultacli;

//Funções para cadastrar os clientes e funcionários
Pessoa* pessoa_cria(); 
void cadastrar_cliente( char *caminho);
void cadastrar_funcionario(Pessoa *funcionario);
void remover_pessoa (char *caminho);
void remover_funcionario(Pessoa *funcionario);
void listar_clientes(char *caminho);
void pesquisar_cliente(char *caminho);
void pesquisar_funcionario(Pessoa *funcionario, char *codfuncionario, char *nome_pesquisado);
void alterar_cliente(Pessoa *cliente, char *codcliente, int novo_telefone, char *novo_endereco);
void alterar_funcionario(Pessoa *funcionario, char *codfuncionario, int novo_telefone, char novo_endereco[]);
#endif // PESSOA_H
