#include <stdio.h>
#include <stdlib.h>

int main() {
    float peso, altura, imc;
    printf("Por favor, digite o seu peso (ex:80.0): ");
    scanf("%f", &peso);
    printf("Por favor, digite a sua altura (ex:1.80): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);
    printf("O seu peso é: %.2f kg e sua altura é: %.2f m. \n", peso, altura);
    printf("O seu IMC é: %.2f\n", imc);

    if (imc <= 18.5) {
        printf("Seu IMC indica que você está abaixo do peso saudável.");
    } else if (imc > 18.5 && imc <= 24.9) {
        printf("Seu IMC indica que você está com um peso normal.");
    } else if (imc > 24.9 && imc <= 29.9){
        printf("Seu IMC indica que você está com sobrepeso");
    } else {
        printf("Seu IMC indica que você está com Obesidade");
    }
    return 0;

    
}