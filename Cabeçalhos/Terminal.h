#ifndef TERMINAL_H
#define TERMINAL_H 1


#define ANSI_COLOR_RESET "\x1b[0m"

#define BRILHOS "\u2728"

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
#define BG_GREEN "\e[42m"

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


#define limpa_tela "\x1B[2J"

void term_cls();
void sair_do_Sistema();
int numeroDeOpcoes(int telaAtual);
void exibirMenuPrincipal(int opcaoSelecionada);
void exibirMenuFilmes(int opcaoSelecionada);
void exibirMenuClientes(int opcaoSelecionada);
void exibirMenuLocacao(int opcaoSelecionada);

#endif
