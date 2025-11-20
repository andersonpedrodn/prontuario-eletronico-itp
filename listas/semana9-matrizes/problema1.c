#include <stdio.h>

int main()
{
    int M, N;
    int i, j;
    int ferteis_irrigados = 0;
    int ferteis_secos = 0;

    scanf("%d %d", &M, &N);

    int campo[M][N];
    int molhado[M][N];

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            molhado[i][j] = 0;
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &campo[i][j]);
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (campo[i][j] == 2)
            {
                if (i > 0)
                    molhado[i - 1][j] = 1;

                if (i < M - 1)
                    molhado[i + 1][j] = 1;

                if (j > 0)
                    molhado[i][j - 1] = 1;

                if (j < N - 1)
                    molhado[i][j + 1] = 1;
            }
        }
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (campo[i][j] == 1)
            {
                if (molhado[i][j] == 1)
                {
                    ferteis_irrigados++;
                }
                else
                {
                    ferteis_secos++;
                }
            }
        }
    }

    printf("%d %d\n", ferteis_irrigados, ferteis_secos);

    return 0;
}