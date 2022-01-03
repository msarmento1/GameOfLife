#pragma once

#include "grid_displayer.hpp"

#include <iostream>

class ConsoleGridDisplayer : public GridDisplayer {
public:
  void Display(const Grid &grid) override;
  void DisplayEndOfGame(const uint32_t rounds) override;
};
