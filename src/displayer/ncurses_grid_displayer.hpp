#pragma once

#include "grid_displayer.hpp"

namespace mms {
class NcursesGridDisplayer final : public GridDisplayer {
 public:
  NcursesGridDisplayer();
  virtual ~NcursesGridDisplayer();
  void display(const Grid &grid) override;
  void display_end_of_game(const uint32_t rounds) override;
};
}  // namespace mms
