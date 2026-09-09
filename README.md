# Course 4 — FreeRTOS Reliability and Low-Power Systems

Build a supervised sleep-aware sensor hub using simulated inputs. QEMU can prove
scheduler and application behavior, but it cannot prove current consumption or
physical sleep behavior; keep that boundary explicit in your engineering answer.

This Codespaces branch contains only the Course 4 starter. The other independent
FreeRTOS courses are intentionally excluded from this workspace.

## Build and run

1. Open `main/main.c` and implement the TODOs for the current EmbeddedVille lab.
2. Run `tools/build-and-run.sh` from the repository root.
3. Capture the requested serial evidence from the same source revision.

The helper performs a public smoke simulation. Scored evaluation remains in
EmbeddedVille Learn and uses the source archive submitted for this course.

## Workspace identity

- Course: **Course 4 — FreeRTOS Reliability and Low-Power Systems**
- Repository: `ShuranXu/embeddedville-freertos-labs`
- Branch: `course-4-reliability`
- Starter version: `2026.9.1`
- Working directory: repository root

Run `tools/workspace-doctor.sh` whenever you are unsure which workspace is open.
If the Explorer shows `course-1-tasking` through `course-4-reliability` together,
you opened the obsolete default-branch workspace. Preserve any work you need,
return to the Course 4 page, and create the course-specific workspace.

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

