#include "supervisor.h"

#include <string.h>

void sv_init(sv_supervisor_t *supervisor)
{
    memset(supervisor, 0, sizeof(*supervisor));
}

int sv_add(sv_supervisor_t *supervisor, sv_policy_t policy, uint32_t now_ms)
{
    /* TODO Lab 1: validate policy fields and initialize one task slot. */
    (void)supervisor;
    (void)policy;
    (void)now_ms;
    return -1;
}

void sv_heartbeat(sv_supervisor_t *supervisor, int task_id, uint32_t generation, uint32_t now_ms)
{
    /* TODO Lab 2: accept only a current generation outside recovery/failed states. */
    (void)supervisor;
    (void)task_id;
    (void)generation;
    (void)now_ms;
}

sv_event_t sv_check(sv_supervisor_t *supervisor, int task_id, uint32_t now_ms)
{
    /* TODO Labs 2-3: implement wrap-safe deadline, grace, budget, and escalation. */
    (void)supervisor;
    sv_event_t event = {
        .task_id = task_id,
        .from = SV_HEALTHY,
        .to = SV_HEALTHY,
        .action = SV_ACTION_NONE,
        .elapsed_ms = now_ms,
    };
    return event;
}

void sv_recovery_completed(sv_supervisor_t *supervisor, int task_id, uint32_t now_ms)
{
    /* TODO Lab 3: complete only an active cooperative recovery. */
    (void)supervisor;
    (void)task_id;
    (void)now_ms;
}

const char *sv_state_name(sv_state_t state)
{
    switch (state) {
    case SV_HEALTHY:
        return "HEALTHY";
    case SV_SUSPECT:
        return "SUSPECT";
    case SV_RECOVERING:
        return "RECOVERING";
    case SV_FAILED:
        return "FAILED";
    default:
        return "UNKNOWN";
    }
}
