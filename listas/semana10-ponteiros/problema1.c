#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tamanho)
{
    int *v = (int *)malloc(tamanho * sizeof(int));
    if (v == NULL)
    {
        printf("Erro de memoria!\n");
        exit(1);
    }
    return v;
}

void lerVetor(int *v, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &v[i]);
    }
}

void somaVetores(int *v1, int *v2, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int soma = v1[i] + v2[i];
        printf("%d ", soma);
    }
    printf("\n");
}

int main()
{
    int n1, n2;
    int *v1, *v2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    v1 = alocarVetor(n1);
    lerVetor(v1, n1);

    v2 = alocarVetor(n2);
    lerVetor(v2, n2);

    if (n1 != n2)
    {
        printf("dimensoes incompativeis\n");
    }
    else
    {

        somaVetores(v1, v2, n1);
    }

    free(v1);
    free(v2);

    return 0;
}