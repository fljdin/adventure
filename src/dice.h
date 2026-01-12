#pragma once

typedef unsigned (*dice_func_t)(unsigned);

struct dice
{
    unsigned count;
    unsigned faces;
    int bonus;
};

unsigned dice_random(unsigned max);
unsigned dice_roll(struct dice const *d);
unsigned dice_roll_with_func(struct dice const *d, dice_func_t dice_func);
