# Adventure

Adventure is a test-driven text adventure side project written in C.

## Gameplay

Player starts in a room. Each action is textually described, and the player can
choose which one to take. Combat show the participant's health, and the player
can choose to attack, cast a sortilege, use an item, or flee.

## Features

- [x] Player has a health bar
- [ ] Player can choose which direction to go in
- [ ] Player has armor and weapon slots
- [ ] Player can pick up items, such as health potions
- [ ] Player can fight enemies in turn-based combat
- [ ] Player can cast spells

## Technical aspects

This project is written in C, and uses the [Unity] testing framework. As the
game is text-based, it runs entirely in a terminal. The [ncurses] library is used
to provide an interactive interface.

[Unity]: https://www.throwtheswitch.org/unity
[ncurses]: https://invisible-island.net/ncurses/
