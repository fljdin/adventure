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
    struct item shield = { .name = "Shield", .weight = 5, .category = WEARABLE, .type = WEARABLE_ARMOR, .protection = 3 };
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

void test_equip_weapon(void)
{
    struct item sword = item_create(ITEM_RUSTY_SWORD);
    inventory_add_item(&player.inventory, sword);
    TEST_ASSERT(entity_equip(&player, 0));
    TEST_ASSERT(player.has_weapon);
    TEST_ASSERT_EQUAL_STRING("Rusty Sword", player.weapon.name);
    TEST_ASSERT_EQUAL_UINT(0, player.inventory.count);
}

void test_equip_armor(void)
{
    struct item armor = item_create(ITEM_LEATHER_ARMOR);
    inventory_add_item(&player.inventory, armor);
    TEST_ASSERT(entity_equip(&player, 0));
    TEST_ASSERT(player.has_armor);
    TEST_ASSERT_EQUAL_UINT(1, player.armor.protection);
    TEST_ASSERT_EQUAL_UINT(0, player.inventory.count);
}

void test_equip_replaces_weapon(void)
{
    struct item sword = item_create(ITEM_RUSTY_SWORD);
    entity_set_weapon(&player, sword);
    struct item club = item_create(ITEM_CLUB);
    inventory_add_item(&player.inventory, club);

    TEST_ASSERT(entity_equip(&player, 0));
    TEST_ASSERT_EQUAL_STRING("Club", player.weapon.name);
    TEST_ASSERT_EQUAL_UINT(1, player.inventory.count);
    TEST_ASSERT_EQUAL_STRING("Rusty Sword", player.inventory.items[0].name);
}

void test_equip_wrong_type(void)
{
    struct item potion = item_create(ITEM_HEAL_POTION);
    inventory_add_item(&player.inventory, potion);
    TEST_ASSERT(!entity_equip(&player, 0));
    TEST_ASSERT_EQUAL_UINT(1, player.inventory.count);
}

void test_equip_out_of_bounds(void)
{
    TEST_ASSERT(!entity_equip(&player, 0));
}

void test_unequip_weapon(void)
{
    struct item sword = item_create(ITEM_RUSTY_SWORD);
    entity_set_weapon(&player, sword);
    TEST_ASSERT(entity_unequip(&player, SLOT_WEAPON));
    TEST_ASSERT(!player.has_weapon);
    TEST_ASSERT_EQUAL_UINT(1, player.inventory.count);
    TEST_ASSERT_EQUAL_STRING("Rusty Sword", player.inventory.items[0].name);
}

void test_unequip_armor(void)
{
    struct item armor = item_create(ITEM_LEATHER_ARMOR);
    entity_set_armor(&player, armor);
    TEST_ASSERT(entity_unequip(&player, SLOT_ARMOR));
    TEST_ASSERT(!player.has_armor);
    TEST_ASSERT_EQUAL_UINT(1, player.inventory.count);
}

void test_unequip_empty_slot(void)
{
    TEST_ASSERT(entity_unequip(&player, SLOT_WEAPON));
    TEST_ASSERT(!player.has_weapon);
}
