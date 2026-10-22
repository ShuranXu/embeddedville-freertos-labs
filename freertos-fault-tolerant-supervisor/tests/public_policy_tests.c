#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "supervisor.h"

static void test_basic_contract(void)
{
    sv_supervisor_t supervisor;
    sv_init(&supervisor);
    const sv_policy_t policy = {"sensor", 100, 50, 2, 10000};
    const int id = sv_add(&supervisor, policy, 0);
    assert(id == 0);
    assert(supervisor.tasks[id].state == SV_HEALTHY);
    assert(supervisor.tasks[id].generation == 1);

    assert(sv_check(&supervisor, id, 100).action == SV_ACTION_NONE);
    assert(sv_check(&supervisor, id, 101).to == SV_SUSPECT);
    assert(sv_check(&supervisor, id, 150).action == SV_ACTION_NONE);
    assert(sv_check(&supervisor, id, 151).action == SV_ACTION_RESTART);
    assert(supervisor.tasks[id].generation == 2);

    sv_heartbeat(&supervisor, id, 1, 152);
    assert(supervisor.tasks[id].state == SV_RECOVERING);
    sv_recovery_completed(&supervisor, id, 152);
    assert(supervisor.tasks[id].state == SV_HEALTHY);
}

static void test_unsigned_wraparound(void)
{
    sv_supervisor_t supervisor;
    sv_init(&supervisor);
    const sv_policy_t policy = {"wrap", 10, 0, 1, 100};
    const int id = sv_add(&supervisor, policy, UINT32_MAX - 15U);
    assert(id == 0);
    assert(sv_check(&supervisor, id, 0).to == SV_SUSPECT);
    assert(sv_check(&supervisor, id, 1).action == SV_ACTION_RESTART);
}

int main(void)
{
    test_basic_contract();
    test_unsigned_wraparound();
    puts("PUBLIC POLICY TESTS PASSED");
    return 0;
}
