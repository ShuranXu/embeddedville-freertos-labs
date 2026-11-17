#include "supervisor.h"

#include <string.h>

void sv_recovery_async_init(sv_recovery_async_t *recovery)
{
    if (recovery != NULL) {
        memset(recovery, 0, sizeof(*recovery));
    }
}

sv_recovery_status_t sv_recovery_begin(sv_recovery_async_t *recovery, int task_id, uint32_t generation, uint32_t now_ms, uint32_t timeout_ms)
{
    (void)task_id;
    (void)generation;
    (void)now_ms;
    (void)timeout_ms;
    if (recovery == NULL) {
        return SV_RECOVERY_ERROR;
    }

    /* TODO (Stretch Goal): record the request and return immediately. */
    return SV_RECOVERY_PENDING;
}

sv_recovery_status_t sv_recovery_poll(sv_recovery_async_t *recovery, uint32_t now_ms)
{
    (void)now_ms;
    if (recovery == NULL) {
        return SV_RECOVERY_ERROR;
    }

    /* TODO (Stretch Goal): test timeout before polling the recovery owner,
     * then return PENDING, OK, ERROR, or TIMEOUT without blocking. */
    return SV_RECOVERY_PENDING;
}
