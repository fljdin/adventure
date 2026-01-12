#include <string.h>
#include "player.h"
#include "inventory.h"

void player_init(struct player *p,
    char const *name,
    unsigned hp,
    unsigned str
)
{
    if (!p) return;
    strcpy(p->name, name);
    p->health_max = (hp > 0) ? hp : 1;
    p->health = p->health_max;
    p->strength = (str > 0) ? str : 1;

    inventory_init(&p->inventory);
}

void player_take_damage(struct player *p, unsigned const damage)
{
    if (!p) return;
    if (p->health < damage)
        p->health = 0;
    else
        p->health -= damage;
}

void player_heal(struct player *p, unsigned const amount)
{
    if (!p) return;
    p->health += amount;
    if (p->health > p->health_max)
        p->health = p->health_max;
}

unsigned player_max_capacity(struct player const *p)
{
    return 5 * p->strength + 50;
}

bool player_is_inventory_overloaded(struct player const *p)
{
    return player_max_capacity(p)
           <= inventory_get_total_weight(&p->inventory);
}
