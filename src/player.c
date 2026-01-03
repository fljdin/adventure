#include <string.h>
#include "player.h"
#include "inventory.h"

void player_init(player_t *p,
    const char *name,
    int hp,
    int str
)
{
    if (!p) return;
    strcpy(p->name, name);
    p->health_max = (hp > 0) ? hp : 1;
    p->health = p->health_max;
    p->strength = (str > 0) ? str : 1;

    inventory_init(&p->inventory);
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

int player_max_capacity(const player_t *p)
{
    return 5 * p->strength + 50;
}

bool player_is_inventory_overloaded(const player_t *p)
{
    return player_max_capacity(p)
           <= inventory_get_total_weight(&p->inventory);
}
