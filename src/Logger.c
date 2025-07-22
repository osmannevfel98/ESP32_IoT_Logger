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
    printf("Temperature: %.1f\n", temp);
    printf("Humidity: %.1f\n", hum);
}