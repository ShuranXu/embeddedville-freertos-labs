#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

void app_main(void)
{
    printf("EVIDENCE item=c3-day-21-idle-daemon status=starter\n");
    fflush(stdout);
    /* TODO: Keep idle-hook and timer-callback work bounded while normal tasks do longer work. */
    /* Emit status=pass only after every published acceptance check succeeds. */
}
