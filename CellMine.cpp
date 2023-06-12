//
// Created by Michal on 02.06.2023.
//

#include "CellMine.h"

CellMine::CellMine() : mine(true) {}

void CellMine::displaySymbol() const {
    //rysowanie symbolu
    sf::Texture t;
    t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
    sf::Sprite s(t);
    if (revealed) {
        // Komórka odkryta - rysuje wartość lub minę
        if (mine) {
            //Kod rysujący minę na komórce
            s.setTextureRect(sf::IntRect (9 * 32, 0, 32, 32));
        }
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