#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-10-binary-semaphore status=starter\n");
    /* TODO: Signal task work with a binary semaphore and make event coalescing observable. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
