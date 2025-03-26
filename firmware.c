#include "stm32f1xx_hal.h"
#include "onewire.h"  // Librería para DS18B20 (descárgala de GitHub)

#define MOSFET_PIN GPIO_PIN_0
#define MOSFET_PORT GPIOA
#define TEMP_SETPOINT 25.0f  // Temperatura deseada (25°C)
#define HYSTERESIS 0.5f      // Margen para evitar oscilaciones (+/-0.5°C)

int main(void) {
    HAL_Init();
    SystemClock_Config();
    
    // Configura el pin del MOSFET como salida
    GPIO_InitTypeDef gpio = {0};
    gpio.Pin = MOSFET_PIN;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(MOSFET_PORT, &gpio);
    
    OneWire_Init(PA1);  // Inicializa el DS18B20 en PA1
    
    while (1) {
        float temp = OneWire_ReadTemp();  // Lee temperatura
        
        // Control ON/OFF con histéresis
        if (temp < TEMP_SETPOINT - HYSTERESIS) {
            HAL_GPIO_WritePin(MOSFET_PORT, MOSFET_PIN, GPIO_PIN_SET);  // ENCIENDE
        } 
        else if (temp > TEMP_SETPOINT + HYSTERESIS) {
            HAL_GPIO_WritePin(MOSFET_PORT, MOSFET_PIN, GPIO_PIN_RESET);  // APAGA
        }
        
        HAL_Delay(1000);  // Espera 1 segundo entre lecturas
    }
}
