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
    InputHandler inputHandler;

    void gameLoop();
    void handleInput(const std::string& input);
    std::string getPlayerName();
};


#endif //HELLOSFML_GAME_H