#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
"$root/tools/workspace-doctor.sh"

if [[ -n "${IDF_PATH:-}" && -f "$IDF_PATH/export.sh" ]]; then
  # shellcheck disable=SC1090
  . "$IDF_PATH/export.sh" >/dev/null 2>&1
fi

idf.py set-target esp32
idf.py build
idf.py merge-bin -o flash_image.bin

qemu-system-xtensa \
  -nographic \
  -machine esp32 \
  -drive "file=build/flash_image.bin,if=mtd,format=raw"
