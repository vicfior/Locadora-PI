#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "Filme.h"
#include "Cliente.h"
#include "Locacao.h"
#include "Terminal.h"

#define ANSI_COLOR_RESET "\x1b[0m"

// teclas
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ENTER 13
#define MENU 'm'
#define SAIR 's'

// Cores ANSI

#define C_BLUE_CUSTOM_BOLD "\033[1;38;5;21m"
#define C_MAGENTA_BOLD "\033[1;38;5;201m"
#define C_PURPLE_BOLD "\033[1;38;5;93m"
#define C_GRAY "\033[38;5;242m"
#define NEG_BRANCO "\e[0;97m"
#define NEG_PINK "\e[0;95m"
#define NEG_PURPLE "\e[1;35m"

// Sublinhados ANSI
#define SUB_BRANCO "\e[4;37m"
#define SUB_PINK "\e[4;95m"
#define C_PURPLE_BOLD_UNDERLINED "\033[1;4;38;5;93m"


#define UP "\u25B2"    // ▲
#define DOWN "\u25BC"  // ▼
#define RIGHT "\u25BA" // ►
#define LEFT "\u25C4"  // ◄

#define MENU_PRINCIPAL_TELA 0
#define MENU_FILMES_TELA 1
#define MENU_CLIENTES_TELA 2
#define MENU_LOCACAO_TELA 3
#define SAIR_PROGRAMA 4

// TELAS DO MENU FILME
#define TELA_NOVO_FILME 5
#define TELA_EXIBIR_FILME 6
#define TELA_PESQUISAR_FILME 7
#define TELA_REMOVER_FILME 8
#define TELA_SAIR_MENUFILME 9

// TELAS DO MENU CLIENTE
#define TELA_NOVO_CLIENTE 10
#define TELA_EXIBIR_CLIENTES 11
#define TELA_PESQUISAR_CLIENTE 12
#define TELA_REMOVER_CLIENTE 13
#define TELA_ALTERAR_CLIENTE 14
#define TELA_SAIR_MENUCLIENTE 15

// TELAS MENU LOCAÇÃO
#define TELA_ALUGAR 16
#define TELA_EXIBIR_LOC 17
#define TELA_PESQUISAR_LOC 18
#define TELA_PESQUISAR_HIST 19
#define TELA_DEVOLVER_FILME 20
#define TELA_RESERVAS 21
#define TELA_REMOVER_RES 22
#define TELA_EXIBIR_RES 23
#define TELA_PESQUISAR_RES 24
#define TELA_SAIR_MENULOCACAO 25

int telaAtual = MENU_PRINCIPAL_TELA;

void sair_do_Sistema()
{
    term_cls();
    printf("Saindo do Sistema...\n");
    getch(); // Aguarda pressionar qualquer tecla para continuar
}

