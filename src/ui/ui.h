#pragma once
#include <curses.h>

#define BOX_W  60
#define BOX_H  22

void ui_init(void);
WINDOW *ui_window(int origin_y, int origin_x);
void ui_teardown(WINDOW *game);
void draw_separator(WINDOW *win, int y, int w);
