#include "pico/stdlib.h"    
#include "hardware/timer.h" 
#include <stdio.h>          

// Definição dos pinos dos LEDs
#define LED2_PIN 13
#define LED1_PIN 12 
#define LED3_PIN 11 

// Função de callback do temporizador para alternar os LEDs sequencialmente.
bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado = 0;
    
    // Desliga todos os LEDs antes de acender o próximo
    gpio_put(LED1_PIN, 0);
    gpio_put(LED2_PIN, 0);
    gpio_put(LED3_PIN, 0);
    
    // Liga o LED correspondente ao estado atual
    switch (estado) {
        case 0:
            gpio_put(LED1_PIN, 1);
            printf("LED azul ligado\n");
            break;
        case 1:
            gpio_put(LED2_PIN, 1);
            printf("LED vermelho ligado\n");
            break;
        case 2:
            gpio_put(LED3_PIN, 1);
            printf("LED verde ligado\n");
            break;
    }
    
    estado = (estado + 1) % 3;
    
    return true;
}

int main() {
    stdio_init_all();
    
    // Inicializa os pinos GPIO e os define como saída.
    gpio_init(LED1_PIN);
    gpio_init(LED2_PIN);
    gpio_init(LED3_PIN);
    gpio_set_dir(LED1_PIN, GPIO_OUT);
    gpio_set_dir(LED2_PIN, GPIO_OUT);
    gpio_set_dir(LED3_PIN, GPIO_OUT);
    
    struct repeating_timer timer;
    
    // Temporizador em 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); 
    
    while (true) {
      
    }
  return 0;
}