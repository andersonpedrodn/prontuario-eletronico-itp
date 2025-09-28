#include <stdio.h>

int main() {
    printf("ALBUM DE FIGURINHAS");
    int m, n;
    printf("\nDigite a quantidade total de figurinhas (m): ");
    scanf("%d", &m);
    printf("Digite a quantidade de figurinhas compradas (n): ");
    scanf("%d", &n);

    int figurinhas[1000];
    int possui[1001] = {0}; 

    printf("Digite os numeros das figurinhas compradas:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &figurinhas[i]);
        possui[figurinhas[i]] = 1; 
    }

    printf("Faltam as figurinhas: ");
    for (int i = 1; i <= m; i++) {
        if (!possui[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}