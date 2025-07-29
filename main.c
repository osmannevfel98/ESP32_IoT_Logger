#include "inc/Logger.h"
#include "inc/WifiManager.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "inc/MqttClient.h"
#include "inc/SensorReader.h"

void app_main(void) {
    if (!wifi_connect()) {
        printf("unsuccessful wifi connection, staring again\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
        esp_restart();
    }

    if (!mqtt_connect()) {
        printf("unsuccessful mqtt connection, staring again\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
        esp_restart();
    }

    sensor_init();

    while (1) {
        SensorData data = get_sensor_data(0);
        LogLevel level = get_log_level(data);

        log_message(level);
        log_params(data);
        log_to_mqtt(data, level);

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

/*
 * test codes
 *
int main(void) {
    bool connected = false;
    wifi_connect(connected);
    int log_level = 0;

    for (int i = 0; i < 10; i++) {
        log_level = get_log_level(i);
        log_message(log_level);
        log_params(i);
    }
    return 0;
}
*/