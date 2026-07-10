#include "combat.h"

void entity_attack_with_func(struct entity *attacker, struct entity *defender, struct dice const *weapon_dice, dice_func_t dice_func)
{
    if (!attacker || !defender || !weapon_dice || !dice_func)
        return;

    struct dice accuracy = { .count = 1, .faces = 20, .bonus = 0 };
    unsigned roll = dice_roll_with_func(&accuracy, dice_func);
    unsigned accuracy_total = roll + attacker->dexterity;

    if (accuracy_total < 10)
        return;

    unsigned damage = dice_roll_with_func(weapon_dice, dice_func) + attacker->strength;

    if (roll == 20)
        damage *= 2;

    entity_take_damage(defender, damage);
}

void entity_attack(struct entity *attacker, struct entity *defender, struct dice const *weapon_dice)
{
    entity_attack_with_func(attacker, defender, weapon_dice, dice_random);
}
