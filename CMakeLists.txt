cmake_minimum_required(VERSION 3.31)
project(ESP32_IoT_Logger C)

set(CMAKE_C_STANDARD 11)

add_executable(ESP32_IoT_Logger main.c
        inc/Logger.h
        src/Logger.c
        utils/WiFiManager.c
        utils/SensorReader.c
        utils/SensorReader.h
)
