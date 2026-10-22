#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

python3 - <<'PY'
import json
from pathlib import Path

root = Path.cwd()
manifest_path = root / ".embeddedville-workspace.json"
if not manifest_path.is_file():
    raise SystemExit("Workspace check failed: .embeddedville-workspace.json is missing.")

manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
workspace = manifest.get("workspace", {})
course = manifest.get("course", {})
activity = manifest.get("activity", {})

expected = {
    "course": "freertos-fault-tolerant-supervisor",
    "activity": "frtsv-capstone",
    "branch": "freertos-fault-tolerant-supervisor",
    "starter": "2026.10-supervisor-project-v1",
}
actual = {
    "course": course.get("id"),
    "activity": activity.get("id"),
    "branch": workspace.get("branch"),
    "starter": workspace.get("starterVersion"),
}
if actual != expected:
    raise SystemExit(f"Workspace check failed: identity mismatch: {actual}")

required = [
    "CMakeLists.txt",
    "sdkconfig.defaults",
    "main/CMakeLists.txt",
    "main/main.c",
    "main/supervisor.c",
    "main/supervisor.h",
    "tests/public_policy_tests.c",
    "tools/build-and-run.sh",
    "tools/run-public-tests.sh",
]
missing = [path for path in required if not (root / path).is_file()]
if missing:
    raise SystemExit(f"Workspace check failed: missing {', '.join(missing)}")

protected_names = {"solution", "solutions", "answer-key", "evaluator", "protected", ".dev.vars"}
protected = sorted(
    str(path.relative_to(root))
    for path in root.rglob("*")
    if path.name.lower() in protected_names
)
if protected:
    raise SystemExit(f"Workspace check failed: protected material found: {', '.join(protected)}")

print(
    "Workspace ready: "
    f"{course.get('title')} - {activity.get('title')} - starter {workspace.get('starterVersion')}"
)
PY
