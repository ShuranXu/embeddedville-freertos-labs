#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

void app_main(void)
{
    printf("EVIDENCE item=c3-day-20-interrupt-management status=starter\n");
    fflush(stdout);
    /* TODO: Compare queue and direct-notification handoffs with equivalent deterministic events. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
