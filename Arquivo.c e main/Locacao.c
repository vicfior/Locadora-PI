#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Filme.h"
#include "Cliente.h"
#include "Locacao.h"

void limpar_buffer_locacao() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Locacao *locacao_cria() {
    Locacao *locacao = (Locacao*)malloc(sizeof(Locacao));
    if (locacao != NULL) {
        locacao->proximo = NULL;
    }
    locacao->proximo = NULL;
    return locacao;
}

void inserir_locacao(Locacao **inicio, Locacao *nova_locacao) {
    if (*inicio == NULL) {
        *inicio = nova_locacao;
    } else {
        Locacao *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nova_locacao;
    }
}

void locacao_libera(Locacao *locacao) {
   if(locacao != NULL) {
       free(locacao);
   }
}

int cliente_existe(char* codcliente) {
    Cliente cliente;
    FILE* arq = fopen("Clientes.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    printf("Digite o código do cliente: ");
    fgets(codcliente, 10, stdin);
    printf("Código do cliente digitado: %s\n", codcliente);

    char linha[200];
    int clienteEncontrado = 0;

    char tempCodCliente[10];
    char tempNome[100];
    char tempTelefone[20];
    char tempEndereco[100];
    char tempDataNascimento[20];

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        if (strstr(linha, codcliente) != NULL) {
            clienteEncontrado = 1;
            strcpy(tempCodCliente, linha);

            fgets(tempNome, sizeof(tempNome), arq);
            fgets(tempTelefone, sizeof(tempTelefone), arq);
            fgets(tempEndereco, sizeof(tempEndereco), arq);
            fgets(tempDataNascimento, sizeof(tempDataNascimento), arq);

            break;
        }
    }

    fclose(arq);

    if (clienteEncontrado) {
        printf("Cliente encontrado!\n");
        printf("Código: %s", tempCodCliente);
        printf("Nome: %s", tempNome);
        printf("Telefone: %s", tempTelefone);
        printf("Endereço: %s", tempEndereco);
        printf("Data de nascimento: %s", tempDataNascimento);
        return 1;
    } else {
        printf("Cliente não encontrado!\n");
        printf("Cadastrar novo cliente? 1 - sim, 0 - não\n");
        //chame a função de cadastro de pessoas
        int opcao;
        scanf("%d", &opcao);
        limpar_buffer_locacao();
        if (opcao == 1) {
            Lista *lista = lista_cria();
            if (cadastrar_cliente(lista)==1) {
                return 1;
            } else {
                return 0;
            }
        } else {
        return 0;
        }
    }
}

int filme_existe(char* codfilme) {
    Filme filme;
    FILE* arq = fopen("Filmes.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    
    printf("Digite o código do filme: ");
    fgets(codfilme, 10, stdin);
    printf("Código do filme digitado: %s\n", codfilme);
    
    char linha[200];
    int filmeEncontrado = 0;
    
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        if (strstr(linha, codfilme) != NULL) {
            filmeEncontrado = 1;
            printf("Filme encontrado!\n");
            printf("Código: %s\n", linha);
            fgets(filme.titulo, sizeof(filme.titulo), arq);
            fgets(filme.ator_principal, sizeof(filme.ator_principal), arq);
            fgets(filme.ator_coadjuvante, sizeof(filme.ator_coadjuvante), arq);
            fgets(filme.ano, sizeof(filme.ano), arq);
            fgets(filme.diretor, sizeof(filme.diretor), arq);
            fgets(filme.genero, sizeof(filme.genero), arq);
            break;
        }
    }
    
    fclose(arq);
    
    if (filmeEncontrado) {
        printf("Titulo: %s", filme.titulo);
        printf("Ator_principal: %s", filme.ator_principal);
        printf("Ator_coadjuvante: %s", filme.ator_coadjuvante);
        printf("Ano: %s", filme.ano);
        printf("Diretor: %s", filme.diretor);
        printf("Gênero: %s", filme.genero);
        return 1;
    } else {
        printf("Filme não encontrado!\n");
        return 0;
    }
}


