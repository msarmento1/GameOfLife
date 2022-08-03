#pragma once

#include "grid_displayer.hpp"

namespace mms {
class ConsoleGridDisplayer final : public GridDisplayer {
 public:
  void display(const Grid &grid) override;
  void display_end_of_game(const uint32_t rounds) override;
};
}  // namespace mms
