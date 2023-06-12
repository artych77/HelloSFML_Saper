//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_GAMEBOARD_H
#define HELLOSFML_GAMEBOARD_H

#include <vector>
#include "Cell.h"
#include <cstdlib>
#include <ctime>

class GameBoard {
private:
    std::vector<std::vector<Cell*>> grid;
    std::vector<std::vector<int>> board;

public:
    GameBoard(int boardWidth, int boardHeight);
    ~GameBoard();
    void createBoard();
    void displayBoard();
    void revealCell(int x, int y);
    void flagCell(int x, int y);
    bool checkGameStatus() const;

    int height = 10;
    int width = 10;
};

#endif //HELLOSFML_GAMEBOARD_H
