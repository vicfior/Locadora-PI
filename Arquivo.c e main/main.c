#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "Filme.h"
#include "Pessoa.h"
#include "Locacao.h"

int main() {
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
    printf("0 - SAIR\n");
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
    case 0: 
        printf("Obrigado por utilizar o sistema ");
		printf("%s", ADEUS);
		exit(0);
        break;
    default:
        printf("Opção inválida.\n");
		return 0;
    } 
}

void menu_clientes() {
     setlocale(LC_ALL, "pt_BR.UTF-8");
    Lista *lista = lista_cria();
    int opcao = 1;
    char codigo_cliente[20];
    printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
    printf("✿                                         BEM VINDO AO MENU DE CLIENTES                                   ✿\n");
    printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
    while(opcao != 0){
    printf("\n✿ -------------------- ✿ Escolha sua opção ✿ ---------------------------- ✿");
    printf("\n✿                      1 - CADASTRAR CLIENTE                              ✿");
    printf("\n✿                      2 - LISTAR CLIENTE                                 ✿");
    printf("\n✿                      3 - REMOVER CLIENTE                                ✿");
    printf("\n✿                      4 - PESQUISAR CLIENTE                              ✿");
    printf("\n✿                      5 - ALTERAR CLIENTE                                ✿");
    printf("\n✿                      6 - VOLTAR AO MENU PRINCIPAL                       ✿");
    printf("\n✿                      0 - SAIR                                           ✿");
    printf("\n✿ ------------------------------------------------------------------------✿");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    limpar_buffer();
switch (opcao)
    {
    case 1:
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("✿                                         CADASTRO DE CLIENTES                                            ✿\n");
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        pessoa_cadastra(lista);
        break;
    case 2:
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("✿                                         LISTAGEM DE CLIENTES                                            ✿\n");
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        listar_clientes(lista);
        break;
    case 3:
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("✿                                         REMOÇÃO DE CLIENTES                                             ✿\n");
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        remover_pessoa(lista);
        break;
    case 4: 
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("✿                                         PESQUISA DE CLIENTES                                            ✿\n");
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        pesquisar_pessoa(lista);
        break;
    case 5:
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("✿                                         ALTERAÇÃO DE CLIENTES                                           ✿\n");
        printf("✿ ------------------------------------------------------------------------------------------------------- ✿\n");
        printf("Digite o código do cliente: ");
        fgets(codigo_cliente, sizeof(codigo_cliente), stdin);
        codigo_cliente[strcspn(codigo_cliente, "\n")] = '\0'; 
        alterar_clientes(codigo_cliente);
        break;
    case 6:
        main();
        break;
    case 0: 
        printf("✿✿ Obrigado por utilizar o sistema ✿✿\n");
        printf("%s", ADEUS"\n");
        exit(0);
        break;
    default:
        printf("Opção inválida.\n");
        break;
        }
    
    }
}
