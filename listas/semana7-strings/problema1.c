#include <stdio.h>
#include <string.h>

int main()
{

    char campo[21];
    int indice;
    int bombas = 0;
    int tamanho;

    scanf("%s", campo);
    scanf("%d", &indice);

    tamanho = strlen(campo);

    if (campo[indice] == 'x')
    {

        printf("bum!\n");
    }
    else
    {

        if (indice > 0 && campo[indice - 1] == 'x')
        {
            bombas++;
        }

        if (indice < tamanho - 1 && campo[indice + 1] == 'x')
        {
            bombas++;
        }

        printf("%d\n", bombas);
    }

    return 0;
}