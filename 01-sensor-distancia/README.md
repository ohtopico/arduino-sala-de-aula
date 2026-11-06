# Sensor de distância com aviso sonoro

Um sensor ultrassônico mede a distância até um objeto e um buzzer apita cada vez mais rápido conforme o objeto se aproxima, como o sensor de estacionamento de um carro. É o mesmo princípio usado em bengalas eletrônicas e em outros recursos de mobilidade para pessoas cegas.

**Nível:** iniciante · **Tempo de montagem:** 20 a 30 min · **Plano de aula:** [plano-de-aula.md](plano-de-aula.md)

🔗 **Simulação no Tinkercad:** _adicionar o link aqui_

## Materiais

| Qtd. | Componente | No Tinkercad |
|---|---|---|
| 1 | Arduino Uno | Arduino Uno R3 |
| 1 | Sensor ultrassônico HC-SR04 (4 pinos) | Sensor de distância ultrassônico (4 pinos) |
| 1 | Buzzer piezoelétrico | Piezo |
| 1 | LED vermelho | LED |
| 1 | Resistor de 220 Ω | Resistor (mude para 220 Ω) |
| 1 | Protoboard e jumpers | Placa de ensaio pequena |

## Ligações

| De | Para |
|---|---|
| HC-SR04 **VCC** | 5V do Arduino |
| HC-SR04 **GND** | GND do Arduino |
| HC-SR04 **TRIG** | Pino digital **9** |
| HC-SR04 **ECHO** | Pino digital **10** |
| Buzzer, terminal **+** (positivo) | Pino digital **8** |
| Buzzer, terminal **−** | GND |
| LED, perna longa (**anodo**) | Resistor de 220 Ω → pino digital **13** |
| LED, perna curta (**catodo**) | GND |

Dica: ligue o 5V e o GND do Arduino às trilhas laterais da protoboard (vermelha e azul) e puxe tudo de lá.

## Montando no Tinkercad

1. Em [tinkercad.com](https://www.tinkercad.com), entre em **Circuitos → Criar novo circuito**.
2. Arraste o **Arduino Uno R3**, uma **placa de ensaio pequena**, o **sensor de distância ultrassônico** de 4 pinos, um **piezo**, um **LED** e um **resistor**.
3. Clique no resistor e mude a resistência para **220 Ω**.
4. Faça as ligações da tabela acima. Clique num fio para mudar a cor: vermelho para 5V, preto para GND e outras cores para sinal ajudam a turma a ler o circuito.
5. Abra **Código → Texto**, apague o exemplo e cole o conteúdo de [`sensor_distancia/sensor_distancia.ino`](sensor_distancia/sensor_distancia.ino).
6. Clique em **Iniciar simulação**. Clique no sensor e arraste o círculo que aparece na frente dele para simular um objeto chegando perto.
7. Abra o **Monitor serial** (embaixo do código) para ver a distância em centímetros.
8. Para compartilhar: **Compartilhar → Convidar pessoas** ou deixe o circuito **Público** e copie o link para o topo deste arquivo.

## Como funciona

1. O Arduino manda um pulso de 10 µs no pino **TRIG**.
2. O sensor emite um som de 40 kHz (ultrassom, que não ouvimos).
3. O som bate no objeto e volta. Enquanto ele não volta, o pino **ECHO** fica ligado.
4. O Arduino mede esse tempo com `pulseIn()` e calcula:

```
distância (cm) = tempo (µs) × 0,0343 ÷ 2
```

0,0343 cm/µs é a velocidade do som no ar (343 m/s). Dividimos por 2 porque o som fez o caminho de ida **e** de volta.

5. A função `map()` transforma a distância (20 a 100 cm) no intervalo entre os bipes (50 a 500 ms). Abaixo de 20 cm o bipe fica contínuo e o LED acende.

## Para ir além

- Mude `DISTANCIA_AVISO` e `DISTANCIA_PERIGO`. Qual distância faz sentido para um carro? E para uma pessoa andando?
- Mude `FREQUENCIA_APITO`. Sons graves ou agudos chamam mais atenção?
- Troque o bipe por um **motor de vibração** (avise sem som, útil para quem tem deficiência auditiva).
- Coloque o circuito numa caixa presa ao corpo ou a uma bengala: vira um protótipo de tecnologia assistiva.
- Meça a mesma distância com uma régua e com o sensor. Qual o erro? Ele muda com o tipo de superfície (parede, tecido, espuma)?

## Problemas comuns

| O que acontece | Provável causa |
|---|---|
| Distância sempre −1 | TRIG e ECHO trocados, ou nada à frente do sensor |
| Distância sempre 0 ou muito estranha | VCC ou GND do sensor soltos |
| Buzzer não apita | Polaridade invertida, ou ligado em outro pino que não o 8 |
| LED não acende | LED ao contrário (a perna longa vai para o lado do pino) |
