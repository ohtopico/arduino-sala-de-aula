/*
  Estação meteorológica (versão kit físico, com DHT11)
  ----------------------------------------------------
  O Tinkercad não tem o sensor DHT11, por isso a versão de simulação usa
  o TMP36. Na bancada, o DHT11 (ou DHT22) mede temperatura E umidade
  do ar com um só componente.

  Biblioteca necessária: "DHT sensor library" (Adafruit), instalada pelo
  Gerenciador de Bibliotecas da IDE do Arduino. Ela pede também a
  "Adafruit Unified Sensor"; aceite instalar as duas.

  Ligações:
    DHT11: VCC -> 5V, GND -> GND, DATA -> pino 7
           (o módulo de 3 pinos já tem resistor; o sensor solto de 4 pinos
            precisa de um resistor de 10 kohms entre DATA e 5V)
    LDR, LED de alerta e LCD 16x2: iguais à versão Tinkercad.

  Autora: Júlia Roberta Quoos Alves (ohtopico.com.br)
  Licença: MIT
*/

#include <LiquidCrystal.h>
#include <DHT.h>

const int PINO_DHT    = 7;
const int PINO_LUZ    = A1;
const int PINO_ALERTA = 9;

const float LIMITE_CALOR = 30.0;

DHT dht(PINO_DHT, DHT11);   // troque DHT11 por DHT22 se for o seu sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(PINO_ALERTA, OUTPUT);
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);
  lcd.print("Estacao DHT11");
  delay(1500);
  lcd.clear();
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int luz = map(analogRead(PINO_LUZ), 0, 1023, 0, 100);

  if (isnan(temperatura) || isnan(umidade)) {
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor  ");
    lcd.setCursor(0, 1);
    lcd.print("Confira os fios ");
    delay(2000);
    return;
  }

  // Sensação térmica (índice de calor), calculada pela biblioteca
  float sensacao = dht.computeHeatIndex(temperatura, umidade, false);

  digitalWrite(PINO_ALERTA, temperatura >= LIMITE_CALOR ? HIGH : LOW);

  lcd.setCursor(0, 0);
  lcd.print("T ");
  lcd.print(temperatura, 1);
  lcd.print((char)223);
  lcd.print("C U ");
  lcd.print(umidade, 0);
  lcd.print("%  ");
  lcd.setCursor(0, 1);
  lcd.print("ST ");   // ST = sensação térmica
  lcd.print(sensacao, 1);
  lcd.print((char)223);
  lcd.print("C L");
  lcd.print(luz);
  lcd.print("% ");

  Serial.print("Temperatura:");
  Serial.print(temperatura);
  Serial.print(",Umidade:");
  Serial.print(umidade);
  Serial.print(",Sensacao:");
  Serial.print(sensacao);
  Serial.print(",Luz:");
  Serial.println(luz);

  delay(2000);  // o DHT11 só aceita uma leitura a cada ~1 s
}
