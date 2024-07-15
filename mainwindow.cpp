#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messagebox.h"

#include "drawing.h"
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the drawing area widget and set it in the layout
    drawingarea = new Drawing;
    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(drawingarea);
    ui->groupBox->setLayout(groupBoxLayout);

    // Set window title and initial size
    setWindowTitle(tr("DRAW & GUESS :)"));
    resize(500, 500);

    // Initialize the game and connect UI actions to slots
    startGame();
    connect(ui->actionPen_Color, SIGNAL(triggered()), this, SLOT(penColor()));
    connect(ui->actionPen_Width, SIGNAL(triggered()), this, SLOT(penWidth()));
    connect(ui->actionClear_Screen, SIGNAL(triggered()), drawingarea, SLOT(clearImage()));
    connect(ui->actionAbout_Game, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Game flow methods

void MainWindow::startGame()
{
    // Get player names and initialize the game
    QString player1Name = QInputDialog::getText(this, tr("Player 1"), tr("Enter Player 1 name:"));
    QString player2Name = QInputDialog::getText(this, tr("Player 2"), tr("Enter Player 2 name:"));
    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    game = new Game(player1, player2, this);

    // Update UI elements for new game
    ui->label_player1->setText(player1Name + "'s Score: ");
    ui->label_player2->setText(player2Name + "'s Score: ");
    updateUIForNewTurn();
}

void MainWindow::resetUIForNewRound()
{
    // Reset UI elements for a new round
    drawingarea->clearImage();
    ui->label_trials->setText(QString::number(game->getAttempts()));
    ui->pushButton_choose->show();
    ui->label_wordLength->setText("");
    ui->lineEdit_guess->setReadOnly(true);
}

void MainWindow::updateUIForNewTurn()
{
    // Update UI for a new turn in the game
    resetUIForNewRound();
    QString drawerName = game->getCurrentDrawer()->getName();
    QString guesserName = game->getCurrentGuesser()->getName();
    ui->groupBox->setTitle("Draw here " + drawerName);
    ui->groupBox_choose->setTitle("Choose here " + drawerName);
    ui->groupBox_Guess->setTitle("Guess here " + guesserName);
    ui->statusbar->showMessage(QString("Drawer: %1, Guesser: %2").arg(drawerName).arg(guesserName));

    // Populate combo box with random words
    for (int i = 0; i < 3; i++)
    {
        QString listWord = game->generateRandomWord();
        ui->comboBox->addItem(listWord);
    }

    // Show message box for screen privacy alert
    MessageBox msgBox("Screen Privacy Alert", drawerName + ", please hide the screen from " + guesserName + " before selecting a word.", this);
    msgBox.exec();
}

void MainWindow::updateRound()
{
    // Update round information
    if (game->getCurrentDrawer() == player1)
    {
        game->increaseRound();
        ui->label_round->setText("Round: " + QString::number(game->getRound()));
    }
}

// Drawing related methods

void MainWindow::penColor()
{
    // Change pen color using QColorDialog
    QColor newColor = QColorDialog::getColor(drawingarea->penColor());
    if (newColor.isValid())
        drawingarea->setPenColor(newColor);
}

void MainWindow::penWidth()
{
    // Change pen width using QInputDialog
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        drawingarea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        drawingarea->setPenWidth(newWidth);
}

// Button click handlers

void MainWindow::on_pushButton_choose_clicked()
{
    // Handle word selection by current drawer
    QString choosedWord = ui->comboBox->currentText();
    ui->comboBox->clear();
    game->setWordToGuess(choosedWord);
    ui->label_wordLength->setText(game->getWordLength());
    ui->pushButton_choose->hide();
    ui->label_trials->setText(QString::number(game->getAttempts()));
    ui->lineEdit_guess->setReadOnly(false);

    // Show message box for guessing instruction
    MessageBox msgBox("Guess It", game->getCurrentGuesser()->getName() + " please guess the word according to drawing.", this);
    msgBox.exec();
}

void MainWindow::on_pushButton_guess_clicked()
{
    QString inputText = ui->lineEdit_guess->text().trimmed();

    if (inputText.isEmpty()) {
        return;
    }

    QListWidgetItem *item = new QListWidgetItem(inputText);
    ui->listWidget->addItem(item);
    ui->lineEdit_guess->clear();

    bool guessCorrect = game->makeGuess(inputText);

    if (guessCorrect) {
        handleCorrectGuess();
    } else {
        handleIncorrectGuess();
    }
}

void MainWindow::handleCorrectGuess()
{
    updatePlayerScores();
    showGuessSuccessMessage();

    game->switchRoles();
    updateRound();
    updateUIForNewTurn();
}

void MainWindow::handleIncorrectGuess()
{
    int remainingAttempts = game->getAttempts();
    ui->label_trials->setText(QString::number(remainingAttempts));

    if (remainingAttempts == 0) {
        handleNoAttemptsLeft();
    }
}

void MainWindow::handleNoAttemptsLeft()
{
    game->getCurrentDrawer()->incrementScore(25);
    updatePlayerScores();
    showGuessFailureMessage();

    game->switchRoles();
    updateRound();
    updateUIForNewTurn();
}

void MainWindow::updatePlayerScores()
{
    ui->label_player1_score->setText(QString::number(player1->getScore()));
    ui->label_player2_score->setText(QString::number(player2->getScore()));
}

void MainWindow::showGuessSuccessMessage()
{
    QString message = "Congratulations, " + game->getCurrentGuesser()->getName() +
                      "! You perfectly guessed the word: \"" + game->getWordToGuess() + "\".";
    MessageBox msgBox("Success :)", message, this);
    msgBox.exec();
}

void MainWindow::showGuessFailureMessage()
{
    QString message = "Alas, " + game->getCurrentGuesser()->getName() +
                      "! You couldn't guess the word: \"" + game->getWordToGuess() + "\".";
    MessageBox msgBox("Try Later :(", message, this);
    msgBox.exec();
}


void MainWindow::showAboutDialog()
{
    // Show an about dialog with HTML content and stylesheet
    QFile fileHtml(":/resourceFile/aboutText.html");
    if (!fileHtml.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open HTML file";
        return;
    }

    QTextStream inText(&fileHtml);
    QString aboutText = inText.readAll();
    fileHtml.close();

    QFile fileStyle(":/resourceFile/aboutStylesheet.css");
    if (!fileStyle.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open stylesheet file";
        return;
    }

    QTextStream inStyle(&fileStyle);
    QString aboutStylesheet = inStyle.readAll();
    fileStyle.close();

    QMessageBox aboutBox;
    aboutBox.setWindowTitle("the Game");
    aboutBox.setTextFormat(Qt::RichText);
    aboutBox.setText(aboutText);
    aboutBox.setStandardButtons(QMessageBox::Ok);
    aboutBox.setStyleSheet(aboutStylesheet);
    aboutBox.exec();
}

void MainWindow::saveGameState()
{
    // Save current game state to a file
    QFile file("C:/Users/ADMIN/Documents/qt/Draw_Guess/game_state.txt");
    if (!file.open(QFile::Append | QFile::Text))
    {
        qDebug() << "Failed to open game_state.txt for appending.";
        return;
    }

    QTextStream out(&file);
    out << "Player 1 Name: " << player1->getName() << "\n";
    out << "Player 2 Name: " << player2->getName() << "\n";
    out << "Player 1 Score: " << player1->getScore() << "\n";
    out << "Player 2 Score: " << player2->getScore() << "\n";
    out << "Total Rounds Played: " << game->getRound() << "\n";
    out << "-----------------------------\n";

    file.flush();
    file.close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Handle close event of the main window
    saveGameState(); // Save the game state
    QMainWindow::closeEvent(event); // Call the base class implementation
}
