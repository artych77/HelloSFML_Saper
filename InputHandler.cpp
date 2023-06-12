//
// Created by Michal on 02.06.2023.
//

#include "InputHandler.h"
#include "GameBoard.h"

InputHandler::InputHandler() = default;

void InputHandler::handleInput(sf::RenderWindow& window,const sf::Event& event, GameBoard& gameBoard) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int x = event.mouseButton.x / 32;
            int y = event.mouseButton.y / 32;

            //fukcja odkrywajaca pole
            gameBoard.revealCell( x, y);
        }
        if (event.mouseButton.button == sf::Mouse::Right) {
            int x = event.mouseButton.x / 32;
            int y = event.mouseButton.y / 32;

            //funkcja do zaznaczania flagi na mapie
            gameBoard.flagCell( x, y);
        }
}
