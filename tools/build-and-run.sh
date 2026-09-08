#!/usr/bin/env bash
set -euo pipefail

course="${1:-}"
case "$course" in
  course-1-tasking|course-2-communication|course-3-pipelines|course-4-reliability) ;;
  *) echo "Usage: $0 <course-1-tasking|course-2-communication|course-3-pipelines|course-4-reliability>" >&2; exit 2 ;;
esac

if [[ -n "${IDF_PATH:-}" && -f "$IDF_PATH/export.sh" ]]; then
  # shellcheck disable=SC1090
  . "$IDF_PATH/export.sh" >/dev/null 2>&1
fi

idf.py -C "$course" set-target esp32
idf.py -C "$course" build
idf.py -C "$course" merge-bin -o flash_image.bin

qemu-system-xtensa \
  -nographic \
  -machine esp32 \
  -drive "file=$course/build/flash_image.bin,if=mtd,format=raw"
