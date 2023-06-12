cmake_minimum_required(VERSION 3.24)
project(HelloSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloSFML main.cpp Renderer.h CellMine.cpp CellNumber.cpp Cell.cpp CellEmpty.cpp GameBoard.h GameBoard.cpp InputHandler.h InputHandler.cpp Player.h Player.cpp Renderer.cpp Game.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

INCLUDE_DIRECTORIES(C::/SFML-2.5.1/include)
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