void alugar_filme() {
    Locacao *locacao = locacao_cria();
    char codfilme[20];
    char codcliente[20];
    char data_locacao[20];
    char data_devolucao[20];
    char linha[300];
    int a;
    int b;

    FILE *arquivo = fopen("Locacao.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (filme_existe(codfilme) && cliente_existe(codcliente)) {
        if (filme_disponivel(codfilme) == 1) {
        printf("Filme disponível para locação!\n");
        printf("Código do filme: %s\n", codfilme);
        printf("Código do cliente: %s\n", codcliente);
        printf("Digite o código de locação: ");
        fgets(locacao->codlocacao, sizeof(locacao->codlocacao), stdin);
        printf("Código de locação: %s\n", locacao->codlocacao);
        printf("Digite a data de locação: ");
        fgets(data_locacao, sizeof(data_locacao), stdin);
        printf("Digite a data de devolução: ");
        fgets(data_devolucao, sizeof(data_devolucao), stdin);

        strcpy(locacao->codfilme, codfilme);
        strcpy(locacao->codcliente, codcliente);
        strcpy(locacao->data_locacao, data_locacao);
        strcpy(locacao->data_devolucao, data_devolucao);
        locacao->proximo = NULL;

        fprintf(arquivo, "%s", locacao->codlocacao);
        fprintf(arquivo, "%s", locacao->codcliente);
        fprintf(arquivo, "%s", locacao->codfilme);
        fprintf(arquivo, "%s", locacao->data_locacao);
        fprintf(arquivo, "%s", locacao->data_devolucao);
        fprintf(arquivo, "\n");
        printf ("Filme alugado com sucesso!\n");
        fclose(arquivo);
        } else {
            printf("Filme indisponível para locação!\n");
            printf("Verificar se o filme está reservado?\n");
                printf("Digite 1 para SIM e 2 para voltar ao menu\n");
                printf("Opção: ");
                scanf ("%d", &a);
                if (a == 1) {
                    if (pesquisar_reserva() == 1) {
                    printf("Filme reservado a mais de 3 dias?\n");
                    printf("Digite 1 para SIM e 2 para NÃO\n");
                    printf("Opção: ");
                    scanf("%d", &b);
                        if (b == 1) {
                            remover_reserva();
                            printf("Filme devolvido com sucesso e disponível para nova locação!\n");
                        } else if (b == 2) {
                            printf("Filme continua indisponível para locação!\n");
                        }
                    } else {
                        printf("Filme continua indisponível para locação\n");
                        printf("Voltando ao menu\n");
                    }
                } else if (a == 2) {
                    //menu_operacao();
                }
        }
    } else {
        printf("Erro ao encontrar o filme ou o cliente!\n");
    }
}

int filme_disponivel(char* codfilme) {
    char linha[300];
    FILE *arquivo = fopen("Locacao.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    } 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, codfilme) != NULL) {
            fclose(arquivo);
            return 0;
        }
    }

    FILE *arquivo2 = fopen("Reservas.txt", "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    while (fgets(linha, sizeof(linha), arquivo2) != NULL) {
        if (strstr(linha, codfilme) != NULL) {
            fclose(arquivo2);
            return 0;
        }
    }
    fclose(arquivo);
    fclose(arquivo2);
    return 1;
}   

void exibir_locacoes() {
    Locacao *locacao = locacao_cria();
    char linha[300];
    FILE *arquivo = fopen("Locacao.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void pesquisar_locacao() {
    Filme filme;
    Locacao *locacao = locacao_cria();
    char codlocacao[20];
    char linha[300];
    int opcao;
    int informacao_encontrada = 0;
    FILE *arquivo = fopen("Locacao.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código de locação: ");
    fgets(codlocacao, sizeof(codlocacao), stdin);
    printf("Procurando informação da locação %s\n", codlocacao);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, codlocacao) != NULL) {
            informacao_encontrada = 1;
            strcpy(locacao->codlocacao, linha);
            fgets(locacao->codcliente, sizeof(locacao->codcliente), arquivo);
            fgets(locacao->codfilme, sizeof(locacao->codfilme), arquivo);
            fgets(locacao->data_locacao, sizeof(locacao->data_locacao), arquivo);
            fgets(locacao->data_devolucao, sizeof(locacao->data_devolucao), arquivo);
            printf("Código de locação: %s", locacao->codlocacao);
            printf("Código do cliente: %s", locacao->codcliente);
            printf("Código do filme: %s", locacao->codfilme);
            printf("Data de locação: %s", locacao->data_locacao);
            printf("Data de devolução: %s", locacao->data_devolucao);
            break;
        }
    }
    fclose(arquivo);
    if (!informacao_encontrada) {
        printf("Locação não encontrada!\n");
    }
}

double aplicar_multa() {
    int dia_de_atraso;
    int opcao;
    double multa;
    printf("Digite a quantidade de dias de atraso: ");
    scanf("%d", &dia_de_atraso);
    if (dia_de_atraso == 1) {
        receber_pagamento() + 2.50;
    } else {
        multa = receber_pagamento() + 2.50 + (0.50*dia_de_atraso);
        printf("Quantidade de dias de atraso: %d\n", dia_de_atraso);
        printf("Valor do pagamento total: %.2f\n", multa);
    }
    return multa;
}

