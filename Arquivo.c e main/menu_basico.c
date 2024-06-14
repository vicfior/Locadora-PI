#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "Filme.h"
#include "Cliente.h"
#include "Locacao.h"


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int escolha;
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    printf("☆                                                 BEM VINDO À LOCADORA DE FILMES                                       ☆\n");
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    printf("\n");
        printf("           ,---------.   .---.  .---.      .-''-.           .-''-.   .-------.         ____        .-'''-.                   \n");        
       printf("           \\         \\   |   |  |_ _|    .' _ _  \\       .' _ _   \\  |  _ _    \\     .'  __ `.    / _      \\        \n");  
       printf("            `--.  ,---'  |   |  ( ' )   /  ( ` )   '    /  ( ` )   ' | ( ' )   |    /   '  \\  \\  (`' ) /`--'            \n"); 
       printf("               |  \\      |   '-(_{;}_) .  (_ o _)  |   .  (_ o _)  | |(_ o _) /     |___|  /  | (_ o _).                 \n"); 
       printf("               :_ _:     |      (_,_)  |   (_,_)___|   |   (_,_)___| | (_,_).' __     _.-`    |  (_,_). '.                \n");
       printf("               (_I_)     | _ _--.   |  '    \\   .---.   '  \\   .---. |  |\\ \\  |  | .'   _     |  .---. \\   :         \n");
       printf("              (_(=)_)    |( ' ) |   |   \\    `-'   /    \\   `-'    / |  | \\  `'  / |   _( )_  | \\    `-'   |          \n");
       printf("               (_I_)     (_{;}_)|   |    \\        /      \\        /  |  |  \\    /   \\ (_ o _) /  \\        /          \n");
       printf("               '---'     '(_,_) '---'     `'-..-'         `'-..-'    ''-'   `'-'     '.(_,_).'     `-...-'                \n");

       printf("                                                                                                                 \n");

       printf("                        ________   .-./`)   .----.      ,---.    ,----.      .-''-.      .-'''-.                           \n");
       printf("                       |        | \\ .-.')   |  ,_|      |    \\  /     |   .' _ _   \\    / _     \\                      \n");
       printf("                       |   .----'  / `-' \\ ,-./  )      |  ,  \\/   ,  |  /  ( ` )   '  (`' )/`--'                        \n");
       printf("                       |  _|____    `-'`'` \\   _ '`)    |  |\\ _   /|  | .  (_ o _)  | (_ o _).                           \n");
       printf("                       |_( )_   |  .---.    > (_)  )    |   _( )_/ |  | |   (_,_)___|  (_,_). '.                           \n"); 
       printf("                       (_ o._)__|  |   |   (  .  .-'    |  (_ o _) |  | '   \\   .---. .---. \\   :                        \n");
       printf("                       |(_,_)      |   |    `-'`-'|___  |   (_,_)  |  |  \\   `-'    /\\    `-'   |                        \n");
       printf("                       |   |       |   |     |        \\ |  |       |  |   \\        /  \\        /                        \n"); 
       printf("                       '---'       '---'     `--------` '--'       '--'    `'-..-'      `-...-'                            \n");
    
    printf("\n");
    printf("Escolha sua opção: \n");
    printf("1 - FILMES\n");
    printf("2 - CLIENTES\n");
    printf("3 - SISTEMA DE LOCAÇÃO\n");
    printf("0 - SAIR\n");
    printf("Opção: ");
    scanf("%d", &escolha);
    printf ("\n");

    switch (escolha)
    {
    case 1: 
        menu_filmes();
        break;
    case 2: 
        menu_clientes();
        break;
    case 3: 
        menu_operacao();
        break;
    case 0: 
        printf(".:*☆ Obrigado por visitar nossa locadora .:*☆ ");
		printf("%s\n", ADEUS);
		exit(0);
        break;
    default:
        printf("Opção inválida.\n");
		return 0;
    } 
}

