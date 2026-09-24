// Vídeo 3/10 — Dois LEDs piscando alternadamente

const int PINO_LED_VERMELHO = 11;
const int PINO_LED_VERDE = 10;

void setup() {
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_LED_VERDE, OUTPUT);
}

void loop() {
  digitalWrite(PINO_LED_VERMELHO, HIGH);
  digitalWrite(PINO_LED_VERDE, LOW);
  delay(500);

  digitalWrite(PINO_LED_VERMELHO, LOW);
  digitalWrite(PINO_LED_VERDE, HIGH);
  delay(500);
}

