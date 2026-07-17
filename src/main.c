#include "ui/ui.h"
#include "ui/log.h"
#include "ui/bar.h"
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

    struct entity_view player = { .name = "Player", .hp = 20, .max = 30 };
    struct entity_view goblin  = { .name = "Gobelin", .hp = 5, .max = 10 };

    werase(game);
    box(game, 0, 0);
    entity_view_draw(game, BOX_W, ly.hp_y, &player, &goblin);
    draw_separator(game, ly.sep1_y, BOX_W);
    log_draw(&log, game, ly.log_y, BOX_W, LOG_LINES);
    draw_separator(game, ly.sep2_y, BOX_W);
    mvwprintw(game, BOX_H - 2, 2, "ESC quitter");

    wnoutrefresh(game);
    doupdate();

    int key;
    do { key = wgetch(game); } while (key != 27);

    ui_teardown(game);
    return 0;
}
