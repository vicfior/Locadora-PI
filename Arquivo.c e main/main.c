#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Filme.h"
#include "Pessoa.h"
#include "Locacao.h"

void menu_filmes() 
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char caminho [20] = "Filmes.txt";
    int fescolha;
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  CADASTRO DE FILMES                                            \n");
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
        cadastrar_filme(caminho);
        break;
    case 2: 
        remover_filme(caminho);
        break;
    case 3: 
        pesquisar_filme(caminho);
        break;
    case 4: 
        listar_filme(caminho);
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

void menu_clientes() 
{
  /*MENU CADASTRO CLIENTES
    1 - CADASTRAR
    2 - REMOVER
    3 - ALTERAR
    4 - PESQUISAR
    5 - LISTAR
    6 - VOLTAR
    7 - SAIR 
    */
}
void menu_operacao() 
{
   /*MENU OPERAÇÕES - TODAS AS FUNÇÕES DE LOCAÇAÕ
    1 - ALUGAR FILME
    2 - DEVOLVER FILME
    3 - REMOVER FILME
    ...
    */
}
void alugar()
{ 

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
        alugar();
        break;
    case 2: 
        menu_filmes();
        break;
    case 3: 
        menu_clientes();
        break;
    case 4: 
        menu_operacao();
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
