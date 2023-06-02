//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_CELL_H
#define HELLOSFML_CELL_H

class Cell {
protected:
    bool revealed;
    bool flagged;

public:
    Cell();
    void reveal();
    void flag();
    virtual void displaySymbol() const = 0;
};

#endif //HELLOSFML_CELL_H
