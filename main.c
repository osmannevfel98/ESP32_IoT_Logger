#include "inc/Logger.h"
#include "utils/WifiManager.h"
#include <unistd.h>
#include <unistd.h>
#include <stdbool.h>

int main(void) {
    bool connected = false;
    wifi_connect(connected);
    int log_level = 0;

    for (int i = 0; i < 10; i++) {
        log_level = get_log_level(i);
        log_message(log_level);
        log_params(i);
        sleep(2);
    }

    return 0;
}