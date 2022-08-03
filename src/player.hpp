#pragma once

#include <chrono>
#include <memory>

#include "displayer/grid_displayer.hpp"
#include "grid.hpp"

using namespace std::chrono_literals;

namespace mms {
class Player {
 public:
  Player(const Grid& grid,
         const std::shared_ptr<GridDisplayer>& grid_displayer);

  void play(const std::chrono::milliseconds& refresh_rate);

 private:
  void run_round_();
  uint8_t count_alive_neighbours_(const uint32_t x, const uint32_t y);

  Grid grid_;
  std::shared_ptr<GridDisplayer> grid_displayer_;
  uint32_t round_ = 0;
};
}  // namespace mms
