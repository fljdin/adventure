#include "unity.h"
#include "item.h"

void test_item_create_weapon(void)
{
    struct item it = item_create(ITEM_RUSTY_SWORD);
    TEST_ASSERT_EQUAL_STRING("Rusty Sword", it.name);
    TEST_ASSERT_EQUAL_UINT(3, it.weight);
    TEST_ASSERT_EQUAL_INT(ITEM_WEAPON, it.type);
    TEST_ASSERT_EQUAL_UINT(1, it.damage.count);
    TEST_ASSERT_EQUAL_UINT(6, it.damage.faces);
    TEST_ASSERT_EQUAL_INT(0, it.damage.bonus);
}

void test_item_create_armor(void)
{
    struct item it = item_create(ITEM_LEATHER_ARMOR);
    TEST_ASSERT_EQUAL_STRING("Leather Armor", it.name);
    TEST_ASSERT_EQUAL_UINT(10, it.weight);
    TEST_ASSERT_EQUAL_INT(ITEM_ARMOR, it.type);
    TEST_ASSERT_EQUAL_UINT(1, it.value);
}

void test_item_create_generic(void)
{
    struct item it = item_create(ITEM_HEAL_POTION);
    TEST_ASSERT_EQUAL_STRING("Heal Potion", it.name);
    TEST_ASSERT_EQUAL_UINT(1, it.weight);
    TEST_ASSERT_EQUAL_INT(ITEM_GENERIC, it.type);
}
