# Menu Interativo

O menu interativo foi feito utilizando as bibliotecas ```conio.h``` e ```windows.h```. Todas as cores do menu, os caracteres em negrito, sublinhados e emojis foram feitos utilizando macros com códigos de cores ANSI, que controlam a aparência do texto no terminal (_para mais informações técnicas sobre como o menu foi implementado, acesse [Implementação Terminal](https://github.com/vicfior/Locadora-PI/blob/961d17042fc51e572774ae5ff0384872ed7401a1/Informa%C3%A7%C3%B5es%20adicionais/Implementa%C3%A7%C3%A3o%20Terminal.md)_). A organização do menu interativo foi feita por meio de telas conforme figura abaixo: 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/d676b05bf2acdb8c8bce1393dcc4724feb24e123/imagens/Diagrama%20das%20telas.png" alt="Diagrama das telas" width="400">
</p>

### Tela Inicial
A tela inicial consiste em uma arte com o nome da locadora "The Eras Filmes", ela espera que o usuário aperte qualquer tecla para continuar para a próxima tela, e dá uma pausa de 1000 ms até avançar para a tela de menu principal. 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/38e524680e3809d75866ce66021a648cf3472e2d/imagens/capa-menu.png" alt="Tela Inicial" width="400">
</p>

### Tela Menu Principal
Esta tela constitui o menu principal no qual o usuário vai escolher se quer avançar para o menu de filmes, de clientes ou do sistema de locação. Ele pode fazer essa escolha por meio do teclado conforme direcionamento na tela. 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/38e524680e3809d75866ce66021a648cf3472e2d/imagens/menu-inicial.png" alt="Diagrama das telas" width="400">
</p>

### Tela Menu dos Filmes
O menu dos filmes permite ao usuário escolher entre 4 opções de gerenciamento dos filmes, além de voltar ao menu principal ou sair do sistema e também permite ao usuário fazer essa escolha utilizando o teclado. 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/38e524680e3809d75866ce66021a648cf3472e2d/imagens/menu-filmes.png" alt="Diagrama das telas" width="400">
</p>

### Tela Menu dos Clientes
No menu dos clientes o usuário pode escolher entre 5 opções de gerenciamento dos clientes e também pode voltar ao menu principal ou sair do sistema, também por meio do teclado.

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/38e524680e3809d75866ce66021a648cf3472e2d/imagens/menu-clientes.png" alt="Diagrama das telas" width="400">
</p>

### Tela Menu de Locação
O menu de locação é o que oferece maior número de opções ao usuário, uma vez que é o sistema de gerenciamento da locadora propriamente dito. Nele é possível alugar filmes, fazer devolução, aplicar multas, reservar filmes e etc, além de voltar ao menu principal e sair do sistema. 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/38e524680e3809d75866ce66021a648cf3472e2d/imagens/menu-locacao.png" alt="Diagrama das telas" width="400">
</p>

# Menu básico

Em primeira opção foi feito um menu mais básico não só para testar as funções mas também para dar uma possibilidade de utilização do código em outros sistemas além do Windows. Este menu necessita que o usuário insira suas escolhas conforme as opções disponíveis no terminal, porém não afeta em nada a usabilidade do sistema ou até mesmo a beleza da interface. Além disso, é um menu menos complexo, podendo ser replicado facilmente por iniciantes. 

<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/72876371ddaba4a0e7fc7bb124af89c6adb97902/imagens/menu%20inicial%20b%C3%A1sico.png" alt="Menu básico" width="500">
</p>
<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/72876371ddaba4a0e7fc7bb124af89c6adb97902/imagens/Menu%20filmes%20b%C3%A1sico.png" alt="Menu de filmes" width="500">
</p>
<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/72876371ddaba4a0e7fc7bb124af89c6adb97902/imagens/Menu%20clientes%20b%C3%A1sico.png" alt="Menu de clientes" width="500">
</p>
<p align="center">
<img src="https://github.com/vicfior/Locadora-PI/blob/72876371ddaba4a0e7fc7bb124af89c6adb97902/imagens/menu%20loca%C3%A7%C3%A3o%20b%C3%A1sico.png" alt="Menu de clientes" width="500">
</p>
