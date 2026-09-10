#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

void app_main(void)
{
    printf("EVIDENCE item=c3-day-15-event-groups status=starter\n");
    /* TODO: Publish named readiness bits and demonstrate any, all, and two-of-three decisions. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
