#include "unity.h"
#include "inventory.h"
#include <stddef.h>

struct inventory inv;

void setUp(void)
{
    inventory_init(&inv);
}

void test_inventory_add_item_increase_count(void)
{
    struct item sword = {.name="Sword", .weight=5};
    int result = inventory_add_item(&inv, sword);

    TEST_ASSERT_EQUAL(true, result);
    TEST_ASSERT_EQUAL_INT(1, inv.count);
    TEST_ASSERT_EQUAL_STRING("Sword", inv.items[0].name);
}

void test_inventory_remove_item_shifts_remaining_items(void)
{
    struct item item1 = {.name="Item 1", .weight=1};
    struct item item2 = {.name="Item 2", .weight=1};

    inventory_add_item(&inv, item1);
    inventory_add_item(&inv, item2);
    inventory_remove_item(&inv, 0);

    TEST_ASSERT_EQUAL_INT(1, inv.count);
    TEST_ASSERT_EQUAL_STRING("Item 2", inv.items[0].name);
}

void test_inventory_remove_invalid_index_fails(void)
{
    bool result = inventory_remove_item(&inv, -1);
    TEST_ASSERT_EQUAL(false, result);

    result = inventory_remove_item(&inv, 10);
    TEST_ASSERT_EQUAL(false, result);
}

void test_inventory_total_weight(void)
{
    struct item sword = {.name="Sword", .weight=5};
    struct item shield = {.name="Shield", .weight=10};

    inventory_add_item(&inv, sword);
    inventory_add_item(&inv, shield);

    size_t weigth = inventory_get_total_weight(&inv);
    TEST_ASSERT_EQUAL_INT(15, weigth);
}
