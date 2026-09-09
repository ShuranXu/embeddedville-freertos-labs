#!/usr/bin/env bash
set -euo pipefail

repo_root="$(git rev-parse --show-toplevel)"
cd "$repo_root"

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
required = ["CMakeLists.txt", "sdkconfig.defaults", "main/CMakeLists.txt", "main/main.c"]
missing = [path for path in required if not (root / path).is_file()]
siblings = sorted(path.name for path in root.glob("course-*") if path.is_dir() and any(path.iterdir()))
protected = sorted(
    str(path.relative_to(root))
    for path in root.rglob("*")
    if path.name.lower() in {"solution", "solutions", "answer-key", "evaluator"}
)

if missing:
    raise SystemExit(f"Workspace check failed: missing {', '.join(missing)}")
if siblings:
    raise SystemExit(f"Workspace check failed: sibling course directories found: {', '.join(siblings)}")
if protected:
    raise SystemExit(f"Workspace check failed: protected material found: {', '.join(protected)}")

print(
    "Workspace ready: "
    f"Course {course.get('number')} · {course.get('title')} · "
    f"{workspace.get('branch')} · starter {workspace.get('starterVersion')}"
)
PY
