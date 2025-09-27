#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media, mediaFinal, notaFinal;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("A media das notas e: %.2f\n", media);

    if (media >= 7.0) {
        printf("Aprovado");
    } else if (media >= 4.0 && media < 7.0) { 
        printf("Recuperacao\n");     
        mediaFinal = 10 - media;
        printf("O aluno precisa de no minimo: %.2f na prova final para ser aprovado.\n", mediaFinal);
        
    } else {
        printf("Reprovado\n");
    }

   
    return 0;
}