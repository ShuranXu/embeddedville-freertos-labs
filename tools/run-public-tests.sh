#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
mkdir -p "$root/build-host"
cc -std=c11 -Wall -Wextra -Wpedantic -Werror \
  -I"$root/main" \
  "$root/main/supervisor.c" \
  "$root/tests/public_policy_tests.c" \
  -o "$root/build-host/public-policy-tests"
"$root/build-host/public-policy-tests"
