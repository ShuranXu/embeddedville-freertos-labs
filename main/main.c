#include <inttypes.h>
#include <stdio.h>

#include "esp_idf_version.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "supervisor.h"

static sv_supervisor_t supervisor;
static volatile bool inject_stall;

static uint32_t now_ms(void)
{
    return (uint32_t)(xTaskGetTickCount() * portTICK_PERIOD_MS);
}

static void worker_task(void *context)
{
    const int task_id = (int)(intptr_t)context;
    uint32_t generation = 1;

    for (;;) {
        if (!inject_stall) {
            sv_heartbeat(&supervisor, task_id, generation, now_ms());
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

static void monitor_task(void *context)
{
    const int task_id = (int)(intptr_t)context;

    for (;;) {
        sv_event_t event = sv_check(&supervisor, task_id, now_ms());
        if (event.to != event.from) {
            printf("EVIDENCE transition=%s->%s elapsed_ms=%" PRIu32 "\n",
                   sv_state_name(event.from), sv_state_name(event.to), event.elapsed_ms);
        }

        /* TODO Lab 4: perform a cooperative recovery for SV_ACTION_RESTART. */
        /* TODO Capstone: emit RESET_REQUESTED for SV_ACTION_SYSTEM_RESET. */
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

static void fault_injector_task(void *context)
{
    (void)context;
    vTaskDelay(pdMS_TO_TICKS(700));
    inject_stall = true;
    puts("EVIDENCE fault=heartbeat-stall");
    vTaskDelete(NULL);
}

void app_main(void)
{
    printf("EVIDENCE boot idf=%s course=freertos-fault-tolerant-supervisor starter=2026.10-supervisor-project-v1\n",
           IDF_VER);

    sv_init(&supervisor);
    const sv_policy_t policy = {
        .name = "sensor",
        .deadline_ms = 300,
        .grace_ms = 150,
        .max_restarts = 2,
        .restart_window_ms = 10000,
    };
    const int task_id = sv_add(&supervisor, policy, now_ms());
    if (task_id < 0) {
        puts("EVIDENCE status=starter policy=not-implemented");
        return;
    }

    xTaskCreate(worker_task, "worker", 3072, (void *)(intptr_t)task_id, 2, NULL);
    xTaskCreate(monitor_task, "monitor", 4096, (void *)(intptr_t)task_id, 3, NULL);
    xTaskCreate(fault_injector_task, "injector", 2048, NULL, 1, NULL);
}
