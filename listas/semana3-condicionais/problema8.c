#include <stdio.h>

int main() {
    int a, b, c;
    printf("Digite o valor de a");
    scanf("%d", &a);
    printf("Digite o valor de b");
    scanf("%d", &b);
    printf("Digite o valor de c");  
    scanf("%d", &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("Os valores formam um triangulo\n");
        if (a == b && b == c) {
            printf("Triangulo Equilatero\n");
        } else if (a == b || a == c || b == c) {
            printf("Triangulo Isosceles\n");
        } else {
            printf("Triangulo Escaleno\n");
        }
    } else {
        printf("Os valores nao formam um triangulo\n");
    }
    return 0;   
}