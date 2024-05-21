#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pessoa.h"
#include "Locacao.h"


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Lista *lista_cria() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

Pessoa *pessoa_cria() {
    Pessoa *pessoa = (Pessoa*)malloc(sizeof(Pessoa));
    if (pessoa != NULL) {
        pessoa->proximo = NULL;
    }
    return pessoa;
}


void pessoa_libera(Pessoa *pessoa) {
   if(pessoa != NULL) {
       free(pessoa);
   }
}

int pessoa_cadastra(Lista *lista) {

    FILE *arquivo = fopen("Clientes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Pessoa *pessoa = malloc(sizeof(Pessoa));
    if (pessoa == NULL) {
        printf("Erro ao alocar memória.\n");
        return 0;
    }

    printf("Digite o código do cliente: ");
    fgets(pessoa->codcliente, sizeof(pessoa->codcliente), stdin);
    getchar();
    pessoa->codcliente[strcspn(pessoa->codcliente, "\n")] = '\0'; 
    
    printf("Digite o nome: ");
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    getchar();
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0'; 

    printf("Digite o telefone: ");
    fgets(pessoa->telefone, sizeof(pessoa->telefone), stdin);
    getchar();
    pessoa->telefone[strcspn(pessoa->telefone, "\n")] = '\0'; 

    printf("Digite o endereço: ");
    fgets(pessoa->endereco, sizeof(pessoa->endereco), stdin);
    getchar();
    pessoa->endereco[strcspn(pessoa->endereco, "\n")] = '\0'; 

    printf("Digite a data de nascimento: ");
    fgets(pessoa->data_nascimento, sizeof(pessoa->data_nascimento), stdin);
    getchar();
    pessoa->data_nascimento[strcspn(pessoa->data_nascimento, "\n")] = '\0'; 

    if (lista->inicio == NULL) {
        lista->inicio = pessoa;
        lista->fim = pessoa;
    } else {
        lista->fim->proximo = pessoa;
        lista->fim = pessoa;
    }

    pessoa->proximo = NULL;
    printf("Pessoa cadastrada com sucesso!\n");
    fprintf(arquivo, "%s\n", pessoa->codcliente);
    fprintf(arquivo, "%s\n", pessoa->nome);
    fprintf(arquivo, "%s\n", pessoa->telefone);
    fprintf(arquivo, "%s\n", pessoa->endereco);
    fprintf(arquivo, "%s\n", pessoa->data_nascimento);
    fprintf(arquivo, "\n");
    fclose(arquivo);

    return 1;
}

void listar_clientes(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("Não há clientes cadastrados.\n");
    } else {
        Pessoa *pessoa = lista->inicio;
        while (pessoa != NULL) {
            printf("Código do cliente: %s\n", pessoa->codcliente);
            printf("Nome: %s\n", pessoa->nome);
            printf("Telefone: %s\n", pessoa->telefone);
            printf("Endereço: %s\n", pessoa->endereco);
            printf("Data de nascimento: %s\n", pessoa->data_nascimento);
            printf("\n");
            pessoa = pessoa->proximo;
        }
    }
    FILE *arquivo = fopen("Clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void remover_pessoa(Lista *lista) {
    char codcliente[15];
    printf("Digite o código do cliente que deseja remover: ");
    fgets(codcliente, sizeof(codcliente), stdin);
    codcliente[strcspn(codcliente, "\n")] = '\0'; 
    FILE *arquivo = fopen("Clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[100];
    FILE *arquivo_temp = fopen("temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }
    int linhas_lidas = 0;
    int linhas_escritas = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; 
        if (strcmp(linha, codcliente) != 0) {
            fprintf(arquivo_temp, "%s\n", linha); 
        } else {
            for(int i = 0; i < 4; i++) {
                fgets(linha, sizeof(linha), arquivo);
                linhas_lidas++;
            }
        }
    }
    fclose(arquivo);
    fclose(arquivo_temp);
    if(linhas_escritas == linhas_lidas - 4) {
        remove("Clientes.txt");
        rename("temp.txt", "Clientes.txt");
        printf("Pessoa removida com sucesso.\n");
    } else {
        printf("Pessoa não encontrada.\n");
    }
}

void pesquisar_pessoa(Lista *lista) {
    char codigo[20];
    char linha[300];
    printf("Digite o código do cliente: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0'; 

    FILE *arquivo = fopen("Clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Pessoa cliente;
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
    if (sscanf(linha, "%s", cliente.codcliente) == 1) {
        fgets(cliente.nome, sizeof(cliente.nome), arquivo);
        fgets(cliente.telefone, sizeof(cliente.telefone), arquivo);
        fgets(cliente.endereco, sizeof(cliente.endereco), arquivo);
        fgets(cliente.data_nascimento, sizeof(cliente.data_nascimento), arquivo);

        // Remova os caracteres de nova linha, se presentes
        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
        cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
        cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
        cliente.data_nascimento[strcspn(cliente.data_nascimento, "\n")] = '\0';

        if (strcmp(cliente.codcliente, codigo) == 0) {
            printf("Cliente encontrado!\n");
            printf("Código: %s\n", cliente.codcliente);
            printf("Nome: %s\n", cliente.nome);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Endereço: %s\n", cliente.endereco);
            printf("Data de nascimento: %s\n", cliente.data_nascimento);
            encontrado = 1;
            break;
            }
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    }

    fclose(arquivo);
}

//alterar cliente no arquivo
void alterar_clientes(const char *codigo_cliente) {
    FILE *arquivo = fopen("Clientes.txt", "r");
    FILE *temp = fopen("Clientes_temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[200]; 
    while (fgets(linha, sizeof(linha), arquivo)) {
        char codigo[10];
        Pessoa cliente;
        int opcao;
        if (sscanf(linha, "%9s", codigo) == 1) {
            if (strcmp(codigo, codigo_cliente) == 0) {
                printf("Cliente encontrado!\n");
                printf("O que deseja alterar?\n");
                printf("1 - Nome\n");
                printf("2 - Telefone\n");
                printf("3 - Endereço\n");
                printf("4 - Data de nascimento\n");
                printf("Opção: ");
                scanf("%d", &opcao);
                limpar_buffer();
                switch(opcao) {
                    case 1:
                        printf("Digite o novo nome: ");
                        fgets(linha, sizeof(linha), stdin);
                        linha [strcspn(linha, "\n")] = '\0';
                        fprintf(temp, "%s\n", codigo);
                        fprintf(temp, "%s\n", linha); // Grava o novo nome
                        fgets(linha, sizeof(linha), arquivo);
                        break; // Encontrou o cliente, para a busca
                    case 2: 
                        printf("Digite o novo telefone: ");
                        fgets(linha, sizeof(linha), stdin);
                        linha [strcspn(linha, "\n")] = '\0';
                        fgets(cliente.nome, sizeof(cliente.nome), arquivo);
                        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
                        fprintf(temp, "%s\n", codigo); 
                        fprintf(temp, "%s\n", cliente.nome); 
                        fprintf(temp, "%s\n", linha); 
                        fgets(linha, sizeof(linha), arquivo);
                        break; 
                    case 3:
                        printf("Digite o novo endereço: ");
                        fgets(linha, sizeof(linha), stdin);
                        linha [strcspn(linha, "\n")] = '\0';
                        fgets(cliente.nome, sizeof(cliente.nome), arquivo);
                        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
                        fgets(cliente.telefone, sizeof(cliente.telefone), arquivo);
                        cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
                        fprintf(temp, "%s\n", codigo);
                        fprintf(temp, "%s\n", cliente.nome); 
                        fprintf(temp, "%s\n", cliente.telefone);
                        fprintf(temp, "%s\n", linha);
                        fgets(linha, sizeof(linha), arquivo);
                        break; 
                    case 4:
                        printf("Digite a nova data de nascimento: ");
                        fgets(linha, sizeof(linha), stdin);
                        linha [strcspn(linha, "\n")] = '\0';
                        fgets(cliente.nome, sizeof(cliente.nome), arquivo);
                        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
                        fgets(cliente.telefone, sizeof(cliente.telefone), arquivo);
                        cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
                        fgets(cliente.endereco, sizeof(cliente.endereco), arquivo);
                        cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
                        fprintf(temp, "%s\n", codigo); 
                        fprintf(temp, "%s\n", cliente.nome);
                        fprintf(temp, "%s\n", cliente.telefone);
                        fprintf(temp, "%s\n", cliente.endereco);
                        fprintf(temp, "%s\n", linha); 
                        fgets(linha, sizeof(linha), arquivo);
                        break; 
                    default:
                        printf("Opção inválida. Nenhuma alteração foi feita.\n");
                        break;
                    }
            } else {
                fprintf(temp, "%s", linha);
            }
        } else {
            fprintf(temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);
    remove("Clientes.txt");
    rename("Clientes_temp.txt", "Clientes.txt");
    printf("Dados atualizados com sucesso!\n");
}

    
