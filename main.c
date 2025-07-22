#include "inc/Logger.h"
#include "utils/WifiManager.h"
#include <unistd.h>

int main(void) {
    wifi_connect();
    //printf("Humidity[3]: %.1f\n", humidity[3]);
    //printf("Temperature[3]: %.1f\n", temperature[3]);
    //printf("%.1f\n",get_humidity());
    //printf("%.1f\n",get_temperature());

    for (int i = 0; i < 10; i++) {
        log_params(i,i);
        sleep(2);
    }

    return 0;
}