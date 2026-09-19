#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-2-timed-counter status=starter idf=%s\n", IDF_VER);
    /* TODO: Print the ESP-IDF version, increment a persistent counter every two seconds, and connect the run to this exact revision. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
