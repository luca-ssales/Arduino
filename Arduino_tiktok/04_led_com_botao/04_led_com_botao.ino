// Vídeo 4/10 — Acendendo um LED com botão
// INPUT_PULLUP: pressionado = LOW; solto = HIGH.

const int PINO_LED = 11;
const int PINO_BOTAO = 3;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
}

void loop() {
  bool botaoPressionado = digitalRead(PINO_BOTAO) == LOW;

  if (botaoPressionado) {
    digitalWrite(PINO_LED, HIGH);
  } else {
    digitalWrite(PINO_LED, LOW);
  }
}

