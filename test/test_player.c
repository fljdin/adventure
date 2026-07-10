#include "inventory.h"
#include "unity.h"
#include "entity.h"

struct entity player;

void setUp(void)
{
    entity_init(&player,
        "John", // Name
        100,    // Health
        10,     // Strength
        10      // Dexterity
    );
}

void tearDown(void)
{
    entity_destroy(&player);
}

void test_entity_init(void)
{
    TEST_ASSERT_EQUAL_STRING("John", player.name);
    TEST_ASSERT_EQUAL(100, player.health_max);
    TEST_ASSERT_EQUAL(100, player.health);
}

void test_entity_takes_damage(void)
{
    entity_take_damage(&player, 10);
    TEST_ASSERT_EQUAL(90, player.health);
}

void test_entity_health_cannot_be_negative(void)
{
    entity_take_damage(&player, 200);
    TEST_ASSERT_EQUAL_INT(0, player.health);
}

void test_entity_health_cannot_exceed_max(void)
{
    entity_heal(&player, 10);
    TEST_ASSERT_EQUAL_INT(player.health, player.health_max);
}

void test_entity_take_damage_with_armor(void)
{
    struct item shield = { .name = "Shield", .weight = 5, .type = ITEM_ARMOR, .value = 3 };
    entity_set_armor(&player, shield);
    entity_take_damage(&player, 10);
    TEST_ASSERT_EQUAL(93, player.health);
}

void test_entity_inventory_is_overloaded(void)
{
    player.strength = 1; // capacity = 5 * str + 50
    TEST_ASSERT_EQUAL_INT(55, entity_max_capacity(&player));

    inventory_add_item(&player.inventory, (struct item){.name="Sword", .weight=30});
    bool is_overloaded = entity_is_inventory_overloaded(&player);
    TEST_ASSERT(!is_overloaded);

    inventory_add_item(&player.inventory, (struct item){.name="Sword", .weight=30});
    is_overloaded = entity_is_inventory_overloaded(&player);
    TEST_ASSERT(is_overloaded);
}
