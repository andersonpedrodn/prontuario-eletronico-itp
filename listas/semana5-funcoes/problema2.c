#include <stdio.h>

int primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    printf("MAQUINA DE N°PRIMOS\n");
    for (int x = 2; x <= 50000; x++) {
        if (primo(x) && primo(x+2) && primo(x+6)) {
            printf("(%d, %d, %d)\n", x, x+2, x+6);
        }
    }


    return 0;
}