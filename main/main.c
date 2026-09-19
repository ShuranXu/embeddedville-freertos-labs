#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/task.h"

void app_main(void)
{
    printf("EVIDENCE item=c4-day-22-tick-timing status=starter\n");
    fflush(stdout);
    /* TODO: Derive timing from the tick rate and preserve observable scheduler idle opportunities. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
