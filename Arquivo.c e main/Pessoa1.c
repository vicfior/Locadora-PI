#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pessoa.h"

struct no_pessoa {
    Pessoa cliente;
    struct no_pessoa *prox;
};

// Definição da estrutura da lista encadeada
struct lista_pessoa {
    struct no_pessoa *inicio;
};

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para inicializar a lista encadeada
ListaPessoa* lista_pessoa_cria() {
    ListaPessoa *lista = (ListaPessoa*)malloc(sizeof(ListaPessoa));
    if (lista != NULL)
        lista->inicio = NULL;
    return lista;
}

void lista_pessoa_inserir(ListaPessoa *lista, Pessoa cliente) {
    if (lista == NULL)
        return;

    // Criar um novo nó para o cliente
    no_pessoa *novo = (no_pessoa*)malloc(sizeof(no_pessoa));
    if (novo == NULL)
        return;

    novo->cliente = cliente;
    novo->prox = NULL;

    // Caso a lista esteja vazia, o novo nó será o primeiro
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        // Percorrer a lista até o final
        no_pessoa *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Inserir o novo nó no final da lista
        atual->prox = novo;
    }
    FILE *arquivo = fopen("clientes2.txt", "a"); // Abre o arquivo em modo de adição
    if (arquivo != NULL) {
        fprintf(arquivo, "Nome: %s\n", cliente.nome);
        fprintf(arquivo, "Código: %s\n", cliente.codcliente);
        fprintf(arquivo, "Telefone: %s\n", cliente.telefone);
        fprintf(arquivo, "Endereço: %s\n", cliente.endereco);
        fprintf(arquivo, "Data de Nascimento: %s\n", cliente.data_nascimento);
        fprintf(arquivo, "\n");
        fclose(arquivo);
    }
}

void lista_pessoa_libera(ListaPessoa *lista) {
    if (lista == NULL)
        return;

    no_pessoa *atual = lista->inicio;
    while (atual != NULL) {
        no_pessoa *aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(lista);
}
