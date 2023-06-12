//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_INPUTHANDLER_H
#define HELLOSFML_INPUTHANDLER_H

#include <SFML/Graphics.hpp>
#include "GameBoard.h"


class InputHandler {
public:
    InputHandler();

    void handleInput(sf::RenderWindow& window,const sf::Event& event, GameBoard& gameBoard);

};


#endif //HELLOSFML_INPUTHANDLER_H
