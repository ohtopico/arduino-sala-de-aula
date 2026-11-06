# Plano de aula: sensor de distância com aviso sonoro

| | |
|---|---|
| **Público** | 8º e 9º ano do Ensino Fundamental, Ensino Médio, cursos técnicos ou oficinas de robótica |
| **Duração** | 2 aulas de 50 min |
| **Áreas** | Ciências (ondas sonoras), Matemática (velocidade, proporção), Computação (pensamento computacional) |
| **Modalidade** | Simulação no Tinkercad (computadores) ou kit físico (grupos de 3 a 4) |

## Objetivos de aprendizagem

Ao final, a turma deve conseguir:

- explicar como o eco permite medir distâncias (morcegos, golfinhos, sonares, sensores de ré);
- usar `distância = velocidade × tempo` e entender por que o tempo é dividido por 2;
- montar um circuito com sensor, LED e buzzer a partir de uma tabela de ligações;
- ler e alterar um programa com condições (`if / else`) e variáveis;
- discutir como a tecnologia pode ajudar pessoas com deficiência visual a se locomover.

## Habilidades da BNCC relacionadas

- **EF08CI02**: construir circuitos elétricos com pilha/bateria, fios e lâmpada ou outros dispositivos e compará-los a circuitos elétricos residenciais.
- **Competência geral 5** (cultura digital): compreender, utilizar e criar tecnologias digitais de forma crítica, significativa e ética.
- **BNCC Computação (2022)**, eixo **Pensamento Computacional**: algoritmos com condições e repetição, decomposição de problemas.

_Os conteúdos de ondas (frequência, propagação, eco) aparecem no 9º ano e na Física do Ensino Médio; adapte as habilidades ao currículo da sua rede._

## Materiais

- Computadores com acesso ao Tinkercad (contas de turma: **Turmas → Criar turma**, sem e-mail dos estudantes), **ou**
- Kit por grupo: Arduino Uno, HC-SR04, buzzer, LED, resistor 220 Ω, protoboard, jumpers, cabo USB;
- Régua ou trena, objetos de superfícies diferentes (caderno, blusa, espuma).

## Aula 1: O som que volta (50 min)

| Tempo | Atividade |
|---|---|
| 10 min | **Abertura.** Pergunta para a turma: _como um morcego voa no escuro sem bater nas paredes?_ Recolha hipóteses no quadro. Se possível, mostre um vídeo curto de ecolocalização ou de um sensor de ré de carro. |
| 15 min | **Conceito.** O som é uma onda que viaja a ~343 m/s no ar. Bate-palma diante de uma parede distante: o eco é o som voltando. Resolva junto: _se o eco volta em 0,01 s, a que distância está a parede?_ (343 × 0,01 ÷ 2 ≈ 1,7 m). Destaque o **÷ 2**. |
| 20 min | **Montagem.** Em grupos, montar o circuito pela tabela do [README](README.md). Ainda sem código: conferir 5V, GND e cada pino. |
| 5 min | **Fechamento.** Cada grupo diz uma coisa que ficou confusa. Anote para retomar na aula 2. |

## Aula 2: Programar o aviso (50 min)

| Tempo | Atividade |
|---|---|
| 5 min | Retomar as dúvidas da aula anterior. |
| 15 min | **Leitura do código.** Colar o programa, rodar e abrir o Monitor serial. Ler em voz alta a função `medirDistancia()` e achar no código a conta da aula 1 (`* 0.0343 / 2`). |
| 15 min | **Experimento.** Comparar a régua com o sensor em 3 distâncias e 2 superfícies. Registrar numa tabela: distância real, medida, diferença. |
| 10 min | **Modificação.** Cada grupo escolhe um desafio: mudar a distância de perigo, mudar o tom, ou fazer o LED piscar na zona de aviso. |
| 5 min | **Fechamento.** Conversa: _quem usaria um aparelho assim? Ele resolveria o problema de uma pessoa cega andando na rua? O que faltaria?_ (desníveis, buracos, objetos na altura da cabeça, ruído da cidade). |

## Avaliação

- **Tabela do experimento** preenchida (medidas e erro).
- **Mudança no código** funcionando, com uma frase explicando o que foi alterado.
- **Pergunta de saída** (individual): _por que o programa divide o tempo por 2?_

| Critério | Inicial | Adequado | Avançado |
|---|---|---|---|
| Circuito | Precisa de ajuda para montar | Monta pela tabela | Monta e encontra erros de outros grupos |
| Conceito | Sabe que o sensor "usa som" | Explica o eco e a conta | Relaciona erro da medida à superfície ou ao ângulo |
| Programação | Roda o código pronto | Altera valores | Cria um comportamento novo |

## Adaptações e inclusão

- Estudantes cegos ou com baixa visão participam bem pelo **aviso sonoro**, que é o resultado principal do projeto. Use jumpers de cores diferentes e com textura (fita) no kit físico, e leia as ligações em voz alta.
- Sem computador para todos: um circuito montado pela professora, projetado, e a turma decide as mudanças no código.
- Turmas mais avançadas: trocar `delay()` por `millis()` e acrescentar um segundo sensor (esquerda e direita) com sons diferentes.
