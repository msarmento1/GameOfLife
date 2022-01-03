#include "player.hpp"

#include <algorithm>
#include <thread>

Player::Player(Grid &grid, GridDisplayer &grid_displayer)
    : grid_(grid), grid_displayer_(&grid_displayer) {}

void Player::Play(const std::chrono::milliseconds &refresh_rate) {
  while (true) {
    const auto gameEnded =
        std::all_of(std::begin(grid_.cells()), std::end(grid_.cells()),
                    [](const auto &row) {
                      return std::all_of(std::begin(row), std::end(row),
                                         [](const auto &cell) {
                                           return cell == Cell::State::kDead;
                                         });
                    });

    if (gameEnded) {
      grid_displayer_->DisplayEndOfGame(round_);
      return;
    }

    grid_displayer_->Display(grid_);
    std::this_thread::sleep_for(refresh_rate);
    RunRound();
  }
}

void Player::RunRound() {
  // #1 - Any live cell with two or three live neighbours survives.
  // #2 - Any dead cell with three live neighbours becomes a live cell.
  // #3 - All other live cells die in the next generation. Similarly, all other
  // dead cells stay dead.

  const auto nRows = grid_.cells().size();
  const auto nColumns = grid_.cells()[0].size();

  auto newGrid(grid_);

  for (size_t i = 0; i < nRows; ++i) {
    for (size_t j = 0; j < nColumns; ++j) {
      const auto aliveNeighbours = CountAliveNeighbours(i, j);

      if (grid_.cells()[i][j] == Cell::State::kAlive) {
        if (aliveNeighbours != 2 && aliveNeighbours != 3) {
          newGrid.SetState(i, j, Cell::State::kDead);
        }
      } else {
        if (aliveNeighbours == 3) {
          newGrid.SetState(i, j, Cell::State::kAlive);
        }
      }
    }
  }

  grid_ = newGrid;
  ++round_;
}

uint8_t Player::CountAliveNeighbours(const uint32_t x, const uint32_t y) {
  const auto nRows = grid_.cells().size();
  const auto nColumns = grid_.cells()[0].size();

  uint8_t counter = 0;

  for (int i = x - 1; i <= x + 1; ++i) {
    for (int j = y - 1; j <= y + 1; ++j) {
      if (i == x && j == y) {
        continue;
      }

      if (i >= 0 && i <= nRows - 1 && j >= 0 && j <= nColumns - 1) {
        counter += (grid_.cells()[i][j] == Cell::State::kAlive) ? 1 : 0;
      }
    }
  }

  return counter;
}
