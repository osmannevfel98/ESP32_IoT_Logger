//
// Created by OSMAN on 22.07.2025.
//

#ifndef LOGGER_H
#define LOGGER_H
enum LogLevel { LOG_INFO, LOG_WARN, LOG_ERROR };
void log_params(int id);
void log_message(enum LogLevel level);
int get_log_level(int id);
#endif //LOGGER_H
