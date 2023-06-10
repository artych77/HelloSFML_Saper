//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_CELLNUMBER_H
#define HELLOSFML_CELLNUMBER_H

#include "Cell.h"
#include <SFML/Graphics.hpp>

class CellNumber : Cell {
private:
    int surroundingMines;

public:
    CellNumber(int mines);
    void displaySymbol() const override;
};

#endif //HELLOSFML_CELLNUMBER_H
