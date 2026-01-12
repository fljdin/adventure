#pragma once

typedef struct {
    char name[32];
    unsigned weight;
} item_t;

typedef struct {
    unsigned count;
    item_t *items;
} inventory_t;

void inventory_init(inventory_t *inv);
bool inventory_add_item(inventory_t *inv, item_t const item);
bool inventory_remove_item(inventory_t *inv, unsigned const index);
unsigned inventory_get_total_weight(inventory_t const *inv);
