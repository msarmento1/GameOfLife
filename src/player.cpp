#include "player.hpp"

#include <algorithm>
#include <stdexcept>
#include <thread>

namespace mms {
Player::Player(const Grid &grid,
               const std::shared_ptr<GridDisplayer> &grid_displayer)
    : grid_(grid), grid_displayer_(grid_displayer) {
  if (grid_displayer == nullptr) {
    throw std::runtime_error("grid displayer is null");
  }
}

void Player::play(const std::chrono::milliseconds &refresh_rate) {
  while (true) {
    const auto game_ended = std::all_of(
        std::begin(grid_.cells()), std::end(grid_.cells()),
        [](const auto &row) {
          return std::all_of(
              std::begin(row), std::end(row),
              [](const auto &cell) { return cell == Cell::State::kDead; });
        });

    if (game_ended) {
      grid_displayer_->display_end_of_game(round_);
      return;
    }

    grid_displayer_->display(grid_);
    std::this_thread::sleep_for(refresh_rate);
    run_round_();
  }
}

void Player::run_round_() {
  // #1 - Any live cell with two or three live neighbours survives.
  // #2 - Any dead cell with three live neighbours becomes a live cell.
  // #3 - All other live cells die in the next generation. Similarly, all other
  // dead cells stay dead.

  const auto n_rows = grid_.cells().size();
  const auto n_columns = grid_.cells()[0].size();

  auto new_grid(grid_);

  for (size_t i = 0; i < n_rows; ++i) {
    for (size_t j = 0; j < n_columns; ++j) {
      const auto alive_neighbours = count_alive_neighbours_(i, j);

      if (grid_.cells()[i][j] == Cell::State::kAlive) {
        if (alive_neighbours != 2 && alive_neighbours != 3) {
          new_grid.set_state(i, j, Cell::State::kDead);
        }
      } else {
        if (alive_neighbours == 3) {
          new_grid.set_state(i, j, Cell::State::kAlive);
        }
      }
    }
  }

  ++round_;
  grid_ = new_grid;
}

uint8_t Player::count_alive_neighbours_(const uint32_t x, const uint32_t y) {
  const auto n_rows = grid_.cells().size();
  const auto n_columns = grid_.cells()[0].size();

  uint8_t counter = 0;

  for (uint32_t i = x - 1; i <= x + 1; ++i) {
    for (uint32_t j = y - 1; j <= y + 1; ++j) {
      if (i == x && j == y) {
        continue;
      }

      if (i >= 0 && i <= n_rows - 1 && j >= 0 && j <= n_columns - 1) {
        counter += (grid_.cells()[i][j] == Cell::State::kAlive) ? 1 : 0;
      }
    }
  }

  return counter;
}
}  // namespace mms
