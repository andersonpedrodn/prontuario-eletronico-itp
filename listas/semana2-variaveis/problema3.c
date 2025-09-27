#include <stdio.h>
#include <math.h>

int main(){
    double capital,  taxa, montante;
    int tempo;
    printf("---Calculadora de Juros Compostos---\n");
    printf("Digite o capital inicial (ex: 1000): ");
    scanf("%lf", &capital);
    printf("Digite a taxa de juros (%% ao mes, ex: 2):");
    scanf("%lf", &taxa);
    printf("Digite o tempo em meses (ex: 12):");
    scanf("%d", &tempo);

    double taxaDecimal = taxa / 100.0;

    montante = capital * pow(1 + taxaDecimal, tempo);

    printf("\n Apos %d meses, o montante sera de: R$ %.2lf\n", tempo, montante);

    return 0;
}