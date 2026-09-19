#include <stdio.h>
#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "driver/gptimer.h"

void app_main(void)
{
    printf("EVIDENCE boot idf=%s\n", IDF_VER);
    fflush(stdout);
    /* TODO: generate a bounded GPTimer ISR event and queue it to task context. */
    /* TODO: protect complete serial records with a mutex and report drops. */
}

