#include "inventory.h"
#include "unity.h"
#include "player.h"

struct player player;

void setUp(void)
{
    player_init(&player,
        "John", // Name
        100,    // Health
        10      // Strength
    );
}

void test_player_init(void)
{
    TEST_ASSERT_EQUAL_STRING("John", player.name);
    TEST_ASSERT_EQUAL(100, player.health_max);
    TEST_ASSERT_EQUAL(100, player.health);
}

void test_player_takes_damage(void)
{
    player_take_damage(&player, 10);
    TEST_ASSERT_EQUAL(90, player.health);
}

void test_player_health_cannot_be_negative(void)
{
    player_take_damage(&player, 200);
    TEST_ASSERT_EQUAL_INT(0, player.health);
}

void test_player_health_cannot_exceed_max(void)
{
    player_heal(&player, 10);
    TEST_ASSERT_EQUAL_INT(player.health, player.health_max);
}

void test_player_inventory_is_overloaded(void)
{
    player.strength = 1; // capacity = 5 * str + 50
    TEST_ASSERT_EQUAL_INT(55, player_max_capacity(&player));

    inventory_add_item(&player.inventory, (struct item){.name="Sword", .weight=30});
    bool is_overloaded = player_is_inventory_overloaded(&player);
    TEST_ASSERT(!is_overloaded);

    inventory_add_item(&player.inventory, (struct item){.name="Sword", .weight=30});
    is_overloaded = player_is_inventory_overloaded(&player);
    TEST_ASSERT(is_overloaded);
}
