#include <stdio.h>

int main() {
    float valorCompra, valorDesconto, valorFinal;
    int porcentagemDesconto = 9;
    printf("---CALCULADORA DE DESCONTO---\n");
    printf("Digite o valor do produto: ");
    scanf("%f", &valorCompra);

    if (valorCompra <= 100.00) {
        porcentagemDesconto = 0;
    } else if (valorCompra <= 500.00) {
        porcentagemDesconto = 10;
    } else if (valorCompra <= 1000.00) {
        porcentagemDesconto = 15;
    } else {
        porcentagemDesconto = 20;
    }
    
    valorDesconto = valorCompra * (porcentagemDesconto / 100.0);
    valorFinal = valorCompra - valorDesconto;

    printf("\n--RESUMO DA COMPRA ---\n");
    printf("Valor da compra: R$ %.2f\n", valorCompra);
    printf("Porcentagem de desconto: %.0f%%\n", valorDesconto);
    printf("Valor do desconto: R$ %.2f\n", valorDesconto);
    printf("Valor final: R$ %.2f\n", valorFinal);

    return 0;
}
