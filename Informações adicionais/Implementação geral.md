# Informações técnicas

Esta seção é destinada a explicações mais detalhadas sobre cada um dos arquivos ```.c ``` construídos para a implementação do sistema de locadora e como cada um deles consegue se relacionar entre si. Para melhorar o entendimento e visualização desses relacionamentos, foram elaborados diagramas de banco de dados, apesar de nenhum tipo de banco de dados ter sido utilizado na elaboração deste projeto.
<p align="float">
<img src="imagens/modelo conceitual.png" width="400" /> 
<img src="imagens/modelo lógico.png" width="400" />
</p>

## Filme.c

Este arquivo foi destinado para incorporação das operações sobre o conjunto de dados dos filmes, disponíveis no arquivo Filme.h. Resumidamente, ele realiza operações de cadastro de filmes, remoção de um filme específico, pesquisa de filmes, listagem de filmes dividida em gênero, ano e ator. Todas as informações ficam salvas em um arquivo Filmes.txt e todas as pesquisas e remoções também acontecem de acordo com a manipulação nesse arquivo.

_Para uma explicação mais detalhada das funções, acesse_

## Cliente.c 

Arquivo destinado para incorporação das operações sobre os dados dos clientes da locadora, cujos protótipos estão disponíveis no arquivo Cliente.h. Realiza as operações de cadastro de clientes, remoção de clientes, pesquisa, listagem e alteração dos clientes. Todos os dados gerados por essas operações, como os dados de cadastro, alteração e remoção são feitos no arquivo Clientes.txt que armazenam os dados inseridos e permitem o salvamento desses dados para as funções de pesquisa e listagem.

_Para uma explicação mais detalhada das funções, acesse_

## Locacao.c

Arquivo destinado para a incorporação das operações sobre os dados das locações feitas no sistema, cujo protótipos estão disponíveis no arquivo Locacao.h. Com ele é possível realizar as operações de aluguel, devolução e reserva de filmes, bem como a exibição e pesquisa de locações e reservas e, ainda, a criação de um histórico para cada cliente. Nele também é feito o recebimento do pagamento das locações e o cálculo e aplicação de multas pros casos em que haja devolução de filmes com atraso. 

Os dados de todas essas operações também ficam salvos nos seguintes arquivos: Locacao.txt, Reservas.txt e Historico.txt.

_Para uma explicação mais detalhada das funções, acesse_
