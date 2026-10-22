#ifndef EMBEDDEDVILLE_SUPERVISOR_H
#define EMBEDDEDVILLE_SUPERVISOR_H

#include <stdbool.h>
#include <stdint.h>

#define SV_MAX_TASKS 8

typedef enum {
    SV_HEALTHY = 0,
    SV_SUSPECT,
    SV_RECOVERING,
    SV_FAILED,
} sv_state_t;

typedef enum {
    SV_ACTION_NONE = 0,
    SV_ACTION_RESTART,
    SV_ACTION_SYSTEM_RESET,
} sv_action_t;

typedef struct {
    const char *name;
    uint32_t deadline_ms;
    uint32_t grace_ms;
    uint8_t max_restarts;
    uint32_t restart_window_ms;
} sv_policy_t;

typedef struct {
    sv_policy_t policy;
    uint32_t last_beat_ms;
    uint32_t suspect_since_ms;
    uint32_t window_start_ms;
    uint32_t generation;
    uint8_t restarts_in_window;
    sv_state_t state;
    bool initialized;
} sv_task_t;

typedef struct {
    sv_task_t tasks[SV_MAX_TASKS];
    uint8_t count;
} sv_supervisor_t;

typedef struct {
    int task_id;
    sv_state_t from;
    sv_state_t to;
    sv_action_t action;
    uint32_t elapsed_ms;
} sv_event_t;

void sv_init(sv_supervisor_t *supervisor);
int sv_add(sv_supervisor_t *supervisor, sv_policy_t policy, uint32_t now_ms);
void sv_heartbeat(sv_supervisor_t *supervisor, int task_id, uint32_t generation, uint32_t now_ms);
sv_event_t sv_check(sv_supervisor_t *supervisor, int task_id, uint32_t now_ms);
void sv_recovery_completed(sv_supervisor_t *supervisor, int task_id, uint32_t now_ms);
const char *sv_state_name(sv_state_t state);

#endif
