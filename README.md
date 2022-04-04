# Game of Life

My implementation of Game of Life using the best practices of C++.

## Build
`$ mkdir build`

`$ cd build`

`$ conan install ..`

`$ cmake .. -DCMAKE_BUILD_TYPE=Release`

`$ make`

## Execute
`$ bin/GameOfLife`

## Ncurses
Might need to export the following environment variables in your .bashrc

`export TERMINFO=/usr/share/terminfo`

`export TERM=xterm-basic`

## Clang-format
Google