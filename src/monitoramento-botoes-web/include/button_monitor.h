#ifndef BUTTON_MONITOR_H
#define BUTTON_MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define BTN_A 05
#define BTN_B 06

typedef struct ButtonStates
{
    bool btn_a_state;
    bool btn_b_state;
} ButtonStates;

void setup_buttons();
ButtonStates read_button_states();

#endif