#include <stdlib.h>
#include "inventory.h"

void inventory_init(inventory_t *inv)
{
    if (!inv) return;
    inv->count = 0;
    inv->items = NULL;
}

bool inventory_add_item(inventory_t *inv, item_t item)
{
    if (!inv) return false;

    item_t *items = realloc(inv->items, (inv->count + 1) * sizeof(item_t));
    if (!items) return false;

    inv->items = items;
    inv->items[inv->count] = item;
    inv->count += 1;
    return true;
}

bool inventory_remove_item(inventory_t *inv, unsigned index)
{
    if (!inv || index >= inv->count) return false;

    // shift remaining items beyond index to the left
    for (unsigned i = index; i < inv->count - 1; i++)
    {
        inv->items[i] = inv->items[i + 1];
    }

    item_t *items = realloc(inv->items, (inv->count - 1) * sizeof(item_t));
    if (!items) return false;

    inv->items = items;
    inv->count -= 1;
    return true;
}

unsigned inventory_get_total_weight(const inventory_t *inv)
{
    if (!inv) return 0;

    unsigned total = 0;
    for (unsigned i = 0; i < inv->count; i++)
    {
        total += inv->items[i].weight;
    }
    return total;
}
