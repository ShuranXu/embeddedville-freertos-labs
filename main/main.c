#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-9-isr-queue-handoff status=starter\n");
    fflush(stdout);
    /* TODO: Keep the simulated interrupt bounded and transfer typed events with xQueueSendFromISR(). */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
