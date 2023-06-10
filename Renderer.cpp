//
// Created by Michal on 02.06.2023.
//

#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Renderer::Renderer() {}

void Renderer::displayStartScreen() {
    // Wyświetlanie ekranu startowego
    sf::RenderWindow window(sf::VideoMode(800, 600), "Wprowadź swoje imię");
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Michal\\OneDrive\\Dokumenty\\hack2022\\HelloSFML_Saper\\fonts\\arial.ttf")) {
        std::cout << "Błąd ładowania czcionki." << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Wprowadź swoje imię:");
    text.setPosition(20, 20);

    sf::RectangleShape inputBox(sf::Vector2f(300, 40));
    inputBox.setPosition(20, 60);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(100, 100);

    std::string playerName;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode != 8) {
                    playerName += static_cast<char>(event.text.unicode);
                    inputText.setString(playerName);
                }
                else if (event.text.unicode == 8 && !playerName.empty()) {
                    playerName.pop_back();
                    inputText.setString(playerName);
                }
            }
        }

        window.clear();
        window.draw(inputText);
        window.display();
    }
}

void Renderer::displayBoard(const GameBoard& gameBoard) {
    // Wyświetlanie planszy
}

void Renderer::displayWinScreen() {
    // Wyświetlanie ekranu wygranej
}

void Renderer::displayLoseScreen() {
    // Wyświetlanie ekranu przegranej
}
