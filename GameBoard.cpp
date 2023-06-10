//
// Created by Michal on 02.06.2023.
//

#include "GameBoard.h"
#include "CellEmpty.h"
#include "CellMine.h"
#include "CellNumber.h"
//Nie rozumiem dlaczego nie dziła mi #include "Cell.h" i muszę wpisywać szystko osobno
#include <cstdlib>
#include <ctime>

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
    // Inicjalizacja planszy z pustymi polami
        // Tworzenie siatki pól
        grid.resize(height);
        board.resize(height);
        for (int i = 0; i < height; ++i) {
            grid[i].resize(width);
            board[i].resize(width, 0); // Inicjalizacja wartości komórek na 0

            for (int j = 0; j < width; ++j) {
                // Tworzenie pustych pól
                grid[i][j] = new CellEmpty();
            }
        }
        // Generowanie min
        int generatedMines = 0;
        while (generatedMines < 10) {
            int x = rand() % width;
            int y = rand() % height;

            if (board[y][x] != -1) {
                // Jeśli pole nie jest miną, zamień je na pole z miną
                delete grid[y][x];
                grid[y][x] = new CellMine();
                board[y][x] = -1;
                ++generatedMines;
            }
        }
    // Obliczanie liczby min sąsiadujących z każdym polem
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (board[y][x] != -1) {
                int count = 0;

                // Sprawdzanie sąsiadujących pól
                if (y > 0 && x > 0 && board[x-1][y-1] == -1) count++;
                if (x > 0 && board[x-1][y] == -1) count++;
                if (y < width-1 && x > 0 && board[x-1][y+1] == -1) count++;
                if (y > 0 && board[x][y-1] == -1) count++;
                if (y < width-1 && board[x][y+1] == -1) count++;
                if (y > 0 && x < height-1 && board[x+1][y-1] == -1) count++;
                if (x < height-1 && board[x+1][y] == -1) count++;
                if (y < width-1 && x < height-1 && board[x+1][y+1] == -1) count++;

                board[y][x] = count;
            }
        }
    }

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
    if (x >= 0 && x < width && y >= 0 && y < height) {
        Cell* cell = grid[y][x];
        if (!cell->revealed) {
            cell->revealed = true;
            // Jeśli pole jest puste, odkryj sąsiednie pola rekurencyjnie
            if (cell == nullptr) {
                revealCell(x - 1, y); // Odkryj pole na lewo
                revealCell(x + 1, y); // Odkryj pole na prawo
                revealCell(x, y - 1); // Odkryj pole u góry
                revealCell(x, y + 1); // Odkryj pole na dole
            }
        }
    }
}

void GameBoard::flagCell(int x, int y) {
    // Oznaczanie komórki o podanych współrzędnych jako zaznaczona
    if (x >= 0 && x < width && y >= 0 && y < height) {
        Cell* cell = grid[y][x];
        if (!cell->revealed) {
            cell->flagged = !cell->flagged;
        }
    }
}

bool GameBoard::checkGameStatus() const {
    // Sprawdzanie stanu gry, czy gra została wygrana lub przegrana
    int flaggedMines = 0;
    int unrevealedCells = 0;

    // Sprawdzenie ilości oznaczonych min i nieodkrytych pól
    for (const auto& row : grid) {
        for (const auto& cell : row) {
           // if (cell->flagged && /*sprawdzenie czy zaznaczamy mine*/ ) {
           //     flaggedMines++;
           //}
            if (!cell->revealed) {
                unrevealedCells++;
            }
        }
    }

    // Sprawdzenie warunków wygranej lub przegranej
    if (/*flaggedMines == 10 &&*/ unrevealedCells == 10) {
        return true;  // Gra wygrana
    } else if (unrevealedCells == 0 /*&& flaggedMines != 10*/) {
        return true;  // Gra przegrana
    }
    return false;
}