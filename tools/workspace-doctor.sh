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
activity = manifest.get("activity", {})
required = ["CMakeLists.txt", "sdkconfig.defaults", "main/CMakeLists.txt", "main/main.c"]
missing = [path for path in required if not (root / path).is_file()]
protected_names = {"solution", "solutions", "answer-key", "evaluator", "protected", ".dev.vars"}
protected = sorted(str(path.relative_to(root)) for path in root.rglob("*") if path.name.lower() in protected_names)
if missing:
    raise SystemExit(f"Workspace check failed: missing {', '.join(missing)}")
if protected:
    raise SystemExit(f"Workspace check failed: protected material found: {', '.join(protected)}")
print(f"Workspace ready: {course.get('title')} · {activity.get('dayLabel')} · {activity.get('title')} · starter {workspace.get('starterVersion')}")
PY
