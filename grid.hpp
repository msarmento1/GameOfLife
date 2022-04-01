#pragma once

#include <cstdint>
#include <vector>

#include "cell.hpp"

namespace gol {
class Grid {
 public:
  Grid(const uint32_t rows, const uint32_t columns);
  void set_state(const uint32_t x, const uint32_t y, const Cell::State state);

  const std::vector<std::vector<Cell>> &cells() const;
  std::vector<std::vector<Cell>> &cells();

 private:
  std::vector<std::vector<Cell>> cells_;
};
}  // namespace gol
