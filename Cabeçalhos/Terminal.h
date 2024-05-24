#ifndef TERMINAL_H
#define TERMINAL_H 1

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>


#define limpa_tela "\x1B[2J"

void term_cls();
void limpa_tudo();
void term_move_xy(int x, int y);
void tc_get_cols_rows(int *cols, int *rows);
void tc_hide_cursor();
void tc_show_cursor();
void draw_menu(int selected);
void draw_confirmation(int selected);

#endif
