//
// Created by Michal on 02.06.2023.
//

#include "Game.h"
#include <iostream>

Game::Game(int width, int height)
        : gameBoard(width, height), player(), gameManager(), renderer(), inputHandler()
{
}

void Game::startGame()
{
    std::string playerName = getPlayerName();
    player.setName(playerName);

    gameManager.initializeGame(playerName);

    gameLoop();
}

void Game::gameLoop()
{
    bool isGameRunning = true;

    while (isGameRunning)
    {
        renderer.displayBoard(gameBoard);

        std::string input;
        std::cout << "Enter your move: ";
        std::cin >> input;

        handleInput(input);

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

void Game::handleInput(const std::string& input)
{
    inputHandler.handleInput();
}

std::string Game::getPlayerName()
{
    /*std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;
    return playerName; */ // Jakas fukcja do pobierania imienia
}