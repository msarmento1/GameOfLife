#pragma once

#include "grid.hpp"

class GridDisplayer {
public:
  virtual void Display(const Grid &grid) = 0;
  virtual void DisplayEndOfGame(const uint32_t rounds) = 0;
};