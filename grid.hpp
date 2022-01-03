#pragma once

#include "cell.hpp"

#include <cstdint>
#include <vector>

class Grid {
public:
  Grid(const uint32_t rows, const uint32_t columns);
  void SetState(uint32_t x, uint32_t y, const Cell::State state);

  const std::vector<std::vector<Cell>> &cells() const;
  std::vector<std::vector<Cell>> &cells();

private:
  std::vector<std::vector<Cell>> cells_;
};