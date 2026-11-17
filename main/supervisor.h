#ifndef EMBEDDEDVILLE_SUPERVISOR_H
#define EMBEDDEDVILLE_SUPERVISOR_H

#include <stdbool.h>
#include <stdint.h>

#define SV_MAX_TASKS 8
#define SV_EVENT_QUEUE_CAPACITY 8

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

/* Optional Stretch Goal scaffold: bounded, drop-newest heartbeat events. */
typedef struct {
    int task_id;
    uint32_t generation;
    uint32_t observed_ms;
} sv_heartbeat_event_t;

typedef struct {
    sv_heartbeat_event_t items[SV_EVENT_QUEUE_CAPACITY];
    uint8_t head;
    uint8_t count;
    uint32_t dropped_newest;
} sv_event_queue_t;

void sv_event_queue_init(sv_event_queue_t *queue);
bool sv_event_enqueue(sv_event_queue_t *queue, sv_heartbeat_event_t event);
bool sv_event_dequeue(sv_event_queue_t *queue, sv_heartbeat_event_t *event);

/* Optional Stretch Goal scaffold: non-blocking recovery begin/poll contract. */
typedef enum {
    SV_RECOVERY_PENDING = 0,
    SV_RECOVERY_OK,
    SV_RECOVERY_ERROR,
    SV_RECOVERY_TIMEOUT,
} sv_recovery_status_t;

typedef struct {
    bool active;
    int task_id;
    uint32_t generation;
    uint32_t started_ms;
    uint32_t timeout_ms;
} sv_recovery_async_t;

void sv_recovery_async_init(sv_recovery_async_t *recovery);
sv_recovery_status_t sv_recovery_begin(sv_recovery_async_t *recovery, int task_id, uint32_t generation, uint32_t now_ms, uint32_t timeout_ms);
sv_recovery_status_t sv_recovery_poll(sv_recovery_async_t *recovery, uint32_t now_ms);

#endif
