# Arquivo Filme.c

Na tabela abaixo há uma breve descrição de cada função presente nos arquivos Filme.c e Filme.h

| Função | Tipo | Descrição |
|---|---|---|
|struct filme | struct | Define os tipos de dados personalizados usados para representar as informações dos filmes | 
|struct lista_filme | struct | Define uma lista encadeada de filmes, onde o campo inicio aponta pro primeiro filme da lista e o fim aponta para o último |
|limpar_buffer() | void | Utilizada para descartar qualquer entrada de teclado pendente até que uma quebra de linha seja encontrada |
|*lista_cria_filme() | Lista_filme | Representa uma lista encadeada de filmes, onde os ponteiros inicio e fim são inicializados como nulos inidicando que a lista está vazia no momento. Cria uma nova lista de filmes vazia. |
|*filme_cria() | Filme | Cria um novo nó para representar um filme na lista encadeada. Aloca memória pro novo nó de filme e define o ponteiro pro próximo nó como nulo representando o final da lista. |
|filme_libera(Filme *filme) | void | Libera a memória alocada para o nó do filme. Possui um ponteiro filme do tipo Filme como parâmetro |
|filme_cadastra(Lista_filme *listaf) | void | Utilizada para inserir os dados do novo filme. A função recebe os dados via terminal, pelo usuário, e armazena-os em uma lista encadeada e também em um arquivo do tipo texto chamado "Filmes.txt". Recebe como parâmetro um ponteiro chamado listaf do tipo Lista_filme|
|remover_filme(Lista_filme *listaf) | void | Utilizada para remover qualquer filme do arquivo com base no código do filme, inserido pelo usuário via terminal. É criado um arquivo temporário do tipo texto para copiar todos os filmes e seus dados menos o do código solicitado. Após isso, esse arquivo é renomeado como "Filmes.txt" e o "Filmes.txt" original é removido em seguida| 
|pesquisar_filme(Lista_filme *listaf) | void | Utilizada para pesquisar qualquer filme no arquivo com base no seu código. Tem como parâmetro um ponteiro listaf do tipo Lista_filme e retorna todos os dados do filme pesquisado.|
|listar_filme() | void | Utilizada para listar os filmes. A função dá a opção do usuário escolher se quer listar todos os filmes cadastrados no sistema ou se quer listar filtrando o gênero, o ano de lançamento ou o ator.| 

> [!NOTE]
> Para a implementação desse sistema de cadastro e gerenciamento dos filmes da locadora, foi utilizada lista encadeada e o armazenamento das informações em um arquivo do tipo texto para poder salvar definitivamente os dados dos filmes. Foi utilizado um arquivo.txt unicamente para melhor visualização das informações guardadas no momento da elaboração deste projeto, visto que era necessário conferir repetidamente se as operações no arquivo estavam sendo feitas corretamente. É aconselhável o uso de arquivos do tipo binário para realizar este armazenamento uma vez que são muitas informações e arquivos do tipo binário possuem maior eficiência.
