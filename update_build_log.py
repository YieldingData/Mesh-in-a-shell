
import os

JOURNAL_DIR = "docs/build-journal"
BUILD_LOG = "BUILD_LOG.md"

def generate_log_links():
    logs = sorted([
        f for f in os.listdir(JOURNAL_DIR)
        if f.endswith(".md")
    ])
    links = "\n".join([
        f"- [{{log.replace('.md', '').replace('_', ' ').title()}}]({JOURNAL_DIR}/{log})"
        for log in logs
    ])
    return links

def update_build_log():
    log_section = f"""
<details>
<summary><strong>View Daily Logs</strong></summary>

{generate_log_links()}

</details>
"""
    static_intro = "# Mesh in a Shell – Build Log\n\nThis file contains a master index of daily development logs, organized by date.\n"
    static_outro = "\n---\n\n## Current Notes\n\nUse the dropdown above to explore detailed logs by day. New entries should be added automatically by script.\n"

    with open(BUILD_LOG, "w") as f:
        f.write(static_intro + log_section + static_outro)

if __name__ == "__main__":
    update_build_log()
