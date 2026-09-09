#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include "freertos/message_buffer.h"

void app_main(void)
{
    printf("EVIDENCE boot idf=%s\n", IDF_VER);
    /* TODO: combine event bits, direct notifications, and message buffers. */
    /* TODO: keep timer callbacks bounded and log heap/runtime evidence. */
}

