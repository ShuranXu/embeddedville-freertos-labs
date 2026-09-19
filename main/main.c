#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_heap_caps.h"

void app_main(void)
{
    printf("EVIDENCE item=c3-day-19-memory-policy status=starter\n");
    fflush(stdout);
    /* TODO: Compare static and dynamic task allocation with heap, stack, and ownership evidence. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
