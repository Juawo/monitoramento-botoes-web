#ifndef TEMPERATURE_SENSOR_H
#define TEMEPERATURE_SENSOR_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>
#include <stdlib.h>

void setup_temperature_sensor();
float read_temperature_sensor();

#endif