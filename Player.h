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
    Player(const std::string& playerName);
    void setName(const std::string& playerName);
    void setScore(int playerScore);
    std::string getName() const;
    int getScore() const;

};


#endif //HELLOSFML_PLAYER_H
