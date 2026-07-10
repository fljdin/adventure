#include "unity.h"
#include "entity.h"
#include "combat.h"

struct entity player;
struct entity monster;
struct entity fast;
struct entity slow;

static unsigned always(unsigned max)
{
    (void)max;
    return 1;
}

static unsigned always_max(unsigned max)
{
    return max;
}

void setUp(void)
{
    entity_init(&player, "John", 30, 3, 14);
    entity_init(&monster, "Goblin", 20, 5, 8);
}

void test_attack_hit_deals_damage(void)
{
    struct item sword = { .name = "Sword", .weight = 3, .type = ITEM_WEAPON, .damage = {1, 4, 0} };
    entity_set_weapon(&player, sword);
    entity_attack_with_func(&player, &monster, always);
    TEST_ASSERT_EQUAL_UINT(16, monster.health);
}

void test_attack_miss_when_dex_too_low(void)
{
    entity_init(&player, "Clumsy", 30, 1, 1);
    struct item sword = { .name = "Sword", .weight = 3, .type = ITEM_WEAPON, .damage = {1, 4, 0} };
    entity_set_weapon(&player, sword);
    entity_attack_with_func(&player, &monster, always);
    TEST_ASSERT_EQUAL_UINT(20, monster.health);
}

void test_critical_hit_deals_double_damage(void)
{
    struct item knife = { .name = "Knife", .weight = 1, .type = ITEM_WEAPON, .damage = {1, 1, 0} };
    entity_set_weapon(&player, knife);
    entity_attack_with_func(&player, &monster, always_max);
    TEST_ASSERT_EQUAL_UINT(12, monster.health);
}

void test_higher_dexterity_goes_first(void)
{
    entity_init(&fast, "Rogue", 10, 5, 18);
    entity_init(&slow, "Knight", 10, 5, 10);
    TEST_ASSERT_EQUAL_INT(1, combat_turn_order(&fast, &slow));
    TEST_ASSERT_EQUAL_INT(-1, combat_turn_order(&slow, &fast));
    TEST_ASSERT_EQUAL_INT(0, combat_turn_order(&fast, &fast));
}
