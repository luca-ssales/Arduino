// Vídeo 5/10 — Um toque liga e o próximo toque desliga o LED

const int PINO_LED = 11;
const int PINO_BOTAO = 3;
const unsigned long TEMPO_DEBOUNCE = 50;

bool estadoLed = false;
int estadoEstavelBotao = HIGH;
int ultimaLeituraBotao = HIGH;
unsigned long instanteUltimaMudanca = 0;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
  digitalWrite(PINO_LED, LOW);
}

void loop() {
  int leituraAtual = digitalRead(PINO_BOTAO);

  if (leituraAtual != ultimaLeituraBotao) {
    instanteUltimaMudanca = millis();
  }

  if (millis() - instanteUltimaMudanca > TEMPO_DEBOUNCE) {
    if (leituraAtual != estadoEstavelBotao) {
      estadoEstavelBotao = leituraAtual;

      // Alterna apenas no instante em que o botão é pressionado.
      if (estadoEstavelBotao == LOW) {
        estadoLed = !estadoLed;
        digitalWrite(PINO_LED, estadoLed ? HIGH : LOW);
      }
    }
  }

  ultimaLeituraBotao = leituraAtual;
}

