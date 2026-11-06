/*
  Estação meteorológica (versão Tinkercad)
  ----------------------------------------
  Mede temperatura (sensor TMP36) e luminosidade (LDR) e mostra no LCD
  16x2. Guarda a mínima e a máxima do dia e acende um LED quando faz
  calor demais. Também envia os dados pelo Serial no formato do
  Plotter Serial, para desenhar gráficos.

  Ligações:
    TMP36: pino esquerdo (lado reto virado para você) -> 5V,
           pino do meio -> A0, pino direito -> GND
    LDR:   um terminal no 5V, outro terminal no A1
           e também num resistor de 10 kohms que vai ao GND (divisor de tensão)
    LED de alerta (+) -> resistor 220 ohms -> pino 9 (o outro no GND)
    LCD 16x2: RS -> 12, E -> 11, D4 -> 5, D5 -> 4, D6 -> 3, D7 -> 2,
              RW -> GND, VSS -> GND, VDD -> 5V,
              V0 -> pino do meio de um potenciômetro de 10 kohms (contraste),
              A (luz de fundo) -> resistor 220 ohms -> 5V, K -> GND

  Autora: Júlia Roberta Quoos Alves (ohtopico.com.br)
  Licença: MIT
*/

#include <LiquidCrystal.h>

const int PINO_TEMPERATURA = A0;
const int PINO_LUZ         = A1;
const int PINO_ALERTA      = 9;

const float LIMITE_CALOR = 30.0;   // graus Celsius. Mude em aula!

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float minima = 1000;
float maxima = -1000;
unsigned long ultimaTroca = 0;
bool mostrarExtremos = false;

void setup() {
  pinMode(PINO_ALERTA, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Estacao");
  lcd.setCursor(0, 1);
  lcd.print("meteorologica");
  delay(1500);
  lcd.clear();
}

// TMP36: 0,5 V a 0 °C e +10 mV (0,01 V) a cada grau
float lerTemperatura() {
  int leitura = analogRead(PINO_TEMPERATURA);   // 0 a 1023
  float tensao = leitura * 5.0 / 1023.0;         // 0 a 5 V
  return (tensao - 0.5) * 100.0;
}

// Converte a leitura do LDR em porcentagem (0 = escuro, 100 = muito claro)
int lerLuminosidade() {
  int leitura = analogRead(PINO_LUZ);
  return map(leitura, 0, 1023, 0, 100);
}

String descreverLuz(int porcentagem) {
  if (porcentagem < 20) return "Escuro";
  if (porcentagem < 60) return "Nublado";
  return "Ensolarado";
}

void loop() {
  float temperatura = lerTemperatura();
  int luz = lerLuminosidade();

  if (temperatura < minima) minima = temperatura;
  if (temperatura > maxima) maxima = temperatura;

  digitalWrite(PINO_ALERTA, temperatura >= LIMITE_CALOR ? HIGH : LOW);

  // A cada 4 segundos alterna entre a tela atual e a de mínima/máxima
  if (millis() - ultimaTroca > 4000) {
    mostrarExtremos = !mostrarExtremos;
    ultimaTroca = millis();
    lcd.clear();
  }

  lcd.setCursor(0, 0);
  if (mostrarExtremos) {
    lcd.print("Min ");
    lcd.print(minima, 1);
    lcd.print((char)223);  // símbolo de grau no LCD
    lcd.print("C   ");
    lcd.setCursor(0, 1);
    lcd.print("Max ");
    lcd.print(maxima, 1);
    lcd.print((char)223);
    lcd.print("C   ");
  } else {
    lcd.print("Temp ");
    lcd.print(temperatura, 1);
    lcd.print((char)223);
    lcd.print("C   ");
    lcd.setCursor(0, 1);
    lcd.print(descreverLuz(luz));
    lcd.print(" ");
    lcd.print(luz);
    lcd.print("%     ");
  }

  // Formato do Plotter Serial: nome:valor separados por vírgula
  Serial.print("Temperatura:");
  Serial.print(temperatura);
  Serial.print(",Luz:");
  Serial.println(luz);

  delay(500);
}
