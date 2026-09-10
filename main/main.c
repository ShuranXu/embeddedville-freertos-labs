#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c4-days-27-28-recovery-performance status=starter\n");
    /* TODO: Recover useful progress and compare queue and notification cost under equivalent load. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
