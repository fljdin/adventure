#pragma once
#include <stdbool.h>
#include "inventory.h"

typedef struct {
    char name[100];
    size_t health;
    size_t health_max;
    size_t strength;
    inventory_t inventory;
} player_t;

void player_init(player_t *p, const char *name, size_t hp, size_t str);
void player_take_damage(player_t *p, size_t damage);
void player_heal(player_t *p, size_t amount);

size_t player_max_capacity(const player_t *p);
bool player_is_inventory_overloaded(const player_t *p);
