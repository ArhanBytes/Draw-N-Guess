#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

// The Player class represents a player in the game
class Player {
public:
    // Constructor to initialize a player with a name
    Player(const QString &name);

    // Returns the name of the player
    QString getName() const;

    // Returns the score of the player
    int getScore() const;

    // Increments the player's score by the given total score
    void incrementScore(int totalScore);

private:
    QString name; // Name of the player
    int score;    // Score of the player
};

#endif // PLAYER_H
