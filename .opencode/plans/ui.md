# UI Agent

## Purpose
Build the ncurses interface for the Adventure Game — Pokémon-battle-style layout.

## Context

### Existing code
- **`src/main.c`**: Minimal ncurses stub (`initscr()` / `endwin()`)
- ncurses is already a required meson dependency

### Conventions (from AGENTS.md)
- C23, `-Wall -Wextra -Werror`
- Right-const, `unsigned` instead of `size_t`, no `stdbool.h`, no typedef'd structs
- No comments in code

### UI Layout

```
+----------------------------------+
|  GUARD  HP: ########----  12/20  |  <- enemy HP bar (top)
+----------------------------------+
|                                    |
|  The guard draws its sword!        |  <- narrative text (center)
|                                    |
|  > Attack                          |  <- arrow menu (center-bottom)
|    Use Potion                      |
+----------------------------------+
|  JOHN  HP: ################  25/25|  <- player HP bar (bottom)
|  Rusty Sword (1d6) | Armor 2     |  <- equipment line
+----------------------------------+
```

## Tasks

### 1. Create `src/ui.h`
Declare:
- `void ui_init(void)` — initialize ncurses, color pairs
- `void ui_cleanup(void)` — endwin
- `void ui_draw_combat_screen(struct entity const *player, struct entity const *monster, char const *narrative, int action_count, char const **actions, int selected)`
- `int ui_get_action(int action_count)` — arrow key menu, returns selected index

### 2. Create `src/ui.c`
Implement screen manager:
- Top section: monster name + HP bar (filled block + empty block characters)
- Bottom section: player name + HP bar + equipment summary
- Center zone: narrative text line + action menu
- Menu navigable via up/down arrows, confirm with enter

### 3. Rewrite `src/main.c`
Game loop skeleton:
```
ui_init()
title_screen()
player = create_player()
dungeon = generate_dungeon()
while not at exit:
    room = current_room(dungeon)
    process_room(room, player)
    if player is dead -> game over screen
    open_door(dungeon)
victory_screen()
ui_cleanup()
```

### 4. Update `src/meson.build`
Add `'ui.c'` to the `core` files list.

## UI Patterns (MVP)
- Use `mvprintw(row, col, ...)` for positioned text
- HP bars: loop printing filled char for alive, empty for lost
- Menu: print options, highlight selected with `>` prefix
- No `WINDOW` objects for MVP — keep it flat
- `start_color()` / `init_pair()` optional (future use)

## Verification
- `make` compiles without warnings
- `./build/adventure` shows the combat layout
