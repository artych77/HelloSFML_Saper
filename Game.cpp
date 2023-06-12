//
// Created by Michal on 02.06.2023.
//

#include "Game.h"
#include <iostream>

Game::Game(int width, int height)
        : gameBoard(width, height), player(), gameManager(), renderer(){}

void Game::startGame()
{
    std::string playerName;
    renderer.displayStartScreen();

    player.setName(playerName);
    gameManager.initializeGame(playerName);

    gameLoop();
}

void Game::gameLoop()
{
    bool isGameRunning = true;
    gameBoard.createBoard();

    while (isGameRunning)
    {

        gameBoard.displayBoard();

        isGameRunning = !gameManager.isGameOver();
    }

    if (gameManager.isGameWon())
    {
        renderer.displayWinScreen();
    }
    else
    {
        renderer.displayLoseScreen();
    }
}

