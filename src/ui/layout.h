#pragma once

#define BOX_W      60
#define BOX_H      22
#define LOG_BUF    64
#define LOG_LINES  12
#define BAR_W      10

struct layout
{
    int ox, oy;
    int hp_y, sep1_y, log_y, sep2_y, menu_y, st_y;
};

struct layout layout_make(int term_rows, int term_cols);
void layout_recenter(struct layout *l, int term_rows, int term_cols);
