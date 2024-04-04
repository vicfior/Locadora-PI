#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Filme.h"

void cadastrar_filme(char *caminho) {
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Cadastro de Filmes                                            \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
   
   Filme *filme = (Filme *)malloc(sizeof(Filme));
   FILE *output = fopen(caminho, "a");
   if(!output) {
	printf("Erro ao abrir o arquivo");
	return;
   }

	printf("%s", CODIGO);
	printf(" Digite o código: ");
	fgets(filme->codfilme, sizeof(filme->codfilme), stdin);
	filme->codfilme[strcspn(filme->codfilme, "\n")] = '\0';
	fflush(stdin);

	printf("%s", CLAQUETE);
	printf(" Digite o título: ");
	//scanf("%s", filme->titulo);
	fgets(filme->titulo, sizeof(filme->titulo), stdin);
	filme->titulo[strcspn(filme->titulo, "\n")] = '\0'; // Remove a quebra de linha do final
	fflush(stdin);
	
	printf("%s", ATORP);
	printf(" Digite o ator principal: ");
	fgets(filme->ator_principal, sizeof(filme->ator_principal), stdin);
	filme->ator_principal[strcspn(filme->ator_principal, "\n")] = '\0';
	fflush(stdin);

	printf("%s", ATORC);
	printf(" Digite o ator coadjuvante: ");
	fgets(filme->ator_coadjuvante, sizeof(filme->ator_coadjuvante), stdin);
	filme->ator_coadjuvante[strcspn(filme->ator_coadjuvante, "\n")] = '\0';
	fflush(stdin);

	printf("%s", ANO);
	printf(" Digite o ano: ");
	fgets(filme->ano, sizeof(filme->ano), stdin);
	filme->ano[strcspn(filme->ano, "\n")] = '\0';
	fflush(stdin);

	printf("%s", DIRETOR);
	printf(" Digite o diretor: ");
	fgets(filme->diretor, sizeof(filme->diretor), stdin);
	filme->diretor[strcspn(filme->diretor, "\n")] = '\0';
	fflush(stdin);

	printf("%s", GENERO);
	printf(" Digite o gênero: ");
	fgets(filme->genero, sizeof(filme->genero), stdin);
	filme->genero[strcspn(filme->genero, "\n")] = '\0';
	fflush(stdin);

	fprintf(output, "%s\t %s\t %s\t %s\t %s\t %s\t %s", filme->codfilme, filme->titulo, filme->ator_principal, filme->ator_coadjuvante, filme->ano, filme->diretor, filme->genero);
	fprintf(output, "\n");

	fclose(output);
	free(filme);
    printf("Informações dos filmes foram salvas no arquivo.\n");
	return;
}

void remover_filme(char *caminho) {
    Filme *codigo = malloc(sizeof(Filme)); 
    if (!codigo) {
        printf("Erro ao alocar memória.\n");
        return;
    }

	FILE *arquivo_entrada = fopen(caminho, "r");
	FILE *arquivo_saida = fopen("temp.txt", "w"); //arquivo temporário para armazenar as linhas que não são o código do filme e nem relativas a ele 
	
	if (!arquivo_entrada || !arquivo_saida) {
		printf("Erro ao abrir os arquivos\n");
		return;
	}

	char linha [100];
	int encontrou_filme = 0;

	printf("Digite o código do filme: ");
    if (!fgets(codigo->codfilme, sizeof(codigo->codfilme), stdin)) {
        printf("Erro ao ler o código do filme.\n");
        fclose(arquivo_entrada);
        fclose(arquivo_saida);
        free(codigo);
        return;
    }
    codigo->codfilme[strcspn(codigo->codfilme, "\n")] = '\0';

	//busca linear, pensar em trocar por uma busca binária depois
	while (fgets(linha, sizeof(linha), arquivo_entrada)) {
        if (strstr(linha, codigo->codfilme)) {
            encontrou_filme = 1;
            // Ignora as próximas 6 linhas
            for (int i = 0; i < 0; i++) {
                if (!fgets(linha, sizeof(linha), arquivo_entrada)) {
                    break; // Fim do arquivo
                }
            }
        } else {
            fputs(linha, arquivo_saida); // Copia a linha para o arquivo temporário
        }
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    if (encontrou_filme) {
        remove(caminho); // Remove o arquivo original
        rename("temp.txt", caminho); // Renomeia o arquivo temporário
        printf("Filme removido com sucesso.\n");
    } else {
        printf("Filme não encontrado.\n");
    }

	free(codigo);
}

/*
void pesquisar_filme(Filme *f, char* codfilme, char *nome_pesquisado) {

}

void listar_filme() {

}

void alterar_filme(Filme *f, char *codfilme, char *novo_titulo, char *novo_ator_principal, char *novo_ator_coadjuvante, char *novo_diretor, int novo_ano, char *novo_genero) {

}*/
