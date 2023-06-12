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

        sf::RenderWindow window(sf::VideoMode(500, 400), "Minesweeper");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    inputHandler.handleInput(window, event, gameBoard);
                }
            }

            window.clear();
            gameBoard.displayBoard(window);
            window.display();
            if(gameBoard.checkGameStatus()){
                break;
            }
        }



    if (gameBoard.checkGameStatus())
    {
        renderer.displayWinScreen();
    }
    else
    {
        renderer.displayLoseScreen();
    }
}

