#pragma once

class Cell {
public:
  enum class State { kAlive, kDead };

  bool operator==(const State &state) const;
  Cell &operator=(const State &state);

private:
  State state_ = State::kDead;
};