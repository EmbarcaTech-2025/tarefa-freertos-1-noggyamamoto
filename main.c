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