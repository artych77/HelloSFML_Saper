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
                if (board[y][x] > 0) {
                    // Jeśli pole nie jest miną i zwyklym polem, zamień je na pole z liczba
                    delete grid[y][x];
                    grid[y][x] = new CellNumber(count);

                }
            }
        }
    }

}

void GameBoard::displayBoard() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        int x = event.mouseButton.x / 32;
                        int y = event.mouseButton.y / 32;

                        //fukcja odkrywajaca pole
                        revealCell(x, y);

                    }
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        int x = event.mouseButton.x / 32;
                        int y = event.mouseButton.y / 32;

                        //funkcja do zaznaczania flagi na mapie
                        flagCell(x, y);
                    }
                }
            }

            window.clear();
            sf::Texture t;
            t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
            sf::Sprite s(t);

            // Rysuje wszystkie komórki na planszy
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    s.setPosition(x * 32, y * 32);
                    //kod do rysowania pola
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
                        if (grid[x][y]->flagged){
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
            window.display();
        }
    }
}



void GameBoard::revealCell(int x, int y) {
    // Odkrywanie zawartości komórki o podanych współrzędnych
    if (grid[x][y]->revealed) {
        return;
    }

    grid[x][y]->revealed = true;

    if (board[x][y] == -1) {
        // Koniec gry - komórka z miną
        //GameOver
        return;
    }

    if (board[x][y] > 0) {
        // Komórka z liczbą min wokół
        return;
    }
    // Jeśli pole jest puste, odkryj sąsiednie pola rekurencyjnie
    if (board[x][y] == 0) {
        revealCell(x - 1, y); // Odkryj pole na lewo
        revealCell(x + 1, y); // Odkryj pole na prawo
        revealCell(x, y - 1); // Odkryj pole u góry
        revealCell(x, y + 1); // Odkryj pole na dole
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