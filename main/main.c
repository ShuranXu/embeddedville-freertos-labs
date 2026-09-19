#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-11-counting-semaphore status=starter\n");
    fflush(stdout);
    /* TODO: Model finite capacity with a counting semaphore and report saturation and recovery. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
