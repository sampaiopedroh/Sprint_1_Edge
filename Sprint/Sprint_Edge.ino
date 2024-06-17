#include <LiquidCrystal.h>

// Definições de pinos
const int ledVermelhos[] = {6, 5, 4, 3, 2, 1, 0, 14}; // Pinos para os LEDs vermelhos
const int ledVerdes[] = {15, 16, 17, 18, 19, 20, 21};  // Pinos para os LEDs verdes
const int botao = 13;  // Pino para o botão
const int buzzer = A0; // Pino para o buzzer

// Definições do display LCD
#define LCD_RS 12  // Pino RS do display LCD
#define LCD_EN 11  // Pino EN do display LCD
#define LCD_D4 10   // Pino D4 do display LCD
#define LCD_D5 9   // Pino D5 do display LCD
#define LCD_D6 8   // Pino D6 do display LCD
#define LCD_D7 7   // Pino D7 do display LCD

// Variáveis
int tempoEspera = 1000; // Tempo em milissegundos para cada led vermelho acender
float tempoAleatorio; // Tempo aleatório para a largada
long tempoInicial;
long tempoFinal;

// Cria o objeto LiquidCrystal
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  // Inicializa os pinos dos LEDs
  for (int i = 0; i < 8; i++) {
    pinMode(ledVermelhos[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(ledVerdes[i], OUTPUT);
  }
  // Inicializa o botão e o buzzer
  pinMode(botao, INPUT_PULLUP); // Utilize pull-up para o botão
  pinMode(buzzer, OUTPUT);

  // Inicializa o display LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Espere...");

  // Semente para o gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  // Animação dos LEDs vermelhos
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledVermelhos[i], HIGH);
    tone(buzzer, 1000); // Toque o buzzer
    delay(tempoEspera);
    //digitalWrite(ledVermelhos[i], LOW);
    noTone(buzzer);
    delay(tempoEspera);
  }

  // Tempo aleatório para a largada
  tempoAleatorio = random(1000, 2000); // Tempo entre 1 e 2 segundos
  delay(tempoAleatorio);

  // Largada!
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledVermelhos[i], LOW);
  }
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledVerdes[i], HIGH);
  }
  tone(buzzer, 500); // Toque o buzzer na frequência mais alta
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vai vai vai!!!");
  tempoInicial = millis(); // Marca o tempo inicial
  while (digitalRead(botao) == HIGH) { // Aguarda o botão ser pressionado
    delay(1);
  }
  tempoFinal = millis(); // Marca o tempo final
  noTone(buzzer); // Para o som do buzzer
  delay(500);

  // Mostra o tempo de reação
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tu demorou:");
  lcd.setCursor(0, 1);
  lcd.print((tempoFinal - tempoInicial) / 1000.0);
  lcd.print(" seg");

  delay(2000); // Aguarda 2 segundos antes de reiniciar o loop

  // Reinicia o jogo
  while (digitalRead(botao) == HIGH) { // Aguarda o botão ser pressionado
    delay(1);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Espere...");
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledVerdes[i], LOW);
  }
}