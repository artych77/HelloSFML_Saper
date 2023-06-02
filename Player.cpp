//
// Created by Michal on 02.06.2023.
//

#include "Player.h"

Player::Player() : name(""), score(0) {}

Player::Player(const std::string& playerName) : name(playerName), score(0) {}

void Player::setName(const std::string& playerName) {
    name = playerName;
}

void Player::setScore(int playerScore) {
    score = playerScore;
}

std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}
