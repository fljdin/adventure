#include "unity.h"
#include "Player.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_NewPlayer(void)
{
    Player player;
    player = NewPlayer("John", 100);
    TEST_ASSERT_EQUAL_STRING("John", player.name);
    TEST_ASSERT_EQUAL(100, player.health);
}

void test_PlayerHasDamage(void)
{
    Player player;
    player = NewPlayer("John", 100);
    player.health -= 10;
    TEST_ASSERT_EQUAL(90, player.health);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_NewPlayer);
    RUN_TEST(test_PlayerHasDamage);
    return UNITY_END();
}
