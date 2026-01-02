#pragma once

typedef struct {
    char name[32];
    int weight;
} item_t;

typedef struct {
    int count;
    item_t *items;
} inventory_t;

void inventory_init(inventory_t *inv);
int inventory_add_item(inventory_t *inv, item_t item);
int inventory_remove_item(inventory_t *inv, int index);
