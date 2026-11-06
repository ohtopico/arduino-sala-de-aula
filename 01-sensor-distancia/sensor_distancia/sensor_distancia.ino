/*
  Sensor de distância com aviso sonoro
  ------------------------------------
  Um sensor ultrassônico (HC-SR04) mede a distância até o objeto mais
  próximo. Quanto mais perto o objeto, mais rápido o buzzer apita,
  como o sensor de ré de um carro. O LED acende quando há perigo.

  Ligações:
    HC-SR04 VCC  -> 5V
    HC-SR04 GND  -> GND
    HC-SR04 TRIG -> pino 9
    HC-SR04 ECHO -> pino 10
    Buzzer (+)   -> pino 8   (o outro terminal no GND)
    LED (+)      -> resistor 220 ohms -> pino 13 (o outro terminal no GND)

  Autora: Júlia Roberta Quoos Alves (ohtopico.com.br)
  Licença: MIT
*/

const int PINO_TRIG   = 9;
const int PINO_ECHO   = 10;
const int PINO_BUZZER = 8;
const int PINO_LED    = 13;

// Distâncias em centímetros. Mude estes valores em aula!
const int DISTANCIA_AVISO  = 100;  // começa a apitar
const int DISTANCIA_PERIGO = 20;   // apito contínuo e LED aceso

const int FREQUENCIA_APITO = 1000; // em hertz (Hz)

void setup() {
  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sensor de distancia pronto!");
}

// Envia um pulso de ultrassom e devolve a distância em centímetros.
// Devolve -1 se nenhum eco voltar (nada à frente, ou longe demais).
long medirDistancia() {
  // 1) Garante o TRIG desligado
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);

  // 2) Pulso de 10 microssegundos: o sensor emite 8 "estalos" de 40 kHz
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  // 3) Mede quanto tempo o ECHO fica ligado (ida + volta do som)
  //    O limite de 30000 us corresponde a uns 5 metros.
  long tempo = pulseIn(PINO_ECHO, HIGH, 30000);
  if (tempo == 0) {
    return -1;
  }

  // 4) O som anda a ~343 m/s = 0,0343 cm por microssegundo.
  //    Dividimos por 2 porque o som foi E voltou.
  return tempo * 0.0343 / 2;
}

void loop() {
  long distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < 0 || distancia > DISTANCIA_AVISO) {
    // Caminho livre: silêncio
    noTone(PINO_BUZZER);
    digitalWrite(PINO_LED, LOW);
    delay(100);

  } else if (distancia <= DISTANCIA_PERIGO) {
    // Muito perto: apito contínuo
    tone(PINO_BUZZER, FREQUENCIA_APITO);
    digitalWrite(PINO_LED, HIGH);
    delay(100);

  } else {
    // Zona de aviso: o intervalo entre os bipes diminui com a distância.
    // map() converte 20..100 cm em 50..500 ms de pausa.
    int pausa = map(distancia, DISTANCIA_PERIGO, DISTANCIA_AVISO, 50, 500);
    digitalWrite(PINO_LED, LOW);
    tone(PINO_BUZZER, FREQUENCIA_APITO, 60);  // bipe de 60 ms
    delay(60 + pausa);
  }
}
