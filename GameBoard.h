//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_GAMEBOARD_H
#define HELLOSFML_GAMEBOARD_H

#include <vector>
#include "Cell.h"

class GameBoard {
private:
    int width;
    int height;
    std::vector<std::vector<Cell*>> grid;

public:
    GameBoard(int boardWidth, int boardHeight);
    ~GameBoard();
    void createBoard();
    void displayBoard() const;
    void revealCell(int x, int y);
    void flagCell(int x, int y);
    bool checkGameStatus() const;
};

#endif //HELLOSFML_GAMEBOARD_H
