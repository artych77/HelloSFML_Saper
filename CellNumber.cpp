//
// Created by Michal on 02.06.2023.
//

#include "CellNumber.h"

CellNumber::CellNumber(int mines) : surroundingMines(mines) {}

void CellNumber::displaySymbol() const {
    //rysowanie symbolu (wartosci ile min dookola)
    sf::Texture t;
    t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
    sf::Sprite s(t);

    if (revealed) {
        // Komórka odkryta - rysuje wartość
        s.setTextureRect(sf::IntRect (surroundingMines * 32, 0, 32, 32));
        }

    else {
        if (flagged){
            // Komórka zaznaczona - rysuje flage
            s.setTextureRect(sf::IntRect (11 * 32, 0, 32, 32));
        }
        else{
            // Komórka nieodkryta - rysuje puste tło
            s.setTextureRect(sf::IntRect (10 * 32, 0, 32, 32));
        }

    }
}
