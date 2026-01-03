#pragma once
#include <stdbool.h>
#include "inventory.h"

typedef struct {
    char name[100];
    int health;
    int health_max;
    int strength;
    inventory_t inventory;
} player_t;

void player_init(player_t *p, const char *name, int hp, int str);
void player_take_damage(player_t *p, int damage);
void player_heal(player_t *p, int amount);

int player_max_capacity(const player_t *p);
bool player_is_inventory_overloaded(const player_t *p);
