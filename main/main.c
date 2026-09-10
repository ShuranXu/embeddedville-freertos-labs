#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

void app_main(void)
{
    printf("EVIDENCE item=c3-day-18-software-timers status=starter\n");
    /* TODO: Coordinate bounded one-shot and periodic callbacks, then stop deterministically. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
