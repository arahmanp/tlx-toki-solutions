# TLX Repo Conventions

Standard for directory structure, file naming, and commit messages in the `tlx` repo.
**Applies to new files going forward** — existing files are left as-is, no need to rename them one by one.

---

## 1. Directory Structure

```
tlx/
├── courses/
│   └── pemrograman-kompetitif-dasar/
│       ├── 01-brute-force/
│       ├── 02-divide-and-conquer/
│       ├── 03-dp/
│       ├── 04-greedy/
│       ├── 05-math/
│       └── 06-searching-sorting/
└── drills/
    ├── osn/
    │   └── <year>/
    ├── troc/
    │   └── <number>/
    ├── ioi/
    │   └── <year>/
    ├── gemastik/
    │   └── <year>/
    ├── ksn/
    │   └── <year>/
    └── misc/
```

**Notes:**
- `courses/` — structured practice following the order of a book/course (currently: TOKI's "Pemrograman Kompetitif Dasar" book). The numeric prefix (`01-`, `02-`, ...) preserves chapter order instead of alphabetical order.
- `drills/` — free-form practice problems, grouped by **contest of origin** rather than by topic/technique. This was chosen deliberately because a single problem often has several technique tags at once (e.g. dp + math + ad hoc), which makes topic-based grouping ambiguous — whereas the source contest is always singular and objective.
- Year/number subfolders inside `drills/` **don't need to be created upfront** — only create them when a problem actually needs to go there (lazy creation). Git doesn't track empty folders anyway, so this happens naturally.
- `drills/misc/` is a fallback folder for problems whose contest of origin is unknown or not shown by TLX (e.g. problems solved through TLX's "drill by topic" feature where the source isn't clear).

---

## 2. Naming Conventions

General rule: all folder and file names use **kebab-case, all lowercase** — don't mix `-` and `_`, avoid uppercase, avoid spaces/special characters (an example to avoid: `kumpulan soal toki #9`).

### a. Files in `courses/`
Format: `<label>-<short-slug>.cpp`
The label follows the original label from the course/book (problem letter or number), and the slug is a short description so the file is self-explanatory without opening it.

Example: `a-jumlah-maksimum.cpp`, `p1-menara-angka.cpp`

### b. Files in `drills/`
Each contest family has its own path standard, since problem-labeling formats differ:

| Contest | Path format | Example |
|---|---|---|
| OSN | `osn/<year>/<problem-code>.cpp` | `osn/2010/3a.cpp` |
| TROC | `troc/<number>/<letter>.cpp` | `troc/12/a.cpp` |
| IOI | `ioi/<year>/<problem-name-slug>.cpp` | `ioi/2016/aliens.cpp` |
| GEMASTIK / KSN / other contests | `<contest-name>/<year>/<code>.cpp` | `gemastik/2023/a.cpp`, `ksn/2021/0b.cpp` |
| Unknown origin | `misc/<problem-slug>.cpp` | `misc/absolute-winner.cpp` |

Problem codes/labels are written in lowercase (`3a`, not `3A`) — for consistency, and to avoid case-sensitivity issues if you ever switch OS (macOS is case-insensitive by default).

### c. In-file metadata header
Since a folder only holds one category (contest of origin), topic/technique tags (dp, math, ad hoc, etc.) are stored as a comment at the top of each file instead of via folders:

```cpp
// problem: 3A - <Problem Title>
// contest: OSN Informatika 2010
// tags: dp, math, ad-hoc
// status: AC
```

This keeps problems searchable by topic (`grep -rl "tags:.*dp" drills/`) without needing file duplication or symlinks.

### d. Test data
If there are `.in`/`.out` files, name them exactly the same as the problem slug, in the same folder: `<slug>.cpp`, `<slug>.in`, `<slug>.out`.

---

## 3. Commit Message Convention

Format: `<scope>: <slug> [optional status]`

**Scope for `courses/`** — use the chapter slug:
```
pkd-brute-force: a - AC
pkd-dp: b - AC
```

**Scope for `drills/`** — use contest + number/year:
```
osn-2010: 3a - AC
troc-12: a - AC
ioi-2016: aliens - AC, used binary search on answer
ksn-2021: 0b - fix WA, edge case n=1
misc: absolute-winner - AC
```

**Non-solution commits** (repo maintenance) use conventional-commit prefixes:
```
chore: update .gitignore
docs: update README on folder structure
refactor: move drills to contest-based scheme
```

For migrating the old structure to the new one: split commits per contest/course rather than one giant commit, so history stays reviewable in parts.

---

## 4. `.gitignore`

```
*.out
*.exe
*.o
a.out
```

---

## 5. Other Important Notes

- Existing files **don't need to be renamed** to match this convention — it only applies to new files going forward.
- If you find old files that look like duplicates (e.g. `segitiga_bebek.cpp` appearing in two different folders), check them — if they really are duplicates, clean up later, no rush.
- Old folders with spaces/special characters (e.g. `kumpulan soal toki #9`) should be renamed to the new format (`toki/09/`) when you get the chance, using `git mv` so history is preserved.