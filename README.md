# Game of Life

My implementation of Game of Life using the best practices of C++.

## Build
`clang-tidy` is required

`$ mkdir build`

`$ cd build`

`$ conan install ..`

`$ cmake .. -DCMAKE_BUILD_TYPE=Release`

`$ make`

## Execute
`$ bin/GameOfLife`

## Ncurses
Install package `ncurses-term` and export the following environment variables to your .bashrc:

`export TERMINFO=/usr/share/terminfo`

`export TERM=xterm-basic`

## Coding style used (clang-format)
Google