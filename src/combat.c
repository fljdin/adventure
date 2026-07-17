#include "combat.h"

unsigned entity_attack_with_func(struct entity *attacker, struct entity *defender, dice_func_t dice_func)
{
    if (!attacker || !defender || !dice_func)
        return 0;

    struct dice accuracy = { .count = 1, .faces = 20, .bonus = 0 };
    unsigned roll = dice_roll_with_func(&accuracy, dice_func);
    unsigned accuracy_total = roll + attacker->dexterity;

    if (accuracy_total < 10)
        return 0;

    unsigned damage = attacker->strength;

    if (attacker->has_weapon)
        damage += dice_roll_with_func(&attacker->weapon.damage, dice_func);

    if (roll == 20)
        damage *= 2;

    return entity_take_damage(defender, damage);
}

unsigned entity_attack(struct entity *attacker, struct entity *defender)
{
    return entity_attack_with_func(attacker, defender, dice_random);
}

int combat_turn_order(struct entity const *a, struct entity const *b)
{
    if (!a || !b)
        return 0;

    if (a->dexterity > b->dexterity)
        return 1;

    if (a->dexterity < b->dexterity)
        return -1;

    return 0;
}
