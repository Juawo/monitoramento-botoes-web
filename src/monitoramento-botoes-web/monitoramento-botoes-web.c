#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "button_monitor.h"
#include "temperature_sensor.h"
#include "web_server.h"
#include "wifi_connection.h"

int main()
{
    stdio_init_all();
    sleep_ms(1000);

    // Inicializando os botões, sensor de temperatura e a placa de Wi-Fi
    setup_buttons();
    setup_wifi();
    setup_temperature_sensor();

    ButtonStates btn_states;
    float temperature;

    while (true)
    {
        // Lendo e armazenando estados dos botões
        btn_states = read_button_states();

        // Lendo e armazenando estado do sensor de temperatura
        temperature = read_temperature_sensor();

        // Criando requisição para enviar o estado do botões e da temperatura do sensor para o servidor
        create_request(btn_states, temperature);

        // Aguardando 1 segundo para repetir o processo
        sleep_ms(1000);
    }
}
