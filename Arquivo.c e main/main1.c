#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pessoa.h"

void menu_clientes() 
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    ListaPessoa *lista = lista_pessoa_cria();

    char nome[100];
    char codcliente[10];
    char telefone[15];
    char endereco[150];
    char data_nascimento[11];

    // Liberar a memória alocada para a lista
    
    int fescolha;
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  CADASTRO DE CLIENTES                                            \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    printf("Escolha sua opção: \n");
    printf("1 - CADASTRAR\n");
    printf("2 - REMOVER\n");
    printf("3 - PESQUISAR\n");
    printf("4 - LISTAR\n");
    printf("5 - VOLTAR\n");
    printf("6 - SAIR\n");
    printf("Opção: ");
    scanf("%d", &fescolha);
    limpar_buffer();

    switch (fescolha)
    {
    case 1:
        printf("Digite o nome do cliente: ");
        fgets(nome, 100, stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remover o caractere de nova linha do final

        printf("Digite o código do cliente: ");
        fgets(codcliente, 10, stdin);
        codcliente[strcspn(codcliente, "\n")] = '\0';

        printf("Digite o telefone do cliente: ");
        fgets(telefone, 15, stdin);
        telefone[strcspn(telefone, "\n")] = '\0';

        printf("Digite o endereço do cliente: ");
        fgets(endereco, 150, stdin);
        endereco[strcspn(endereco, "\n")] = '\0';

        printf("Digite a data de nascimento do cliente (DD/MM/AAAA): ");
        fgets(data_nascimento, 11, stdin);
        data_nascimento[strcspn(data_nascimento, "\n")] = '\0';

        // Criar um novo cliente com as informações fornecidas
        Pessoa novo_cliente;
        strcpy(novo_cliente.nome, nome);
        strcpy(novo_cliente.codcliente, codcliente);
        strcpy(novo_cliente.telefone, telefone);
        strcpy(novo_cliente.endereco, endereco);
        strcpy(novo_cliente.data_nascimento, data_nascimento);

        // Inserir o novo cliente na lista e escrever no arquivo
        lista_pessoa_inserir(lista, novo_cliente);
        lista_pessoa_libera(lista);
        break;
    case 2: 
        //remover_filme(caminho);
        break;
    case 3: 
        //pesquisar_filme(caminho);
        break;
    case 4: 
        //listar_filme(caminho);
        break;
    case 5: 
        //voltar ao menu inicial do sistema
        break;
    case 6: 
        printf("Obrigado por utilizar o sistema ");
		printf("%s", ADEUS"\n");
		exit(0);
        break;
    default:
        printf("Opção inválida.\n");
		return;
    }
}

int main()
{   
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int escolha;
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  BEM VINDO À LOCADORA DE FILMES                                \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    printf("Escolha sua opção: \n");
    printf("1 - ALUGAR\n");
    printf("2 - FILMES\n");
    printf("3 - CLIENTES\n");
    printf("4 - OPERAÇÕES\n");
    printf("5 - SAIR\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        //alugar();
        break;
    case 2: 
        //menu_filmes();
        break;
    case 3: 
        menu_clientes();
        break;
    case 4: 
        //menu_operacao();
        break;
    case 5: 
        printf("Obrigado por utilizar o sistema ");
		printf("%s", ADEUS);
		exit(0);
        break;
    default:
        printf("Opção inválida.\n");
		return 0;
    } 
}
