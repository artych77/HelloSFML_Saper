//
// Created by Michal on 02.06.2023.
//

#include "Player.h"

#include <utility>

Player::Player() : name(""), score(0) {}

[[maybe_unused]] Player::Player(std::string  playerName) : name(std::move(playerName)), score(0) {}

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
