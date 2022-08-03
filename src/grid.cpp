#include "grid.hpp"

#include <stdexcept>

namespace mms {
Grid::Grid(const uint32_t rows, const uint32_t columns) {
  if (rows < 0) {
    throw std::invalid_argument("rows should be greater than zero");
  }

  if (columns < 0) {
    throw std::invalid_argument("columns should be greater than zero");
  }

  cells_.resize(rows, std::vector<Cell>(columns));
}

void Grid::set_state(const uint32_t x, const uint32_t y,
                     const Cell::State state) {
  if (x > cells_.size()) {
    throw std::invalid_argument("invalid x value: " + std::to_string(y));
  }

  if (y > cells_[0].size()) {
    throw std::invalid_argument("invalid y value: " + std::to_string(x));
  }

  cells_[x][y] = state;
}

const std::vector<std::vector<Cell>> &Grid::cells() const { return cells_; }
std::vector<std::vector<Cell>> &Grid::cells() { return cells_; }
}  // namespace mms
