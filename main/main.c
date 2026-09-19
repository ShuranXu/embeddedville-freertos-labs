#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-3-core-affinity status=starter idf=%s\n", IDF_VER);
    fflush(stdout);
    /* TODO: Create one unpinned task and one Core 1 task; check both results and report each observed core. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
