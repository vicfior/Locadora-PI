#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pessoa.h"

typedef struct no_pessoa {
    Pessoa pessoa;
    struct no_pessoa *prox; 
} no_pessoa;

enum propriedades_cliente {
    nome,
    codcliente,
    telefone,
    endereco,
    data_nascimento,
};

typedef struct consultacli {
    char *prop[7]; // Corrigido aqui
    enum propriedades_cliente propriedade;
	char valor[100];
} Consultacli;

typedef struct lista_pessoa {
    no_pessoa *inicio; // Corrigido aqui
    struct consultacli Consultacli;
} ListaPessoa;

void inicializar_propriedades(struct consultacli *con) {
    con->prop[nome] = "nome";
    con->prop[codcliente] = "código";
    con->prop[telefone] = "telefone";
    con->prop[endereco] = "endereço";
    con->prop[data_nascimento] = "data de nascimento";
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_cliente (char *caminho) {
    printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Cadastro de Clientes                                          \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    if(!p) {
        printf("Erro ao alocar memória\n");
        return;
    }

    FILE *output = fopen(caminho, "a");
    if(!output) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    printf("%s", PESSOA);
    printf("Digite o nome do cliente: ");
    fgets(p->nome, sizeof(p->nome),stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';
    fflush(stdin);

    printf("%s", PESSOA);
    printf("Digite o código do cliente: ");
    fgets(p->codcliente, sizeof(p->codcliente),stdin);
    p->codcliente[strcspn(p->codcliente, "\n")] = '\0';
    fflush(stdin);

    printf("%s", PESSOA);
    printf("Digite o telefone do cliente: ");
    fgets(p->telefone, sizeof(p->telefone),stdin);
    p->telefone[strcspn(p->telefone, "\n")] = '\0';
    fflush(stdin);

    printf("%s", PESSOA);
    printf("Digite o endereço do cliente: ");
    fgets(p->endereco, sizeof(p->endereco),stdin);
    p->endereco[strcspn(p->endereco, "\n")] = '\0';
    fflush(stdin);

    printf("%s", PESSOA);
    printf("Digite a data de nascimento do cliente: ");
    fgets(p->data_nascimento, sizeof(p->data_nascimento),stdin);
    p->data_nascimento[strcspn(p->data_nascimento, "\n")] = '\0';
    fflush(stdin);

    fprintf(output, "\n%s\n %s\n %s\n %s\n %s",p->nome,p->codcliente,p->telefone,p->endereco,p->data_nascimento);
    fprintf(output, "\n");

    fclose(output);
    free(p);
    printf("Informações do filme salvas com sucesso.\n");
    return;
}

void remover_pessoa (char *caminho) {
    printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Removendo                                                     \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    if(!p) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    FILE *arquivo_e = fopen(caminho, "r");
    FILE *arquivo_s = fopen("temp.txt","w");

    if(!arquivo_e || !arquivo_s) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    char linha [100];
    int encontrou_pessoa = 0;

    printf("Digite o código do cliente: ");
    if(!fgets(p->codcliente, sizeof(p->codcliente), stdin)) {
        printf("Erro ao ler o código do cliente.\n");
        fclose(arquivo_e);
        fclose(arquivo_s);
        free(p);
        return;
    }
    p->codcliente[strcspn(p->codcliente, "\n")] = '\0';

    while(fgets(linha, sizeof(linha), arquivo_e)) {
        if(strstr(linha, p->codcliente)) {
            encontrou_pessoa = 1;
            for(int i = 0; i<4; i++) {
                if(!fgets(linha, sizeof(linha), arquivo_e)) {
                    break;
                }
            } 
        } else {
            fputs(linha, arquivo_s);
        }
    }
    fclose(arquivo_e);
    fclose(arquivo_s);
    
    if(encontrou_pessoa) 
    {
        remove(caminho);
        rename("temp.txt",caminho);
        printf("Pessoa removida com sucesso. \n");
    } else {
        printf("Pessoa não encontrada.\n");
    }
    free(p);
}

