#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_pm.h"
#include "esp_task_wdt.h"

void app_main(void)
{
    printf("EVIDENCE boot idf=%s\n", IDF_VER);
    fflush(stdout);
    /* TODO: build the supervised producer/consumer sensor-hub task graph. */
    /* TODO: configure an explicit power policy and track useful progress. */
}

