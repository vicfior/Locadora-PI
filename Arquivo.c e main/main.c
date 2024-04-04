#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Filme.h"
#include "Pessoa.h"
#include "Locacao.h"

int main()
{   
    setlocale(LC_ALL, "pt_BR.UTF-8");
    //Criar menu geral e menu do cadastro
    /*MENU GERAL
    BEM VNDO À LOCADORA DE FILMES
    1 - ALUGAR
    2 - FILMES
    3 - CLIENTES
    4 - OPERAÇÕES
    6 - SAIR
    */

   /*MENU CADASTRO FILMES
   1 - CADASTRAR
   2 - REMOVER
   3 - ALTERAR
   4 - PESQUISAR
   5 - LISTAR
   6 - VOLTAR
   7 - SAIR 
   */

    /*MENU CADASTRO CLIENTES
    1 - CADASTRAR
    2 - REMOVER
    3 - ALTERAR
    4 - PESQUISAR
    5 - LISTAR
    6 - VOLTAR
    7 - SAIR 
    */

    /*MENU OPERAÇÕES - TODAS AS FUNÇÕES DE LOCAÇAÕ
    1 - ALUGAR FILME
    2 - DEVOLVER FILME
    3 - REMOVER FILME
    ...
    */

   //TESTE DE CHAMADA DE FUNÇÕES
    char caminho [20] = "Filmes.txt";
    cadastrar_filme(caminho);
    return 0;
}
