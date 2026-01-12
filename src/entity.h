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
};

void entity_init(
    struct entity *entity, char const *name,
    unsigned hp, unsigned str, unsigned dex
);
void entity_destroy(struct entity *entity);
void entity_take_damage(struct entity *entity, unsigned const damage);
void entity_heal(struct entity *entity, unsigned const amount);

unsigned entity_max_capacity(struct entity const *entity);
bool entity_is_inventory_overloaded(struct entity const *entity);
