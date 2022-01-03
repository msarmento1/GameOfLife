#include "console_grid_displayer.hpp"

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
  if (cell == Cell::State::kAlive) {
    os << 'o';
  } else if (cell == Cell::State::kDead) {
    os << ' ';
  }

  return os;
}

void ConsoleGridDisplayer::Display(const Grid &grid) {
  const auto nRows = grid.cells().size();
  const auto nColumns = grid.cells()[0].size();

  std::cout << "+" << std::string((nColumns * 2) - 1, '-') << "+\n";

  for (size_t i = 0; i < nRows; ++i) {
    for (size_t j = 0; j < nColumns; ++j) {
      std::cout << "|" << grid.cells()[i][j];

      if (j == nColumns - 1) {
        std::cout << "|\n";
      }
    }
  }

  std::cout << "+" << std::string((nColumns * 2) - 1, '-') << "+\n";
}

void ConsoleGridDisplayer::DisplayEndOfGame(const uint32_t rounds) {
  std::cout << " ____  _   _  ____    ____  _  _  ____\n"
               "(_  _)( )_( )( ___)  ( ___)( \\( )(  _ \\\n"
               "  )(   ) _ (  )__)    )__)  )  (  )(_) )\n"
               " (__) (_) (_)(____)  (____)(_)\\_)(____/\n\n";

  std::cout << "Number of rounds: " << rounds << "\n";
}
