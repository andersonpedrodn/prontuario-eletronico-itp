#include <stdio.h>

int main() {
    int m, n;
    int i, j;
    int acertos = 0;

    // m = qtd sorteados, n = qtd apostados
    scanf("%d %d", &m, &n);

    // Como m e n são variáveis lidas em tempo de execução, 
    // usamos VLA (Variable Length Array) permitido no C99
    int sorteados[m];
    int apostados[n];

    // 2. Leitura dos números sorteados
    for (i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }

    // 3. Leitura dos números apostados
    for (i = 0; i < n; i++) {
        scanf("%d", &apostados[i]);
    }

    // 4. Verificação de Acertos (Loop Aninhado)
    
    // Loop Externo: Para cada número que eu apostei...
    for (i = 0; i < n; i++) {
        
        // Loop Interno: ...eu verifico em toda a lista de sorteados se ele existe.
        for (j = 0; j < m; j++) {
            
            // Se o número da minha aposta for igual a um número sorteado
            if (apostados[i] == sorteados[j]) {
                acertos++; // Conta um acerto
                break; // Para de procurar este número, já achamos! Vai para o próximo da aposta.
            }
        }
    }

    // 5. Saída
    printf("%d\n", acertos);

    return 0;
}