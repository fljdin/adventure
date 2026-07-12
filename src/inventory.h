#pragma once
#include "item.h"

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
