//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_INPUTHANDLER_H
#define HELLOSFML_INPUTHANDLER_H

#include <SFML/Graphics.hpp>


class InputHandler {
public:
    InputHandler();

    void handleInput(sf::RenderWindow& window);

};


#endif //HELLOSFML_INPUTHANDLER_H
