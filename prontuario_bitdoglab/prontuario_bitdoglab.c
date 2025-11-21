#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h" 

// LED Azul para indicar status (ajuste para 11 ou 13 se sua placa for diferente)
#define LED_PIN 12 

int main() {
    // 1. Inicialização do Hardware
    stdio_init_all();

    // Configura o LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1); // Liga o LED

    // Inicializa o Display OLED
    ssd1306_init();
    ssd1306_clear();

    // 2. "Banco de Dados" Simulado (Hardcoded)
    // Como não temos teclado, já deixamos alguns pacientes prontos na memória
    char *nomes[] = {"Anderson", "Maria Silva", "Joao Santos"};
    int idades[] = {30, 45, 62};
    char *sintomas[] = {"Enxaqueca", "Febre Alta", "Tosse Seca"};
    int total_pacientes = 3;

    int i = 0; // Índice do paciente atual

    // 3. Loop Principal
    while (true) {
        // --- DESENHANDO NA TELA ---
        ssd1306_clear(); // Limpa a tela para o novo frame

        // Cabeçalho
        ssd1306_draw_string(15, 0, "PRONTUARIO"); 
        
        // Linha divisória (desenhada com caracteres '-')
        ssd1306_draw_string(0, 8, "---------------------");

        // Dados do Paciente Atual
        // Formatamos strings temporárias para desenhar números e textos juntos
        char buffer_nome[20];
        char buffer_idade[20];
        
        sprintf(buffer_nome, "Nome: %s", nomes[i]);
        sprintf(buffer_idade, "Idade: %d anos", idades[i]);

        ssd1306_draw_string(0, 20, buffer_nome);
        ssd1306_draw_string(0, 32, buffer_idade);
        ssd1306_draw_string(0, 44, "Sintoma:");
        ssd1306_draw_string(0, 54, sintomas[i]);

        // Envia tudo para o display
        ssd1306_show();

        // Log no Serial (para você ver no PC também)
        printf("Mostrando Paciente %d: %s\n", i+1, nomes[i]);

        // --- CONTROLE DO TEMPO ---
        // Espera 3 segundos lendo o paciente
        sleep_ms(3000);

        // Passa para o próximo paciente
        i++;
        if (i >= total_pacientes) {
            i = 0; // Volta para o primeiro se chegar no fim
        }
        
        // Pisca o LED para mostrar que trocou
        gpio_put(LED_PIN, 0);
        sleep_ms(100);
        gpio_put(LED_PIN, 1);
    }

    return 0;
}