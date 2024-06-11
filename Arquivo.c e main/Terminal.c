#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include "Terminal.h"
#include "Filme.h"
#include "Cliente.h"
#include "Locacao.h"


void term_cls() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    GetConsoleScreenBufferInfo(hConsole, &csbi); // Obtem os atributos da tela
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y; // tamanho da tela
    FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten); // limpa a tela
    GetConsoleScreenBufferInfo(hConsole, &csbi); // Obtem os atributos da tela
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten); // Atualiza os atributos da tela
    SetConsoleCursorPosition(hConsole, coordScreen); // posiciona o cursor
}

void sair_do_Sistema()
{
    term_cls();
    printf("Saindo do Sistema...\n");
    getch(); 
}

int numeroDeOpcoes(int telaAtual) {
    switch (telaAtual) {
        case MENU_PRINCIPAL_TELA:
            return 4; 
        case MENU_FILMES_TELA:
            return 6; 
        case MENU_CLIENTES_TELA:
            return 7; 
        case MENU_LOCACAO_TELA:
            return 12; 
        default:
            return 0;
    }
}

void exibirMenuPrincipal(int opcaoSelecionada)
{
    term_cls();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    const char *opcoesMenuPrincipal[] = {
        "1 - FILMES",
        "2 - CLIENTES",
        "3 - SISTEMA DE LOCAÇÃO",
        "4 - SAIR"};

    printf("================================= "NEG_PURPLE" "BRILHOS" BEM VINDO À LOCADORA DE FILMES "BRILHOS" "NEG_BRANCO" ==============================\n" NEG_PINK,BRILHOS, ANSI_COLOR_RESET);

    for (int i = 0; i < sizeof(opcoesMenuPrincipal) / sizeof(opcoesMenuPrincipal[0]); i++)
    {
        if (i == opcaoSelecionada - 1)
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET NEG_PINK "%s", " > ");
        }
        else
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET);
        }
        printf("%s\n", opcoesMenuPrincipal[i]);
    }

    printf("\n");
    printf(NEG_BRANCO "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
    printf(C_GRAY "Navegue por meio das setas %s %s %s %s\n" ANSI_COLOR_RESET, UP, DOWN, LEFT, RIGHT);
}

void exibirMenuFilmes(int opcaoSelecionada)
{
    term_cls();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Lista_filme *listaf = lista_cria_filme();
    int opcao = 1;
    char codigo_filme[20];

    const char *opcoesMenuFilmes[] = {
        "1 - CADASTRAR FILME",
        "2 - LISTAR FILME",
        "3 - REMOVER FILME",
        "4 - PESQUISAR FILME",
        "5 - VOLTAR AO MENU PRINCIPAL",
        "6 - SAIR"};

    printf(" ===================================== "NEG_PURPLE" "BRILHOS" MENU DE FILMES "BRILHOS" "NEG_BRANCO" ====================================== " ANSI_COLOR_RESET "\n");
    for (int i = 0; i < sizeof(opcoesMenuFilmes) / sizeof(opcoesMenuFilmes[0]); i++)
    {
        if (i == opcaoSelecionada - 1)
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET NEG_PINK "%s", " > ");
        }
        else
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET);
        }
        printf("%s\n" ANSI_COLOR_RESET, opcoesMenuFilmes[i]);
    }

    printf("\n");
    printf(NEG_BRANCO "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
    printf(C_GRAY "Navegue por meio das setas %s %s %s %s\n", UP, DOWN, LEFT, RIGHT, ANSI_COLOR_RESET);
}

void exibirMenuClientes(int opcaoSelecionada)
{
    term_cls();

    const char *opcoesMenuClientes[] = {
        "1 - CADASTRAR CLIENTE",
        "2 - LISTAR CLIENTE",
        "3 - PESQUISAR CLIENTE",
        "4 - ALTERAR CLIENTE",
        "5 - REMOVER CLIENTE",
        "6 - VOLTAR AO MENU PRINCIPAL",
        "7 - SAIR"
        };

    printf(" ===================================== "NEG_PURPLE" "BRILHOS" MENU DE CLIENTES "BRILHOS" "NEG_BRANCO" ===================================== " ANSI_COLOR_RESET "\n");
    for (int i = 0; i < sizeof(opcoesMenuClientes) / sizeof(opcoesMenuClientes[0]); i++)
    {
        if (i == opcaoSelecionada - 1)
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET NEG_PINK " > ");
        }
        else
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET);
        }
        printf("%s\n" ANSI_COLOR_RESET, opcoesMenuClientes[i]);
    }

    printf("\n");
    printf( "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
    printf(C_GRAY "Navegue por meio das setas %s %s %s %s\n", UP, DOWN, LEFT, RIGHT ANSI_COLOR_RESET);
}

void exibirMenuLocacao(int opcaoSelecionada)
{
    term_cls();

    const char *opcoesMenuLocacao[] = {
        "1 - ALUGAR FILME",
        "2 - EXIBIR LOCACOES",
        "3 - PESQUISAR LOCACOES",
        "4 - PESQUISAR HISTÓRICO DO CLIENTE",
        "5 - PESQUISAR RESERVA",
        "6 - DEVOLVER FILME",
        "7 - RESERVAR FILME",
        "8 - REMOVER RESERVA",
        "9 - EXIBIR RESERVAS",
        "10 - VOLTAR AO MENU PRINCIPAL",
        "0 - SAIR"};

    printf(" ===================================== "NEG_PURPLE" "BRILHOS" MENU DE LOCAÇÃO "BRILHOS" "NEG_BRANCO" ==================================== " ANSI_COLOR_RESET "\n");
    for (int i = 0; i < sizeof(opcoesMenuLocacao) / sizeof(opcoesMenuLocacao[0]); i++)
    {
        if (i == opcaoSelecionada - 1)
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET NEG_PINK " > ");
        }
        else
        {
            printf(NEG_BRANCO " | " ANSI_COLOR_RESET);
        }
        printf("%s\n" ANSI_COLOR_RESET, opcoesMenuLocacao[i]);
    }

    printf("\n");
    printf(NEG_BRANCO "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
    printf(C_GRAY "Navegue por meio das setas %s %s %s %s\n", UP, DOWN, LEFT, RIGHT ANSI_COLOR_RESET);
}
