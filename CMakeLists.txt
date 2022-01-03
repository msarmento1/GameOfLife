cmake_minimum_required (VERSION 2.8.11)
project (GameOfLife)

add_executable (${PROJECT_NAME} cell.cpp console_grid_displayer.cpp grid.cpp main.cpp player.cpp)
