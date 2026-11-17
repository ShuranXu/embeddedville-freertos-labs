#include "supervisor.h"

#include <string.h>

void sv_event_queue_init(sv_event_queue_t *queue)
{
    if (queue != NULL) {
        memset(queue, 0, sizeof(*queue));
    }
}

bool sv_event_enqueue(sv_event_queue_t *queue, sv_heartbeat_event_t event)
{
    (void)event;
    if (queue == NULL) {
        return false;
    }

    /* TODO (Stretch Goal): append when capacity remains. When full, preserve
     * the queued events, increment dropped_newest, and return false. */
    queue->dropped_newest += 1U;
    return false;
}

bool sv_event_dequeue(sv_event_queue_t *queue, sv_heartbeat_event_t *event)
{
    (void)event;
    if (queue == NULL) {
        return false;
    }

    /* TODO (Stretch Goal): remove the oldest event without creating a second
     * writer for supervisor policy state. */
    return false;
}
