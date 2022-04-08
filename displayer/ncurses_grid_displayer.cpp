#include "ncurses_grid_displayer.hpp"

#include <ncurses.h>

#include <string>

namespace mms {
NcursesGridDisplayer::NcursesGridDisplayer() {
  setlocale(LC_ALL, "");
  initscr();
}

NcursesGridDisplayer::~NcursesGridDisplayer() {
  getch();
  endwin();
}

void NcursesGridDisplayer::display(const Grid &grid) {
  const auto n_rows = grid.cells().size();
  const auto n_columns = grid.cells()[0].size();

  move(0, 0);

  printw("+%s+\n", std::string(n_columns, '-').c_str());

  for (size_t i = 0; i < n_rows; ++i) {
    printw("|");
    for (size_t j = 0; j < n_columns; ++j) {
      if (grid.cells()[i][j] == mms::Cell::State::kAlive) {
        printw("o");
      } else if (grid.cells()[i][j] == mms::Cell::State::kDead) {
        printw(" ");
      }
    }
    printw("|\n");
  }

  printw("+%s+\n", std::string(n_columns, '-').c_str());

  refresh();
}

void NcursesGridDisplayer::display_end_of_game(const uint32_t rounds) {
  clear();
  move(0, 0);

  printw(" ____  _   _  ____    ____  _  _  ____\n");
  printw("(_  _)( )_( )( ___)  ( ___)( \\( )(  _ \\\n");
  printw("  )(   ) _ (  )__)    )__)  )  (  )(_) )\n");
  printw(" (__) (_) (_)(____)  (____)(_)\\_)(____/\n\n");

  printw("Number of rounds: %i\n", rounds);
  refresh();
}
} // namespace mms
