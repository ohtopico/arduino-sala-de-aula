# Plano de aula: estação meteorológica

| | |
|---|---|
| **Público** | 8º e 9º ano do Ensino Fundamental, Ensino Médio, cursos técnicos |
| **Duração** | 3 aulas de 50 min (ou 2 aulas + coleta de dados em casa ou na escola) |
| **Áreas** | Ciências e Geografia (tempo e clima), Matemática (funções, gráficos, média), Computação |
| **Modalidade** | Simulação no Tinkercad e, se houver, kit físico para medir o ambiente real |

## Objetivos de aprendizagem

Ao final, a turma deve conseguir:

- diferenciar **tempo** (o que acontece agora) de **clima** (o padrão ao longo dos anos);
- identificar variáveis da previsão do tempo (temperatura, umidade, luminosidade, pressão, vento) e como cada uma é medida;
- transformar a leitura de um sensor em grandeza física por meio de uma fórmula (função do 1º grau);
- coletar, organizar e representar dados em gráfico, calculando mínima, máxima e média;
- comparar os dados da estação da turma com dados oficiais (INMET).

## Habilidades da BNCC relacionadas

- **EF08CI15**: identificar as principais variáveis envolvidas na previsão do tempo e simular situações nas quais elas possam ser medidas.
- **EF08CI02**: construir circuitos elétricos com pilha/bateria, fios e lâmpada ou outros dispositivos.
- **EF07CI02**: diferenciar temperatura, calor e sensação térmica nas diferentes situações de equilíbrio termodinâmico cotidianas.
- **BNCC Computação (2022)**, eixos **Pensamento Computacional** e **Mundo Digital**: sensores como entrada de dados, representação e processamento de informações.

_Adapte as habilidades ao ano e ao currículo da sua rede._

## Materiais

- Tinkercad (contas de turma) **ou** kit por grupo: Arduino Uno, TMP36 ou DHT11, LDR, resistores (10 kΩ e 220 Ω), LED, LCD 16x2, potenciômetro, protoboard, jumpers;
- Termômetro comum para comparação;
- Planilha (Google Planilhas, Excel ou LibreOffice) para os gráficos.

## Aula 1: Como se mede o tempo? (50 min)

| Tempo | Atividade |
|---|---|
| 10 min | **Abertura.** Mostrar a previsão do tempo do dia (jornal ou site do INMET). _Quais números aparecem? Quem mede isso? Com quê?_ Separar no quadro **tempo** e **clima**. |
| 15 min | **Conceito.** Cada variável e seu instrumento: termômetro, higrômetro, barômetro, anemômetro, pluviômetro. Explicar que um sensor eletrônico transforma a grandeza em **tensão elétrica** e o Arduino lê essa tensão como um número. |
| 20 min | **Montagem, parte 1.** TMP36 e LDR, ainda sem o LCD. Usar um código mínimo com `Serial.println(analogRead(A0));` para ver o número cru mudar. |
| 5 min | **Fechamento.** _O número 153 é a temperatura?_ Deixar a pergunta para a próxima aula. |

## Aula 2: Do número à temperatura (50 min)

| Tempo | Atividade |
|---|---|
| 15 min | **Matemática.** Montar com a turma a fórmula do TMP36 (0,5 V a 0 °C, +0,01 V por grau). Converter 3 leituras à mão. Mostrar que é uma **função do 1º grau** e esboçar o gráfico. |
| 25 min | **Montagem, parte 2.** Ligar o LCD e o potenciômetro, colar o código completo e testar. Comparar com o termômetro comum: qual a diferença? |
| 10 min | **Modificação.** Mudar o `LIMITE_CALOR`; criar um aviso de frio; mudar os limites de _Escuro / Nublado / Ensolarado_. |

## Aula 3: Dados e gráficos (50 min)

| Tempo | Atividade |
|---|---|
| 15 min | **Coleta.** Kit físico: deixar a estação registrando em pontos diferentes da escola (sala, pátio ao sol, sombra). Tinkercad: cada grupo simula um "dia" mexendo nos controles e copia os dados do Monitor serial. |
| 20 min | **Análise.** Colar os dados na planilha, fazer o gráfico de linha, calcular mínima, máxima e média. Comparar com a estação do INMET mais próxima. |
| 15 min | **Socialização.** Cada grupo apresenta o gráfico em 2 minutos: _onde fez mais calor? Por quê? A medida da turma bate com a oficial?_ Gancho para conversar sobre ilhas de calor, árvores no pátio e eventos extremos no RS. |

## Avaliação

- **Conversões à mão** (aula 2) corretas.
- **Gráfico e resumo** (mínima, máxima, média) com uma frase de interpretação.
- **Pergunta de saída** (individual): _por que a temperatura no LCD pode ser diferente da que aparece na previsão do tempo?_ (local da medida, sol direto, precisão do sensor, horário)

| Critério | Inicial | Adequado | Avançado |
|---|---|---|---|
| Conceitos | Lista variáveis do tempo | Diferencia tempo e clima, relaciona sensor e variável | Explica sensação térmica e umidade |
| Matemática | Usa a fórmula com ajuda | Converte leituras sozinho | Explica a fórmula como função e interpreta o gráfico |
| Circuito e código | Roda o código pronto | Monta e altera limites | Acrescenta sensor ou alerta novo |
| Dados | Copia os dados | Faz gráfico e resumo | Compara com dados oficiais e explica diferenças |

## Adaptações e inclusão

- Para estudantes cegos ou com baixa visão: acrescentar um **buzzer** que muda de tom conforme a temperatura (tom mais agudo = mais quente) e ler os valores do Monitor serial com leitor de tela.
- Turma sem kit: tudo funciona no Tinkercad; a aula 3 pode usar dados abertos do INMET no lugar dos dados medidos.
- Projeto longo: a estação vira um projeto de feira de ciências, com coleta durante uma semana e comparação com o histórico do município.
