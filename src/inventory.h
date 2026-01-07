#pragma once
#include <stddef.h>

typedef struct {
    char name[32];
    size_t weight;
} item_t;

typedef struct {
    size_t count;
    item_t *items;
} inventory_t;

void inventory_init(inventory_t *inv);
int inventory_add_item(inventory_t *inv, item_t item);
int inventory_remove_item(inventory_t *inv, size_t index);
size_t inventory_get_total_weight(const inventory_t *inv);
