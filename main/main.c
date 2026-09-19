#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-8-queue-backpressure status=starter\n");
    fflush(stdout);
    /* TODO: Create a bounded queue, check every send and receive, and report depth and drops. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
