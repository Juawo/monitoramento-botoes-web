#include "button_monitor.h"

void setup_buttons()
{
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
}

ButtonStates read_button_states()
{
    ButtonStates btn_states;
    // Pegando o valor ao contrário, porque está em Pull-Up, ou seja, solto é 1 e pressionado é 0, para facilitar a lógica invertemos a leitura aqui.
    btn_states.btn_a_state = !gpio_get(BTN_A); 
    btn_states.btn_b_state = !gpio_get(BTN_B);
    return btn_states;
}