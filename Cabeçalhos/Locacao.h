#ifndef LOCACAO_H
#define LOCACAO_H 1

#include "Pessoa.h"
#include "Filme.h"

typedef struct locacao {
    char codlocacao [10];
    Pessoa* cliente;
    Filme* filme;
    Pessoa* funcionario;
    int data_locacao;
    int prazo;
    int data_devolucao;
}Locacao;

typedef struct pagamento {
	char codpagamento[10];
    Pessoa* cliente;
    Filme* filme;
    Pessoa* funcionario;
    int data_pagamento;
    float valor_locacao;
    float valor_juros;
    int atraso;
    float valor_multa;
} Pagamento;

typedef struct reserva {
	char codreserva[10];
	Filme* filme;
	Pessoa* cliente;
	int data_reserva;
	int prazo;
} Reserva;

typedef struct historico {
	char codhistorico [10];
	Filme* filme;
	Pessoa* cliente;
	struct Pagamento* pagamento;
} Historico;




//funções
Locacao* locacao_criar();
Locacao* cadastrar_locacao(Locacao *alugar);
void remover_locacao(Locacao *alugar);
void pesquisar_locacao(Locacao *alugar, char *codlocacao, char *nome_pesquisado);
void alterar_locacao(Locacao *alugar, char *codlocacao, int novo_prazo, int nova_data_devolucao);
//pesquisa reservas feitas com um cliente com base no nome do cliente e o código da reserva
void pesquisar_reserva(Locacao *alugar, char *codreserva, char *nome_pesquisado);
void reservar_filme(Reserva *reservar);
void excluir_reserva(Reserva *reservar);
//exibe o histórico de locação com base no código do histórico, o nome pesquisado do cliente e o código do cliente
void exibir_historico(Historico *historico, char *codhistorico, char *nome_pesquisado, char *codcliente);

//aqui a função retorna uma mensagem com o valor a ser pago. Também calcula uma possível multa a ser paga de acordo com o atraso e retorna o valor total.
void receber_pagamento(Pagamento *pagar, int data_devolucao_atual);
#endif
