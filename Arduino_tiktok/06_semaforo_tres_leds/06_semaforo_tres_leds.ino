// Vídeo 6/10 — Semáforo com três LEDs

const int LED_VERMELHO = 11;
const int LED_AMARELO = 10;
const int LED_VERDE = 9;

void apagarTodos() {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  apagarTodos();
}

void loop() {
  // Pare.
  apagarTodos();
  digitalWrite(LED_VERMELHO, HIGH);
  delay(5000);

  // Siga.
  apagarTodos();
  digitalWrite(LED_VERDE, HIGH);
  delay(5000);

  // Atenção.
  apagarTodos();
  digitalWrite(LED_AMARELO, HIGH);
  delay(2000);
}

