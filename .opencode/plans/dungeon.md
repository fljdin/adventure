# Dungeon Agent

## Purpose
Extend the dungeon module with room descriptions, loot tables, and monster spawning.

## Context

### Existing code
- **`src/dungeon.h`**: `struct room { int type; char *description; }`, `enum room_type { EMPTY, MONSTER, CHEST, SHOP, BOSS }`, `struct dungeon` with linear traversal
- **`src/dungeon.c`**: `dungeon_init()` does NOT set `description` pointer (UB), `dungeon_open_door()` advances `current`
- **`src/entity.h`**: `struct entity` with inventory, needs equipment slot additions

### Room types

| Type | Behavior |
|---|---|
| MONSTER | 1 monster, turn-based fight |
| CHEST | Random loot (weapon / armor / potion) |
| EMPTY (rest) | Recover portion of HP |
| BOSS | Final room, guaranteed boss encounter |

### Loot table

Chest loot for MVP:
- Weapon: Rusty Sword (1d6), Club (1d4+1), Short Sword (1d6+1)
- Armor: Leather Armor (1), Chain Shirt (2), Scale Mail (3)
- Potion: Heal Potion (restore 10 HP)

### Monster spawning by depth

| Room depth | Spawn chances |
|---|---|
| 1-2 | 75% Rat, 25% Goblin |
| 3-4 | 40% Rat, 40% Goblin, 20% Guard |
| 5-6 | 30% Goblin, 60% Guard, 10% Rat |
| 7-8 | Boss (guaranteed) |

### Conventions (from AGENTS.md)
- C23, `-Wall -Wextra -Werror`
- Right-const, `unsigned` instead of `size_t`, no `stdbool.h`, no typedef'd structs
- No comments in code

## Tasks

### 1. Fix `dungeon_init()`
- Allocate and set descriptions for each room based on type
- Accept room-type array from the caller

### 2. Implement loot table
- Add function `struct item dungeon_chest_loot(void)` — pick random loot
- Weighted randomization across weapons, armor, and potions

### 3. Implement monster spawning
- Add function `struct entity dungeon_spawn_monster(unsigned room_depth)`
- Pick monster type based on depth table, init with bestiary stats

### 4. Extend `struct entity` in `entity.h`
Add equipment slots:
- `unsigned weapon_dice_count`
- `unsigned weapon_dice_faces`
- `int weapon_bonus`
- `unsigned armor_value`

Or prefer a struct to keep it clean. Follow existing conventions.

### 5. Add `src/bestiary.c` + `src/bestiary.h` (optional)
If spawning logic grows large, extract bestiary constants into a separate module.

## Verification
- All existing dungeon tests must still pass
- New tests for: loot table draws valid items, monster spawn at correct depths, room descriptions are initialized
- `make && make tests` clean
