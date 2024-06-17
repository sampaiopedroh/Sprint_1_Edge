#include <LiquidCrystal.h>

// Definição dos pinos
const int botaoCima = 2;
const int botaoBaixo = 3;

// Definir os pinos do display LCD (I2C)
const int rs = 11, en = 10, d4 = 8, d5 = 9, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Posição inicial do carro do jogador
int posicaoCarro = 1;

// Velocidade do jogo
int velocidade = 150; // Aumentado para oponentes mais lentos

// Posição dos carros inimigos
int posicaoInimigoCima = 16; // Linha de cima
int posicaoInimigoBaixo = 8;  // Linha de baixo

// Flag para indicar se o jogo está em andamento
bool jogoEmAndamento = true;

void setup() {
  // Configurar os pinos dos botões como entrada
  pinMode(botaoCima, INPUT_PULLUP);
  pinMode(botaoBaixo, INPUT_PULLUP);

  // Inicializar o display LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("JOGO DE DESVIO");
  lcd.setCursor(1, 1);
  lcd.print("PRESS ANY BTN");

  // Esperar o jogador iniciar o jogo
  while (digitalRead(botaoCima) == HIGH && digitalRead(botaoBaixo) == HIGH);
}

void loop() {
  // Verificar se o jogo está em andamento
  if (jogoEmAndamento) {
    // Atualizar a posição do carro do jogador
    if (digitalRead(botaoCima) == LOW && posicaoCarro > 1) {
      posicaoCarro--;
    } else if (digitalRead(botaoBaixo) == LOW && posicaoCarro < 4) {
      posicaoCarro++;
    }

    // Mover os carros inimigos
    if (posicaoInimigoCima > 0) { // Verifica se o oponente de cima está na tela
      posicaoInimigoCima--;
    } else {
      posicaoInimigoCima = 16; // Reinicia o oponente de cima se ele sair da tela
    }

    if (posicaoInimigoBaixo > 0) { // Verifica se o oponente de baixo está na tela
      posicaoInimigoBaixo--;
    } else {
      posicaoInimigoBaixo = 16; // Reinicia o oponente de baixo se ele sair da tela
    }

    // Verificar colisões (somente quando os oponentes chegam na coluna 0)
    if (posicaoInimigoCima == 0 && posicaoCarro == 1) {
      gameOver();
    } else if (posicaoInimigoBaixo == 0 && posicaoCarro == 1) {
      gameOver();
    }

    // Desenhar o jogo no display
    desenharJogo();

    // Aguardar antes de atualizar novamente
    delay(velocidade);
  }
}

void desenharJogo() {
  // Limpar o display
  lcd.clear();

  // Desenhar o carro do jogador
  lcd.setCursor(0, posicaoCarro - 1);
  lcd.print("V");

  // Desenhar os carros inimigos
  lcd.setCursor(posicaoInimigoCima, 0);
  lcd.print("O"); // Desenhar o oponente de cima
  lcd.setCursor(posicaoInimigoBaixo, 0); // Desenhar o oponente de baixo
  lcd.print("O");
}

void gameOver() {
  // Parar o jogo
  jogoEmAndamento = false;

  // Mostrar "Game Over" no display
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(1, 1);
  lcd.print("PRESS ANY BTN");

  // Esperar o jogador reiniciar
  while (digitalRead(botaoCima) == HIGH && digitalRead(botaoBaixo) == HIGH) {
    delay(100); // Aguardar 100ms para evitar reiniciar instantaneamente
  }

  // Reiniciar o jogo
  resetarJogo();
}

void resetarJogo() {
  // Reiniciar as variáveis do jogo
  posicaoCarro = 1;
  posicaoInimigoCima = 16;
  posicaoInimigoBaixo = 8;
  jogoEmAndamento = true;
}