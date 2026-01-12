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
bool inventory_add_item(inventory_t *inv, item_t item);
bool inventory_remove_item(inventory_t *inv, unsigned index);
unsigned inventory_get_total_weight(const inventory_t *inv);
