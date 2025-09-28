#include <stdio.h>

int main()
{
    int i;
    int n;
    printf("---CONSTRUCAO DA PONTE---\n");
    printf("\n Digite o n° de terros (maximo 30): ");
    scanf("%d", &n);

    if (n > 30 || n < 2)
    {
        printf("Numero de terrnos invalido. Deve ser entre 2 e 30.\n");
        return 1;
    }
    int altura[n];

    {
        printf("Digite as alturas dos terrenos (separadas por espaco):\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &altura[i]);
        }

        int alturaMax = altura[0];
        for (i = 0; i < n - 1; i++){
            if (altura[i + 1] > alturaMax){
                alturaMax = altura[i];
            }
        }

        int pico = -1;
        int ultimoPico = -1;
        for (i = 0; i < n; i++){
            if (altura[i] == alturaMax){
    
                if (ultimoPico != -1){
                    int largura = pico - ultimoPico;
                    int alturaPonte = (altura[ultimoPico] < altura[pico]) ? altura[ultimoPico] : altura[pico];
                    int areaPonte = largura * alturaPonte;
                    printf("Ponte entre terrenos %d e %d: Largura = %d, Altura = %d, Area = %d\n", ultimoPico + 1, pico + 1, largura, alturaPonte, areaPonte);
                }
                ultimoPico = pico;
            }
        }
    }
    return 0;
}