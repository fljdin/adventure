#pragma once
#include "item.h"

struct entity;

enum monster_type
{
    MONSTER_RAT,
    MONSTER_GOBLIN,
    MONSTER_GUARD,
    MONSTER_BOSS,
};

struct monster_equip_range
{
    unsigned low;
    unsigned high;
    enum item_kind kind;
};

struct monster_stats
{
    char const *name;
    unsigned health;
    struct dice damage;
    unsigned dexterity;
    struct monster_equip_range const *weapons;
    unsigned weapon_count;
    struct monster_equip_range const *armors;
    unsigned armor_count;
};

extern struct monster_stats const monster_table[];

void monster_spawn(struct entity *entity, enum monster_type type);
void monster_spawn_with_func(struct entity *entity, enum monster_type type, dice_func_t dice_func);
