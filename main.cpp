#include <iostream>
#include <random>

#include "console_grid_displayer.hpp"
#include "grid.hpp"
#include "player.hpp"

int main(int argc, char *argv[]) {
  try {
    gol::Grid grid(10, 10);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    for (auto &columns : grid.cells()) {
      for (auto &cell : columns) {
        if (dist(rng)) {
          cell = gol::Cell::State::kAlive;
        }
      }
    }

    auto console_grid_displayer =
        std::make_shared<gol::ConsoleGridDisplayer>();

    // Create your own GridDisplayer and pass it to Player
    gol::Player player(grid, console_grid_displayer);
    player.play(100ms);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}