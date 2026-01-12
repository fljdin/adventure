#pragma once
#include "inventory.h"

struct player
{
    char name[100];
    unsigned health;
    unsigned health_max;
    unsigned strength;
    struct inventory inventory;
};

void player_init(struct player *p, char const *name, unsigned hp, unsigned str);
void player_take_damage(struct player *p, unsigned const damage);
void player_heal(struct player *p, unsigned const amount);

unsigned player_max_capacity(struct player const *p);
bool player_is_inventory_overloaded(struct player const *p);
