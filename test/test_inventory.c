#include "unity.h"
#include "inventory.h"

inventory_t inv;

void setUp(void)
{
    inventory_init(&inv);
}

void test_inventory_add_item_increase_count(void)
{
    item_t sword = {"Sword", 5};
    int result = inventory_add_item(&inv, sword);

    TEST_ASSERT_EQUAL_INT(0, result); // OK
    TEST_ASSERT_EQUAL_INT(1, inv.count);
    TEST_ASSERT_EQUAL_STRING("Sword", inv.items[0].name);
}

void test_inventory_remove_item_shifts_remaining_items(void)
{
    item_t item1 = {"Item 1", 1};
    item_t item2 = {"Item 2", 1};

    inventory_add_item(&inv, item1);
    inventory_add_item(&inv, item2);
    inventory_remove_item(&inv, 0);

    TEST_ASSERT_EQUAL_INT(1, inv.count);
    TEST_ASSERT_EQUAL_STRING("Item 2", inv.items[0].name);
}

void test_inventory_remove_invalid_index_fails(void)
{
    int result = inventory_remove_item(&inv, -1);
    TEST_ASSERT_NOT_EQUAL_INT(0, result);

    result = inventory_remove_item(&inv, 10);
    TEST_ASSERT_NOT_EQUAL_INT(0, result);
}

void test_inventory_total_weight(void)
{
    item_t sword = {"Sword", 5};
    item_t shield = {"Shield", 10};

    inventory_add_item(&inv, sword);
    inventory_add_item(&inv, shield);

    int weigth = inventory_get_total_weight(&inv);
    TEST_ASSERT_EQUAL_INT(15, weigth);
}

void test_inventory_item_weight_cannot_be_negative(void)
{
    item_t item = {"Item", -1};
    int result = inventory_add_item(&inv, item);
    TEST_ASSERT_NOT_EQUAL_INT(0, result);
}
