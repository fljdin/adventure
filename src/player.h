#pragma once
#include "inventory.h"

typedef struct {
    char name[100];
    unsigned health;
    unsigned health_max;
    unsigned strength;
    inventory_t inventory;
} player_t;

void player_init(player_t *p, char const *name, unsigned hp, unsigned str);
void player_take_damage(player_t *p, unsigned const damage);
void player_heal(player_t *p, unsigned const amount);

unsigned player_max_capacity(player_t const *p);
bool player_is_inventory_overloaded(player_t const *p);
