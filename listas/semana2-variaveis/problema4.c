#include <stdio.h>

int main() {
    int numeroUm, numeroDois;
    printf("---Operacoes Aritmeticas Basicas ---\n");
    printf("Digite dois numeros inteiros separados por espaco (ex: 10 3): ");
    scanf("%d %d", &numeroUm, &numeroDois);

    int soma = numeroUm + numeroDois;
    int diferenca = numeroUm - numeroDois;
    int produto = numeroUm * numeroDois;
    float divisao = (float)numeroUm/numeroDois;
    int resto = numeroUm % numeroDois;
    float media = (float)(numeroUm + numeroDois) / 2.0;

    printf("\n Resultados para os numeros %d e %d: \n", numeroUm, numeroDois);
    printf("Soma: %d\n", soma);
    printf("Divisao Real: %.2f\n", divisao);
    printf("Produto: %d\n", produto);
    printf("Diferenca: %d\n", diferenca);
    printf("Media Aritmetica: %.2f\n", media);
    printf("Resto da Divisao: %d\n", resto);

    return 0;
}