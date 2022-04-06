cmake_minimum_required (VERSION 3.7.2)
project (GameOfLife)

find_program(CLANG_TIDY clang-tidy REQUIRED)
if(CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=google-*,bugprone-*,performance-*,portability-*,readability-*")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR})

add_executable (${PROJECT_NAME} cell.cpp displayer/console_grid_displayer.cpp displayer/ncurses_grid_displayer.cpp grid.cpp main.cpp player.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)