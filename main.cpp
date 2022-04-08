#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <random>

#include <boost/program_options.hpp>

#include "displayer/console_grid_displayer.hpp"
#include "displayer/ncurses_grid_displayer.hpp"
#include "grid.hpp"
#include "player.hpp"

namespace bpo = boost::program_options;

int main(int argc, char *argv[]) {
  try {
    bpo::options_description desc{"Options"};

    // clang-format off
    desc.add_options()
      ("help,h", "Help screen")
      ("columns,c", bpo::value<uint32_t>()->required(), "Columns")
      ("rows,r", bpo::value<uint32_t>()->required(), "Rows")
      ("displayer,d", 
        bpo::value<uint16_t>()->default_value(
          mms::GridDisplayer::Options::kNcurses),
          "Displayer")
      ("refresh-rate", bpo::value<int64_t>()->default_value(100),
       "Refresh rate in millisseconds");
    // clang-format on

    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help") != 0U) {
      std::cout << desc << '\n';
      return EXIT_SUCCESS;
    }

    bpo::notify(vm);

    mms::Grid grid(vm["columns"].as<uint32_t>(), vm["rows"].as<uint32_t>());

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

    for (auto &columns : grid.cells()) {
      for (auto &cell : columns) {
        if (dist(rng) != 0U) {
          cell = mms::Cell::State::kAlive;
        }
      }
    }

    std::shared_ptr<mms::GridDisplayer> displayer = nullptr;

    const auto display_chosen = vm["displayer"].as<uint16_t>();

    switch (display_chosen) {
    case mms::GridDisplayer::kConsole:
      displayer = std::make_shared<mms::ConsoleGridDisplayer>();
      break;

    case mms::GridDisplayer::kNcurses:
      displayer = std::make_shared<mms::NcursesGridDisplayer>();
      break;

    default:
      std::cerr << "Invalid displayer: " << display_chosen << "\n";
      return EXIT_FAILURE;
    }

    // Grid is internally copied
    // Create your own GridDisplayer and pass it to Player
    mms::Player player(grid, displayer);
    player.play(std::chrono::milliseconds(vm["refresh-rate"].as<int64_t>()));
    return EXIT_SUCCESS;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
}