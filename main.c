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