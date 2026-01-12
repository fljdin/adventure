#pragma once

typedef unsigned (*dice_func_t)(unsigned);

typedef struct {
    unsigned count;
    unsigned faces;
    int bonus;
} dice_t;

unsigned dice_random(unsigned max);
unsigned dice_roll(dice_t const *d);
unsigned dice_roll_with_func(dice_t const *d, dice_func_t dice_func);