double receber_pagamento() {
    int valor = 10;
    printf("Recebendo pagamento...\n");
    printf("Valor do pagamento: %d\n", valor);
    return valor;
}

void devolver_filme(char *codlocacao) {
    Locacao *locacao = locacao_cria();
    //char codlocacao[20];
    char linha[300];
    int informacao_encontrada = 0;
    FILE *arquivo = fopen("Locacao.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    printf("Procurando informação da locação %s\n", codlocacao);
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, codlocacao) != NULL) {
            informacao_encontrada = 1;
            strcpy(locacao->codlocacao, linha);
            fgets(locacao->codcliente, sizeof(locacao->codcliente), arquivo);
            fgets(locacao->codfilme, sizeof(locacao->codfilme), arquivo);
            fgets(locacao->data_locacao, sizeof(locacao->data_locacao), arquivo);
            fgets(locacao->data_devolucao, sizeof(locacao->data_devolucao), arquivo);
            
            locacao->codlocacao[strcspn(locacao->codlocacao, "\n")] = '\0';
            locacao->codcliente[strcspn(locacao->codcliente, "\n")] = '\0';
            locacao->codfilme[strcspn(locacao->codfilme, "\n")] = '\0';
            locacao->data_locacao[strcspn(locacao->data_locacao, "\n")] = '\0';
            locacao->data_devolucao[strcspn(locacao->data_devolucao, "\n")] = '\0';
            
            printf("%s\n", locacao->codlocacao);
            printf("%s\n", locacao->codcliente);
            printf("%s\n", locacao->codfilme);
            printf("%s\n", locacao->data_locacao);
            printf("%s\n", locacao->data_devolucao);
            break;
        }
    }
    printf ("Digite a data da devolução:");
    scanf("%s", locacao->data_devolucao);
    if (informacao_encontrada) {
        int dia_atrasado;
        printf("Teve atraso? (1 - Sim, 2 - Não): ");
        scanf("%d", &dia_atrasado);
        if (dia_atrasado == 1) {
            printf("Aplicando multa...\n");
            locacao->valorpago = aplicar_multa();
        } else {
            locacao->valorpago = receber_pagamento();
        }
    } else {
        printf("Locação não encontrada!\n");
    }

    FILE *arquivo_historico = fopen("Historico.txt", "a");
    if (arquivo_historico == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(arquivo_historico, "%s\n", locacao->codcliente);
    fprintf(arquivo_historico, "%s\n", locacao->codlocacao);
    fprintf(arquivo_historico, "%s\n", locacao->codfilme);
    fprintf(arquivo_historico, "%s\n", locacao->data_devolucao);
    fprintf(arquivo_historico, "%.2f\n", locacao->valorpago);
    fprintf(arquivo_historico, "\n");
    fclose(arquivo_historico);
    fclose(arquivo);
}

