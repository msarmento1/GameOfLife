#pragma once

#include <chrono>
#include <memory>

#include "grid.hpp"
#include "grid_displayer.hpp"

using namespace std::chrono_literals;

namespace gol {
class Player {
 public:
  Player(const Grid& grid, std::shared_ptr<GridDisplayer> grid_displayer);

  void play(const std::chrono::milliseconds& refresh_rate = 500ms);

 private:
  void run_round_();
  uint8_t count_alive_neighbours_(const uint32_t x, const uint32_t y);

  Grid grid_;
  std::shared_ptr<GridDisplayer> grid_displayer_;
  uint32_t round_ = 0;
};
}  // namespace gol
