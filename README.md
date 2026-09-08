# EmbeddedVille FreeRTOS browser labs

These are starter-only ESP-IDF v6.0.3 projects for the four independent
EmbeddedVille FreeRTOS courses. Open this repository in GitHub Codespaces, choose
the matching course directory, and implement the TODOs from its project brief.

| Course | Starter directory | Culminating project |
| --- | --- | --- |
| 1 | `course-1-tasking` | Deterministic Dual-LED Controller (logical outputs in QEMU) |
| 2 | `course-2-communication` | Interrupt-Driven UART Event Logger |
| 3 | `course-3-pipelines` | Event-Driven Telemetry Pipeline |
| 4 | `course-4-reliability` | Resilient Sleep-Aware Sensor Hub |

## Use the browser lab

1. Create a Codespace from this repository.
2. In the terminal, run `tools/build-and-run.sh course-1-tasking` (replace the
   directory for your course).
3. Edit `main/main.c`, rebuild, and inspect the serial evidence.
4. Download or archive only the chosen course directory and submit it through
   EmbeddedVille Learn.

The local helper runs a public smoke simulation. The scored review is separate:
a credential-free GitHub Actions job compiles and inspects your submitted source,
then a protected job receives only the compiled firmware and runs a private QEMU
scenario. Reference solutions are not stored here.

## Scope

These labs validate FreeRTOS code structure and behavior in Espressif QEMU. They
do not validate electrical behavior, real sensors, radio links, sleep current, or
physical ESP32 hardware.