void menu_operacao() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Locacao *locacao = locacao_cria();
    Lista *lista = lista_cria();
    char codcliente[10]; 
    char codfilme[10];
    char codlocacao[10];
    int a;
    int b;
    int opcao = 1;
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    printf("☆                                                 MENU DE SISTEMA DE LOCAÇÃO                                           ☆\n");
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    while (opcao != 0) {
        printf("\n                  ☆ -------------------- ☆ Escolha sua opção ☆ ---------------------------- ☆");
        printf("\n                  ☆                      1 - ALUGAR FILME                                   ☆");
        printf("\n                  ☆                      2 - EXIBIR LOCACOES                                ☆");
        printf("\n                  ☆                      3 - PESQUISAR LOCACOES                             ☆");
        printf("\n                  ☆                      4 - PESQUISAR HISTÓRICO DO CLIENTE                 ☆");
        printf("\n                  ☆                      5 - DEVOLVER FILME                                 ☆");
        printf("\n                  ☆                      6 - RESERVAR FILME                                 ☆");
        printf("\n                  ☆                      7 - REMOVER RESERVA                                ☆");
        printf("\n                  ☆                      8 - EXIBIR RESERVAS                                ☆");
        printf("\n                  ☆                      9 - PESQUISAR RESERVA                              ☆");
        printf("\n                  ☆                      10 - VOLTAR AO MENU PRINCIPAL                      ☆");
        printf("\n                  ☆                      0 - SAIR                                           ☆");
        printf("\n                  ☆ -------------------- ☆ Escolha sua opção ☆ ---------------------------- ☆");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        limpar_buffer_locacao();
        switch (opcao) {
            case 1:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                                 ☆ ALUGAR FILMES ☆                                                   ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                alugar_filme();     
                break;
            case 2:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                                ☆ EXIBINDO LOCAÇÕES ☆                                                ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                exibir_locacoes();
                break;
            case 3:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                              ☆ PESQUISANDO LOCAÇÕES ☆                                               ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                pesquisar_locacao();
                break;
            case 4:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                          ☆ HISTÓRICO DO CLIENTE ☆                                                   ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                pesquisar_historico();
                break;
            case 5:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                          ☆ DEVOLVENDO O FILME ☆                                                     ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("Digite o código de locação: ");
                fgets(codlocacao, sizeof(codlocacao), stdin);
                codlocacao[strcspn(codlocacao, "\n")] = '\0';  
                devolver_filme(codlocacao);
                printf("Removendo locação %s\n", codlocacao);
                remover_locacao(codlocacao);
                printf("Filme %s devolvido com sucesso e disponível para nova locação!\n", codlocacao);
                break;
            case 6:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                              ☆ RESERVANDO FILME ☆                                                   ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                reservar_filme();
                break;
            case 7:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                             ☆ REMOVENDO RESERVA ☆                                                   ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                remover_reserva();
                break;
            case 8:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                                  ☆ EXIBINDO RESERVAS ☆                                              ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                exibir_reservas();
                break;
            case 9:
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                printf("☆                                                ☆ PESQUISANDO RESERVA ☆                                              ☆\n");
                printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
                pesquisar_reserva();
                break;
            case 10:
                main();
                break;
            case 0:
                printf(".:*☆ Obrigado por visitar nossa locadora .:*☆ ");
                printf("%s", ADEUS);
                exit(0);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}

void menu_filmes() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Lista_filme *listaf = lista_cria_filme();
    int opcao = 1;
    char codigo_filme[20];
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    printf("☆                                                 MENU DE FILMES                                                       ☆\n");
    printf("☆----------------------------------------------------------------------------------------------------------------------☆\n");
    while (opcao != 0) {
        printf("\n                      ☆ -------------------- ☆ Escolha sua opção ☆ ---------------------------- ☆");
        printf("\n                      ☆                      1 - CADASTRAR FILME                                ☆");
        printf("\n                      ☆                      2 - LISTAR FILME                                   ☆");
        printf("\n                      ☆                      3 - REMOVER FILME                                  ☆");
        printf("\n                      ☆                      4 - PESQUISAR FILME                                ☆");
        printf("\n                      ☆                      5 - VOLTAR AO MENU PRINCIPAL                       ☆");
        printf("\n                      ☆                      0 - SAIR                                           ☆");
        printf("\n                      ☆ -------------------- ☆ Escolha sua opção ☆ ---------------------------- ☆");
        printf("\nOpção: ");
        scanf("%d", &opcao);
        limpar_buffer_filme();
        switch (opcao) {
        case 1:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ CADASTRANDO FILMES ☆                                         ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            filme_cadastra(listaf);
            break;
        case 2:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ LISTANDO FILMES ☆                                            ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            listar_filme();
            break;
        case 3:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ REMOVENDO FILMES ☆                                           ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            remover_filme(listaf);
            break;
        case 4:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ PESQUISANDO FILMES ☆                                         ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            pesquisar_filme(listaf);
            break;
        case 5:
            main();
            break;
        case 0:
            printf("Obrigado por utilizar o sistema ");
            printf("%s", ADEUS);
            exit(0);
        default:
            printf("Opção inválida.\n");
            break;
        }

    }
}

void menu_clientes() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Lista *lista = lista_cria();
    int opcao = 1;
    char codigo_cliente[20];
    printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
    printf("☆                                         BEM VINDO AO MENU DE CLIENTES                                   ☆\n");
    printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
    while(opcao != 0) {
    printf("\n                  ☆ -------------------- ☆ Escolha sua opção ☆ -----------------------------☆");
    printf("\n                  ☆                      1 - CADASTRAR CLIENTE                              ☆");
    printf("\n                  ☆                      2 - LISTAR CLIENTE                                 ☆");
    printf("\n                  ☆                      3 - REMOVER CLIENTE                                ☆");
    printf("\n                  ☆                      4 - PESQUISAR CLIENTE                              ☆");
    printf("\n                  ☆                      5 - ALTERAR CLIENTE                                ☆");
    printf("\n                  ☆                      6 - VOLTAR AO MENU PRINCIPAL                       ☆");
    printf("\n                  ☆                      0 - SAIR                                           ☆");
    printf("\n                  ☆ ------------------------------------------------------------------------☆");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    limpar_buffer();
    switch (opcao)
        {
        case 1:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ CADASTRANDO CLIENTES ☆                                       ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("\n");
            cadastrar_cliente(lista);
            break;
        case 2:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ LISTANDO CLIENTES ☆                                          ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("\n");
            listar_clientes(lista);
            break;
        case 3:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ REMOVENDO CLIENTES ☆                                         ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("\n");
            remover_cliente(lista);
            break;
        case 4: 
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                        ☆ PESQUISANDO CLIENTES ☆                                        ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("\n");
            pesquisar_cliente(lista);
            break;
        case 5:
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("☆                                         ☆ ALTERANDO CLIENTES ☆                                         ☆\n");
            printf("☆ ------------------------------------------------------------------------------------------------------- ☆\n");
            printf("\n");
            printf("Digite o código do cliente: ");
            fgets(codigo_cliente, sizeof(codigo_cliente), stdin);
            codigo_cliente[strcspn(codigo_cliente, "\n")] = '\0'; 
            alterar_clientes(codigo_cliente);
            break;
        case 6:
            main();
            break;
        case 0: 
            printf("☆ Obrigado por utilizar o sistema ☆\n");
            printf("%s", ADEUS"\n");
            exit(0);
            break;
        default:
            printf("Opção inválida.\n");
            break;
            }
    
    }
}
