#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lwip/netif.h"
#include "lwip/tcp.h"
#include "lwip/pbuf.h"
#include "button_monitor.h"

#define SERVER_IP "192.168.1.196"        // IP do servidor
#define SERVER_PORT 5000    // Número da porta que o servidor está rodando
#define SERVER_PATH "/dados"      // Nome da rota

err_t sent_callback(void *arg, struct tcp_pcb *tpcb, u16_t len);
void send_data_to_server(const char *path, char *request_body, const char *type_method);
void create_request(ButtonStates btn_states, float temperature);

#endif