# Plano de aula: semáforo com botão de pedestre e sinal sonoro

| | |
|---|---|
| **Público** | 6º ao 9º ano do Ensino Fundamental, Ensino Médio, oficinas de robótica |
| **Duração** | 2 aulas de 50 min |
| **Áreas** | Computação (algoritmos e estados), Ciências (circuitos elétricos), Geografia e cidadania (mobilidade urbana, acessibilidade) |
| **Modalidade** | Simulação no Tinkercad ou kit físico (grupos de 3 a 4) |

## Objetivos de aprendizagem

Ao final, a turma deve conseguir:

- descrever o funcionamento de um semáforo como uma **sequência de estados** com tempos e condições;
- montar um circuito com vários LEDs, resistores e um botão;
- entender o que o resistor faz no LED e por que o botão usa `INPUT_PULLUP`;
- alterar tempos e regras no código e prever o efeito antes de testar;
- reconhecer o semáforo sonoro como recurso de acessibilidade e discutir o direito de ir e vir.

## Habilidades da BNCC relacionadas

- **EF08CI02**: construir circuitos elétricos com pilha/bateria, fios e lâmpada ou outros dispositivos e compará-los a circuitos elétricos residenciais.
- **Competência geral 5** (cultura digital) e **competência geral 9** (empatia e cooperação, valorizando a diversidade).
- **BNCC Computação (2022)**, eixo **Pensamento Computacional**: algoritmos com sequência, condição e repetição; decomposição do problema em estados.

_Adapte as habilidades ao ano e ao currículo da sua rede._

## Materiais

- Tinkercad (contas de turma) **ou** kit por grupo: Arduino Uno, 5 LEDs (2 vermelhos, 1 amarelo, 2 verdes), 5 resistores de 220 Ω, botão, buzzer, protoboard e jumpers;
- Papel e canetas coloridas para o diagrama de estados.

## Aula 1: O semáforo é um algoritmo (50 min)

| Tempo | Atividade |
|---|---|
| 10 min | **Abertura.** _Quem já esperou muito tempo para atravessar? Quem já viu um semáforo que apita?_ Conversa sobre semáforos sonoros e quem precisa deles (pessoas cegas, com baixa visão, idosas). |
| 15 min | **Desplugado.** Em grupos, desenhar no papel o semáforo como "caixinhas" (estados) ligadas por setas (o que faz mudar: tempo ou botão). Um estudante faz o papel do semáforo com cartões coloridos e o grupo "executa" o diagrama. |
| 20 min | **Montagem.** Montar os LEDs e resistores pela tabela do [README](README.md). Conversa rápida: sem o resistor, a corrente seria alta demais e o LED queimaria. |
| 5 min | **Fechamento.** Comparar dois diagramas diferentes da turma: os dois funcionam? Algum deixa carro e pedestre no verde ao mesmo tempo? |

## Aula 2: Programando a travessia (50 min)

| Tempo | Atividade |
|---|---|
| 5 min | Ligar botão e buzzer ao circuito da aula anterior. |
| 15 min | **Leitura do código.** Colar e rodar. Achar no código cada estado do diagrama feito em papel. Explicar o `INPUT_PULLUP` (solto = HIGH, apertado = LOW). |
| 20 min | **Desafios em grupo** (escolher um): (a) aumentar o tempo de travessia e justificar com uma conta (largura da rua ÷ velocidade de caminhada, ~1 m/s); (b) mudar o som para a turma reconhecer de olhos fechados quando pode atravessar; (c) amarelo piscante à noite. |
| 10 min | **Teste de olhos vendados** (voluntários): só pelo som, a pessoa diz quando pode atravessar. Conversa: _o som foi claro? E numa rua barulhenta?_ |

## Avaliação

- **Diagrama de estados** da aula 1 (correto e completo).
- **Desafio** funcionando, com explicação do que foi alterado e por quê.
- **Pergunta de saída** (individual): _o que aconteceria se o botão fosse apertado logo depois de o verde abrir para os carros?_

| Critério | Inicial | Adequado | Avançado |
|---|---|---|---|
| Algoritmo | Lista as cores na ordem | Faz o diagrama com tempos e botão | Encontra falhas de segurança no diagrama |
| Circuito | Monta com ajuda | Monta pela tabela | Explica o papel do resistor e do pull-up |
| Programação | Roda o código pronto | Altera tempos e sons | Cria um estado novo (piscante, cruzamento) |
| Cidadania | Cita o semáforo sonoro | Explica para quem ele serve | Propõe melhorias para a própria cidade |

## Adaptações e inclusão

- O bipe torna o resultado acessível a estudantes cegos ou com baixa visão. No kit físico, marque os LEDs com formatos diferentes (fita, adesivo) e descreva as ligações em voz alta.
- Pouco tempo ou poucos computadores: pular a montagem física e fazer só o desplugado + simulação projetada.
- Extensão interdisciplinar: levantar com a turma onde há (ou faltam) semáforos sonoros no bairro e escrever uma carta à prefeitura.
