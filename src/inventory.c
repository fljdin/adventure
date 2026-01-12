#include <stdlib.h>
#include "inventory.h"

void inventory_init(struct inventory *inv)
{
    if (!inv) return;
    inv->count = 0;
    inv->items = NULL;
}

bool inventory_add_item(struct inventory *inv, struct item const item)
{
    if (!inv) return false;

    struct item *items = realloc(inv->items, (inv->count + 1) * sizeof(struct item));
    if (!items) return false;

    inv->items = items;
    inv->items[inv->count] = item;
    inv->count += 1;
    return true;
}

bool inventory_remove_item(struct inventory *inv, unsigned const index)
{
    if (!inv || index >= inv->count) return false;

    // shift remaining items beyond index to the left
    for (unsigned i = index; i < inv->count - 1; i++)
    {
        inv->items[i] = inv->items[i + 1];
    }

    struct item *items = realloc(inv->items, (inv->count - 1) * sizeof(struct item));
    if (!items) return false;

    inv->items = items;
    inv->count -= 1;
    return true;
}

unsigned inventory_get_total_weight(struct inventory const *inv)
{
    if (!inv) return 0;

    unsigned total = 0;
    for (unsigned i = 0; i < inv->count; i++)
    {
        total += inv->items[i].weight;
    }
    return total;
}
