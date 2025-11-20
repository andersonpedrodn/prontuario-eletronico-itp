#include <stdio.h>
#include <string.h>

int main()
{
    char nome_alvo[20];
    char relatorio[1001];
    char palavra_atual[30];

    int total_aulas = 0;
    int presencas = 0;

    scanf("%s", nome_alvo);

    getchar();

    fgets(relatorio, 1005, stdin);

    relatorio[strcspn(relatorio, "\n")] = '\0';

    int tamanho_relatorio = strlen(relatorio);
    int j = 0;

    for (int i = 0; i <= tamanho_relatorio; i++)
    {

        if (relatorio[i] == ' ' || relatorio[i] == '\0')
        {

            if (j > 0)
            {
                palavra_atual[j] = '\0';

                if (strlen(palavra_atual) == 5 && palavra_atual[2] == '/')
                {
                    total_aulas++;
                }
                else
                {
                    if (strcmp(palavra_atual, nome_alvo) == 0)
                    {
                        presencas++;
                    }
                }

                j = 0;
            }
        }
        else
        {
            palavra_atual[j] = relatorio[i];
            j++;
        }
    }

    int faltas = total_aulas - presencas;
    printf("%d\n", faltas);

    return 0;
}