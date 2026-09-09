# Course 3 — FreeRTOS Event and Resource Pipelines

Build a bounded telemetry pipeline driven by simulated periodic and fault events.
Use event groups for state, direct notifications for lightweight wakeups, and a
message buffer for telemetry records.

This Codespaces branch contains only the Course 3 starter. The other independent
FreeRTOS courses are intentionally excluded from this workspace.

## Build and run

1. Open `main/main.c` and implement the TODOs for the current EmbeddedVille lab.
2. Run `tools/build-and-run.sh` from the repository root.
3. Capture the requested serial evidence from the same source revision.

The helper performs a public smoke simulation. Scored evaluation remains in
EmbeddedVille Learn and uses the source archive submitted for this course.

## Workspace identity

- Course: **Course 3 — FreeRTOS Event and Resource Pipelines**
- Repository: `ShuranXu/embeddedville-freertos-labs`
- Branch: `course-3-pipelines`
- Starter version: `2026.9.1`
- Working directory: repository root

Run `tools/workspace-doctor.sh` whenever you are unsure which workspace is open.
If the Explorer shows `course-1-tasking` through `course-4-reliability` together,
you opened the obsolete default-branch workspace. Preserve any work you need,
return to the Course 3 page, and create the course-specific workspace.

## Save and leave safely

The browser editor saves files in this Codespace, but course submission is
separate. Submit the source archive requested by EmbeddedVille Learn or commit
and push/export work you need to keep. Stopping and restarting normally preserves
saved workspace files. Deleting the Codespace or reaching its retention limit can
remove unpushed work, and rebuilding clears changes outside `/workspaces`.

Closing the browser tab does not stop compute. Stop the Codespace when you finish.
Codespaces availability, quota, storage, and possible billing depend on your
GitHub account or organization. Keep forwarded ports private and never paste
credentials into source, logs, serial evidence, or a submitted archive.

