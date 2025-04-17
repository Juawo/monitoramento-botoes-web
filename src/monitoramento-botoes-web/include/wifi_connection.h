#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define WIFI_SSID "NOME_DA_REDE"
#define WIFI_PASSWORD "SENHA_DA_REDE" // Caso a rede não possua senha, coloque NULL

void setup_wifi();

#endif