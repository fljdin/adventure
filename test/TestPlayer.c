#include "unity.h"
#include "Player.h"

player_t player;

void setUp(void) {
    player_init(&player, "John", 100);
}

void test_player_init(void)
{
    TEST_ASSERT_EQUAL_STRING("John", player.name);
    TEST_ASSERT_EQUAL(100, player.health_max);
    TEST_ASSERT_EQUAL(100, player.health);
}

void test_player_take_damage(void)
{
    player_take_damage(&player, 10);
    TEST_ASSERT_EQUAL(90, player.health);
}
