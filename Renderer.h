//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_RENDERER_H
#define HELLOSFML_RENDERER_H

#include "GameBoard.h"

class Renderer {
public:
    Renderer();

    static void displayStartScreen();
    void displayBoard(GameBoard& gameBoard);
    static void displayWinScreen();
    static void displayLoseScreen();

};


#endif //HELLOSFML_RENDERER_H
