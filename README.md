# Projeto: Fórmula E - Brincando com a Velocidade
Este projeto visa introduzir crianças ao mundo da Fórmula E por meio de jogos e brinquedos interativos, criando uma experiência divertida e educativa que atrai a atenção dos pequenos e estimula o interesse dos pais.

-> Objetivo:
- Atrair crianças para o mundo da Fórmula E através de uma experiência interativa e educativa.
- Estimular o interesse dos pais por meio de brinquedos e jogos temáticos relacionados à Fórmula E.

-> Público-alvo:
- Crianças de 5 a 10 anos.
- Pais e entusiastas da Fórmula E.

-> Conceito:
-> O projeto combina dois elementos:
- Brinquedos interativos: Brinquedos controlados por Arduino, que simulam carros de corrida da Fórmula E e interagem com o usuário.
- Jogos: Um jogo de corrida simples para Arduino, que simula uma corrida de Fórmula E e incentiva a interação do usuário.

-> Como funciona:
- O Arduino controla os brinquedos, permitindo que eles se movam, façam sons e emitam luzes.
- O jogo de corrida no Arduino oferece uma experiência divertida de corrida, permitindo que os jogadores controlem seus carros e evitem obstáculos.
- Os pais podem usar esses brinquedos e jogos para educar seus filhos sobre a Fórmula E, seus carros, pilotos e tecnologia.

-> Componentes:
- Arduino Uno
- Display LCD
- Botões
- Sensores (opcional)
- LEDs
- Buzzer
- Outros componentes para a construção dos brinquedos

-> Códigos:
- LED_F1.ino: Código para controlar os LEDs vermelhos e verdes, representando as luzes de partida da Fórmula E.
- JogoDesvio.ino: Código para o jogo de corrida simples no Arduino, onde o jogador precisa evitar obstáculos.

-> Requisitos:
- Ambiente de desenvolvimento Arduino
- Conhecimento básico de programação em C/C++
- Componentes eletrônicos mencionados acima

-> Instalação:
- Baixe os códigos LED_F1.ino e JogoDesvio.ino.
- Carregue os códigos no Arduino Uno.
- Conecte os componentes conforme o diagrama de ligação.
- Execute os programas.

-> Observações:
- Os códigos podem ser modificados e personalizados para criar novos jogos e funcionalidades.
- Este projeto é um exemplo inicial e pode ser expandido para incluir mais recursos, como:

-> Mais tipos de brinquedos
- Jogos mais complexos
- Integração com aplicativos móveis
- Monitoramento de dados em tempo real

-> Contribuições:
Este projeto é de código aberto e encorajamos contribuições para melhorá-lo.
Autoria:
- 556798 - Davi Vieira
- 555819 - Felipe Alamino
- 556906 - Luca Monteiro
- 555613 - Pedro Sampaio
- 558258 - Victor Mesquita

-> LED_F1.ino
Este código controla os LEDs vermelhos e verdes, simulando as luzes de partida da Fórmula E.
- Como funciona:
O código acende os LEDs vermelhos sequencialmente, simulando a contagem regressiva.
Após a contagem regressiva, os LEDs vermelhos são desligados e os LEDs verdes são acendidos, simulando a largada.
O buzzer emite um som diferente para cada etapa, indicando o início da corrida.

- Funcionalidades:
Contar regressivamente de 8 a 1 usando LEDs vermelhos.
Acender os LEDs verdes ao final da contagem regressiva.
Emitir sons diferentes para cada etapa com o buzzer.

- Instruções:
Conecte os LEDs vermelhos e verdes aos pinos especificados no código.
Conecte o buzzer ao pino A0.
Carregue o código no Arduino Uno.
Execute o código.

-> JogoDesvio.ino
Este código implementa um jogo de corrida simples para Arduino, onde o jogador precisa evitar obstáculos que descem pela tela.

- Como funciona:
O jogador controla um carro que se move para cima e para baixo na tela.
Os obstáculos descem pela tela em duas colunas.
Se o carro colidir com um obstáculo, o jogo termina.
O jogador pode controlar o carro usando dois botões.

- Funcionalidades:
Mover o carro para cima e para baixo.
Obstáculos que descem pela tela.
Detecção de colisão.
Tela de fim de jogo.

- Instruções:
Conecte os botões aos pinos especificados no código.
Conecte o display LCD aos pinos especificados no código.
Carregue o código no Arduino Uno.
Execute o código.

-> Observações:
O jogo é simples e pode ser personalizado para incluir mais recursos, como:
Pontuação
Níveis de dificuldade
Diferentes tipos de obstáculos
Gráficos mais elaborados
Este projeto serve como base para desenvolver jogos mais complexos e interativos com a Fórmula E.
