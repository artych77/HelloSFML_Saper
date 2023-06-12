//
// Created by Michal on 02.06.2023.
//

#include "GameManager.h"
#include "Renderer.h"
#include "GameBoard.h"

GameManager::GameManager() : isGameActive(false), gameBoard(400, 400), player() {}

void GameManager::initializeGame(const std::string& playerName) {
    isGameActive = true;
    //gameBoard.createBoard();
}

void GameManager::updateGame() {
    // Aktualizacja stanu gry, interakcja z użytkownikiem, itp.
}

bool GameManager::isGameOver() const {
    // Sprawdzenie warunków zakończenia gry
    // Zwraca true, jeśli gra jest zakończona
    // W przeciwnym razie zwraca false
    return false;
}

bool GameManager::isGameWon() const {
    // Sprawdzenie warunków wygranej gry
    // Zwraca true, jeśli gra została wygrana
    // W przeciwnym razie zwraca false
    return true;
}