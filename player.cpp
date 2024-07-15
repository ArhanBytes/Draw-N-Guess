#include "player.h"

Player::Player(const QString &name) : name(name), score(0) {}

QString Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::incrementScore(int totalScore) {
    score += totalScore;
}
