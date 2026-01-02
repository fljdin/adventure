#include <stdlib.h>
#include "inventory.h"

void inventory_init(inventory_t *inv)
{
    if (!inv) return;
    inv->count = 0;
    inv->items = NULL;
}

int inventory_add_item(inventory_t *inv, item_t item) {
    if (!inv || item.weight < 0) return -1;

    item_t *items = realloc(inv->items, (inv->count + 1) * sizeof(item_t));
    if (!items) return -1;

    inv->items = items;
    inv->items[inv->count] = item;
    inv->count += 1;
    return 0;
}

int inventory_remove_item(inventory_t *inv, int index)
{
    if (!inv || index < 0 || index >= inv->count) return -1;

    // shift remaining items beyond index to the left
    for (int i = index; i < inv->count - 1; i++)
    {
        inv->items[i] = inv->items[i + 1];
    }

    item_t *items = realloc(inv->items, (inv->count - 1) * sizeof(item_t));
    if (!items) return -1;

    inv->items = items;
    inv->count -= 1;
    return 0;
}

int inventory_get_total_weight(const inventory_t *inv)
{
    if (!inv) return 0;
    int total = 0;
    for (int i = 0; i < inv->count; i++)
    {
        total += inv->items[i].weight;
    }
    return total;
}
