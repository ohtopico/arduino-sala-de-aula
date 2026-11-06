/*
  Semáforo com botão de pedestre e sinal sonoro
  ---------------------------------------------
  Semáforo de carros (vermelho, amarelo, verde) e de pedestres
  (vermelho, verde). Quando alguém aperta o botão, o semáforo dos carros
  fecha e o dos pedestres abre. Enquanto os pedestres podem atravessar,
  o buzzer bipa, como nos semáforos sonoros para pessoas cegas.

  Ligações (cada LED com resistor de 220 ohms em série, catodo no GND):
    LED vermelho dos carros  -> pino 12
    LED amarelo dos carros   -> pino 11
    LED verde dos carros     -> pino 10
    LED vermelho do pedestre -> pino 7
    LED verde do pedestre    -> pino 6
    Botão                    -> pino 2 e GND (usa o resistor interno, INPUT_PULLUP)
    Buzzer (+)               -> pino 8 (o outro terminal no GND)

  Autora: Júlia Roberta Quoos Alves (ohtopico.com.br)
  Licença: MIT
*/

const int CARRO_VERMELHO    = 12;
const int CARRO_AMARELO     = 11;
const int CARRO_VERDE       = 10;
const int PEDESTRE_VERMELHO = 7;
const int PEDESTRE_VERDE    = 6;
const int BOTAO             = 2;
const int BUZZER            = 8;

// Tempos em milissegundos (1000 ms = 1 segundo)
const unsigned long VERDE_MINIMO    = 5000;  // verde mínimo para os carros
const unsigned long TEMPO_AMARELO   = 2000;
const unsigned long TEMPO_TRAVESSIA = 6000;  // pedestre atravessando
const int PISCADAS_FINAIS           = 6;     // vermelho do pedestre piscando

bool pedidoDePedestre = false;
unsigned long inicioDoVerde = 0;

// Avisa o compilador que estas funções existem mais abaixo
void abrirParaCarros();
void travessiaDePedestres();

void setup() {
  pinMode(CARRO_VERMELHO, OUTPUT);
  pinMode(CARRO_AMARELO, OUTPUT);
  pinMode(CARRO_VERDE, OUTPUT);
  pinMode(PEDESTRE_VERMELHO, OUTPUT);
  pinMode(PEDESTRE_VERDE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);  // solto = HIGH, apertado = LOW
  Serial.begin(9600);

  abrirParaCarros();
}

// Acende só os LEDs que recebem HIGH
void luzes(int vermelho, int amarelo, int verde, int pedVermelho, int pedVerde) {
  digitalWrite(CARRO_VERMELHO, vermelho);
  digitalWrite(CARRO_AMARELO, amarelo);
  digitalWrite(CARRO_VERDE, verde);
  digitalWrite(PEDESTRE_VERMELHO, pedVermelho);
  digitalWrite(PEDESTRE_VERDE, pedVerde);
}

void abrirParaCarros() {
  luzes(LOW, LOW, HIGH, HIGH, LOW);
  inicioDoVerde = millis();
  pedidoDePedestre = false;
  Serial.println("Carros: VERDE | Pedestres: VERMELHO");
}

void travessiaDePedestres() {
  // 1) Amarelo para os carros
  luzes(LOW, HIGH, LOW, HIGH, LOW);
  Serial.println("Carros: AMARELO");
  delay(TEMPO_AMARELO);

  // 2) Vermelho para os carros, verde para os pedestres, com bipes
  luzes(HIGH, LOW, LOW, LOW, HIGH);
  Serial.println("Carros: VERMELHO | Pedestres: VERDE (bipando)");
  unsigned long inicio = millis();
  while (millis() - inicio < TEMPO_TRAVESSIA) {
    tone(BUZZER, 880, 100);   // bipe curto
    delay(500);               // ritmo lento: pode atravessar
  }

  // 3) Vermelho do pedestre piscando com bipes rápidos: termine a travessia
  digitalWrite(PEDESTRE_VERDE, LOW);
  Serial.println("Pedestres: VERMELHO PISCANDO");
  for (int i = 0; i < PISCADAS_FINAIS; i++) {
    digitalWrite(PEDESTRE_VERMELHO, HIGH);
    tone(BUZZER, 1200, 80);
    delay(250);
    digitalWrite(PEDESTRE_VERMELHO, LOW);
    delay(250);
  }
  noTone(BUZZER);

  abrirParaCarros();
}

void loop() {
  // Guarda o pedido assim que o botão é apertado, mesmo que o carro
  // ainda não tenha cumprido o verde mínimo.
  if (digitalRead(BOTAO) == LOW && !pedidoDePedestre) {
    pedidoDePedestre = true;
    Serial.println("Botao apertado: pedido de travessia registrado");
  }

  // Só fecha para os carros depois do verde mínimo
  if (pedidoDePedestre && millis() - inicioDoVerde >= VERDE_MINIMO) {
    travessiaDePedestres();
  }
}
