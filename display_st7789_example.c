#include <stdlib.h>
#include "pico/stdlib.h"
#include "inc/st7789/st7789.h"

#define COLOR_BLACK 0x0000
#define COLOR_GREEN 0x07E0

// Configuração do display 
const struct st7789_config lcd_config = {
    .spi = spi0,
    .gpio_din = PICO_DEFAULT_SPI_TX_PIN,
    .gpio_clk = PICO_DEFAULT_SPI_SCK_PIN,
    .gpio_cs = -1,
    .gpio_dc  = 4,
    .gpio_rst = 20
};

// Dimensões do display
const int lcd_width = 240;
const int lcd_height = 320;

int main()
{
    // Inicializa o display 
    st7789_init(&lcd_config, lcd_width, lcd_height);

    // Fundo escuro
    st7789_fill(COLOR_BLACK);

    // Escreve um texto no display
    st7789_draw_text(10, 10, "HELLO WORLD!", COLOR_GREEN, COLOR_BLACK, 3);

    while (true) {
        tight_loop_contents();
    }
}