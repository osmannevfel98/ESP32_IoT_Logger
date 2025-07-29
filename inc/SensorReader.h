//
// Created by OSMAN on 22.07.2025.
//

#ifndef SENSORREADER_H
#define SENSORREADER_H

typedef struct {
    float temperature;
    float humidity;
    int id;
} SensorData;

SensorData get_sensor_data(int id);

#endif // SENSORREADER_H

/*
 * test code
 *
#ifndef SENSORREADER_H
#define SENSORREADER_H

typedef struct {
    double temperature;
    double humidity;
    int id;
} SensorData;

double get_temperature(int i_sensor);
double get_humidity(int j_sensor);
double get_id(int k_sensor);
SensorData get_sensor_data(int id);

#endif //SENSORREADER_H
*/