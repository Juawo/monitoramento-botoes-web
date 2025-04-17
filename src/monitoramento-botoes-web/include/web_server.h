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

err_t tcp_server_env_data();

#endif