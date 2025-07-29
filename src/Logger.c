//
// Created by OSMAN on 22.07.2025.
//

#include "../inc/Logger.h"
#include "../inc/SensorReader.h"
#include "esp_log.h"
#include "../inc/MqttClient.h"
#include <stdio.h>
#include <string.h>

static const char *TAG = "LOGGER";

void log_message(LogLevel level) {
    switch (level) {
        case LOG_INFO:
            ESP_LOGI(TAG, "[INFO]");
            break;
        case LOG_WARN:
            ESP_LOGW(TAG, "[WARN]");
            break;
        case LOG_ERROR:
            ESP_LOGE(TAG, "[ERROR]");
            break;
    }
}

void log_params(SensorData data) {
    ESP_LOGI(TAG, "Temperature: %.1f °C", data.temperature);
    ESP_LOGI(TAG, "Humidity: %.1f %%", data.humidity);
    ESP_LOGI(TAG, "Sensor ID: %d", data.id);
}

LogLevel get_log_level(SensorData data) {
    // Örnek kural:
    // - Temp > 30.0 veya Humidity > 80.0 → WARN
    // - Temp > 45.0 → ERROR

    if (data.temperature > 45.0) {
        return LOG_ERROR;
    } else if (data.temperature > 40.0 || data.humidity > 80.0) {
        return LOG_WARN;
    } else {
        return LOG_INFO;
    }
}

void log_to_mqtt(SensorData data, LogLevel level) {
    if (!mqtt_is_connected()) {
        ESP_LOGW(TAG, "MQTT not connected. Skipping MQTT log.");
        return;
    }

    char payload[256];
    const char *level_str = (level == LOG_INFO) ? "INFO" :
                            (level == LOG_WARN) ? "WARN" : "ERROR";

    snprintf(payload, sizeof(payload),
             "{\"id\": %d, \"temperature\": %.1f, \"humidity\": %.1f, \"level\": \"%s\"}",
             data.id, data.temperature, data.humidity, level_str);

    mqtt_publish("esp32/log", payload);
}



/*
 * test codes
 *
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
*/