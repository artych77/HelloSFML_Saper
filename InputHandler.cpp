//
// Created by Michal on 02.06.2023.
//

#include "InputHandler.h"

InputHandler::InputHandler() {}

void InputHandler::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Obsługa innych zdarzeń wejściowych
    }
}
