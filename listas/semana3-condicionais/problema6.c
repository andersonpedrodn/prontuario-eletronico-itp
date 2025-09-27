#include <stdio.h>

int main() {
    char febre, dorDeCabeca, tosse, dorNoCorpo;
    printf("DIAGNOSTICO MEDICO\n");
    
    printf("Febre (s/n): ");
    scanf(" %c", &febre);
    printf("Dor de cabeça (s/n): ");
    scanf(" %c", &dorDeCabeca);
    printf("Tosse (s/n): ");
    scanf(" %c", &tosse);
    printf("Dor no corpo (s/n): ");
    scanf(" %c", &dorNoCorpo);

     if (febre == 'S' && dorDeCabeca == 'S' && dorNoCorpo == 'S') {
        printf("Possivel gripe\n");
    } else if (tosse == 'S' && febre == 'S') {
        printf("Possivel resfriado\n");
    } else if (dorDeCabeca == 'S' && febre == 'N' && dorNoCorpo == 'N' && tosse == 'N') {
        printf("Possivel enxaqueca\n");
    } else if (febre == 'S' && dorDeCabeca == 'N' && dorNoCorpo == 'N' && tosse == 'N') {
        printf("Consulte um medico\n");
    } else if (febre == 'N' && dorDeCabeca == 'N' && dorNoCorpo == 'N' && tosse == 'N') {
        printf("Voce parece estar bem\n");
    } else {
        printf("Consulte um medico para avaliacao\n");
    }

    return 0;
}