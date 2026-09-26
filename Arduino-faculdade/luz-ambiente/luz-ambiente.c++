#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int pinoLDR = A0;
const int pinoLED = 6;
const int limiarLuz = 500;

int estadoAnterior = -1;

void setup() {
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setBacklight(1); 
  lcd.clear();
}

void loop() {
  int leitura = analogRead(pinoLDR);
  Serial.print("Leitura LDR: ");
  Serial.println(leitura);

  if (leitura < limiarLuz) {
    digitalWrite(pinoLED, HIGH);

    if (estadoAnterior != 1) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Boa noite");
      estadoAnterior = 1;
    }
  } 
  else {
    digitalWrite(pinoLED, LOW);

    if (estadoAnterior != 0) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Bom dia");
      estadoAnterior = 0;
    }
  }

  delay(100);
}