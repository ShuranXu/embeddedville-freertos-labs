# Course 2 — FreeRTOS Communication and Synchronization

Build an interrupt-driven logger. A simulated GPTimer callback is the hardware
interrupt source; the ISR transfers typed records into a bounded FreeRTOS queue.
Use the exact readiness and evidence contract in the course project brief.

This Codespaces branch contains only the Course 2 starter. The other independent
FreeRTOS courses are intentionally excluded from this workspace.

## Build and run

1. Open `main/main.c` and implement the TODOs for the current EmbeddedVille lab.
2. Run `tools/build-and-run.sh` from the repository root.
3. Capture the requested serial evidence from the same source revision.

The helper performs a public smoke simulation. Scored evaluation remains in
EmbeddedVille Learn and uses the source archive submitted for this course.

