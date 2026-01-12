#include <string.h>
#include "entity.h"
#include "inventory.h"

void entity_init(struct entity *entity,
    char const *name,
    unsigned hp,
    unsigned str
)
{
    if (!entity) return;
    strcpy(entity->name, name);
    entity->health_max = (hp > 0) ? hp : 1;
    entity->health = entity->health_max;
    entity->strength = (str > 0) ? str : 1;

    inventory_init(&entity->inventory);
}

void entity_destroy(struct entity *entity)
{
    if (!entity) return;
    inventory_destroy(&entity->inventory);
    memset(entity, 0, sizeof(struct entity));
}

void entity_take_damage(struct entity *entity, unsigned const damage)
{
    if (!entity) return;
    if (entity->health < damage)
        entity->health = 0;
    else
        entity->health -= damage;
}

void entity_heal(struct entity *entity, unsigned const amount)
{
    if (!entity) return;
    entity->health += amount;
    if (entity->health > entity->health_max)
        entity->health = entity->health_max;
}

unsigned entity_max_capacity(struct entity const *entity)
{
    return 5 * entity->strength + 50;
}

bool entity_is_inventory_overloaded(struct entity const *entity)
{
    return entity_max_capacity(entity)
           <= inventory_get_total_weight(&entity->inventory);
}
