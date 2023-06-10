//
// Created by Michal on 02.06.2023.
//

#include "CellEmpty.h"

CellEmpty::CellEmpty() {}

void CellEmpty::displaySymbol() const {
    //Rysowanie pustego symbolu
    sf::Texture t;
    t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
    sf::Sprite s(t);

    if (revealed) {
        // Komórka odkryta
        s.setTextureRect(sf::IntRect ( 0, 0, 32, 32));
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
