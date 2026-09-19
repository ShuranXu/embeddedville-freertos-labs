#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_pm.h"

void app_main(void)
{
    printf("EVIDENCE item=c4-day-24-power-policy status=starter\n");
    fflush(stdout);
    /* TODO: Prove policy and wake behavior in simulation; reserve physical current claims for hardware. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
