#pragma once
#include "dice.h"

enum item_type
{
    ITEM_GENERIC,
    ITEM_WEAPON,
    ITEM_ARMOR,
    ITEM_POTION,
};

struct item
{
    char name[32];
    unsigned weight;
    enum item_type type;
    union {
        struct dice damage;
        unsigned protection;
        unsigned heal;
    };
};

#define FOREACH_ITEM(X)                                                        \
    X(ITEM_RUSTY_SWORD,   "Rusty Sword",    3, ITEM_WEAPON, .damage = {1, 6, 0}) \
    X(ITEM_CLUB,          "Club",           4, ITEM_WEAPON, .damage = {1, 4, 1}) \
    X(ITEM_SHORT_SWORD,   "Short Sword",    3, ITEM_WEAPON, .damage = {1, 6, 1}) \
    X(ITEM_LEATHER_ARMOR, "Leather Armor", 10, ITEM_ARMOR,  .protection = 1)     \
    X(ITEM_CHAIN_SHIRT,   "Chain Shirt",   15, ITEM_ARMOR,  .protection = 2)     \
    X(ITEM_SCALE_MAIL,    "Scale Mail",    20, ITEM_ARMOR,  .protection = 3)     \
    X(ITEM_HEAL_POTION,   "Heal Potion",    1, ITEM_POTION, .heal = 10)

#define ITEM_ENUM(name_, ...) name_,

enum item_kind
{
    FOREACH_ITEM(ITEM_ENUM)
};

struct item item_create(enum item_kind kind);
