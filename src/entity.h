#pragma once
#include "inventory.h"

struct entity
{
    char name[100];
    unsigned health;
    unsigned health_max;
    unsigned strength;
    unsigned dexterity;
    struct inventory inventory;
    struct item weapon;
    struct item armor;
    bool has_weapon;
    bool has_armor;
};

void entity_init(
    struct entity *entity, char const *name,
    unsigned hp, unsigned str, unsigned dex
);
void entity_destroy(struct entity *entity);
unsigned entity_take_damage(struct entity *entity, unsigned const damage);
void entity_heal(struct entity *entity, unsigned const amount);
void entity_set_weapon(struct entity *entity, struct item const item);
void entity_set_armor(struct entity *entity, struct item const item);

enum entity_slot_type
{
    SLOT_WEAPON = WEARABLE_WEAPON,
    SLOT_ARMOR  = WEARABLE_ARMOR,
};

bool entity_equip(struct entity *entity, unsigned inventory_index);
bool entity_unequip(struct entity *entity, enum entity_slot_type slot);

unsigned entity_max_capacity(struct entity const *entity);
bool entity_is_inventory_overloaded(struct entity const *entity);
