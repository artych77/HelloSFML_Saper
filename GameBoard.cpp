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
#include "InputHandler.h"

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

            if (board[x][y] != -1) {
                // Jeśli pole nie jest miną, zamień je na pole z miną
                delete grid[x][y];
                grid[x][y] = new CellMine();
                board[x][y] = -1;
                ++generatedMines;
            }
        }
    // Obliczanie liczby min sąsiadujących z każdym polem
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (board[x][y] != -1) {
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

                board[x][y] = count;
                if (board[x][y] > 0) {
                    // Jeśli pole nie jest miną i zwyklym polem, zamień je na pole z liczba
                    delete grid[x][y];
                    grid[x][y] = new CellNumber(count);

                }
            }
        }
    }

}

void GameBoard::displayBoard(sf::RenderWindow& window) {
    int width = board.size();
    int height = board[0].size();
    sf::Texture t;
    t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
    sf::Sprite s(t);

    // Rysuje wszystkie komórki na planszy
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            s.setPosition(x * 32, y * 32);
            if (grid[x][y]->revealed) {
                // Komórka odkryta - rysuje wartość lub minę
                if (board[x][y] == -1) {
                    //Kod rysujący minę na komórce
                    s.setTextureRect(sf::IntRect (9 * 32, 0, 32, 32));
                } else {
                    //Kod rysujący wartość liczbową na komórce
                    s.setTextureRect(sf::IntRect (board[x][y] * 32, 0, 32, 32));

                }
            }
            else {
                if (grid[x][y]->flagged == true){
                    // Komórka zaznaczona - rysuje flage
                    s.setTextureRect(sf::IntRect (11 * 32, 0, 32, 32));
                }
                else{
                    // Komórka nieodkryta - rysuje puste tło
                    s.setTextureRect(sf::IntRect (10 * 32, 0, 32, 32));
                }

            }

            window.draw(s);
        }
    }
}



void GameBoard::revealCell(int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board.size()) {
        return;
    }
    // Odkrywanie zawartości komórki o podanych współrzędnych
    if (grid[x][y]->revealed) {
        return;
    }

    grid[x][y]->revealed = true;

    if (board[x][y] == -1) {
        // Koniec gry - komórka z miną
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // Odkrywanie całej planszy
                grid[i][j]->revealed = true;
            }
        }
        return;
    }

    if (board[x][y] > 0) {
        // Komórka z liczbą min wokół
        return;
    }
    // Jeśli pole jest puste, odkryj sąsiednie pola rekurencyjnie
    if (board[x][y] == 0) {
        revealCell( x-1, y-1);
        revealCell( x, y-1);
        revealCell( x+1, y-1);
        revealCell( x-1, y);
        revealCell( x+1, y);
        revealCell( x-1, y+1);
        revealCell( x, y+1);
        revealCell( x+1, y+1);
    }
}

void GameBoard::flagCell(int x, int y) {
    // Oznaczanie komórki o podanych współrzędnych jako zaznaczona
    if (grid[x][y]->flagged) {
        // Oznacznie pola
        grid[x][y]->flagged = false;
    }
    else{
        // Zaznacznie pola
        grid[x][y]->flagged = true;
    }
}

bool GameBoard::checkGameStatus() const {
    // Sprawdzanie stanu gry, czy gra została wygrana lub przegrana
    int mines = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[j][i]->revealed == false)
                mines++;
        }
    }
    // Sprawdzenie warunków wygranej lub przegranej
    if (mines == 10) {
        return true;  // Gra wygrana
    }
    return false;
}