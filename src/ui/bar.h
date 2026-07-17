#pragma once
#include <curses.h>

struct entity_view
{
    char const *name;
    unsigned hp;
    unsigned max;
};

void entity_view_draw(WINDOW *win, int w, int y,
                      struct entity_view const *player,
                      struct entity_view const *monster);
