project(Julianne)
add_executable(Julianne main.cpp)
add_executable(Julianne Bitboard.cpp)
add_executable(Julianne Gameboard.cpp)
add_executable(Julianne Game.cpp)
add_executable(Julianne Pieces/Piece.cpp)
add_executable(Julianne Pieces/Queen.cpp)
add_executable(Julianne Pieces/Rook.cpp)
add_executable(Julianne Pieces/Bishop.cpp)
add_executable(Julianne Pieces/King.cpp)
add_executable(Julianne Pieces/Knight.cpp)
add_executable(Julianne Pieces/Pawn.cpp)

set(CMAKE_BUILD_TYPE Debug)
set_property(TARGET Julianne PROPERTY CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g")

#[[Required for C++ 20 standard]]
cmake_minimum_required(VERSION 3.2.0)
