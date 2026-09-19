#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-1-led-task status=starter idf=%s\n", IDF_VER);
    fflush(stdout);
    /* TODO: Create one checked task, toggle one logical output, delay for 500 ms, and emit four timestamped transitions. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
