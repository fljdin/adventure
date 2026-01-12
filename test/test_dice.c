#include "unity.h"
#include "dice.h"

unsigned int always_max(unsigned int max)
{
    return max;
}

void test_dice_roll_1d6_plus_2(void)
{
    struct dice d6_plus_2 = { .count = 1, .faces = 6, .bonus = 2 };
    int result = dice_roll_with_func(&d6_plus_2, always_max);

    TEST_ASSERT_EQUAL_INT(8, result);
}

void test_dice_roll_3d20_plus_5(void)
{
    struct dice d20_plus_5 = { .count = 3, .faces = 20, .bonus = 5 };
    int result = dice_roll_with_func(&d20_plus_5, always_max);

    TEST_ASSERT_EQUAL_INT(65, result);
}

void test_dice_roll_1d100_minus_50(void)
{
    struct dice d100_minus_50 = { .count = 1, .faces = 100, .bonus = -50 };
    int result = dice_roll_with_func(&d100_minus_50, always_max);

    TEST_ASSERT_EQUAL_INT(50, result);
}
