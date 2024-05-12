#include <string.h>
#include "Player.h"

Player NewPlayer(const char *name, int hp) 
{
    Player player;
    strcpy(player.name, name);
    player.health = hp;
    return player;
} 
