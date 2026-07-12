#include "unity.h"
#include "entity.h"
#include "monster.h"

struct entity monster;

void tearDown(void)
{
    entity_destroy(&monster);
}

static unsigned always(unsigned max)
{
    (void)max;
    return 1;
}

static unsigned never(unsigned max)
{
    return max;
}

void test_spawn_rat_has_no_equipment(void)
{
    monster_spawn(&monster, MONSTER_RAT);
    TEST_ASSERT_EQUAL_UINT(4, monster.health_max);
    TEST_ASSERT_EQUAL_UINT(12, monster.dexterity);
    TEST_ASSERT(!monster.has_weapon);
    TEST_ASSERT(!monster.has_armor);
}

void test_spawn_goblin_gets_short_sword_and_armor(void)
{
    monster_spawn_with_func(&monster, MONSTER_GOBLIN, never);
    TEST_ASSERT(monster.has_weapon);
    TEST_ASSERT_EQUAL_STRING("Short Sword", monster.weapon.name);
    TEST_ASSERT(monster.has_armor);
    TEST_ASSERT_EQUAL_STRING("Leather Armor", monster.armor.name);
}

void test_spawn_goblin_gets_nothing(void)
{
    monster_spawn_with_func(&monster, MONSTER_GOBLIN, always);
    TEST_ASSERT(!monster.has_weapon);
    TEST_ASSERT(!monster.has_armor);
}
