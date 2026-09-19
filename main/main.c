#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c1-day-5-priority-change status=starter idf=%s\n", IDF_VER);
    /* TODO: Run three blocking tasks, change the high task priority after five iterations, and preserve before-and-after evidence. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
