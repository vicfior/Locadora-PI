#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Filme.h"

void limpar_buffer_filme() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Lista_filme *lista_cria_filme() {
    Lista_filme *listaf = (Lista_filme*)malloc(sizeof(Lista_filme));
    if (listaf != NULL) {
        listaf->inicio = NULL;
        listaf->fim = NULL;
    }
    return listaf;
}

Filme *filme_cria() {
    Filme *filme = (Filme*)malloc(sizeof(Filme));
    if (filme != NULL) {
        filme->proximo = NULL;
    }
    return filme;
}


void filme_libera(Filme *filme) {
   if(filme != NULL) {
       free(filme);
   }
}

void filme_cadastra(Lista_filme *listaf) {
    FILE *arquivo = fopen("Filmes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Filme *filme = malloc(sizeof(Filme));
    if (filme == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    printf("%s", CODIGO);
	printf(" Digite o código: \n");
    printf(">>");
	scanf ("%[^\n]", filme->codfilme);
    getchar();

    printf("%s", CLAQUETE);
	printf(" Digite o título: \n");
    printf(">>");
    fgets(filme->titulo, sizeof(filme->titulo), stdin);
	

	printf("%s", ATORP);
	printf(" Digite o ator principal: \n");
    printf(">>");
	fgets(filme->ator_principal, sizeof(filme->ator_principal), stdin);
	
	printf("%s", ATORC);
	printf(" Digite o ator coadjuvante: \n");
    printf(">>");
	fgets(filme->ator_coadjuvante, sizeof(filme->ator_coadjuvante), stdin);

	printf("%s", ANO);
	printf(" Digite o ano: \n");
    printf(">>");
	fgets(filme->ano, sizeof(filme->ano), stdin);

	printf("%s", DIRETOR);
	printf(" Digite o diretor: \n");
    printf(">>");
	fgets(filme->diretor, sizeof(filme->diretor), stdin);

	printf("%s", GENERO);
	printf(" Digite o gênero: \n");
    printf(">>");
	fgets(filme->genero, sizeof(filme->genero), stdin);

    if (listaf->inicio == NULL) {
        listaf->inicio = filme;
        listaf->fim = filme;
    } else {
        listaf->fim->proximo = filme;
        listaf->fim = filme;
    }

    printf("Filme cadastrado com sucesso!\n");
    filme->proximo = NULL;
    filme->codfilme[strcspn(filme->codfilme, "\n")] = '\0';
    filme->titulo[strcspn(filme->titulo, "\n")] = '\0';
    filme->ator_principal[strcspn(filme->ator_principal, "\n")] = '\0';
    filme->ator_coadjuvante[strcspn(filme->ator_coadjuvante, "\n")] = '\0';
    filme->ano[strcspn(filme->ano, "\n")] = '\0';
    filme->diretor[strcspn(filme->diretor, "\n")] = '\0';
    filme->genero[strcspn(filme->genero, "\n")] = '\0';
	fprintf(arquivo, "%s\n", filme->codfilme);
    fprintf(arquivo, "%s\n", filme->titulo);
    fprintf(arquivo, "%s\n", filme->ator_principal);
    fprintf(arquivo, "%s\n", filme->ator_coadjuvante);
    fprintf(arquivo, "%s\n", filme->ano);
    fprintf(arquivo, "%s\n", filme->diretor);
    fprintf(arquivo, "%s\n", filme->genero);
    fprintf(arquivo, "\n");
    fclose(arquivo);
}


void remover_filme(Lista_filme *listaf) {
    char codfilme[15];
    printf("Digite o código do filme que deseja remover: ");
    fgets(codfilme, sizeof(codfilme), stdin);
    codfilme[strcspn(codfilme, "\n")] = '\0'; 
    FILE *arquivo = fopen("Filmes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[1000];
    FILE *arquivo_temp = fopen("temp1.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }
    int linhas_lidas = 0;
    int linhas_escritas = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; 
        if (strcmp(linha, codfilme) != 0) {
            fprintf(arquivo_temp, "%s\n", linha); 
        } else {
            for(int i = 0; i < 7; i++) {
                fgets(linha, sizeof(linha), arquivo);
                linhas_lidas++;
            }
        }
    }
    fclose(arquivo);
    fclose(arquivo_temp);
    if(linhas_escritas == linhas_lidas - 7) {
        remove("Filmes.txt");
        rename("temp1.txt","Filmes.txt");
        printf("Filme removido com sucesso.\n");
    } else {
        printf("Filme não encontrado.\n");
    }
    return;
}


void pesquisar_filme(Lista_filme *listaf) {
    char codigo[20];
    char linha[1000];
    printf("Digite o código do filme: \n");
    printf(">> ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    FILE *arquivo = fopen("Filmes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Filme filme;
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%s", filme.codfilme) == 1) {
            fgets(filme.titulo, sizeof(filme.titulo), arquivo);
            fgets(filme.ator_principal, sizeof(filme.ator_principal), arquivo);
            fgets(filme.ator_coadjuvante, sizeof(filme.ator_coadjuvante), arquivo);
            fgets(filme.ano, sizeof(filme.ano), arquivo);
            fgets(filme.diretor, sizeof(filme.diretor), arquivo);
            fgets(filme.genero, sizeof(filme.genero), arquivo);

            filme.titulo[strcspn(filme.titulo, "\n")] = '\0';
            filme.ator_principal[strcspn(filme.ator_principal, "\n")] = '\0';
            filme.ator_coadjuvante[strcspn(filme.ator_coadjuvante, "\n")] = '\0';
            filme.ano[strcspn(filme.ano, "\n")] = '\0';
            filme.diretor[strcspn(filme.diretor, "\n")] = '\0';
            filme.genero[strcspn(filme.genero, "\n")] = '\0';

            if (strcmp(filme.codfilme, codigo) == 0) {
                printf("Filme encontrado!\n");
                printf("\n");
                printf("------------------ Informações do Filme %s -----------------------------\n", filme.codfilme);
                printf("                   Código: %s\n", filme.codfilme);
                printf("                   Título: %s\n", filme.titulo);
                printf("                   Ator principal: %s\n", filme.ator_principal);
                printf("                   Ator coadjuvante: %s\n", filme.ator_coadjuvante);
                printf("                   Ano: %s\n", filme.ano);
                printf("                   Diretor: %s\n", filme.diretor);
                printf("                   Gênero: %s\n", filme.genero);
                printf("------------------------------------------------------------------------------\n");
                encontrou = 1;
                break;
            }
        }
    }  
    if (!encontrou) {
        printf("Filme não encontrado.\n");
    }
    fclose(arquivo);   
}


void listar_filme() {
    int opcao;
    Filme f;
    FILE *arquivo = fopen("Filmes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    int encontrou = 0;
    char linha [1000];
    char genero[1000];
    char ano[10];
    char ator[1000]
    printf("Escolha sua opção: \n");
    printf("1 - Listar todos os filmes\n");
    printf("2 - Listar filmes por genero\n");
    printf("3 - Listar filmes por ano\n");
    printf("4 - Listar filmes por ator\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            while (fgets(linha, sizeof(linha), arquivo)) {
                printf("%s", linha);
            }
            fclose(arquivo);
            break;
        case 2:
            printf("Digite o genero: ");
            limpar_buffer_filme();
            fgets(genero, sizeof(genero), stdin);
            genero[strcspn(genero, "\n")] = '\0';
            printf("Buscando filmes com o genero: %s\n\n", genero);
            while (fgets(linha, sizeof(linha), arquivo)) {
                if (strcmp(linha, "\n") == 0) {
                    continue;
                }
                sscanf(linha, "%[^\n]", f.codfilme);
                fgets(f.titulo, sizeof(f.titulo), arquivo);
                fgets(f.ator_principal, sizeof(f.ator_principal), arquivo);
                fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), arquivo);
                fgets(f.ano, sizeof(f.ano), arquivo);
                fgets(f.diretor, sizeof(f.diretor), arquivo);
                fgets(f.genero, sizeof(f.genero), arquivo);
                f.titulo[strcspn(f.titulo, "\n")] = '\0';
                f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
                f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
                f.ano[strcspn(f.ano, "\n")] = '\0';
                f.diretor[strcspn(f.diretor, "\n")] = '\0';
                f.genero[strcspn(f.genero, "\n")] = '\0';
                if (strcmp(f.genero, genero) == 0) {
                    encontrou = 1;
                    printf("Código: %s\n", f.codfilme);
                    printf("Título: %s\n", f.titulo);
                    printf("Ator principal: %s\n", f.ator_principal);
                    printf("Ator coadjuvante: %s\n", f.ator_coadjuvante);
                    printf("Ano: %s\n", f.ano);
                    printf("Diretor: %s\n", f.diretor);
                    printf("Gênero: %s\n", f.genero);
                    printf("\n");
                }
            }
            if (!encontrou) {
                printf("Filme não encontrado.\n");
            }
            fclose(arquivo);
            break;
        case 3:
            printf("Digite o ano: ");
            limpar_buffer_filme();
            fgets(ano, sizeof(ano), stdin);
            ano[strcspn(ano, "\n")] = '\0';
            printf("Buscando filmes do ano: %s\n\n", ano);
            while (fgets(linha, sizeof(linha), arquivo)) {
                if (strcmp(linha, "\n") == 0) {
                    continue;
                }
                sscanf(linha, "%[^\n]", f.codfilme);
                fgets(f.titulo, sizeof(f.titulo), arquivo);
                fgets(f.ator_principal, sizeof(f.ator_principal), arquivo);
                fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), arquivo);
                fgets(f.ano, sizeof(f.ano), arquivo);
                fgets(f.diretor, sizeof(f.diretor), arquivo);
                fgets(f.genero, sizeof(f.genero), arquivo);
                f.titulo[strcspn(f.titulo, "\n")] = '\0';
                f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
                f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
                f.ano[strcspn(f.ano, "\n")] = '\0';
                f.diretor[strcspn(f.diretor, "\n")] = '\0';
                f.genero[strcspn(f.genero, "\n")] = '\0';
                if (strcmp(f.ano, ano) == 0) {
                    encontrou = 1;
                    printf("Código: %s\n", f.codfilme);
                    printf("Título: %s\n", f.titulo);
                    printf("Ator principal: %s\n", f.ator_principal);
                    printf("Ator coadjuvante: %s\n", f.ator_coadjuvante);
                    printf("Ano: %s\n", f.ano);
                    printf("Diretor: %s\n", f.diretor);
                    printf("Gênero: %s\n", f.genero);
                    printf("\n");
                }
            }
            if (!encontrou) {
                printf("Filme não encontrado.\n");
            }
            fclose(arquivo);
        break;
        case 4:
            printf("Digite o ator: ");
            limpar_buffer_filme();
            fgets(ator, sizeof(ator), stdin);
            ator[strcspn(ator, "\n")] = '\0';
            printf("Buscando filmes do ator: %s\n\n", ator);
            while (fgets(linha, sizeof(linha), arquivo)) {
                if (strcmp(linha, "\n") == 0) {
                    continue;
                }
                sscanf(linha, "%[^\n]", f.codfilme);
                fgets(f.titulo, sizeof(f.titulo), arquivo);
                fgets(f.ator_principal, sizeof(f.ator_principal), arquivo);
                fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), arquivo);
                fgets(f.ano, sizeof(f.ano), arquivo);
                fgets(f.diretor, sizeof(f.diretor), arquivo);
                fgets(f.genero, sizeof(f.genero), arquivo);
                f.titulo[strcspn(f.titulo, "\n")] = '\0';
                f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
                f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
                f.ano[strcspn(f.ano, "\n")] = '\0';
                f.diretor[strcspn(f.diretor, "\n")] = '\0';
                f.genero[strcspn(f.genero, "\n")] = '\0';
                if (strcmp(f.ator_principal, ator) == 0 || strcmp(f.ator_coadjuvante, ator) == 0) {
                    encontrou = 1;
                    printf("Código: %s\n", f.codfilme);
                    printf("Título: %s\n", f.titulo);
                    printf("Ator principal: %s\n", f.ator_principal);
                    printf("Ator coadjuvante: %s\n", f.ator_coadjuvante);
                    printf("Ano: %s\n", f.ano);
                    printf("Diretor: %s\n", f.diretor);
                    printf("Gênero: %s\n", f.genero);
                    printf("\n");
                }
            }
            if (!encontrou) {
                printf("Filme não encontrado.\n");
            }
            fclose(arquivo);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}
