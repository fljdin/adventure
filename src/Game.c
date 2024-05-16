#include "Game.h"

Game InitGame(Player *player, Room *room) {
    Game game = {player, room, 1};
    return game;
}

void OpenDoor(Game *game) {
    game->level++;
    game->room = game->room->door;
}
