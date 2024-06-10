# Informações técnicas

Esta seção é destinada a explicações mais detalhadas sobre cada um dos arquivos ```.c ``` construídos para a implementação do sistema de locadora e como cada um deles consegue se relacionar entre si. Para melhorar o entendimento e visualização desses relacionamentos, foram elaborados diagramas de banco de dados, apesar de nenhum tipo de banco de dados ter sido utilizado na elaboração deste projeto.

<p align="center">
<img src="/imagens/modelo conceitual.png" width="400" /> 
<img src="/imagens/modelo lógico.png" width="400" />
</p>

## Filme.c

Este arquivo foi destinado para incorporação das operações sobre o conjunto de dados dos filmes, disponíveis no arquivo Filme.h. Resumidamente, ele realiza operações de cadastro de filmes, remoção de um filme específico, pesquisa de filmes, listagem de filmes dividida em gênero, ano e ator. Todas as informações ficam salvas em um arquivo Filmes.txt e todas as pesquisas e remoções também acontecem de acordo com a manipulação nesse arquivo.

_Para uma explicação mais detalhada das funções, acesse_ [Implementação de Filme.c](https://github.com/vicfior/Locadora-PI/blob/57b572569d1b0e6776813fc150d1939f3a535d1d/Informa%C3%A7%C3%B5es%20adicionais/Implementa%C3%A7%C3%A3o%20Filme.md)

## Cliente.c 

Arquivo destinado para incorporação das operações sobre os dados dos clientes da locadora, cujos protótipos estão disponíveis no arquivo Cliente.h. Realiza as operações de cadastro de clientes, remoção de clientes, pesquisa, listagem e alteração dos clientes. Todos os dados gerados por essas operações, como os dados de cadastro, alteração e remoção são feitos no arquivo Clientes.txt que armazenam os dados inseridos e permitem o salvamento desses dados para as funções de pesquisa e listagem.

_Para uma explicação mais detalhada das funções, acesse_ [Implementação de Cliente.c](https://github.com/vicfior/Locadora-PI/blob/a82a4c47c34afc67e7b751dc3fcb7315021070f2/Informa%C3%A7%C3%B5es%20adicionais/Implementa%C3%A7%C3%A3o%20Cliente.md)

## Locacao.c

Arquivo destinado para a incorporação das operações sobre os dados das locações feitas no sistema, cujo protótipos estão disponíveis no arquivo Locacao.h. Com ele é possível realizar as operações de aluguel, devolução e reserva de filmes, bem como a exibição e pesquisa de locações e reservas e, ainda, a criação de um histórico para cada cliente. Nele também é feito o recebimento do pagamento das locações e o cálculo e aplicação de multas pros casos em que haja devolução de filmes com atraso. 

Os dados de todas essas operações também ficam salvos nos seguintes arquivos: Locacao.txt, Reservas.txt e Historico.txt.

_Para uma explicação mais detalhada das funções, acesse_ [Implementação de Locacao.c](https://github.com/vicfior/Locadora-PI/blob/a82a4c47c34afc67e7b751dc3fcb7315021070f2/Informa%C3%A7%C3%B5es%20adicionais/Implementa%C3%A7%C3%A3o%20Locacao.md)

# Menu

O Menu foi implementado utilizando as bibliotecas ```conio.h``` e ```windows.h``` que possibilitaram a criação de um menu interativo por meio do teclado, evitando a necessidade de o usuário digitar uma opção de escolha. No entanto, não foi feito uma opção de menu interativo para sistemas Unix, de forma que ele apenas funciona em sistemas operacionais Windows. De forma alternativa, em primeira opção foi criado um menu mais simples que funciona em qualquer sistema operacional. 

_Para uma explicação mais detalhada das funções, acesse_ 
