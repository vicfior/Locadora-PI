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
    Pessoa* funcionario;
    int data_pagamento;
    float valor_locacao;
} Pagamento;

typedef struct reserva {
	char codreserva[10];
	Locacao *locacao;
	Pessoa* cliente;
	int data_reserva;
	int prazo;
} Reserva;

typedef struct historico {
	char codhistorico [10];
	Filme* filme;
	Pessoa* cliente;
	Pagamento* pagamento;
} Historico;


//funções + explicação
Locacao* locacao_criar();
//alocação de memória para locação

Locacao* cadastrar_locacao(Locacao *alugar);
//abertura do arquivo e inserção dos dados da locação

void remover_locacao(Locacao *remove_loc);
//exclui alguma locação

void pesquisar_locacao(Locacao *alugar, char *codlocacao, char *nome_pesquisado);
//pesquisa locação no arquivo locação com o código da locação e o nome do cliente

void alterar_locacao(Locacao *alterar, char *codlocacao, int novo_prazo, int nova_data_devolucao);
//Altera informações: prazo e data de devolução de uma locação 

void pesquisar_reserva(Locacao *alugar, char *codreserva, char *nome_pesquisado);
//pesquisa reservas feitas com um cliente com base no nome do cliente e o código da reserva

void reservar_filme(Reserva *reservar);
//reserva um filme de acordo com seu codfilme

void excluir_reserva(Reserva *reservar);
//Exclui uma reserva no sistema (pode implementar uma forma de excluir a reserva automaticamente após o prazo da reserva se esgotar

void exibir_historico(Historico *historico, char *codhistorico, char *nome_pesquisado, char *codcliente);
//exibe o histórico de locação com base no código do histórico, o nome pesquisado do cliente e o código do cliente

void receber_pagamento(Pagamento *pagar, int data_devolucao_atual); 
//aqui a função retorna uma mensagem com o valor a ser pago. Também calcula uma possível multa a ser paga de acordo com o atraso e retorna o valor total.

#endif
