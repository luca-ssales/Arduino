// Vídeo 7/10 — Semáforo de pedestres com botão
// Estado normal: carros seguem e pedestres aguardam.

const int CARRO_VERMELHO = 13;
const int CARRO_AMARELO = 12;
const int CARRO_VERDE = 11;
const int PEDESTRE_VERMELHO = 10;
const int PEDESTRE_VERDE = 9;
const int PINO_BOTAO = 2;

void estadoNormal() {
  digitalWrite(CARRO_VERMELHO, LOW);
  digitalWrite(CARRO_AMARELO, LOW);
  digitalWrite(CARRO_VERDE, HIGH);
  digitalWrite(PEDESTRE_VERMELHO, HIGH);
  digitalWrite(PEDESTRE_VERDE, LOW);
}

void executarTravessia() {
  // Carros recebem o amarelo antes de parar.
  digitalWrite(CARRO_VERDE, LOW);
  digitalWrite(CARRO_AMARELO, HIGH);
  delay(2000);

  // Carros param.
  digitalWrite(CARRO_AMARELO, LOW);
  digitalWrite(CARRO_VERMELHO, HIGH);
  delay(1000);

  // Pedestres atravessam.
  digitalWrite(PEDESTRE_VERMELHO, LOW);
  digitalWrite(PEDESTRE_VERDE, HIGH);
  delay(5000);

  // O verde dos pedestres pisca antes de fechar.
  for (int i = 0; i < 3; i++) {
    digitalWrite(PEDESTRE_VERDE, LOW);
    delay(300);
    digitalWrite(PEDESTRE_VERDE, HIGH);
    delay(300);
  }

  digitalWrite(PEDESTRE_VERDE, LOW);
  digitalWrite(PEDESTRE_VERMELHO, HIGH);
  delay(1000);

  estadoNormal();
}

void setup() {
  pinMode(CARRO_VERMELHO, OUTPUT);
  pinMode(CARRO_AMARELO, OUTPUT);
  pinMode(CARRO_VERDE, OUTPUT);
  pinMode(PEDESTRE_VERMELHO, OUTPUT);
  pinMode(PEDESTRE_VERDE, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);

  estadoNormal();
}

void loop() {
  if (digitalRead(PINO_BOTAO) == LOW) {
    delay(30); // Debounce simples

    if (digitalRead(PINO_BOTAO) == LOW) {
      // Aguarda o jogador soltar para não repetir a solicitação.
      while (digitalRead(PINO_BOTAO) == LOW) {
        delay(5);
      }

      executarTravessia();
    }
  }
}

