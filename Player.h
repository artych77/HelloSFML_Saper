//
// Created by Michal on 02.06.2023.
//

#ifndef HELLOSFML_PLAYER_H
#define HELLOSFML_PLAYER_H

#include <string>


class Player {
private:
    std::string name;
    int score;

public:
    Player();
    [[maybe_unused]] Player(std::string  playerName);
    void setName(const std::string& playerName);
    void setScore(int playerScore);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getScore() const;

};


#endif //HELLOSFML_PLAYER_H
