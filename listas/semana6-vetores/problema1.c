#include <stdio.h>

int gabarito[20], aluno[20];

int main() {
    printf("---CORRECAO DO ENEM---\n");
    int n;
    printf("Digite o numero de questoes (maximo 20): ");
    scanf("%d", &n);

    printf("Digite as respostas do gabarito (separadas por espaco): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }

    printf("Digite as respostas do aluno (separadas por espaco): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &aluno[i]);
    }
    int acertos = 0;
    for (int i = 0; i < n; i++) {
        if (gabarito[i] == aluno[i]) {
            acertos++;
        }
    }
    if (acertos == 1)
        printf("1 acerto\n");
    else
        printf("%d acertos\n", acertos);
    return 0;
}