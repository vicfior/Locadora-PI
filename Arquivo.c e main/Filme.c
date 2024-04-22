#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Filme.h"

typedef struct no_filme {
    Filme filme;
    struct no_filme *prox; // Corrigido aqui
} no_filme;

enum propriedades_filme {
    titulo,
    codfilme,
    ator_principal,
    ator_coadjuvante,
    diretor,
    ano,
    genero
};

typedef struct consulta {
    char *propriedades[7]; // Corrigido aqui
    enum propriedades_filme propriedade;
	char valor[100];
} Consulta;

typedef struct lista_filme {
    no_filme *inicio; // Corrigido aqui
    struct consulta consulta;
} lista_filme;

void inicializar_propriedades(struct consulta *consulta) {
    consulta->propriedades[titulo] = "titulo";
    consulta->propriedades[codfilme] = "codfilme";
    consulta->propriedades[ator_principal] = "ator_principal";
    consulta->propriedades[ator_coadjuvante] = "ator_coadjuvante";
    consulta->propriedades[diretor] = "diretor";
    consulta->propriedades[ano] = "ano";
    consulta->propriedades[genero] = "genero";
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

	printf("%s", CLAQUETE);
	printf(" Digite o título: ");
	//scanf("%s", filme->titulo);
	fgets(filme->titulo, sizeof(filme->titulo), stdin);
	filme->titulo[strcspn(filme->titulo, "\n")] = '\0'; // Remove a quebra de linha do final
	fflush(stdin);

	printf("%s", CODIGO);
	printf(" Digite o código: ");
	fgets(filme->codfilme, sizeof(filme->codfilme), stdin);
	filme->codfilme[strcspn(filme->codfilme, "\n")] = '\0';
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

	fprintf(output, "\n%s\n %s\n %s\n %s\n %s\n %s\n %s",filme->titulo, filme->codfilme, filme->ator_principal, filme->ator_coadjuvante, filme->ano, filme->diretor, filme->genero);
	fprintf(output, "\n");

	fclose(output);
	free(filme);
    printf("Informações dos filmes foram salvas no arquivo.\n");
	return;
}

void remover_filme(char *caminho) {
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Remover filmes                                                \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
   
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
            for (int i = 0; i < 6; i++) {
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

void pesquisar_filme(char *caminho) {

	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Pesquisar filmes                                                \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

	Filme *f = malloc(sizeof(Filme));
	if (!f) {
		printf("Erro ao alocar memória.\n");
		return;
	}

	FILE *input = fopen(caminho, "r");
	if (!input) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	printf("Digite o código do filme: ");
	fgets(f->codfilme, sizeof(f->codfilme), stdin);
	f->codfilme[strcspn(f->codfilme, "\n")] = '\0';

	char linha [500];
	int encontrou_filme = 0;

	while (fgets(linha, sizeof(linha), input)) {
		if (strstr(linha, f->codfilme)) {
			encontrou_filme = 1;
			for(int i = 0; i < 6; i++) {
				fgets(linha, sizeof(linha), input);
				printf("%s", linha);
			}
			printf("\n");
			break;
		}
	}

	if (!encontrou_filme) {
		printf("Filme não encontrado.\n");
	}

	fclose(input);
	free(f);

	return;
}

void listar_tudo(char *caminho) 
{
		Filme *f = malloc(sizeof(Filme));
		if (!f) {
			printf("Erro ao alocar memória.\n");
			return;
		}
		FILE *input = fopen(caminho, "r");
		if (!input) {
			printf("Erro ao abrir o arquivo.\n");
			return;
		}
		printf("----------------------------------------------------------------------------------------------------------------\n");
		printf("                                                  Listando todos os filmes                                      \n");
		printf("----------------------------------------------------------------------------------------------------------------\n");
		char linha [1000];
		while (fgets(linha, sizeof(linha), input)) {
			printf("%s", linha);
		}
		fclose(input);
		free(f);
		return;
	}

void listar_genero(char *caminho) {
    Consulta consulta;
    consulta.propriedade = genero;

	printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  Listagem de filmes por gênero                                  \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    // Solicitar ao usuário o gênero desejado
    printf("Digite o gênero que deseja buscar: ");
	limpar_buffer();
    fgets(consulta.valor, sizeof(consulta.valor), stdin);
    consulta.valor[strcspn(consulta.valor, "\n")] = '\0';

    printf("Buscando filmes do gênero: %s\n\n", consulta.valor); // Mensagem de depuração

    FILE *input = fopen(caminho, "r");
    if (!input) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[1000];
    Filme f;
    int encontrou_filme = 0; // Variável para verificar se pelo menos um filme foi encontrado

    while (fgets(linha, sizeof(linha), input)) {
        if (strcmp(linha, "\n") == 0) {
            continue; // Ignorar linhas em branco
        }

        sscanf(linha, "%[^\n]", f.codfilme);

        // Ler as outras propriedades do filme
        fgets(f.titulo, sizeof(f.titulo), input);
        fgets(f.ator_principal, sizeof(f.ator_principal), input);
        fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), input);
        fgets(f.ano, sizeof(f.ano), input);
        fgets(f.diretor, sizeof(f.diretor), input);
        fgets(f.genero, sizeof(f.genero), input);

        // Remover a quebra de linha no final de cada propriedade
        f.titulo[strcspn(f.titulo, "\n")] = '\0';
        f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
        f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
        f.ano[strcspn(f.ano, "\n")] = '\0';
        f.diretor[strcspn(f.diretor, "\n")] = '\0';
        f.genero[strcspn(f.genero, "\n")] = '\0';

        // Verificar se o filme pertence ao gênero desejado
        if (strcmp(f.genero, consulta.valor) == 0) {
            encontrou_filme = 1; // Marcando que pelo menos um filme foi encontrado
            printf("Título: %s\n", f.titulo);
            printf("Código do Filme: %s\n", f.codfilme);
            printf("Ator Principal: %s\n", f.ator_principal);
            printf("Ator Coadjuvante: %s\n", f.ator_coadjuvante);
            printf("Diretor: %s\n", f.diretor);
            printf("Ano: %s\n", f.ano);
            printf("Gênero: %s\n", f.genero);
            printf("\n");
        }
    }
    if (!encontrou_filme) {
        printf("Nenhum filme encontrado para o gênero especificado.\n");
    }

    fclose(input);
}

