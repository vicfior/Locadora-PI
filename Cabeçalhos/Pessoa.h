#ifndef PESSOA_H
#define PESSOA_H 1

typedef struct pessoa {
    char nome[100];
    char codcliente [10];
    char codfuncionario [10];
    char codadmin[10];
    int telefone;
    char endereco[100];
    int data_nascimento;
}Pessoa;

//Funções para cadastrar os clientes e funcionários
Pessoa* pessoa_cria(); 
void cadastrar_cliente(Pessoa *cliente);
void cadastrar_funcionario(Pessoa *funcionario);
void remover_cliente(Pessoa *cliente);
void remover_funcionario(Pessoa *funcionario);
void listar_cliente();
void pesquisar_cliente(Pessoa *cliente, char* codcliente, char *nome_pesquisado);
void pesquisar_funcionario(Pessoa *funcionario, char *codfuncionario, char *nome_pesquisado);
void alterar_cliente(Pessoa *cliente, char *codcliente, int novo_telefone, char *novo_endereco);
void alterar_funcionario(Pessoa *funcionario, char *codfuncionario, int novo_telefone, char novo_endereco[]);
#endif // PESSOA_H
