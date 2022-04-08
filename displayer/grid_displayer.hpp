#pragma once

#include "grid.hpp"

namespace mms {
class GridDisplayer {
public:
  enum Options { kConsole = 0, kNcurses };

  virtual void display(const Grid &grid) = 0;
  virtual void display_end_of_game(const uint32_t rounds) = 0;
};
} // namespace mms