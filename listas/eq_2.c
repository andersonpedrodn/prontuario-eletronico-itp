#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c; 
    float delta, r1, r2;
    
    printf("Digite a b c: \n");
    scanf("%d %d %d", &a, &b, &c);
    
    delta = (b * b) - (4 * a * c);

    r1 = (-b + sqrt(delta)) / (2 * a);
    r2 = (-b - sqrt(delta)) / (2 * a);

    printf("Raíz 1: %f\n", r1);
    printf("Raíz 2: %f\n", r2);

    return 0;
}