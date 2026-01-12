#pragma once
#include "inventory.h"

typedef struct {
    char name[100];
    unsigned health;
    unsigned health_max;
    unsigned strength;
    inventory_t inventory;
} player_t;

void player_init(player_t *p, const char *name, unsigned hp, unsigned str);
void player_take_damage(player_t *p, unsigned damage);
void player_heal(player_t *p, unsigned amount);

unsigned player_max_capacity(const player_t *p);
bool player_is_inventory_overloaded(const player_t *p);
