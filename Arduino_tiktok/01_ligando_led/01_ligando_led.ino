// Vídeo 1/10 — Ligando um LED com Arduino

const int PINO_LED = 11;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  digitalWrite(PINO_LED, HIGH); // Mantém o LED aceso
}

void loop() {
  // Nada precisa se repetir neste projeto.
}

