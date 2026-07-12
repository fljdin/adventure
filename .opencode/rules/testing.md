# Testing Rules

## Build & test commands

```sh
make                    # Build (meson setup --reconfigure + meson compile)
make tests              # Run all tests via meson
meson test -C build -v  # Individual test run with verbose output
meson clean             # Also: rm -rf build .cache subprojects/*/
```

The Makefile is the single source of truth for build commands. Meson will reconfigure on version mismatch.

## Unity conventions

- Test files define functions like `void test_inventory_add_item_increase_count(void)`
- `TEST_SETUP` / `TEST_TEAR_DOWN` if needed
- Unity runs 4 separate executables, one per test file; failures in one don't block others
- No shared fixtures; each test suite links against core library
