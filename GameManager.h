//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_GAMEMANAGER_H
#define HELLOSFML_GAMEMANAGER_H

#include "GameBoard.h"
#include "Player.h"


class GameManager {
protected:
    bool isGameActive;
    GameBoard gameBoard;
    Player player;

public:
    GameManager();

    void initializeGame(const std::string& playerName);
    void updateGame();
    bool isGameOver() const;
    bool isGameWon() const;

};


#endif //HELLOSFML_GAMEMANAGER_H
