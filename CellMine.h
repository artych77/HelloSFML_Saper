//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_CELLMINE_H
#define HELLOSFML_CELLMINE_H

#include "Cell.h"

class CellMine : public Cell {
private:
    bool mine;

public:
    CellMine();
    void displaySymbol() const override;
};

#endif //HELLOSFML_CELLMINE_H
