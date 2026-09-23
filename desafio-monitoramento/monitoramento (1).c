/*
 * Projeto: Monitoramento de Temperatura
 * Disciplina: (coloque aqui o nome da disciplina)
 * Profa. Karla Sartin
 * Aluno(a): (coloque aqui o seu nome)
 */

#include <stdio.h>

#define TEMP_MIN     -50.0
#define TEMP_MAX     150.0
#define LIMITE_MIN     0.0
#define LIMITE_MAX   100.0
#define ENCERRAR    -999.0
#define MAX_SEGUIDAS     3

/* Descarta o que sobrou no teclado (ex.: letras digitadas) */
void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {
    float limite, temp;
    float soma = 0.0, maior = 0.0, menor = 0.0;
    int qtdLeituras = 0, qtdAcima = 0, consecutivas = 0;
    int lido, valido, encerrar = 0;

    setbuf(stdout, NULL); /* mostra o texto na tela na hora */

    printf("=== MONITORAMENTO DE TEMPERATURA ===\n\n");

    /* do...while: pede o limite ate ser valido */
    do {
        printf("Digite o limite de temperatura (%.0f a %.0f graus Celsius): ",
               LIMITE_MIN, LIMITE_MAX);
        lido = scanf("%f", &limite);
        if (lido == EOF) {
            return 1;
        }

        valido = (lido == 1 && limite >= LIMITE_MIN && limite <= LIMITE_MAX);
        if (!valido) {
            printf("Limite invalido! Tente novamente.\n");
        }
        limparEntrada();
    } while (!valido);

    printf("\nLimite definido: %.1f graus Celsius\n", limite);
    printf("Digite as temperaturas em graus Celsius (-999 para encerrar).\n\n");

    /* while: testa ANTES de cada leitura se ainda deve continuar */
    while (consecutivas < MAX_SEGUIDAS && !encerrar) {

        /* do...while: pede a temperatura ate ser valida */
        do {
            printf("Leitura %d: ", qtdLeituras + 1);
            lido = scanf("%f", &temp);
            if (lido == EOF) {
                return 1;
            }

            if (lido == 1 && temp == ENCERRAR) {
                valido = 1;
                encerrar = 1;
            } else {
                valido = (lido == 1 && temp >= TEMP_MIN && temp <= TEMP_MAX);
                if (!valido) {
                    printf("Temperatura invalida! Use valores entre %.0f e %.0f graus Celsius.\n",
                           TEMP_MIN, TEMP_MAX);
                }
            }
            limparEntrada();
        } while (!valido);

        if (encerrar) {
            printf("\nMonitoramento encerrado pelo usuario.\n");
        } else {
            qtdLeituras++;
            soma += temp;

            if (qtdLeituras == 1 || temp > maior) {
                maior = temp;
            }
            if (qtdLeituras == 1 || temp < menor) {
                menor = temp;
            }

            /* Conta leituras seguidas acima do limite; zera se a sequencia quebrar */
            if (temp > limite) {
                qtdAcima++;
                consecutivas++;
                printf("  ALERTA: acima do limite! (%d seguida(s))\n", consecutivas);
            } else {
                consecutivas = 0;
                printf("  Temperatura normal.\n");
            }
        }
    }

    if (consecutivas >= MAX_SEGUIDAS) {
        printf("\n*** %d temperaturas consecutivas acima do limite! ***\n", MAX_SEGUIDAS);
        printf("*** Monitoramento encerrado automaticamente. ***\n");
    }

    /* Relatorio final */
    printf("\n========== RELATORIO FINAL ==========\n");
    if (qtdLeituras > 0) {
        printf("Quantidade de leituras: %d\n", qtdLeituras);
        printf("Media das temperaturas: %.2f graus Celsius\n", soma / qtdLeituras);
        printf("Maior temperatura:      %.2f graus Celsius\n", maior);
        printf("Menor temperatura:      %.2f graus Celsius\n", menor);
        printf("Leituras acima do limite: %d (%.2f%%)\n",
               qtdAcima, (qtdAcima * 100.0) / qtdLeituras);
    } else {
        printf("Nenhuma leitura valida foi registrada.\n");
    }
    printf("=====================================\n");

    return 0;
}
