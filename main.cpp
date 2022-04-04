#include <iostream>
#include <random>

#include "displayer/console_grid_displayer.hpp"
#include "displayer/ncurses_grid_displayer.hpp"
#include "grid.hpp"
#include "player.hpp"

int main(int argc, char *argv[]) {
  try {
    mms::Grid grid(10, 10);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    for (auto &columns : grid.cells()) {
      for (auto &cell : columns) {
        if (dist(rng)) {
          cell = mms::Cell::State::kAlive;
        }
      }
    }

    std::shared_ptr<mms::GridDisplayer> displayer = nullptr;
    // displayer = std::make_shared<mms::ConsoleGridDisplayer>();
    displayer = std::make_shared<mms::NcursesGridDisplayer>();

    // Grid is internally copied
    // Create your own GridDisplayer and pass it to Player
    mms::Player player(grid, displayer);
    player.play();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}