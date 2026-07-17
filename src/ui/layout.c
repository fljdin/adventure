#include "layout.h"

struct layout layout_make(int term_rows, int term_cols)
{
    struct layout l = { 0 };
    l.ox = (term_cols - BOX_W) / 2;
    l.oy = (term_rows - BOX_H) / 2;
    if (l.ox < 0) l.ox = 0;
    if (l.oy < 0) l.oy = 0;

    l.hp_y   = 1;
    l.sep1_y = 4;
    l.log_y  = 5;
    l.sep2_y = l.log_y + LOG_LINES;
    l.menu_y = l.sep2_y + 1;
    l.st_y   = BOX_H - 2;
    return l;
}

void layout_recenter(struct layout *l, int term_rows, int term_cols)
{
    l->ox = (term_cols - BOX_W) / 2;
    l->oy = (term_rows - BOX_H) / 2;
    if (l->ox < 0) l->ox = 0;
    if (l->oy < 0) l->oy = 0;
}
