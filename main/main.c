#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE boot idf=%s\n", IDF_VER);
    /* TODO: create two independently periodic logical-output tasks. */
    /* TODO: report task creation, tick, level, and core evidence. */
}

