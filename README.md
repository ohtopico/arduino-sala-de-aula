# Arduino na sala de aula

Projetos de Arduino documentados para usar com turmas do Ensino Fundamental, do Ensino Médio e de cursos técnicos. Cada projeto tem **código comentado em português**, **tabela de ligações** para montar no Tinkercad ou na bancada, e **plano de aula** com objetivos, habilidades da BNCC, roteiro, avaliação e adaptações para inclusão.

Feito por **Júlia Roberta Quoos Alves**, professora com pós-graduação em robótica e mestranda em Ciência da Computação (PPGCC/UFSM). Mais materiais em [ohtopico.com.br/material-didatico](https://ohtopico.com.br/material-didatico).

## Projetos

| # | Projeto | O que a turma aprende | Nível | Aulas | Tinkercad |
|---|---|---|---|---|---|
| 1 | [Sensor de distância com aviso sonoro](01-sensor-distancia/) | Eco, velocidade do som, condições (`if`), tecnologia assistiva | Iniciante | 2 | _link_ |
| 2 | [Semáforo com botão de pedestre e sinal sonoro](02-semaforo/) | Algoritmos e estados, LEDs e resistores, botão, acessibilidade urbana | Iniciante | 2 | _link_ |
| 3 | [Estação meteorológica](03-estacao-meteorologica/) | Tempo e clima, sensores analógicos, funções, gráficos | Intermediário | 3 | _link_ |

Em cada pasta:

```
README.md          materiais, ligações, montagem no Tinkercad, como funciona, desafios
plano-de-aula.md   objetivos, BNCC, roteiro por aula, avaliação, adaptações
<nome>/<nome>.ino  código para colar no Tinkercad ou abrir na IDE do Arduino
```

Os três projetos usam som de propósito: o aviso sonoro deixa o resultado acessível a estudantes cegos ou com baixa visão e abre a conversa sobre tecnologia assistiva.

## Como usar

**No Tinkercad (sem comprar nada).** Crie uma turma em [tinkercad.com](https://www.tinkercad.com) (**Turmas → Criar turma**) e os estudantes entram com um código, sem e-mail. Em cada projeto, o README explica como montar o circuito e colar o código em **Código → Texto**.

**Na bancada.** Abra o arquivo `.ino` na [IDE do Arduino](https://www.arduino.cc/en/software), escolha **Arduino Uno** em Ferramentas → Placa, a porta USB em Ferramentas → Porta, e clique em **Carregar**.

## Kit para os três projetos

| Componente | Qtd. por grupo |
|---|---|
| Arduino Uno + cabo USB | 1 |
| Protoboard + jumpers | 1 + ~30 |
| LEDs (2 vermelhos, 1 amarelo, 2 verdes) | 5 |
| Resistores de 220 Ω | 6 |
| Resistor de 10 kΩ | 1 |
| Buzzer piezoelétrico | 1 |
| Botão (push button) | 1 |
| Sensor ultrassônico HC-SR04 | 1 |
| Sensor de temperatura TMP36 (ou DHT11) | 1 |
| LDR (fotorresistor) | 1 |
| Display LCD 16x2 + potenciômetro de 10 kΩ | 1 |

## Licença

- Código (`.ino`): [MIT](LICENSE).
- Textos e planos de aula: [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/deed.pt-br). Pode usar, adaptar e compartilhar, citando a autoria.

Usou com a sua turma? Abra uma _issue_ contando como foi ou sugerindo melhorias.
