#pragma once

#include "grid.hpp"
#include "grid_displayer.hpp"

#include <chrono>
#include <memory>

class Player {
public:
  Player(Grid &grid, GridDisplayer &grid_displayer);

  void Play(const std::chrono::milliseconds &refresh_rate =
                std::chrono::milliseconds(500));

private:
  void RunRound();
  uint8_t CountAliveNeighbours(const uint32_t x, const uint32_t y);

  Grid &grid_;
  GridDisplayer *grid_displayer_;
  uint32_t round_ = 0;
};