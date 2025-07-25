//
// Created by OSMAN on 22.07.2025.
//
#include "SensorReader.h"

SensorData sensorData;

double dummy_temperature[] = {22.7, 26.5, 25.9, 26.4, 22.8, 23.4, 24.4, 26.9, 21.0, 24.3};
double dummy_humidity[] = {71.5, 84.8, 93.6, 87.4, 80.4, 87.6, 61.3, 89.0, 81.3, 93.6};
double dummy_id[] = {0,1,2,3,4,5,6,7,8,9};

double get_temperature(int i_sensor) {
    return dummy_temperature[i_sensor];
}

double get_humidity(int j_sensor) {
    return dummy_humidity[j_sensor];
}

double get_id(int k_sensor) {
    return dummy_id[k_sensor];
}

SensorData get_sensor_data(int id){
    sensorData.temperature = get_temperature(id);;
    sensorData.humidity = get_humidity(id);
    sensorData.id = get_id(id);
    return sensorData;
}
