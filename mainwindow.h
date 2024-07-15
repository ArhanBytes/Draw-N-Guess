#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "game.h"

class Drawing;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// The MainWindow class provides the main application window
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);

    // Destructor
    ~MainWindow();

private slots:
    // Slot to start the game
    void startGame();

    // Slot to select the pen color
    void penColor();

    // Slot to set the pen width
    void penWidth();

    // Slot to show the About dialog
    void showAboutDialog();

    // Slot for handling the "Choose" button click
    void on_pushButton_choose_clicked();

    // Slot for handling the "Guess" button click
    void on_pushButton_guess_clicked();

protected:
    // Event handler for the close event
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui; // UI object

    // Pointers to the two players
    Player *player1;
    Player *player2;

    // Pointer to the game object
    Game *game;

    // Pointer to the drawing area
    Drawing *drawingarea;

    // Resets the UI for a new round
    void resetUIForNewRound();

    // Updates the UI for a new turn
    void updateUIForNewTurn();

    // Updates the UI for a new round
    void updateRound();

    // Saves the game state
    void saveGameState();

    void handleCorrectGuess();
    void handleIncorrectGuess();
    void handleNoAttemptsLeft();
    void updatePlayerScores();
    void showGuessSuccessMessage();
    void showGuessFailureMessage();
};

#endif // MAINWINDOW_H
