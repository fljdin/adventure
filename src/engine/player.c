#include <stdlib.h>
#include "player.h"

Player *Player_create()
{
  Player *player = malloc(sizeof(Player));
  player->position = 0;

  return player;
}