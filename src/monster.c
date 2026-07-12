#include "monster.h"
#include "entity.h"

static struct monster_equip_range const goblin_weapons[] = {
    {61, 85, ITEM_CLUB},
    {86, 100, ITEM_SHORT_SWORD},
};

static struct monster_equip_range const goblin_armors[] = {
    {91, 100, ITEM_LEATHER_ARMOR},
};

static struct monster_equip_range const guard_weapons[] = {
    {1, 100, ITEM_SHORT_SWORD},
};

static struct monster_equip_range const guard_armors[] = {
    {1, 80, ITEM_CHAIN_SHIRT},
};

static struct monster_equip_range const boss_armors[] = {
    {1, 100, ITEM_SCALE_MAIL},
};

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
        .weapons = goblin_weapons,
        .weapon_count = 2,
        .armors = goblin_armors,
        .armor_count = 1,
    },
    [MONSTER_GUARD] = {
        .name = "Guard",
        .health = 15,
        .damage = {1, 8, 2},
        .dexterity = 12,
        .weapons = guard_weapons,
        .weapon_count = 1,
        .armors = guard_armors,
        .armor_count = 1,
    },
    [MONSTER_BOSS] = {
        .name = "Warden",
        .health = 35,
        .damage = {1, 10, 5},
        .dexterity = 10,
        .armors = boss_armors,
        .armor_count = 1,
    },
};

void monster_spawn_with_func(struct entity *entity, enum monster_type type, dice_func_t dice_func)
{
    struct monster_stats const *m = &monster_table[type];
    entity_init(entity, m->name, m->health, 0, m->dexterity);

    struct dice d100 = { .count = 1, .faces = 100, .bonus = 0 };

    unsigned roll = dice_roll_with_func(&d100, dice_func);
    for (unsigned i = 0; i < m->weapon_count; i++)
    {
        if (roll >= m->weapons[i].low && roll <= m->weapons[i].high)
        {
            entity_set_weapon(entity, item_create(m->weapons[i].kind));
            break;
        }
    }

    roll = dice_roll_with_func(&d100, dice_func);
    for (unsigned i = 0; i < m->armor_count; i++)
    {
        if (roll >= m->armors[i].low && roll <= m->armors[i].high)
        {
            entity_set_armor(entity, item_create(m->armors[i].kind));
            break;
        }
    }
}

void monster_spawn(struct entity *entity, enum monster_type type)
{
    monster_spawn_with_func(entity, type, dice_random);
}
