#ifndef LOCACAO_H
#define LOCACAO_H 1

#include "Pessoa.h"
#include "Filme.h"

typedef struct locacao {
    char codlocacao[20];
    char codcliente[20];
    char codfilme[20];
    char data_locacao[20];
    char data_devolucao[20];
    double valorpago;
    char codreserva[20];
    char data_reserva[20];
    struct locacao *proximo;
} Locacao;

typedef struct consulta_h {
	char *propriedades[6]; 
	char valor[100];
} Consulta_h;

void limpar_buffer_locacao();
Locacao *locacao_cria();
void inserir_locacao(Locacao **inicio, Locacao *nova_locacao);
void locacao_libera(Locacao *locacao);
int cliente_existe(char* codcliente);
int filme_existe(char* codfilme);
int filme_disponivel(char* codfilme);
void exibir_locacoes();
void alugar_filme();
void pesquisar_locacao();
double aplicar_multa();
double receber_pagamento();
void devolver_filme(char *codlocacao);
void pesquisar_historico();
void remover_locacao(char *codlocacao);
void reservar_filme();
void menu_operacao();
void remover_reserva();
int pesquisar_reserva();

#endif
