#include "console_grid_displayer.hpp"
#include "grid.hpp"
#include "player.hpp"

#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
  try {
    Grid grid(10, 5);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    for (auto &columns : grid.cells()) {
      for (auto &cell : columns) {
        if (dist(rng)) {
          cell = Cell::State::kAlive;
        }
      }
    }

    ConsoleGridDisplayer consoleGridDisplayer;

    // Create your own GridDisplayer and pass it to Player
    Player player(grid, consoleGridDisplayer);
    player.Play();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}