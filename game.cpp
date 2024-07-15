#include "game.h"
#include <QRandomGenerator>
#include <QFile>
#include <QDebug>

// Constructor for the Game class
Game::Game(Player *player1, Player *player2, QObject *parent)
    : QObject(parent), player1(player1), player2(player2), attempts(0), round(1) {
    currentDrawer = player1;
    currentGuesser = player2;

    // Load the word list from the resource file
    QFile file(":/resourceFile/word.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open word list file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString word = in.readLine().trimmed();
        if (!word.isEmpty()) {
            wordList.push_back(word);
        }
    }

    file.close();
    startNewRound();
}

// Start a new round in the game
void Game::startNewRound() {
    attempts = 0;
    wordToGuess.clear();
}

// Get the current drawer player
Player* Game::getCurrentDrawer() const {
    return currentDrawer;
}

// Get the current guesser player
Player* Game::getCurrentGuesser() const {
    return currentGuesser;
}

// Get the word to be guessed
QString Game::getWordToGuess() const {
    return wordToGuess;
}

// Get the remaining attempts
int Game::getAttempts() {
    return maxAttempts - attempts;
}

// Calculate the score for the guesser based on the number of attempts
int Game::getGuesserScore() {
    switch (attempts) {
    case 1: return 500;
    case 2: return 400;
    case 3: return 300;
    case 4: return 200;
    case 5: return 100;
    default: return 0;
    }
}

// Calculate the score for the drawer based on the number of attempts
int Game::getDrawerScore() {
    switch (attempts) {
    case 1: return 250;
    case 2: return 200;
    case 3: return 150;
    case 4: return 100;
    case 5: return 50;
    default: return 0;
    }
}

// Process a guess made by the guesser
bool Game::makeGuess(const QString &guess) {
    attempts++;
    if (guess.toLower() == wordToGuess.toLower()) {
        currentGuesser->incrementScore(getGuesserScore());
        currentDrawer->incrementScore(getDrawerScore());
        return true;
    }
    return false;
}

// Switch the roles of the drawer and guesser
void Game::switchRoles() {
    std::swap(currentDrawer, currentGuesser);
    startNewRound();
}

// Set the word to be guessed
void Game::setWordToGuess(QString word) {
    wordToGuess = word;
}

// Generate a random word from the word list
QString Game::generateRandomWord() {
    int index = QRandomGenerator::global()->bounded(wordList.size());
    return wordList[index];
}

// Get the length of the word to be guessed, represented as underscores
QString Game::getWordLength() {
    QString length;
    for (int i = 0; i < wordToGuess.length(); ++i) {
        length += "_ ";
    }
    return length;
}

// Get the current round number
int Game::getRound() {
    return round;
}

// Increase the round number
void Game::increaseRound() {
    round++;
}