int numeroDeOpcoes(int telaAtual) {
    switch (telaAtual) {
        case MENU_PRINCIPAL_TELA:
            return 4; // 4 opções no menu principal
        case MENU_FILMES_TELA:
            return 6; // 5 opções no menu de filmes
        case MENU_CLIENTES_TELA:
            return 7; // 6 opções no menu de clientes
        case MENU_LOCACAO_TELA:
            return 12; // 11 opções no menu de locação
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

    printf(SUB_BRANCO NEG_PINK "================================= BEM VINDO À LOCADORA DE FILMES ==============================\n"ANSI_COLOR_RESET);

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
    printf(NEG_PINK "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
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

    printf(SUB_BRANCO NEG_PINK " ================================= MENU DE FILMES ================================= " ANSI_COLOR_RESET "\n");
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
    printf(NEG_PINK "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
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

    printf(SUB_BRANCO NEG_PINK " ================================= MENU DE CLIENTES ================================= " ANSI_COLOR_RESET "\n");
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
    printf(NEG_PINK "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
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

    printf(SUB_BRANCO NEG_PINK " ================================= MENU DE LOCAÇÃO ================================= " ANSI_COLOR_RESET "\n");
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
    printf(NEG_PINK "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" ANSI_COLOR_RESET "\n");
    printf(C_GRAY "Navegue por meio das setas %s %s %s %s\n", UP, DOWN, LEFT, RIGHT ANSI_COLOR_RESET);
}

int main()
{
        setlocale(LC_ALL, "pt_BR.UTF-8");
        int telaAtual = MENU_PRINCIPAL_TELA;
        int opcaoSelecionada = MENU_FILMES_TELA;
        int tecla;
        Lista_filme *listaf = lista_cria_filme();
        Lista *lista = lista_cria();
        Locacao *locacao = locacao_cria();
        char codcliente[20];
        char codfilme[20];
        char codlocacao[10];

        term_cls();

       printf(C_MAGENTA_BOLD" ,---------.   .---.  .---.      .-''-.           .-''-.   .-------.         ____        .-'''-.                \n");        
       printf(" \\         \\   |   |  |_ _|    .' _ _  \\       .' _ _   \\  |  _ _    \\     .'  __ `.    / _      \\        \n");  
       printf("  `--.  ,---'  |   |  ( ' )   /  ( ` )   '    /  ( ` )   ' | ( ' )   |    /   '  \\  \\  (`' ) /`--'            \n"); 
       printf("     |  \\      |   '-(_{;}_) .  (_ o _)  |   .  (_ o _)  | |(_ o _) /     |___|  /  | (_ o _).                 \n"); 
       printf("     :_ _:     |      (_,_)  |   (_,_)___|   |   (_,_)___| | (_,_).' __     _.-`    |  (_,_). '.                \n");
       printf("     (_I_)     | _ _--.   |  '    \\   .---.   '  \\   .---. |  |\\ \\  |  | .'   _     |  .---. \\   :         " ANSI_COLOR_RESET "\n");
       printf(C_PURPLE_BOLD"    (_(=)_)    |( ' ) |   |   \\    `-'   /    \\   `-'    / |  | \\  `'  / |   _( )_  | \\    `-'   |          \n");
       printf("     (_I_)     (_{;}_)|   |    \\        /      \\        /  |  |  \\    /   \\ (_ o _) /  \\        /          \n");
       printf("     '---'     '(_,_) '---'     `'-..-'         `'-..-'    ''-'   `'-'     '.(_,_).'     `-...-'                \n");

       printf("                                                                                                                 \n");

       printf("              ________   .-./`)   .----.      ,---.    ,----.      .-''-.      .-'''-.                           \n");
       printf("             |        | \\ .-.')   |  ,_|      |    \\  /     |   .' _ _   \\    / _     \\                      \n");
       printf("             |   .----'  / `-' \\ ,-./  )      |  ,  \\/   ,  |  /  ( ` )   '  (`' )/`--'                        " ANSI_COLOR_RESET "\n");
       printf(C_BLUE_CUSTOM_BOLD"             |  _|____    `-'`'` \\   _ '`)    |  |\\ _   /|  | .  (_ o _)  | (_ o _).                           \n");
       printf("             |_( )_   |  .---.    > (_)  )    |   _( )_/ |  | |   (_,_)___|  (_,_). '.                           \n"); 
       printf("             (_ o._)__|  |   |   (  .  .-'    |  (_ o _) |  | '   \\   .---. .---. \\   :                        \n");
       printf("             |(_,_)      |   |    `-'`-'|___  |   (_,_)  |  |  \\   `-'    /\\    `-'   |                        \n");
       printf("             |   |       |   |     |        \\ |  |       |  |   \\        /  \\        /                        \n"); 
       printf("             '---'       '---'     `--------` '--'       '--'    `'-..-'      `-...-'                            " ANSI_COLOR_RESET "\n");
    
        
        printf(C_GRAY"\n                          Pressione qualquer tecla para continuar...                                            "ANSI_COLOR_RESET"\n");
        getch();
        Sleep(1000);

        while (1)
        {
            term_cls();

            switch (telaAtual)
            {
            case MENU_PRINCIPAL_TELA:
                exibirMenuPrincipal(opcaoSelecionada);
                break;
            case MENU_FILMES_TELA:
                exibirMenuFilmes(opcaoSelecionada);
                break;
            case MENU_CLIENTES_TELA:
                exibirMenuClientes(opcaoSelecionada);
                break;
            case MENU_LOCACAO_TELA:
                exibirMenuLocacao(opcaoSelecionada);
                break;
            case TELA_NOVO_FILME:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== CADASTRANDO FILMES =====================" ANSI_COLOR_RESET "\n");
                filme_cadastra(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_EXIBIR_FILME:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== EXIBINDO FILMES =====================" ANSI_COLOR_RESET "\n");
                listar_filme();
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_PESQUISAR_FILME:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== PESQUISANDO FILMES =====================" ANSI_COLOR_RESET "\n");
                pesquisar_filme(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_REMOVER_FILME:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== REMOVENDO FILMES =====================" ANSI_COLOR_RESET "\n");
                remover_filme(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_SAIR_MENUFILME:
                telaAtual = MENU_PRINCIPAL_TELA;
                break;
            case TELA_NOVO_CLIENTE: 
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== CADASTRANDO CLIENTES =====================" ANSI_COLOR_RESET "\n");
                cadastrar_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_EXIBIR_CLIENTES:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== EXIBINDO TODOS OS CLIENTES =====================" ANSI_COLOR_RESET "\n");
                listar_clientes(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_PESQUISAR_CLIENTE:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== PESQUISANDO CLIENTES =====================" ANSI_COLOR_RESET "\n");
                pesquisar_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_ALTERAR_CLIENTE:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== ALTERANDO CLIENTES =====================" ANSI_COLOR_RESET "\n");
                printf("Digite o código do cliente: ");
                fgets(codcliente, sizeof(codcliente), stdin);
                codcliente[strcspn(codcliente, "\n")] = '\0';
                alterar_clientes(codcliente);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_REMOVER_CLIENTE:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== REMOVENDO CLIENTES =====================" ANSI_COLOR_RESET "\n");
                remover_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_SAIR_MENUCLIENTE:
                telaAtual = MENU_PRINCIPAL_TELA;
                break;
            case TELA_ALUGAR:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== ALUGANDO FILMES =====================" ANSI_COLOR_RESET "\n");
                alugar_filme();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_EXIBIR_LOC:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== EXIBINDO LOCAÇÕES =====================" ANSI_COLOR_RESET "\n");
                exibir_locacoes();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_LOC:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== PESQUISANDO LOCAÇÕES =====================" ANSI_COLOR_RESET "\n");
                pesquisar_locacao();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_HIST:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== PESQUISANDO HISTÓRICO =====================" ANSI_COLOR_RESET "\n");
                pesquisar_historico();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_RES:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== PESQUISANDO RESERVAS =====================" ANSI_COLOR_RESET "\n");
                pesquisar_reserva();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_DEVOLVER_FILME:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== DEVOLVENDO O FILME =====================" ANSI_COLOR_RESET "\n");
                printf("Digite o código de locação: ");
                fgets(codlocacao, sizeof(codlocacao), stdin);
                codlocacao[strcspn(codlocacao, "\n")] = '\0';
                devolver_filme(codlocacao);
                printf("Removendo locação %s\n", codlocacao);
                remover_locacao(codlocacao);
                printf("Filme %s devolvido com sucesso e disponível para nova locação!\n", codlocacao);
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_RESERVAS:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== RESERVANDO FILME =====================" ANSI_COLOR_RESET "\n");
                reservar_filme();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_REMOVER_RES:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== REMOVENDO RESERVA =====================" ANSI_COLOR_RESET "\n");
                remover_reserva();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_EXIBIR_RES:
                term_cls();
                printf(SUB_BRANCO NEG_PINK "==================== EXIBINDO RESERVAS =====================" ANSI_COLOR_RESET "\n");
                exibir_reservas();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_SAIR_MENULOCACAO:
                telaAtual = MENU_PRINCIPAL_TELA;
                break;
            case SAIR_PROGRAMA:
                sair_do_Sistema();
                return 0;
            }

            tecla = _getch();
            int numOpcoes = numeroDeOpcoes(telaAtual);

            if (tecla == SAIR) {
            sair_do_Sistema();
            } else if (tecla == MENU) {
                telaAtual = MENU_PRINCIPAL_TELA;
                opcaoSelecionada = 1;
                continue;
            }

            switch (tecla)
            {
            case UP_ARROW:
                if (telaAtual == MENU_PRINCIPAL_TELA || telaAtual == MENU_FILMES_TELA || telaAtual == MENU_CLIENTES_TELA || telaAtual == MENU_LOCACAO_TELA)
                {
                    opcaoSelecionada = (opcaoSelecionada > 1) ? opcaoSelecionada - 1 : numOpcoes;
                }
                break;
            case DOWN_ARROW:
                if (telaAtual == MENU_PRINCIPAL_TELA || telaAtual == MENU_FILMES_TELA || telaAtual == MENU_CLIENTES_TELA || telaAtual == MENU_LOCACAO_TELA)
                {
                    opcaoSelecionada = (opcaoSelecionada < numOpcoes) ? opcaoSelecionada + 1 : 1;
                }
                break;
            case LEFT_ARROW:
                if (telaAtual != MENU_PRINCIPAL_TELA)
                {
                    telaAtual = MENU_PRINCIPAL_TELA;
                    opcaoSelecionada = MENU_FILMES_TELA || MENU_CLIENTES_TELA || MENU_LOCACAO_TELA;
                }
                break;
            case RIGHT_ARROW:
            case ENTER:
                if (telaAtual == MENU_PRINCIPAL_TELA)
                {
                    telaAtual = opcaoSelecionada;
                }
                else if (telaAtual ==  MENU_FILMES_TELA)
                {
                    switch (opcaoSelecionada)
                    {
                    case 1:
                        telaAtual = TELA_NOVO_FILME;
                        break;
                    case 2:
                        telaAtual = TELA_EXIBIR_FILME;
                        break;
                    case 3:
                        telaAtual = TELA_REMOVER_FILME;
                        break;
                    case 4:
                        telaAtual = TELA_PESQUISAR_FILME;
                        break;
                    case 5:
                        telaAtual = MENU_PRINCIPAL_TELA;
                        opcaoSelecionada = MENU_FILMES_TELA;
                        break;
                    case 6:
                        telaAtual = SAIR_PROGRAMA;
                        break;
                    }
                } 
                else if (telaAtual == MENU_CLIENTES_TELA)
                {
                    switch (opcaoSelecionada)
                    {
                    case 1:
                        telaAtual = TELA_NOVO_CLIENTE;
                        break;
                    case 2:
                        telaAtual = TELA_EXIBIR_CLIENTES;
                        break;
                    case 3: 
                        telaAtual = TELA_PESQUISAR_CLIENTE;
                        break;
                    case 4:
                        telaAtual = TELA_ALTERAR_CLIENTE;
                        break;
                    case 5:
                        telaAtual = TELA_REMOVER_CLIENTE;
                        break;  
                    case 6:
                        telaAtual = MENU_PRINCIPAL_TELA;
                        opcaoSelecionada = MENU_CLIENTES_TELA;
                        break;
                    case 7:
                        telaAtual = SAIR_PROGRAMA;
                        break;
                    }
                } else if (telaAtual == MENU_LOCACAO_TELA) {
                    switch (opcaoSelecionada)
                    {
                    case 1:
                        telaAtual = TELA_ALUGAR;
                        break;
                    case 2:
                        telaAtual = TELA_EXIBIR_LOC;
                        break;
                    case 3:
                        telaAtual = TELA_PESQUISAR_LOC;
                        break;
                    case 4:
                        telaAtual = TELA_PESQUISAR_HIST;
                        break;
                    case 5:
                        telaAtual = TELA_PESQUISAR_RES;
                        break;
                    case 6:
                        telaAtual = TELA_DEVOLVER_FILME;
                        break;
                    case 7:
                        telaAtual = TELA_RESERVAS;
                        break;
                    case 8:
                        telaAtual = TELA_REMOVER_RES;
                        break;
                    case 9:
                        telaAtual = TELA_EXIBIR_RES;
                        break;
                    case 10:
                        telaAtual = MENU_PRINCIPAL_TELA;
                        opcaoSelecionada = MENU_LOCACAO_TELA;
                        break;
                    case 11:
                        telaAtual = SAIR_PROGRAMA;
                        break;
                    }
                } break;
            } 
        } 

        return 0;
}
