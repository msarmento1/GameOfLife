#pragma once

#include <iostream>

#include "grid_displayer.hpp"

namespace gol {
class ConsoleGridDisplayer final : public GridDisplayer {
 public:
  void display(const Grid &grid) override;
  void display_end_of_game(const uint32_t rounds) override;
};
}  // namespace gol
