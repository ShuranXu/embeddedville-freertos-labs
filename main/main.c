#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

void app_main(void)
{
    printf("EVIDENCE item=c2-day-12-uart-mutex status=starter\n");
    fflush(stdout);
    /* TODO: Protect complete UART records with a mutex and release ownership on every path. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
