//
// Created by OSMAN on 29.07.2025.
//

#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <stdbool.h>

bool mqtt_connect(void);
bool mqtt_is_connected(void);
bool mqtt_publish(const char *topic, const char *payload);

#endif // MQTT_CLIENT_H