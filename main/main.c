#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void)
{
    printf("EVIDENCE item=c4-day-26-runtime-trace status=starter\n");
    fflush(stdout);
    /* TODO: Measure runtime, queue pressure, and stack headroom before changing one bottleneck. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
