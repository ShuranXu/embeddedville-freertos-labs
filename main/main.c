#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-14-uart-logger status=starter\n");
    /* TODO: Integrate queue handoff, finite buffers, mutex-protected records, overload, and recovery. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
