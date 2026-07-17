#include "ui/ui.h"
#include "ui/log.h"
#include <curses.h>

int main(void)
{
    ui_init();

    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols);

    struct layout ly = layout_make(term_rows, term_cols);

    WINDOW *game = ui_window(&ly);

    struct log log;
    log_init(&log);
    log_add(&log, "Bienvenue dans le donjon !");

    werase(game);
    box(game, 0, 0);
    draw_separator(game, 3, BOX_W);
    mvwprintw(game, 1, 2, "Adventure");
    log_draw(&log, game, 4, BOX_W, LOG_LINES);
    mvwprintw(game, BOX_H - 2, 2, "ESC quitter");

    wnoutrefresh(game);
    doupdate();

    int key;
    do { key = wgetch(game); } while (key != 27);

    ui_teardown(game);
    return 0;
}
