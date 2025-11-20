#include <stdio.h>

int main()
{
    int m, n;
    int i, j;
    int acertos = 0;

    scanf("%d %d", &m, &n);

    int sorteados[m];
    int apostados[n];

    for (i = 0; i < m; i++)
    {
        scanf("%d", &sorteados[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &apostados[i]);
    }

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < m; j++)
        {

            if (apostados[i] == sorteados[j])
            {
                acertos++;
                break;
            }
        }
    }

    printf("%d\n", acertos);

    return 0;
}