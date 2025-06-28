#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Definição dos pinos utilizados para LEDs, buzzers e botões
#define PIN_VERDE 11
#define PIN_AZUL 12
#define PIN_VERMELHO 13
#define PIN_BUZZER1 10
#define PIN_BUZZER2 21
#define PIN_BOTAO_A 5
#define PIN_BOTAO_B 6

// Handles para as tarefas para suspender/retomar
TaskHandle_t handle_tarefa_led = NULL;
TaskHandle_t handle_tarefa_buzzer = NULL;

// Variáveis para controle de debounce dos botões
uint32_t tempo_ultimo_botao_a = 0;
uint32_t tempo_ultimo_botao_b = 0;
const uint32_t atraso_antirruido = 200; // 200 ms de debounce

// Tarefa responsável por acionar os buzzers periodicamente
void tarefa_buzzer(void *parametros) {
    // Inicializa os pinos dos buzzers
    gpio_init(PIN_BUZZER1);
    gpio_set_dir(PIN_BUZZER1, GPIO_OUT);

    gpio_init(PIN_BUZZER2);
    gpio_set_dir(PIN_BUZZER2, GPIO_OUT);

    while (true) {
        // Liga ambos os buzzers por 100 ms
        gpio_put(PIN_BUZZER1, 1);
        gpio_put(PIN_BUZZER2, 1);
        vTaskDelay(pdMS_TO_TICKS(100));

        // Desliga ambos os buzzers por 900 ms
        gpio_put(PIN_BUZZER1, 0);
        gpio_put(PIN_BUZZER2, 0);
        vTaskDelay(pdMS_TO_TICKS(900));
    }
}

// Tarefa responsável por alternar as cores do LED RGB
void tarefa_led(void *parametros) {
    // Inicializa os pinos dos LEDs
    gpio_init(PIN_VERMELHO);
    gpio_init(PIN_VERDE);
    gpio_init(PIN_AZUL);

    gpio_set_dir(PIN_VERMELHO, GPIO_OUT);
    gpio_set_dir(PIN_VERDE, GPIO_OUT);
    gpio_set_dir(PIN_AZUL, GPIO_OUT);

    uint8_t cor_atual = 0; // 0: vermelho, 1: verde, 2: azul

    while (true) {
        // Apaga todos os LEDs
        gpio_put(PIN_VERMELHO, 0);
        gpio_put(PIN_VERDE, 0);
        gpio_put(PIN_AZUL, 0);

        // Acende o LED correspondente à cor atual
        switch(cor_atual) {
            case 0:
                gpio_put(PIN_VERMELHO, 1);
                break;
            case 1:
                gpio_put(PIN_VERDE, 1);
                break;
            case 2:
                gpio_put(PIN_AZUL, 1);
                break;
        }
        // Alterna para a próxima cor
        cor_atual = (cor_atual + 1) % 3;

        // Aguarda 500 ms antes de trocar a cor
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

