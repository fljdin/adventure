#pragma once
#include "dice.h"

enum item_type
{
    ITEM_GENERIC,
    ITEM_WEAPON,
    ITEM_ARMOR,
};

struct item
{
    char name[32];
    unsigned weight;
    enum item_type type;
    union {
        struct dice damage;
        unsigned value;
    };
};

struct inventory
{
    unsigned count;
    struct item *items;
};

void inventory_init(struct inventory *inv);
void inventory_destroy(struct inventory *inv);
bool inventory_add_item(struct inventory *inv, struct item const item);
bool inventory_remove_item(struct inventory *inv, unsigned const index);
unsigned inventory_get_total_weight(struct inventory const *inv);
