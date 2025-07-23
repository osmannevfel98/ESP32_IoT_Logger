//
// Created by OSMAN on 22.07.2025.
//
#include <stdio.h>
#include "../inc/Logger.h"
#include "../utils/SensorReader.h"

void log_params(int id) {
    printf("LOG - Temp: %.1f\n", get_sensor_data(id).temperature);
    printf("LOG - Humd: %.1f\n", get_sensor_data(id).humidity);
    printf("LOG - Id: %d\n\n", get_sensor_data(id).id);
}

int get_log_level(int id){
    if (id < 0 || id >= 10)
        return 2; // LOG_ERROR
    else if (id >= 0 && id < 10)
        return 0; // LOG_INFO
    else
        return 1; // LOG_WARN
}

void log_message(enum LogLevel level){
    switch(level){
        case 0:
            printf("[LOG_INFO]\n");
            break;
        case 1:
            printf("[LOG_WARN]\n");
            break;
        case 2:
            printf("[LOG_ERROR]\n");
            break;
    }
}