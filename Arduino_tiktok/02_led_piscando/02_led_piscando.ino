// Vídeo 2/10 — Fazendo o LED piscar

const int PINO_LED = 11;

void setup() {
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  digitalWrite(PINO_LED, HIGH); // Acende
  delay(500);

  digitalWrite(PINO_LED, LOW);  // Apaga
  delay(500);
}

