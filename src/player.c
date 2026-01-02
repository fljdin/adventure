#include <string.h>
#include "player.h"

void player_init(player_t *p, const char *name, int hp)
{
    if (!p) return;
    strcpy(p->name, name);
    p->health_max = (hp > 0) ? hp : 1;
    p->health = p->health_max;
}

void player_take_damage(player_t *p, int damage)
{
    if (!p || damage <= 0) return;
    p->health -= damage;
    if (p->health < 0) p->health = 0;
}

void player_heal(player_t *p, int amount)
{
    if (!p || amount <= 0) return;
    p->health += amount;
    if (p->health > p->health_max) p->health = p->health_max;
}
