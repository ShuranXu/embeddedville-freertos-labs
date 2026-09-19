#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-6-periodic-timing status=starter idf=%s\n", IDF_VER);
    /* TODO: Use vTaskDelayUntil() for a 200 ms release and vTaskDelay() for a one-second logical output; calculate consecutive intervals. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
