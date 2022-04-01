#pragma once

#include "grid.hpp"

namespace gol {
class GridDisplayer {
 public:
  virtual void display(const Grid &grid) = 0;
  virtual void display_end_of_game(const uint32_t rounds) = 0;
};
}