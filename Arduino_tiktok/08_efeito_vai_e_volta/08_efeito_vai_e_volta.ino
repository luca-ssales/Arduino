// Vídeo 8/10 — Efeito de luz sequencial com cinco LEDs

const int QUANTIDADE_LEDS = 5;
const int leds[QUANTIDADE_LEDS] = {13, 12, 11, 10, 9};
const int TEMPO_PASSO = 120;

void acenderPorUmInstante(int indice) {
  digitalWrite(leds[indice], HIGH);
  delay(TEMPO_PASSO);
  digitalWrite(leds[indice], LOW);
}

void setup() {
  for (int i = 0; i < QUANTIDADE_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  // Vai da esquerda para a direita.
  for (int i = 0; i < QUANTIDADE_LEDS; i++) {
    acenderPorUmInstante(i);
  }

  // Volta sem repetir imediatamente os LEDs das pontas.
  for (int i = QUANTIDADE_LEDS - 2; i > 0; i--) {
    acenderPorUmInstante(i);
  }
}

