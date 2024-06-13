# Arquivo Terminal.c

Na tabela abaixo há uma breve descrição de cada função presente nos arquivos Terminal.c e Terminal.h:

| Função | Tipo | Descrição |
|---|---|---|
|term_cls() | void | Utilizada para limpar a tela do console preenchendo-a com espaços em branco e redefinindo a posição do cursor.|
|sair_do_Sistema() | void |Utilizada para sair do sistema após chamar a função term_cls().|
|numeroDeOpcoes(int telaAtual)|int | Função que mapeia o valor das telas para o número correspondente de opções. Retorna o número de opções com base no valor de entrada da telaAtual.|
|exibirMenuPrincipal(int opcaoSelecionada)| void  | Mostra o menu principal na tela do terminal. Após limpar a tela, o código itera sobre as opções do menu e imprime cada uma delas.|
|exibirMenuFilmes(int opcaoSelecionada)|void| Mostra o menu dos filmes na tela do terminal. Após limpar a tela, o código itera sobre as opções do menu e imprime cada uma delas.|
|exibirMenuClientes(int opcaoSelecionada) |void | Mostra o menu dos clientes na tela do terminal. Após limpar a tela, o código itera sobre as opções do menu e imprime cada uma delas. |
|exibirMenuLocacao(int opcaoSelecionada) |void | Mostra o menu das locações na tela do terminal. Após limpar a tela, o código itera sobre as opções do menu e imprime cada uma delas. |

No arquivo Terminal.h há algumas macros para definir cores para o enfeite das telas, além de códigos para representar as setas de comando e o número de cada tela do menu. 
