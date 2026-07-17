#include "ui.h"

void ui_init(void)
{
    initscr();
    set_escdelay(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

WINDOW *ui_window(struct layout const *l)
{
    WINDOW *game = newwin(BOX_H, BOX_W, l->oy, l->ox);
    keypad(game, TRUE);
    return game;
}

void ui_teardown(WINDOW *game)
{
    delwin(game);
    endwin();
}

void draw_separator(WINDOW *win, int y, int w)
{
    mvwaddch(win, y, 0, ACS_LTEE);
    mvwhline(win, y, 1, ACS_HLINE, w - 2);
    mvwaddch(win, y, w - 1, ACS_RTEE);
}
