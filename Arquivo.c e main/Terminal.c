#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>



#define SETA_ESQUERDA "\u25B6"
#define SETA_DIREITA "\u25C0"
#define SETA_CIMA "\u25B2"
#define SETA_BAIXO "\u25BC"


//Para limpar a tela
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

void term_move_xy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // posiciona o cursor
}

void tc_get_cols_rows(int *cols, int *rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void tc_hide_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void tc_show_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void draw_menu(int selected) {
    const char *options[] = {
        "Option 1", 
        "Option 2", 
        "Option 3", 
        "Option 4", 
        "Option 5", 
        "Option 6", 
        "Option 7", 
        "Option 8"
    };
    int num_options = 8;
    term_cls();
    int col, lin;
    tc_get_cols_rows(&col, &lin);
    for (int i = 0; i < num_options; ++i) {
        term_move_xy(col / 2 - 5, lin / 2 - num_options / 2 + i);
        if (i == selected) {
            printf("-> %s", options[i]);
        } else {
            printf("   %s", options[i]);
        }
    }
    term_move_xy(col / 2 - 10, lin / 2 + num_options);
    printf("Press ESC to exit");
}

void draw_confirmation(int selected) {
    int col, lin;
    tc_get_cols_rows(&col, &lin);
    term_cls();
    term_move_xy(col / 2 - 10, lin / 2);
    printf("Você selecionou a opção %d", selected + 1);
    term_move_xy(col / 2 - 10, lin / 2 + 1);
    printf("Pressione a tecla da direita ( %s ) para voltar", SETA_DIREITA);
    term_move_xy(col / 2 - 10, lin / 2 + 2);
    printf("Press ESC to exit");
}

