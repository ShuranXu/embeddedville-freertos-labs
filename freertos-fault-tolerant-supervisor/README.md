# Fault-Tolerant FreeRTOS Supervisor

Course: `freertos-fault-tolerant-supervisor`

Capstone: `frtsv-capstone`

Branch: `freertos-fault-tolerant-supervisor`

Starter: `2026.10-supervisor-project-v1`

Build a policy-driven supervisor for an ESP32 FreeRTOS application. You will make missed progress observable, allow cooperative recovery within a bounded budget, reject stale heartbeats, and request a system reset after the budget is exhausted.

The required project runs in Espressif QEMU. No physical board is required. QEMU can demonstrate software state transitions, task coordination, and emitted evidence; it cannot prove electrical behavior, physical watchdog operation, real-time guarantees, current consumption, or hardware reset behavior.

## First action

1. Run `tools/workspace-doctor.sh` and confirm the course, activity, and starter version.
2. Open `main/supervisor.c` and begin with the Lab 1 TODO in `sv_add()`.
3. Run `tools/run-public-tests.sh` while building the policy core.
4. Run `tools/build-and-run.sh` to build and boot the ESP-IDF application in QEMU.
5. Return to the matching EmbeddedVille lab page for the current milestone, evidence requirements, and capstone submission.

The incomplete starter emits `status=starter` until the policy core is implemented. A completed Basic Goal should emit observable `HEALTHY -> SUSPECT -> RECOVERING` transitions, cooperative recovery evidence, and a reset request after the third qualifying stall inside the ten-second restart window.

## Project boundaries

- Heartbeats prove useful progress, not merely that a task was scheduled.
- Recovery is cooperative. Do not delete a task that may own a mutex or peripheral state.
- Use unsigned subtraction for tick comparisons so rollover remains deterministic.
- The optional stretch work adds multiple workers, a bounded heartbeat queue, single-writer policy ownership, and non-blocking recovery callbacks. Stretch results never gate course completion.
- Do not add credentials, protected tests, evaluator files, or copied solutions to this workspace.

## Codespaces lifecycle and cost

A GitHub account, browser, network access, repository access, and available Codespaces quota are required. Quota, retention, storage, machine availability, and billing depend on the GitHub account or organization; Codespaces is not universally free.

Saving in the editor preserves a workspace file, but it is not the same as committing, exporting, or submitting. Closing the browser does not stop compute. Stopping and restarting normally preserves files under `/workspaces`; rebuilding can remove state outside that persistent area; deleting the Codespace or reaching its retention limit can remove unpushed work. Commit or export important work before rebuild or deletion, stop compute when finished, and keep forwarded ports private.

If setup fails, rerun `tools/workspace-doctor.sh`. Preserve your edits before rebuilding. A wrong branch, stale starter, missing QEMU installation, denied repository permission, exhausted quota, or deleted session should be resolved from the course workspace page without replacing saved work blindly.
