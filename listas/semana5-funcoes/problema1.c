#include <stdio.h>

void imprime_24h(int hora, int minuto);
void imprime_12h(int hora, int minuto);
void soma_tempo(int *hora, int *minuto, int acrescimo);

int main() {
    int hora, minuto, formato;
    printf("--- HORARIOS DAS RONDAS ---\n");
    printf("Digite a hora, minuto e formato (0 para 24h, 1 para 12h): ");
    scanf("%d %d %d", &hora, &minuto, &formato);


    int acrescimos[3] = {70, 130, 125}; 

    
    if (formato == 0)
        imprime_24h(hora, minuto);
    else
        imprime_12h(hora, minuto);

 
    for (int i = 0; i < 3; i++) {
        soma_tempo(&hora, &minuto, acrescimos[i]);
        if (formato == 0)
            imprime_24h(hora, minuto);
        else
            imprime_12h(hora, minuto);
    }

    return 0;
}

void imprime_24h(int hora, int minuto) {
    printf("%02d:%02d\n", hora, minuto);
}

void imprime_12h(int hora, int minuto) {
    int h = hora % 12;
    if (h == 0) h = 12;
    printf("%02d:%02d %s\n", h, minuto, hora < 12 || hora == 24 ? "AM" : "PM");
}


void soma_tempo(int *hora, int *minuto, int acrescimo) {
    *minuto += acrescimo;
    while (*minuto >= 60) {
        *minuto -= 60;
        (*hora)++;
    }
    while (*hora >= 24) {
        *hora -= 24;
    }
}
