//
// Created by Michal on 02.06.2023.
//

#include "InputHandler.h"
#include "GameBoard.h"
#include "GameManager.h"

InputHandler::InputHandler() {}

void InputHandler::handleInput(sf::RenderWindow& window, GameBoard& gameBoard) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.mouseButton.button == sf::Mouse::Left) {
            int x = event.mouseButton.x / 32;
            int y = event.mouseButton.y / 32;

            //fukcja odkrywajaca pole
            gameBoard.revealCell(x, y);
        }
        if (event.mouseButton.button == sf::Mouse::Right) {
            int x = event.mouseButton.x / 32;
            int y = event.mouseButton.y / 32;

            //funkcja do zaznaczania flagi na mapie
            gameBoard.flagCell(x, y);
        }
    }
}
