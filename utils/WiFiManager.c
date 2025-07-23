//
// Created by OSMAN on 22.07.2025.
//

#include <stdio.h>
#include "WifiManager.h"
#include <stdbool.h>

void wifi_connect(bool connected) {
    if(connected)
        printf("Connected to Wi-Fi!\n\n");
    else
        printf("Not connected to Wi-Fi!\n\n");
}
