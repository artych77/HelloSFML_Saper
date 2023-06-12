//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_GAME_H
#define HELLOSFML_GAME_H

#include "string"
#include "GameBoard.h"
#include "Player.h"
#include "GameManager.h"
#include "Renderer.h"
#include "InputHandler.h"

class Game {
public:
    Game(int width, int height);
    void startGame();

private:
    GameBoard gameBoard;
    Player player;
    GameManager gameManager;
    Renderer renderer;

    void gameLoop();
};


#endif //HELLOSFML_GAME_H
