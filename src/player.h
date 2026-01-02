#pragma once

typedef struct {
    char name[100];
    int health;
    int health_max;
} player_t;

void player_init(player_t *p, const char *name, int hp);
void player_take_damage(player_t *p, int damage);
void player_heal(player_t *p, int amount);
