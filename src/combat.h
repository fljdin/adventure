#pragma once
#include "dice.h"
#include "entity.h"

void entity_attack(struct entity *attacker, struct entity *defender);
void entity_attack_with_func(struct entity *attacker, struct entity *defender, dice_func_t dice_func);
int combat_turn_order(struct entity const *a, struct entity const *b);
