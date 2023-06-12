//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_CELL_H
#define HELLOSFML_CELL_H

class Cell {

public:
    Cell();
    virtual void displaySymbol() const = 0;

    bool revealed;
    bool flagged;
};

#endif //HELLOSFML_CELL_H
