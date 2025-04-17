#include "web_server.h"

err_t sent_callback(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
    printf("Dados enviados com sucesso!\n");
    tcp_close(tpcb);
    return ERR_OK;
}

void send_data_to_server(const char *path, char *request_body, const char *type_method)
{
    // Implementar lógica de envio de dados para o servidor!
}

void create_request(ButtonStates btn_states, float temperature)
{
    const char *type_method = "POST";
    const char *path = SERVER_PATH;
    const json_request[256];

    snprintf(json_request, sizeof(json_request),
        "{ \"temperature\" : %f, "
        "\"btn_a_state\" : %d, "
        "\"btn_b_state\" : %d }", 
        temperature, btn_states.btn_a_state, btn_states.btn_b_state);

    send_data_to_server(path, json_request, type_method);
}
