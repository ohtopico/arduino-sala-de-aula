# Semáforo com botão de pedestre e sinal sonoro

Um semáforo de carros (vermelho, amarelo e verde) e outro de pedestres (vermelho e verde). Quando alguém aperta o botão, os carros recebem o amarelo, depois o vermelho, e os pedestres podem atravessar. Durante a travessia o buzzer bipa, como os **semáforos sonoros** que ajudam pessoas cegas a saber quando atravessar.

**Nível:** iniciante · **Tempo de montagem:** 30 a 40 min · **Plano de aula:** [plano-de-aula.md](plano-de-aula.md)

🔗 **Simulação no Tinkercad:** _adicionar o link aqui_

## Materiais

| Qtd. | Componente | No Tinkercad |
|---|---|---|
| 1 | Arduino Uno | Arduino Uno R3 |
| 2 | LED vermelho | LED (cor vermelha) |
| 1 | LED amarelo | LED (cor amarela) |
| 2 | LED verde | LED (cor verde) |
| 5 | Resistor de 220 Ω | Resistor (mude para 220 Ω) |
| 1 | Botão (push button) | Botão |
| 1 | Buzzer piezoelétrico | Piezo |
| 1 | Protoboard e jumpers | Placa de ensaio |

## Ligações

Todos os LEDs: perna longa (**anodo**) → resistor de 220 Ω → pino do Arduino; perna curta (**catodo**) → GND.

| Componente | Pino do Arduino |
|---|---|
| LED vermelho dos carros | **12** |
| LED amarelo dos carros | **11** |
| LED verde dos carros | **10** |
| LED vermelho do pedestre | **7** |
| LED verde do pedestre | **6** |
| Buzzer, terminal **+** | **8** (terminal **−** no GND) |
| Botão, um terminal | **2** |
| Botão, terminal na diagonal oposta | GND |

O botão não precisa de resistor externo: o código usa `INPUT_PULLUP`, que liga um resistor interno do Arduino. Por isso a leitura é **HIGH quando solto** e **LOW quando apertado** (o contrário do que a turma costuma esperar, e um bom ponto de conversa).

## Montando no Tinkercad

1. **Circuitos → Criar novo circuito**. Arraste o **Arduino Uno R3** e uma **placa de ensaio**.
2. Ligue o **GND** do Arduino à trilha azul (−) da placa.
3. Coloque os três LEDs dos carros em coluna, de cima para baixo: vermelho, amarelo, verde. Mude a cor clicando em cada LED. Faça o mesmo com os dois LEDs do pedestre, um pouco ao lado.
4. Para cada LED: resistor de 220 Ω saindo da perna longa (o Tinkercad mostra "Anodo" ao passar o mouse) até o pino da tabela, e a perna curta para a trilha GND.
5. Coloque o **botão** atravessando o vão central da placa. Ligue um terminal ao pino **2** e o terminal na diagonal oposta ao GND.
6. Coloque o **piezo**: terminal positivo no pino **8**, negativo no GND.
7. Em **Código → Texto**, cole o conteúdo de [`semaforo/semaforo.ino`](semaforo/semaforo.ino).
8. **Iniciar simulação** e clique no botão. Abra o **Monitor serial** para ver em que fase o semáforo está.

## Como funciona

O programa é uma **sequência de estados**:

```
Carros VERDE ──(botão + 5 s de verde mínimo)──▶ Carros AMARELO (2 s)
      ▲                                                   │
      │                                                   ▼
Pedestre VERMELHO PISCANDO (3 s, bipe rápido) ◀── Pedestre VERDE (6 s, bipe lento)
```

- `millis()` conta os milissegundos desde que o Arduino ligou. Com ele o programa sabe há quanto tempo o verde dos carros está aceso, sem parar de olhar o botão.
- O pedido do pedestre fica guardado na variável `pedidoDePedestre`: se o botão for apertado logo depois que o verde abriu, o semáforo espera completar o verde mínimo e só então troca.
- O ritmo do bipe muda: **lento** = pode atravessar, **rápido** = termine a travessia. É assim que funcionam os semáforos sonoros reais.

## Para ir além

- Mude os tempos (`VERDE_MINIMO`, `TEMPO_TRAVESSIA`). Quanto tempo uma pessoa idosa precisa para atravessar uma rua de 4 faixas?
- Faça o semáforo funcionar à noite em **amarelo piscante** (dica: acrescente um LDR).
- Acrescente um **display** com contagem regressiva para os pedestres.
- Monte um **cruzamento** com dois semáforos de carros que nunca ficam verdes ao mesmo tempo.

## Problemas comuns

| O que acontece | Provável causa |
|---|---|
| Um LED não acende | LED ao contrário ou resistor fora da trilha certa |
| O semáforo troca sozinho, sem apertar o botão | Botão ligado em terminais do mesmo lado (sempre fechado); use os da diagonal |
| Apertar o botão não faz nada | Botão sem ligação com o GND, ou o verde mínimo ainda não passou (espere 5 s) |
| LEDs muito fracos | Resistor de valor alto demais (confira os 220 Ω) |
