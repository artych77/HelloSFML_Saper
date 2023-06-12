//
// Created by Michal on 02.06.2023.
//

#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Renderer::Renderer() = default;

void Renderer::displayStartScreen() {
    // Wyświetlanie ekranu startowego
   setlocale(LC_CTYPE, "Polish");
    //problem z polskimi znakami
    sf::RenderWindow window(sf::VideoMode(300, 200), "Wprowadz swoje imie");
    sf::Font font;
    font.loadFromFile(R"(C:\Users\Michal\OneDrive\Dokumenty\hack2022\HelloSFML_Saper\fonts\arial.ttf)");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString("Wprowadz swoje imie:");
    text.setPosition(20, 20);

    sf::RectangleShape inputBox(sf::Vector2f(300, 40));
    inputBox.setPosition(20, 60);
    inputBox.setOutlineColor(sf::Color::Green);
    inputBox.setOutlineThickness(2);
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(100, 100);

    std::string playerName;

    while (window.isOpen()) {
        sf::Event event{};
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
        window.draw(text);
        window.draw(inputText);
        window.display();

    }
}

void Renderer::displayBoard(GameBoard& gameBoard) {
    // Wyświetlanie planszy
   // gameBoard.displayBoard(window);
}

void Renderer::displayWinScreen() {
    // Wyświetlanie ekranu wygranej
    sf::RenderWindow window(sf::VideoMode(400, 300), "Wygrana!");

    sf::Font font;
    font.loadFromFile(R"(C:\Users\Michal\OneDrive\Dokumenty\hack2022\HelloSFML_Saper\fonts\arial.ttf)");


    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setString("Wygrana!");
    text.setPosition(100, 100);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }
}

void Renderer::displayLoseScreen() {
    // Wyświetlanie ekranu przegranej
    sf::RenderWindow window(sf::VideoMode(400, 300), "Przegrana!");

    sf::Font font;
    font.loadFromFile(R"(C:\Users\Michal\OneDrive\Dokumenty\hack2022\HelloSFML_Saper\fonts\arial.ttf)");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setString("Przegrana!");
    text.setPosition(100, 100);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }
}
