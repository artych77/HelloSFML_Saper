#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 32; // Rozmiar pojedynczej komórki planszy


// Funkcja generująca planszę z minami
void generateBoard(std::vector<std::vector<int>>& board, int width, int height, int mines)
{
    board = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));

    // Losowo ustawia miny na planszy
    while (mines > 0) {
        int x = rand() % width;
        int y = rand() % height;

        if (board[x][y] != -1) {
            board[x][y] = -1;
            mines--;
        }
    }

    // Ustawia wartości komórek bez min na ilość min wokół
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (board[x][y] != -1) {
                int count = 0;

                if (x > 0 && y > 0 && board[x-1][y-1] == -1) count++;
                if (y > 0 && board[x][y-1] == -1) count++;
                if (x < width-1 && y > 0 && board[x+1][y-1] == -1) count++;
                if (x > 0 && board[x-1][y] == -1) count++;
                if (x < width-1 && board[x+1][y] == -1) count++;
                if (x > 0 && y < height-1 && board[x-1][y+1] == -1) count++;
                if (y < height-1 && board[x][y+1] == -1) count++;
                if (x < width-1 && y < height-1 && board[x+1][y+1] == -1) count++;

                board[x][y] = count;
            }
        }
    }
}

// Funkcja odkrywająca komórkę i jej sąsiadów
void revealCell(const std::vector<std::vector<int>>& board, std::vector<std::vector<bool>>& revealed, int x, int y)
{
    if (x < 0 || x >= board.size() || y < 0 || y >= board.size()) {
        return;
    }

    if (revealed[x][y]) {
        return;
    }

    revealed[x][y] = true;

    if (board[x][y] == -1) {
        // Koniec gry - komórka z miną
        // Tutaj możesz dodać kod obsługi przegrania gry
        return;
    }

    if (board[x][y] > 0) {
        // Komórka z liczbą min wokół
        return;
    }

    // Komórka bez min wokół - rekurencyjnie odkryj sąsiadów
    revealCell(board, revealed, x-1, y-1);
    revealCell(board, revealed, x, y-1);
    revealCell(board, revealed, x+1, y-1);
    revealCell(board, revealed, x-1, y);
    revealCell(board, revealed, x+1, y);
    revealCell(board, revealed, x-1, y+1);
    revealCell(board, revealed, x, y+1);
    revealCell(board, revealed, x+1, y+1);
}

// Funkcja zaznaczajaca pole
void flaggedCell(const std::vector<std::vector<int>>& board, std::vector<std::vector<bool>>& flagged, int x, int y){
    if (x < 0 || x >= board.size() || y < 0 || y >= board.size()) {
        return;
    }

    if (flagged[x][y]) {
        flagged[x][y] = false;
    }

    flagged[x][y] = true;
}


// Funkcja rysująca plansze
void drawBoard(sf::RenderWindow& window, const std::vector<std::vector<int>>& board, const std::vector<std::vector<bool>>& revealed, std::vector<std::vector<bool>>& flagged)
{
    int width = board.size();
    int height = board[0].size();
    sf::Texture t;
    t.loadFromFile("C:\\Users\\Michal\\CLionProjects\\HelloSFML\\image\\tiles.jpg");
    sf::Sprite s(t);

    // Rysuje wszystkie komórki na planszy
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            s.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            if (flagged[x][y])
            if (revealed[x][y]) {
                // Komórka odkryta - rysuje wartość lub minę
                if (board[x][y] == -1) {
                    //Kod rysujący minę na komórce
                    s.setTextureRect(sf::IntRect (9 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
                } else {
                    //Kod rysujący wartość liczbową na komórce
                    s.setTextureRect(sf::IntRect (board[x][y] * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));

                }
            } else {
                // Komórka nieodkryta - rysuje puste tło
                s.setTextureRect(sf::IntRect (10 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
            }

            window.draw(s);
        }
    }
}
// Funkcja do obslugi planszy
void handleMouseClick(sf::RenderWindow& window, const sf::Event& event, std::vector<std::vector<bool>>& revealed, const std::vector<std::vector<int>>& board)
{
    if (event.mouseButton.button == sf::Mouse::Left) {
        int x = event.mouseButton.x / CELL_SIZE;
        int y = event.mouseButton.y / CELL_SIZE;

        revealCell(board, revealed, x, y);
    }
    if (event.mouseButton.button == sf::Mouse::Right) {
        int x = event.mouseButton.x / CELL_SIZE;
        int y = event.mouseButton.y / CELL_SIZE;
        //funkcja do zaznaczania flagi na mapie

    }
}

int main()
{
    srand(time(NULL));

    int width = 10;
    int height = 10;
    int mines = 10;

    std::vector<std::vector<int>> board;
    generateBoard(board, width, height, mines);

    std::vector<std::vector<bool>> revealed(width, std::vector<bool>(height, false));

    std::vector<std::vector<bool>> flagged(width, std::vector<bool>(height, false));

    sf::RenderWindow window(sf::VideoMode(width * CELL_SIZE, height * CELL_SIZE), "Minesweeper");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                handleMouseClick(window, event, revealed, board);
            }
        }

        window.clear();
        drawBoard(window, board, revealed, flagged);
        window.display();
    }

    return 0;
}
