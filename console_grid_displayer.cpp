#include "console_grid_displayer.hpp"

std::ostream &operator<<(std::ostream &os, const gol::Cell &cell) {
  if (cell == gol::Cell::State::kAlive) {
    os << 'o';
  } else if (cell == gol::Cell::State::kDead) {
    os << ' ';
  }

  return os;
}

namespace gol {
void ConsoleGridDisplayer::display(const Grid &grid) {
  const auto n_rows = grid.cells().size();
  const auto n_columns = grid.cells()[0].size();

  std::cout << "+" << std::string((n_columns * 2) - 1, '-') << "+\n";

  for (size_t i = 0; i < n_rows; ++i) {
    for (size_t j = 0; j < n_columns; ++j) {
      std::cout << "|" << grid.cells()[i][j];

      if (j == n_columns - 1) {
        std::cout << "|\n";
      }
    }
  }

  std::cout << "+" << std::string((n_columns * 2) - 1, '-') << "+\n";
}

void ConsoleGridDisplayer::display_end_of_game(const uint32_t rounds) {
  std::cout << " ____  _   _  ____    ____  _  _  ____\n"
               "(_  _)( )_( )( ___)  ( ___)( \\( )(  _ \\\n"
               "  )(   ) _ (  )__)    )__)  )  (  )(_) )\n"
               " (__) (_) (_)(____)  (____)(_)\\_)(____/\n\n";

  std::cout << "Number of rounds: " << rounds << "\n";
}
}
