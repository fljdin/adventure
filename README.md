# Adventure

Adventure is a test-driven linear dungeon crawler side project written in C.

## Gameplay

Player starts in a room. Combat is turn-based with an ncurses interface showing
HP bars, a combat log, and an action menu (attack, inventory, etc.).

## Features

- [x] ncurses UI (window, layout, HP bars, combat log, action menu)
- [x] Full combat encounter loop with turn-based attacks
- [x] Player has armor and weapon slots (equip/unequip)
- [x] Player can pick up items, such as health potions
- [x] Armor reduces incoming damage
- [x] Dungeon is a succession of rooms connected by doors
- [ ] Player can cast spells
- [ ] Title screen and game over screen

## Technical aspects

This project is written in C and follows TDD with the [Unity] testing framework.
The [ncurses] library provides a terminal-based interactive interface.

[Unity]: https://www.throwtheswitch.org/unity
[ncurses]: https://invisible-island.net/ncurses/

## Building

[Meson] is used as the build system. To build the project, run the following
commands:

```sh
make
./build/adventure
```

[Meson]: https://mesonbuild.com/
