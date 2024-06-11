#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Filme.h"
#include "Cliente.h"
#include "Locacao.h"
#include "Terminal.h"

int telaAtual = MENU_PRINCIPAL_TELA;


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
                printf( "==================== "NEG_PURPLE" "BRILHOS" CADASTRANDO FILMES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                filme_cadastra(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_EXIBIR_FILME:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" EXIBINDO FILMES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                listar_filme();
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_PESQUISAR_FILME:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" PESQUISANDO FILMES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                pesquisar_filme(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_REMOVER_FILME:
                term_cls();
                printf( "==================== "NEG_PURPLE" "BRILHOS" REMOVENDO FILMES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                remover_filme(listaf);
                getch();
                telaAtual = MENU_FILMES_TELA;
                break;
            case TELA_SAIR_MENUFILME:
                telaAtual = MENU_PRINCIPAL_TELA;
                break;
            case TELA_NOVO_CLIENTE: 
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" CADASTRANDO CLIENTES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                cadastrar_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_EXIBIR_CLIENTES:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" EXIBINDO TODOS OS CLIENTES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                listar_clientes(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_PESQUISAR_CLIENTE:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" PESQUISANDO CLIENTES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                pesquisar_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_ALTERAR_CLIENTE:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" ALTERANDO CLIENTES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                printf("Digite o código do cliente: ");
                fgets(codcliente, sizeof(codcliente), stdin);
                codcliente[strcspn(codcliente, "\n")] = '\0';
                alterar_clientes(codcliente);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_REMOVER_CLIENTE:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" REMOVENDO CLIENTES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                remover_cliente(lista);
                getch();
                telaAtual = MENU_CLIENTES_TELA;
                break;
            case TELA_SAIR_MENUCLIENTE:
                telaAtual = MENU_PRINCIPAL_TELA;
                break;
            case TELA_ALUGAR:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" ALUGANDO FILMES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                alugar_filme();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_EXIBIR_LOC:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" EXIBINDO LOCAÇÕES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                exibir_locacoes();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_LOC:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" PESQUISANDO LOCAÇÕES "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                pesquisar_locacao();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_HIST:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" PESQUISANDO HISTÓRICO "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                pesquisar_historico();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_PESQUISAR_RES:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" PESQUISANDO RESERVAS "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                pesquisar_reserva();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_DEVOLVER_FILME:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" DEVOLVENDO O FILME "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
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
                printf("==================== "NEG_PURPLE" "BRILHOS" RESERVANDO FILME "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                reservar_filme();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_REMOVER_RES:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" REMOVENDO RESERVA "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
                remover_reserva();
                getch();
                telaAtual = MENU_LOCACAO_TELA;
                break;
            case TELA_EXIBIR_RES:
                term_cls();
                printf("==================== "NEG_PURPLE" "BRILHOS" EXIBINDO RESERVAS "BRILHOS" "NEG_BRANCO" =====================" ANSI_COLOR_RESET "\n");
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
