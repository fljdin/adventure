#include "monster.h"
#include "entity.h"

struct monster_stats const monster_table[] = {
    [MONSTER_RAT] = {
        .name = "Rat",
        .health = 4,
        .damage = {1, 3, 1},
        .dexterity = 12,
    },
    [MONSTER_GOBLIN] = {
        .name = "Goblin",
        .health = 10,
        .damage = {1, 6, 1},
        .dexterity = 14,
        .weapons = (struct dice_range[]){
            {61, 85, ITEM_CLUB},
            {86, 100, ITEM_SHORT_SWORD},
        },
        .weapon_count = 2,
        .armors = (struct dice_range[]){
            {91, 100, ITEM_LEATHER_ARMOR},
        },
        .armor_count = 1,
    },
    [MONSTER_GUARD] = {
        .name = "Guard",
        .health = 15,
        .damage = {1, 8, 2},
        .dexterity = 12,
        .weapons = (struct dice_range[]){
            {1, 100, ITEM_SHORT_SWORD},
        },
        .weapon_count = 1,
        .armors = (struct dice_range[]){
            {1, 80, ITEM_CHAIN_SHIRT},
        },
        .armor_count = 1,
    },
    [MONSTER_BOSS] = {
        .name = "Warden",
        .health = 35,
        .damage = {1, 10, 5},
        .dexterity = 10,
        .armors = (struct dice_range[]){
            {1, 100, ITEM_SCALE_MAIL},
        },
        .armor_count = 1,
    },
};

void monster_spawn_with_func(struct entity *entity, enum monster_type type, dice_func_t dice_func)
{
    struct monster_stats const *m = &monster_table[type];
    entity_init(entity, m->name, m->health, 0, m->dexterity);

    struct dice d100 = { .count = 1, .faces = 100, .bonus = 0 };

    unsigned roll = dice_roll_with_func(&d100, dice_func);
    int val = dice_range_lookup(roll, m->weapons, m->weapon_count);
    if (val >= 0)
        entity_set_weapon(entity, item_create((enum item_kind)val));

    roll = dice_roll_with_func(&d100, dice_func);
    val = dice_range_lookup(roll, m->armors, m->armor_count);
    if (val >= 0)
        entity_set_armor(entity, item_create((enum item_kind)val));
}

void monster_spawn(struct entity *entity, enum monster_type type)
{
    monster_spawn_with_func(entity, type, dice_random);
}
