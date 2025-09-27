#include <stdio.h>

int main() {
    float consumo_kWh, taxa, total;
    char tipoConsumidor;

    printf("--->>CALCULO DA CONTA DE ENERGIA ELETRICA<<---\n");
    printf("Digite o tipo de consumidor (R para Residencial, C para Comercial, I para Industrial): ");
    scanf(" %c", &tipoConsumidor);
    printf("Digite o consumo em kWh: ");
    scanf("%f", &consumo_kWh);

    switch (tipoConsumidor) {
        case 'R':
            taxa = 0.60;
            break;
        case 'C':
            taxa = 0.48;
            break;
        case 'I':
            taxa = 1.29;
            break;
        default:
            printf("Tipo de consumidor invalido.\n");
            return 1;
    }

    total = (consumo_kWh * taxa) + 15.00; 
    printf("O valor total da conta de energia e: R$ %.2f\n", total);

    return 0;
}