void listar_ano(char *caminho) {
    Consulta consulta;
    consulta.propriedade = ano;

	printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  Listagem de filmes por ano                                    \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    // Solicitar ao usuário o gênero desejado
    printf("Digite o ano que deseja buscar: ");
	limpar_buffer();
    fgets(consulta.valor, sizeof(consulta.valor), stdin);
    consulta.valor[strcspn(consulta.valor, "\n")] = '\0';

    printf("Buscando filmes do ano: %s\n\n", consulta.valor); // Mensagem de depuração

    FILE *input = fopen(caminho, "r");
    if (!input) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[1000];
    Filme f;
    int encontrou_filme = 0; // Variável para verificar se pelo menos um filme foi encontrado

    while (fgets(linha, sizeof(linha), input)) {
        if (strcmp(linha, "\n") == 0) {
            continue; // Ignorar linhas em branco
        }

        sscanf(linha, "%[^\n]", f.codfilme);

        // Ler as outras propriedades do filme
        fgets(f.titulo, sizeof(f.titulo), input);
        fgets(f.ator_principal, sizeof(f.ator_principal), input);
        fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), input);
        fgets(f.ano, sizeof(f.ano), input);
        fgets(f.diretor, sizeof(f.diretor), input);
        fgets(f.genero, sizeof(f.genero), input);

        // Remover a quebra de linha no final de cada propriedade
        f.titulo[strcspn(f.titulo, "\n")] = '\0';
        f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
        f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
        f.ano[strcspn(f.ano, "\n")] = '\0';
        f.diretor[strcspn(f.diretor, "\n")] = '\0';
        f.genero[strcspn(f.genero, "\n")] = '\0';

        // Verificar se o filme pertence ao gênero desejado
        if (strcmp(f.ano, consulta.valor) == 0) {
            encontrou_filme = 1; // Marcando que pelo menos um filme foi encontrado
            printf("Título: %s\n", f.titulo);
            printf("Código do Filme: %s\n", f.codfilme);
            printf("Ator Principal: %s\n", f.ator_principal);
            printf("Ator Coadjuvante: %s\n", f.ator_coadjuvante);
            printf("Diretor: %s\n", f.diretor);
            printf("Ano: %s\n", f.ano);
            printf("Gênero: %s\n", f.genero);
            printf("\n");
        }
    }
    if (!encontrou_filme) {
        printf("Nenhum filme encontrado para o ano especificado.\n");
    }

    fclose(input);
}

