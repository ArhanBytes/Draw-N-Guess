#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QString>
#include <vector>

#include "player.h"

// The Game class manages the logic and state of the game
class Game : public QObject {
    Q_OBJECT

public:
    // Constructor that initializes the game with two players
    Game(Player *player1, Player *player2, QObject *parent = nullptr);

    // Starts a new round in the game
    void startNewRound();

    // Returns the current drawer player
    Player* getCurrentDrawer() const;

    // Returns the current guesser player
    Player* getCurrentGuesser() const;

    // Returns the word to be guessed
    QString getWordToGuess() const;

    // Sets the word to be guessed
    void setWordToGuess(QString word);

    // Processes a guess made by the guesser
    bool makeGuess(const QString &guess);

    // Generates a random word from the word list
    QString generateRandomWord();

    // Returns the number of attempts made in the current round
    int getAttempts();

    // Returns the length of the word to be guessed
    QString getWordLength();

    // Switches the roles of the drawer and guesser
    void switchRoles();

    // Increases the round number
    void increaseRound();

    // Returns the current round number
    int getRound();

private:
    // Pointers to the two players in the game
    Player *player1;
    Player *player2;

    // Pointers to the current drawer and guesser
    Player *currentDrawer;
    Player *currentGuesser;

    // The word that needs to be guessed
    QString wordToGuess;

    // The number of attempts made in the current round
    int attempts;

    // The maximum number of attempts allowed
    const int maxAttempts = 5;

    // A list of possible words to be guessed
    std::vector<QString> wordList;

    // The current round number
    int round;

    // Returns the score of the current guesser
    int getGuesserScore();

    // Returns the score of the current drawer
    int getDrawerScore();
};

#endif // GAME_H
