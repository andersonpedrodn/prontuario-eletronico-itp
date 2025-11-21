#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <string.h>
#include <ctype.h>
#include "font.h" // Inclui nossa fonte

#define SSD1306_HEIGHT 64
#define SSD1306_WIDTH 128
#define SSD1306_I2C_ADDR _u(0x3C)

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

static uint8_t ssd1306_buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

void ssd1306_send_cmd(uint8_t cmd) {
    uint8_t buf[2] = {0x00, cmd};
    i2c_write_blocking(I2C_PORT, SSD1306_I2C_ADDR, buf, 2, false);
}

void ssd1306_send_data(uint8_t *data, int count) {
    uint8_t buf[count + 1];
    buf[0] = 0x40;
    memcpy(buf + 1, data, count);
    i2c_write_blocking(I2C_PORT, SSD1306_I2C_ADDR, buf, count + 1, false);
}

void ssd1306_init() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    uint8_t cmds[] = {
        0xAE, 0xD5, 0x80, 0xA8, 0x3F, 0xD3, 0x00, 0x40, 0x8D, 0x14, 0x20, 0x00, 
        0xA1, 0xC8, 0xDA, 0x12, 0x81, 0xCF, 0xD9, 0xF1, 0xDB, 0x40, 0xA4, 0xA6, 0x2E, 0xAF
    };
    for (int i = 0; i < sizeof(cmds); i++) ssd1306_send_cmd(cmds[i]);
}

void ssd1306_show() {
    for (int i = 0; i < 8; i++) {
        ssd1306_send_cmd(0xB0 + i);
        ssd1306_send_cmd(0x00);
        ssd1306_send_cmd(0x10);
        ssd1306_send_data(&ssd1306_buffer[i * SSD1306_WIDTH], SSD1306_WIDTH);
    }
}

void ssd1306_clear() {
    memset(ssd1306_buffer, 0, sizeof(ssd1306_buffer));
}

// Função para desenhar um caractere na posição X, Y
void ssd1306_draw_char(int x, int y, char c) {
    if (x > SSD1306_WIDTH - 5 || y > SSD1306_HEIGHT - 8) return;

    // Converte para maiúsculo e ajusta índice para nossa tabela font.h (começa no espaço ' ')
    c = toupper(c);
    int idx = c - 32;
    if (idx < 0 || idx >= 59) idx = 0; // Se não tiver na fonte, desenha espaço

    for (int i = 0; i < 5; i++) {
        uint8_t line = font[idx][i];
        for (int j = 0; j < 8; j++) {
            if (line & (1 << j)) {
                int byte_idx = (x + i) + ((y + j) / 8) * SSD1306_WIDTH;
                ssd1306_buffer[byte_idx] |= (1 << ((y + j) % 8));
            }
        }
    }
}

// Função para escrever texto completo
void ssd1306_draw_string(int x, int y, char *str) {
    int cursor_x = x;
    while (*str) {
        ssd1306_draw_char(cursor_x, y, *str);
        cursor_x += 6; // Avança 6 pixels (5 da letra + 1 espaço)
        str++;
    }
}

#endif