void listar_ator(char *caminho) {
    Consulta consulta;
    consulta.propriedade = ano;

	printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                                  Listagem de filmes por ator                                   \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    // Solicitar ao usuário o gênero desejado
    printf("Digite o ator que deseja buscar: ");
	limpar_buffer();
    fgets(consulta.valor, sizeof(consulta.valor), stdin);
    consulta.valor[strcspn(consulta.valor, "\n")] = '\0';

    printf("Buscando filmes com o ator: %s\n\n", consulta.valor); // Mensagem de depuração

    FILE *input = fopen(caminho, "r");
    if (!input) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[1000];
    Filme f;
    int encontrou_filme = 0; // Variável para verificar se pelo menos um filme foi encontrado

    while (fgets(linha, sizeof(linha), input)) {
        if (strcmp(linha, "\n") == 0) {
            continue; // Ignorar linhas em branco
        }

        sscanf(linha, "%[^\n]", f.codfilme);

        // Ler as outras propriedades do filme
        fgets(f.titulo, sizeof(f.titulo), input);
        fgets(f.ator_principal, sizeof(f.ator_principal), input);
        fgets(f.ator_coadjuvante, sizeof(f.ator_coadjuvante), input);
        fgets(f.ano, sizeof(f.ano), input);
        fgets(f.diretor, sizeof(f.diretor), input);
        fgets(f.genero, sizeof(f.genero), input);

        // Remover a quebra de linha no final de cada propriedade
        f.titulo[strcspn(f.titulo, "\n")] = '\0';
        f.ator_principal[strcspn(f.ator_principal, "\n")] = '\0';
        f.ator_coadjuvante[strcspn(f.ator_coadjuvante, "\n")] = '\0';
        f.ano[strcspn(f.ano, "\n")] = '\0';
        f.diretor[strcspn(f.diretor, "\n")] = '\0';
        f.genero[strcspn(f.genero, "\n")] = '\0';

        // Verificar se o filme pertence ao gênero desejado
        if (strcmp(f.ator_principal, consulta.valor) == 0 || strcmp(f.ator_coadjuvante, consulta.valor) == 0) {
            encontrou_filme = 1; // Marcando que pelo menos um filme foi encontrado
            printf("Título: %s\n", f.titulo);
            printf("Código do Filme: %s\n", f.codfilme);
            printf("Ator Principal: %s\n", f.ator_principal);
            printf("Ator Coadjuvante: %s\n", f.ator_coadjuvante);
            printf("Diretor: %s\n", f.diretor);
            printf("Ano: %s\n", f.ano);
            printf("Gênero: %s\n", f.genero);
            printf("\n");
        }
    }
    if (!encontrou_filme) {
        printf("Nenhum filme encontrado para com o ator especificado.\n");
    }

    fclose(input);
}

void listar_filme(char *caminho) {
	int escolha;
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("                                                  Listagem de filmes                                            \n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

	printf("Escolha sua opção: \n");
	printf("1 - Listar todos os filmes\n");
	printf("2 - Lista por gênero\n");
	printf("3 - Lista por ator principal\n");
	printf("4 - Listar por ano\n");
	printf("Voltar\n");
	printf("Sair\n");
	printf("Opção: ");
	scanf("%d", &escolha);

	switch (escolha)
	{
	case 1:
		listar_tudo(caminho);
		break;
	case 2:
		listar_genero(caminho);
		break;
	case 3:
		listar_ator(caminho);
		break;
	case 4:
		listar_ano(caminho);
		break;
	case 5:
		/* code */
		break;
	case 6:
		/* code */
		break;
	default:
		printf("Opção inválida.\n");
		return;
	}
}


/*
void listar_atorp(char *caminho) {
	
}

void criar_lista_filmes(struct consulta consulta, char *caminho) {
    struct lista_filme *lista = malloc(sizeof(struct lista_filme));
    if (!lista) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    lista->inicio = NULL;
    lista->consulta = consulta;

    FILE *input = fopen(caminho, "r");
    if (!input) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char linha[1000];
    Filme f;
    while (fgets(linha, sizeof(linha), input)) {
        if (lista->consulta.propriedades[codfilme] == codfilme) {

        }
    }
    fclose(input);
    return;
}
*/

/*
void alterar_filme(Filme *f, char *codfilme, char *novo_titulo, char *novo_ator_principal, char *novo_ator_coadjuvante, char *novo_diretor, int novo_ano, char *novo_genero) {

}*/
