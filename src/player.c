#include <string.h>
#include "player.h"
#include "inventory.h"

void player_init(player_t *p,
    const char *name,
    size_t hp,
    size_t str
)
{
    if (!p) return;
    strcpy(p->name, name);
    p->health_max = (hp > 0) ? hp : 1;
    p->health = p->health_max;
    p->strength = (str > 0) ? str : 1;

    inventory_init(&p->inventory);
}

void player_take_damage(player_t *p, size_t damage)
{
    if (!p) return;
    if (p->health < damage)
        p->health = 0;
    else
        p->health -= damage;
}

void player_heal(player_t *p, size_t amount)
{
    if (!p) return;
    p->health += amount;
    if (p->health > p->health_max)
        p->health = p->health_max;
}

size_t player_max_capacity(const player_t *p)
{
    return 5 * p->strength + 50;
}

bool player_is_inventory_overloaded(const player_t *p)
{
    return player_max_capacity(p)
           <= inventory_get_total_weight(&p->inventory);
}
