#pragma once

#include "Player.h"
#include "Map.h"

typedef struct Game {
    Player *player;
    Room *room;
    int level;
} Game;

Game InitGame(Player *player, Room *room);
void OpenDoor(Game *game);
