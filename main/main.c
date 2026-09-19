#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c4-day-25-system-integration status=starter\n");
    fflush(stdout);
    /* TODO: Integrate typed samples, state, signaling, supervision, and protected output. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
