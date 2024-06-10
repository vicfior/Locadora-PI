# Arquivo Cliente.c

Na tabela abaixo há uma breve descrição de cada função presente nos arquivos Cliente.c e Cliente.h

| Função | Tipo | Descrição |
|---|---|---|
|struct cliente | struct | Define os tipos de dados personalizados usados para representar as informações dos clientes. |
|struct lista | struct |Define uma lista encadeada de clientes, onde o campo início aponta pro primeiro cliente da lista e o fim aponta para o último cliente.|
|limpar_buffer()|void | Utilizada para descartar qualquer entrada de teclado pendente até que uma quebra de linha seja encontrada |
|*lista_cria() | Lista | Representa uma lista encadeada de clientes, onde os ponteiros início e fim são inicializados como nulos, indicando que a lista está vazia no momento. Cria uma nova lista de clientes vazia.|
|*cliente_cria()|Cliente|Cria um novo nó para representar um cliente na lista encadeada. Aloca memória pro novo nó de cliente e define o ponteiro pro próximo nó como nulo, representando o final da lista.|
|liberar_cliente(Cliente *cliente) | void | Libera a memória alocada para o nó de clientes. Possui um ponteiro cliente do tipo Cliente como parâmetro.|
|cadastrar_cliente(Lista *lista) | int |Utilizada para inserir os dados do novo cliente. A função recebe os dados via terminal, pelo usuário, e armazena-os em uma lista encadeada e os salva em um arquivo "Clientes.txt". Recebe como parâmetro um ponteiro chamado lista do tipo Lista. A função é do tipo inteiro e retorna 1 quando executada com sucesso pois sua lógica é utilizada novamente na implementação de Locacao.c. |
|listar_clientes(Lista *lista) | void |Utilizada para listar todos os clientes. A função abre o arquivo no modo leitura, percorre todo o arquivo e imprime os clientes cadastrados. |
|remover_cliente(Lista *lista) | void | Utilizada para remover qualquer cliente do arquivo com base no código do cliente, inserido via terminal. É criado um arquivo temporário do tipo texto para copiar todos os clientes e sesu dados, menos o do código solicitado. Após isso esse arquivo é renomeado para "Clientes.txt" e o "Clientes.txt" original é removido em seguida.|
|pesquisar_cliente(Lista *lista)| void | Utilizada para pesquisar qualquer cliente no arquivo com base no seu código. Tem como parâmetro um ponteiro lista do tipo Lista e mostra todos os dados do cliente pesquisado.|
|alterar_cliente(const char *codigo_cliente)| void | Função que altera uma informação específica do cliente. A função solicita que o usuário escolha entre Nome, Telefone, Endereço ou Data de nascimento para alterar a informação. Ela grava os dados atualizados no arquivo temporário "Cliente_temp.txt" e a função grava os dados do arquivo anterior e após esse procedimento, renomeia o arquivo "Clientes_temp.txt" para "Clientes.txt" e remove o "Clientes.txt" no final. |

> [!NOTE]
> Para a implementação desse sistema de cadastro e gerenciamento dos clientes da locadora, foi utilizada lista encadeada e o armazenamento das informações em um arquivo do tipo texto para poder salvar definitivamente os dados dos filmes. Foi utilizado um arquivo.txt unicamente para melhor visualização das informações guardadas no momento da elaboração deste projeto, visto que era necessário conferir repetidamente se as operações no arquivo estavam sendo feitas corretamente. É aconselhável o uso de arquivos do tipo binário para realizar este armazenamento uma vez que são muitas informações e arquivos do tipo binário possuem maior eficiência.
