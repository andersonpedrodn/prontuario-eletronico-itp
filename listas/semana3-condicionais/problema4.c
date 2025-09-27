#include <stdio.h>

int main() {
    printf("--- JOKENPÔ ---\n");
    printf("Jogador nº1: Escolha uma opcao:\n");
    printf("P. Pedra\n");
    printf("A. Papel\n");
    printf("T. Tesoura\n");

    char escolha1;
    scanf(" %c", &escolha1);

    printf("Jogador nº2: Escolha uma opcao:\n");
    printf("P. Pedra\n");
    printf("A. Papel\n");
    printf("T. Tesoura\n");

    char escolha2;
    scanf(" %c", &escolha2);

    if (escolha1 == escolha2) {
        printf("Empate!\n");
    } else if ((escolha1 == 'P' && escolha2 == 'T') || (escolha1 == 'A' && escolha2 == 'P') || (escolha1 == 'T' && escolha2 == 'A')) {
        printf("Jogador nº1 venceu!\n");
    } else {
        printf("Jogador nº2 venceu!\n");
    }

    return 0;
}