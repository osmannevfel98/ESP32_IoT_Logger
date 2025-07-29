//
// Created by OSMAN on 22.07.2025.
//

#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

#include "SensorReader.h"

void log_message(LogLevel level);
void log_params(SensorData data);
LogLevel get_log_level(SensorData data);
void log_to_mqtt(SensorData data, LogLevel level);

#endif // LOGGER_H

/*
 * test codes
 *
#ifndef LOGGER_H
#define LOGGER_H
enum LogLevel { LOG_INFO, LOG_WARN, LOG_ERROR };
void log_params(int id);
void log_message(enum LogLevel level);
int get_log_level(int id);
#endif //LOGGER_H
*/