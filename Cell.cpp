//
// Created by Michal on 02.06.2023.
//

#include "Cell.h"

Cell::Cell() : revealed(false), flagged(false) {}

void Cell::reveal() {
    revealed = true;
}

void Cell::flag() {
    flagged = !flagged;
}
