#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-13-priority-inheritance status=starter\n");
    /* TODO: Reproduce bounded contention and report the mutex owner's effective priority. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
