//
// Created by OSMAN on 29.07.2025.
//
#include "../inc/MqttClient.h"
#include "esp_log.h"
#include "mqtt_client.h"

static const char *TAG = "MQTT";
static esp_mqtt_client_handle_t client = NULL;
static bool mqtt_connected = false;

// MQTT event handler
static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event) {
    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT connected");
            mqtt_connected = true;
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG, "MQTT disconnected");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGE(TAG, "MQTT error");
            break;
        default:
            break;
    }
    return ESP_OK;
}

bool mqtt_connect(void) {
    const esp_mqtt_client_config_t mqtt_cfg = {
        .uri = "mqtt://test.mosquitto.org",
        .port = 1883,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);
    if (client == NULL) {
        ESP_LOGE(TAG, "MQTT client init failed");
        return false;
    }

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler_cb, NULL);
    esp_err_t start_result = esp_mqtt_client_start(client);

    if (start_result == ESP_OK) {
        ESP_LOGI(TAG, "MQTT client started");
        return true;
    } else {
        ESP_LOGE(TAG, "MQTT client start failed");
        return false;
    }
}

bool mqtt_is_connected(void) {
    return mqtt_connected;
}

bool mqtt_publish(const char *topic, const char *payload) {
    if (!mqtt_connected || client == NULL) {
        ESP_LOGW(TAG, "MQTT not connected, cannot publish");
        return false;
    }

    int msg_id = esp_mqtt_client_publish(client, topic, payload, 0, 1, 0);
    if (msg_id != -1) {
        ESP_LOGI(TAG, "MQTT published to %s: %s", topic, payload);
        return true;
    } else {
        ESP_LOGE(TAG, "MQTT publish failed");
        return false;
    }
}