void remover_locacao(char *codlocacao) {
    //char codlocacao[20];
    
    FILE *arquivo = fopen("Locacao.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[1000];
    FILE *arquivotemp = fopen("temp.txt", "w");
    if (arquivotemp == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }
    int linhas_lidas = 0;
    int linhas_escritas = 0;

    while (fgets(linha, sizeof(linha),arquivo)!=NULL) {
        linha[strcspn(linha, "\n")] = '\0';  
        if (strcmp(linha, codlocacao) != 0) {
            fprintf(arquivotemp, "%s\n", linha);
        } else {
            for(int i = 0; i < 5; i++) {
                fgets(linha, sizeof(linha), arquivo);
                linhas_lidas++;
            }
        }
    }

    fclose(arquivo);
    fclose(arquivotemp);
    if (linhas_escritas == linhas_lidas - 5) {
        remove("Locacao.txt");
        rename("temp.txt","Locacao.txt");
        printf("Locação removida com sucesso.\n");
    } else {
        printf("Locação não encontrada.\n");
    }
    return;
}
    
void pesquisar_historico() {
    char codigo[20];
    char linha[300];
    Locacao l;
    int informacao_encontrada = 0;
    FILE *arquivo = fopen("Historico.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    printf("Digite o código do cliente: \n");
    printf(">> ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0'; 
    
    printf("Procurando informação do cliente %s\n", codigo);
    
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strcmp(linha, "\n") == 0) {
            continue;
        }
        sscanf(linha, "%[^\n]", l.codcliente);
        fgets(l.codlocacao, sizeof(l.codlocacao), arquivo);
        fgets(l.codfilme, sizeof(l.codfilme), arquivo);
        fgets(l.data_devolucao, sizeof(l.data_devolucao), arquivo);
        fscanf(arquivo, "%lf", &l.valorpago);
        
        // Remove newline characters from the strings
        l.codlocacao[strcspn(l.codlocacao, "\n")] = '\0';
        l.codcliente[strcspn(l.codcliente, "\n")] = '\0';
        l.codfilme[strcspn(l.codfilme, "\n")] = '\0';
        l.data_devolucao[strcspn(l.data_devolucao, "\n")] = '\0';
        
        if (strcmp(l.codcliente, codigo) == 0) {
            informacao_encontrada = 1;
            printf("Código do cliente: %s\n", l.codcliente);
            printf("Código da locação: %s\n", l.codlocacao);
            printf("Código do filme: %s\n", l.codfilme);
            printf("Data de devolução: %s\n", l.data_devolucao);
            printf("Valor pago: %.2f\n", l.valorpago);
            printf("\n");
        }
    } 
    if(!informacao_encontrada) {
        printf("Cliente não encontrado!\n");
    }
    fclose(arquivo);
}

void reservar_filme() {
    char codcliente[20];
    char codfilme[20];
    char data_reserva[20];
    char codreserva[20];

    printf("Digite o código do cliente: ");
    fgets(codcliente, sizeof(codcliente), stdin);
    codcliente[strcspn(codcliente, "\n")] = '\0'; 
    printf("Digite o código do filme: ");
    fgets(codfilme, sizeof(codfilme), stdin);
    codfilme[strcspn(codfilme, "\n")] = '\0';
    printf("Digite a data da reserva (dd/mm/aaaa): ");
    fgets(data_reserva, sizeof(data_reserva), stdin);
    data_reserva[strcspn(data_reserva, "\n")] = '\0';

    FILE *arquivo = fopen("Reservas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo, "%s\n", codfilme);
    fprintf(arquivo, "%s\n", codcliente);
    fprintf(arquivo, "%s\n", data_reserva);
    fclose(arquivo);
    printf("Reserva efetuada com sucesso.\n");
    printf("A reserva ficará ativa por 3 dias, após isso o filme ficará disponível para locação.\n");
}

void remover_reserva() {
    char codfilme[20];
    printf("Digite o código do filme reservado: ");
    getchar();
    fgets(codfilme, sizeof(codfilme), stdin);
    codfilme[strcspn(codfilme, "\n")] = '\0'; 
    FILE *arquivo = fopen("Reservas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[100];
    FILE *arquivo_temp_r = fopen("tempr.txt", "w");
    if (arquivo_temp_r == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo_temp_r);
        return;
    }
    int linhas_lidas = 0;
    int linhas_escritas = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, codfilme) != 0) {
            fprintf(arquivo_temp_r, "%s\n", linha); 
        } else {
            for(int i = 0; i < 3; i++) {
                fgets(linha, sizeof(linha), arquivo);
                linhas_lidas++;
            }
        }
    }
    fclose(arquivo);
    fclose(arquivo_temp_r);
    if(linhas_escritas == linhas_lidas - 3) {
        remove("Reservas.txt");
        rename("tempr.txt", "Reservas.txt");
        printf("Reserva removida com sucesso.\n");
    } else {
        printf("Reserva não encontrada.\n");
    }
}

int pesquisar_reserva() {
    Locacao *locacao = locacao_cria();
    Locacao l;
    char codigofilme[20];
    char linha[300];
    int informacao_encontrada = 0;
    FILE *arquivo = fopen("Reservas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    printf("Digite o código do filme: \n");
    printf(">> ");
    fgets(codigofilme , sizeof(codigofilme), stdin);
    codigofilme[strcspn(codigofilme, "\n")] = '\0';
    printf ("Procurando informação do filme %s\n", codigofilme);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if(strcmp (linha, "\n") == 0) {
            continue;
        } 
        sscanf(linha, "%s[^\n]", l.codfilme);
        fgets(l.codcliente, sizeof(l.codcliente), arquivo);
        fgets(l.data_reserva, sizeof(l.data_reserva), arquivo);
 
        l.codfilme[strcspn(l.codfilme, "\n")] = '\0';
        l.codcliente[strcspn(l.codcliente, "\n")] = '\0';
        l.data_reserva[strcspn(l.data_reserva, "\n")] = '\0';
        
        if (strcmp(l.codfilme, codigofilme) == 0) {
            informacao_encontrada = 1;
            printf("%s\n", l.codfilme);
            printf("%s\n", l.codcliente);
            printf("%s\n", l.data_reserva);
            printf("\n");
            break;
        }
    }
    if(!informacao_encontrada) {
        printf("Reserva não encontrada!\n");
        return 0;
    }
    fclose(arquivo);
    return 1;
}

void exibir_reservas() {
    Locacao *locacao = locacao_cria();
    char linha[300];
    FILE *arquivo = fopen("Reservas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
}
