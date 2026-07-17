#include <string.h>
#include "entity.h"
#include "inventory.h"

void entity_init(struct entity *entity,
    char const *name,
    unsigned hp,
    unsigned str,
    unsigned dex
)
{
    if (!entity) return;
    strcpy(entity->name, name);
    entity->health_max = (hp > 0) ? hp : 1;
    entity->health = entity->health_max;
    entity->strength = (str > 0) ? str : 1;
    entity->dexterity = (dex > 0) ? dex : 1;

    inventory_init(&entity->inventory);
    entity->has_weapon = false;
    entity->has_armor = false;
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
    unsigned effective = damage;
    if (entity->has_armor && entity->armor.protection > 0)
        effective = damage > entity->armor.protection
                  ? damage - entity->armor.protection
                  : 0;
    if (entity->health < effective)
        entity->health = 0;
    else
        entity->health -= effective;
}

void entity_set_weapon(struct entity *entity, struct item const item)
{
    if (!entity) return;
    entity->weapon = item;
    entity->has_weapon = true;
}

void entity_set_armor(struct entity *entity, struct item const item)
{
    if (!entity) return;
    entity->armor = item;
    entity->has_armor = true;
}

bool entity_equip(struct entity *entity, unsigned inventory_index)
{
    if (!entity || inventory_index >= entity->inventory.count)
        return false;

    struct item item = entity->inventory.items[inventory_index];

    switch (item.type)
    {
    case WEARABLE_WEAPON:
        if (entity->has_weapon)
            inventory_add_item(&entity->inventory, entity->weapon);
        entity_set_weapon(entity, item);
        break;
    case WEARABLE_ARMOR:
        if (entity->has_armor)
            inventory_add_item(&entity->inventory, entity->armor);
        entity_set_armor(entity, item);
        break;
    default:
        return false;
    }

    inventory_remove_item(&entity->inventory, inventory_index);
    return true;
}

bool entity_unequip(struct entity *entity, enum entity_slot_type slot)
{
    if (!entity)
        return false;

    switch (slot)
    {
    case SLOT_WEAPON:
        if (!entity->has_weapon)
            return true;
        inventory_add_item(&entity->inventory, entity->weapon);
        entity->has_weapon = false;
        return true;
    case SLOT_ARMOR:
        if (!entity->has_armor)
            return true;
        inventory_add_item(&entity->inventory, entity->armor);
        entity->has_armor = false;
        return true;
    default:
        return false;
    }
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
