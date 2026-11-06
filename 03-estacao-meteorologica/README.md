# Estação meteorológica

Mede a **temperatura** e a **luminosidade** do ambiente e mostra os valores num display LCD, junto com a mínima e a máxima registradas. Um LED acende quando passa de 30 °C. Os dados também saem pelo **Plotter Serial**, que desenha o gráfico em tempo real.

Há duas versões do código:

| Versão | Sensores | Para quê |
|---|---|---|
| [`estacao_meteorologica/`](estacao_meteorologica/estacao_meteorologica.ino) | TMP36 (temperatura) + LDR (luz) | **Tinkercad** e kits simples |
| [`estacao_dht11/`](estacao_dht11/estacao_dht11.ino) | DHT11 (temperatura e umidade) + LDR | **Kit físico**. O Tinkercad não tem o DHT11 |

**Nível:** intermediário · **Tempo de montagem:** 40 a 50 min · **Plano de aula:** [plano-de-aula.md](plano-de-aula.md)

🔗 **Simulação no Tinkercad:** _adicionar o link aqui_

## Materiais

| Qtd. | Componente | No Tinkercad |
|---|---|---|
| 1 | Arduino Uno | Arduino Uno R3 |
| 1 | Sensor de temperatura TMP36 | Sensor de temperatura [TMP36] |
| 1 | LDR (fotorresistor) | Fotorresistor |
| 1 | Resistor de 10 kΩ (para o LDR) | Resistor (mude para 10 kΩ) |
| 1 | LED vermelho + resistor de 220 Ω | LED + Resistor |
| 1 | Display LCD 16x2 | LCD 16 x 2 |
| 1 | Potenciômetro de 10 kΩ (contraste do LCD) | Potenciômetro |
| 1 | Resistor de 220 Ω (luz de fundo do LCD) | Resistor |
| 1 | Protoboard e jumpers | Placa de ensaio |
| _opcional_ | DHT11 ou DHT22 (versão kit físico) | não existe no Tinkercad |

## Ligações

Ligue o **5V** do Arduino na trilha vermelha (+) e o **GND** na trilha azul (−) da protoboard.

**Sensores e LED**

| Componente | Ligação |
|---|---|
| TMP36, pino esquerdo (lado reto virado para você) | 5V |
| TMP36, pino do meio | **A0** |
| TMP36, pino direito | GND |
| LDR, um terminal | 5V |
| LDR, outro terminal | **A1** e também resistor de 10 kΩ → GND |
| LED, anodo (perna longa) | resistor 220 Ω → pino **9** |
| LED, catodo | GND |

**Display LCD 16x2** (pinos da esquerda para a direita)

| Pino do LCD | Ligação |
|---|---|
| VSS (GND) | GND |
| VDD (VCC) | 5V |
| V0 (contraste) | pino do meio do potenciômetro (as pontas do potenciômetro no 5V e no GND) |
| RS | pino **12** |
| RW | GND |
| E | pino **11** |
| D0 a D3 | sem ligação |
| D4 | pino **5** |
| D5 | pino **4** |
| D6 | pino **3** |
| D7 | pino **2** |
| A (luz de fundo, +) | resistor 220 Ω → 5V |
| K (luz de fundo, −) | GND |

**Versão DHT11:** em vez do TMP36, ligue o DHT11 com VCC no 5V, GND no GND e DATA no pino **7**. O módulo de 3 pinos já tem resistor; o sensor solto, de 4 pinos, precisa de um resistor de 10 kΩ entre DATA e 5V.

## Montando no Tinkercad

1. **Circuitos → Criar novo circuito**. Arraste o **Arduino Uno R3** e uma **placa de ensaio**. Ligue 5V e GND às trilhas laterais.
2. Comece pelo **LCD**, que tem mais fios. Siga a tabela pino a pino. Passe o mouse sobre cada pino do LCD para ver o nome.
3. Coloque o **potenciômetro** e ligue o pino do meio ao V0. Se a tela ficar vazia na simulação, gire o potenciômetro.
4. Coloque o **TMP36**, o **fotorresistor** com o resistor de 10 kΩ e o **LED** com o resistor de 220 Ω.
5. Em **Código → Texto**, cole [`estacao_meteorologica/estacao_meteorologica.ino`](estacao_meteorologica/estacao_meteorologica.ino).
6. **Iniciar simulação**. Clique no TMP36 e arraste o controle de temperatura; clique no fotorresistor e mude a luz. Acima de 30 °C o LED acende.
7. Abra o **Monitor serial** e clique no ícone de gráfico para ver as curvas de temperatura e luz.

> No kit físico, a versão TMP36 também funciona. Para a versão DHT11, instale pela IDE do Arduino (**Ferramentas → Gerenciar bibliotecas**) a **DHT sensor library**, da Adafruit, e aceite instalar a **Adafruit Unified Sensor**.

## Como funciona

**Temperatura (TMP36).** O sensor entrega 0,5 V a 0 °C e mais 0,01 V (10 mV) para cada grau. O Arduino lê de 0 a 1023 (para 0 a 5 V), então:

```
tensão = leitura × 5 ÷ 1023
temperatura (°C) = (tensão − 0,5) × 100
```

Exemplo: leitura 153 → 0,748 V → 24,8 °C.

**Luz (LDR).** A resistência do LDR cai quando há mais luz. Junto com o resistor de 10 kΩ ele forma um **divisor de tensão**: mais luz, mais tensão no A1. A função `map()` transforma 0 a 1023 em 0 a 100 %, e o código classifica em _Escuro_, _Nublado_ ou _Ensolarado_.

**Mínima e máxima.** Duas variáveis guardam o menor e o maior valor já lidos. A cada 4 s o LCD alterna entre a leitura atual e esses extremos.

**Umidade e sensação térmica (versão DHT11).** O DHT11 mede a umidade relativa do ar. Com temperatura e umidade, a biblioteca calcula o **índice de calor** (sensação térmica): com o ar úmido, o suor evapora menos e sentimos mais calor.

## Para ir além

- Deixe a estação ligada uma manhã inteira e salve os dados do Monitor serial. Faça o gráfico numa planilha e compare com o site do INMET.
- Acrescente um **buzzer** que avisa quando a temperatura passa do limite (onda de calor) ou cai muito (geada).
- Troque o LCD por um **LCD com módulo I2C** (só 4 fios, biblioteca `LiquidCrystal_I2C`).
- Use um **sensor de umidade do solo** (existe no Tinkercad) e transforme a estação num sistema de irrigação de horta.
- Com um ESP32 ou ESP8266, envie os dados para a internet.

## Problemas comuns

| O que acontece | Provável causa |
|---|---|
| LCD aceso mas sem letras, ou só quadrados | Contraste: gire o potenciômetro |
| LCD com caracteres estranhos | Algum fio de D4 a D7, RS ou E trocado |
| Temperatura absurda (−50 °C, 450 °C) | TMP36 virado ao contrário (esquenta, cuidado) ou pino do meio fora do A0 |
| Luz sempre 0 % ou 100 % | Falta o resistor de 10 kΩ no divisor, ou LDR fora do A1 |
| "Erro no sensor" (versão DHT11) | Fio DATA fora do pino 7, ou falta o resistor de 10 kΩ no sensor de 4 pinos |
