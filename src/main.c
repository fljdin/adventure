#include "ui/ui.h"
#include <curses.h>

int main(void)
{
    ui_init();

    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols);

    struct layout ly = layout_make(term_rows, term_cols);

    WINDOW *game = ui_window(&ly);

    werase(game);
    box(game, 0, 0);
    draw_separator(game, 3, BOX_W);
    mvwprintw(game, 1, 2, "Adventure");
    mvwprintw(game, BOX_H - 2, 2, "ESC quitter");

    wnoutrefresh(game);
    doupdate();

    int key;
    do { key = wgetch(game); } while (key != 27);

    ui_teardown(game);
    return 0;
}
