#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-7-dual-output status=starter idf=%s\n", IDF_VER);
    /* TODO: Create and check two task-owned logical outputs with independent 500 ms and one-second schedules. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
