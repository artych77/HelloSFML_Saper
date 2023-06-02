//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_CELLEMPTY_H
#define HELLOSFML_CELLEMPTY_H

#include "Cell.h"

class CellEmpty : public Cell {
public:
    CellEmpty();
    void displaySymbol() const override;
};

#endif //HELLOSFML_CELLEMPTY_H
