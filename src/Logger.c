//
// Created by OSMAN on 22.07.2025.
//
#include <stdio.h>
#include "../inc/Logger.h"
#include "../utils/SensorReader.h"

double temp = 0;
double hum = 0;

void log_params(int i_sensor, int j_sensor) {
    temp = get_temperature(i_sensor);
    hum = get_humidity(j_sensor);
    printf("LOG - Temp: %.1f\n", temp);
    printf("LOG - Humd: %.1f\n\n", hum);
}