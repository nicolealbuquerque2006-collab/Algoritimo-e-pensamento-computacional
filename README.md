# Calculadora Multifuncional

Projeto desenvolvido em grupo para aplicar conceitos de lógica de programação na criação de uma calculadora seguindo um fluxograma
## Objetivo

Desenvolver, em Flowgorithm, um fluxograma para uma Calculadora Multifuncional que apresente um menu principal com **11 opções** (10 funções de cálculo + a opção de encerrar o programa), permanecendo em execução — retornando sempre ao menu — até que o usuário escolha encerrar.
## Integrantes do grupo

- Julia Rodrigues Bezerra
- Rafael Oliveira
- Roberto Rosado
- Nicole moreira
## Ferramenta utilizada

## Descrição das 10 funções de cálculo

O menu principal oferece as seguintes operações:

1. **Soma** — soma dois números reais informados pelo usuário (`n1 + n2`).
2. **Subtração** — subtrai o segundo número do primeiro (`n1 - n2`).
3. **Multiplicação** — multiplica dois números reais (`n1 * n2`).
4. **Divisão** — divide o primeiro número pelo segundo (`n1 / n2`); antes de calcular, verifica se o divisor é igual a zero e, nesse caso, exibe uma mensagem de erro em vez de tentar dividir.
5. **Potenciação** — eleva uma base a um expoente informado (`base ^ expoente`).
6. **Raiz Quadrada** — calcula a raiz quadrada de um número usando a função `Sqrt`; se o número informado for negativo, exibe uma mensagem de erro em vez de calcular.
7. **Área do Círculo** — calcula a área a partir do raio informado, usando a constante `pi` (`pi * raio²`).
8. **Área do Retângulo** — calcula a área a partir da base e da altura informadas (`base * altura`).
9. **Conversão de Celsius para Fahrenheit** — converte uma temperatura em graus Celsius para Fahrenheit (`F = C * 9/5 + 32`).
10. **Média Aritmética** — calcula a média de três números informados pelo usuário (`(n1 + n2 + n3) / 3`).
11. **Encerrar** — finaliza a execução do programa, saindo do laço principal.

## Lógica de funcionamento do programa

1. A variável `opcao` é inicializada com `0` antes do menu começar.
2. Um laço `While (opcao <> 11)` mantém o programa em execução enquanto a opção escolhida não for "Encerrar".
3. A cada repetição do laço:
   - o menu com as 11 opções é exibido na tela;
   - o programa lê a opção escolhida pelo usuário (`Input opcao`);
   - uma cadeia de estruturas `If / Else` (uma para cada opção, de 1 a 11) verifica qual foi a opção selecionada e executa a operação correspondente;
   - se o valor digitado não corresponder a nenhuma opção válida (não estiver entre 1 e 11), o programa exibe a mensagem **"Opção inválida! Digite um número entre 1 e 11."**;
   - ao final da operação (ou da mensagem de erro), o fluxo volta automaticamente ao topo do laço `While`, reexibindo o menu — **exceto** quando a opção 11 é escolhida, pois nesse caso a condição do laço (`opcao <> 11`) passa a ser falsa e o programa é encerrado.
4. Ao sair do laço, o programa exibe a mensagem **"Programa encerrado."**.

Algumas operações (Divisão e Raiz Quadrada) possuem uma segunda camada de decisão interna, para tratar entradas inválidas (divisão por zero e raiz de número negativo) antes de realizar o cálculo.

## Estruturas utilizadas

| Estrutura | Onde é usada |
|---|---|
| **Variáveis** | `opcao` (Integer); `n1`, `n2`, `n3`, `resultado`, `base`, `expoente`, `raio`, `baseRet`, `alturaRet`, `celsius` (Real) |
| **Entrada de dados (`Input`)** | Leitura da opção do menu e dos valores numéricos de cada operação |
| **Saída de dados (`Output`)** | Exibição do menu, das mensagens de erro e dos resultados formatados |
| **Estrutura de repetição (`While`)** | Mantém o menu em execução até a opção "Encerrar" (11) ser escolhida |
| **Estruturas de decisão (`If`/`Else`)** | Identificam qual opção do menu foi escolhida (cadeia de 11 decisões) e tratam casos especiais (divisão por zero, raiz de número negativo, opção inválida) |
| **Atribuição (`Assign`)** | Cálculo do resultado de cada operação |
| **Funções internas do Flowgorithm** | `Sqrt()` (raiz quadrada) e a constante `pi` (área do círculo) |

