# Combat Agent

## Purpose
Implement turn-based combat for the Adventure Game.

## Context

### Existing code
- **`src/entity.h`**: `struct entity` with health, strength, dexterity, inventory
- **`src/dice.h`**: `struct dice` with count/faces/bonus, `dice_roll()`, function pointer injection for testing
- **`src/combat.h/c`**: Must be created (do NOT modify `entity.h`)
- **`test/test_combat.c`**: Dead file (not built) — references `entity_attack()` which does not exist. Restore in meson.build.

### Combat rules

| Rule | Detail |
|---|---|
| Turn order | Higher dexterity goes first |
| Accuracy | 1d20 + dex >= 10 to hit |
| Critical hit | Natural 20 -> double damage |
| Player damage | Weapon dice + strength bonus |
| Monster damage | Monster-specific dice |
| Armor | Flat reduction after dice roll (min 0) |
| No fleeing | Combat is to the death |
| Healing | Via potions from inventory or rest rooms |

### Bestiary

| Monster | HP | Damage | Armor | Dex | Room range |
|---|---|---|---|---|---|
| Rat | 4 | 1d3+1 | 0 | 12 | 1-2 |
| Goblin | 10 | 1d6+1 | 0 | 14 | 2-4 |
| Guard | 15 | 1d8+2 | 3 | 12 | 4-6 |
| Boss (Warden) | 35 | 1d10+5 | 5 | 10 | Final |

## Tasks

### 1. Create `src/combat.h`
Declare:
- `void entity_attack(struct entity *attacker, struct entity *defender, struct dice const *weapon_dice)`
- `int combat_turn_order(struct entity const *a, struct entity const *b)` — returns 1 if a first, -1 if b first, 0 if equal

### 2. Create `src/combat.c`
Implement:
- `entity_attack()`: roll accuracy (1d20 + dex), check hit (>=10), if hit roll weapon damage + str bonus, apply minus defender armor (min 0), call `entity_take_damage()`
- Natural 20 on accuracy roll = critical (double damage before armor)
- `combat_turn_order()`: compare dexterity

### 3. Update `test/meson.build`
Restore `test_combat.c` to the build list alongside other test suites.

### 4. Rewrite `test/test_combat.c`
Tests to write:
- `test_attack_reduces_health_on_hit` (inject `always_max` for deterministic hit)
- `test_attack_misses_when_dex_too_low` (inject `always_min`)
- `test_critical_hit_deals_double_damage`
- `test_armor_reduces_damage`
- `test_higher_dexterity_goes_first`

### 5. Update `src/meson.build`
Add `'combat.c'` to the `core` files list.

## Verification
- `make && make tests` — all tests pass, including new combat tests
- Test suite must compile without warnings under `-Wall -Wextra -Werror`
