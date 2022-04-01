#include "cell.hpp"

namespace gol {
bool Cell::operator==(const State &state) const { return state_ == state; }

Cell &Cell::operator=(const State &state) {
  state_ = state;
  return *this;
}
}  // namespace gol
