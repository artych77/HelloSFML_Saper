//
// Created by Michal on 02.06.2023.
//

#include "GameBoard.h"
#include "CellEmpty.h"
#include "CellMine.h"
#include "CellNumber.h"
//Nie rozumiem dlaczego nie dziła mi #include "Cell.h" i muszę wpisywać szystko osobno

GameBoard::GameBoard(int boardWidth, int boardHeight)
        : width(boardWidth), height(boardHeight), grid(boardHeight, std::vector<Cell*>(boardWidth, nullptr)) {
}

GameBoard::~GameBoard() {
    // Zwalnianie pamięci zajmowanej przez pola w siatce
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            delete grid[i][j];
        }
    }
}

void GameBoard::createBoard() {
    // Tworzenie siatki pól
    grid.resize(height);
    for (int i = 0; i < height; ++i) {
        grid[i].resize(width);
        for (int j = 0; j < width; ++j) {
            // Tworzenie pustych pól
            grid[i][j] = new CellEmpty();
        }
    }

    // Tutaj bedzie kod do losowego rozmieszczenia min i pól liczbowych na planszy
}


void GameBoard::displayBoard() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j]->displaySymbol();
        }
    }
}

void GameBoard::revealCell(int x, int y) {
    // Odkrywanie zawartości komórki o podanych współrzędnych
}

void GameBoard::flagCell(int x, int y) {
    // Oznaczanie komórki o podanych współrzędnych jako flagowaną
}

bool GameBoard::checkGameStatus() const {
    // Sprawdzanie stanu gry, czy gra została wygrana lub przegrana
    return false;
}