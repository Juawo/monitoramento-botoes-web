#include "web_server.h"

err_t sent_callback(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
    printf("Dados enviados com sucesso!\n");
    tcp_close(tpcb);
    return ERR_OK;
}

void send_data_to_server(const char *path, char *request_body, const char *type_method)
{
    struct tcp_pcb *pcb = tcp_new();
    if (!pcb)
    {
        printf("Erro ao criar pcb\n");
        return;
    }

    ip_addr_t server_ip;
    server_ip.addr = ipaddr_addr(SERVER_IP);

    if (tcp_connect(pcb, &server_ip, SERVER_PORT, NULL) != ERR_OK)
    {
        printf("Erro ao conectar com o servidor!\n");
        tcp_abort(pcb);
        return;
    }

    char request[521];
    snprintf(request, strlen(request),
             "%s %s HTTP/1.1\r\n"
             "Host: %s \r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %d\r\n"
             "\r\n"
             "%s",
             type_method, path, strlen(request), request_body);
    
    tcp_sent(pcb, sent_callback);

    if(tcp_write(pcb, request, strlen(request), TCP_WRITE_FLAG_COPY) != ERR_OK)
    {
        printf("Erro ao enviar dados!\n");
        tcp_abort(pcb);
        return;
    }

    if(tcp_output(pcb) != ERR_OK)
    {
        printf("Erro ao enviar dados (tcp_output) !\n");
        tcp_abort(pcb);
        return;
    }
}

void create_request(ButtonStates btn_states, float temperature)
{
    const char *type_method = "POST";
    const char *path = SERVER_PATH;
    char json_request[256];

    snprintf(json_request, sizeof(json_request),
             "{ \"temperature\" : %f, "
             "\"btn_a_state\" : %d, "
             "\"btn_b_state\" : %d }",
             temperature, btn_states.btn_a_state, btn_states.btn_b_state);

    send_data_to_server(path, json_request, type_method);
}
