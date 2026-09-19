#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-4-task-deletion status=starter idf=%s\n", IDF_VER);
    fflush(stdout);
    /* TODO: Implement exactly one safe self-or-manager deletion path and invalidate the stored handle after controller-owned deletion. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
