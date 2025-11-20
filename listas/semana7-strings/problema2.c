#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char placa[20]; 
    int tamanho;

    // Lê a placa
    scanf("%s", placa);
    tamanho = strlen(placa);

    if (tamanho == 8)
    {
        // Verifica formato LLL-AAAA
        if (isupper(placa[0]) && isupper(placa[1]) && isupper(placa[2]) &&
            placa[3] == '-' &&
            isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]))
        {
            printf("brasileiro\n");
        }
        else
        {
            printf("inválido\n");
        }
    }
    else if (tamanho == 7)
    {
        if (isupper(placa[0]) && isupper(placa[1]) && isupper(placa[2]) &&
            isdigit(placa[3]) &&
            isupper(placa[4]) &&
            isdigit(placa[5]) && isdigit(placa[6]))
        {
            printf("mercosul\n");
        }
        else
        {
            printf("inválido\n");
        }
    }
    else
    {
        printf("inválido\n");
    }

    return 0;
}