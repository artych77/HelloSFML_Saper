//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_RENDERER_H
#define HELLOSFML_RENDERER_H

#include "GameBoard.h"

class Renderer {
public:
    Renderer();

    void displayStartScreen();
    void displayBoard(const GameBoard& gameBoard);
    void displayWinScreen();
    void displayLoseScreen();

};


#endif //HELLOSFML_RENDERER_H
