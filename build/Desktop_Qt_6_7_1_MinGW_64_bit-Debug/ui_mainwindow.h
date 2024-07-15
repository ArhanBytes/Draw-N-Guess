/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPen_Color;
    QAction *actionPen_Width;
    QAction *actionClear_Screen;
    QAction *actionAbout_Game;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_round;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *label_wordLength;
    QLabel *label_player1;
    QLabel *label_player1_score;
    QLabel *label_player2;
    QLabel *label_player2_score;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_choose;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *pushButton_choose;
    QGroupBox *groupBox_Guess;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_guess;
    QPushButton *pushButton_guess;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_trials;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionPen_Color = new QAction(MainWindow);
        actionPen_Color->setObjectName("actionPen_Color");
        actionPen_Width = new QAction(MainWindow);
        actionPen_Width->setObjectName("actionPen_Width");
        actionClear_Screen = new QAction(MainWindow);
        actionClear_Screen->setObjectName("actionClear_Screen");
        actionAbout_Game = new QAction(MainWindow);
        actionAbout_Game->setObjectName("actionAbout_Game");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_round = new QLabel(centralwidget);
        label_round->setObjectName("label_round");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_round->sizePolicy().hasHeightForWidth());
        label_round->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_round->setFont(font);
        label_round->setStyleSheet(QString::fromUtf8("color: \"#2b80ff\";"));

        horizontalLayout_5->addWidget(label_round);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        label_wordLength = new QLabel(centralwidget);
        label_wordLength->setObjectName("label_wordLength");
        sizePolicy.setHeightForWidth(label_wordLength->sizePolicy().hasHeightForWidth());
        label_wordLength->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        label_wordLength->setFont(font1);

        horizontalLayout_4->addWidget(label_wordLength);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        label_player1 = new QLabel(centralwidget);
        label_player1->setObjectName("label_player1");
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label_player1->setFont(font2);
        label_player1->setStyleSheet(QString::fromUtf8("color: \"green\";\n"
""));

        horizontalLayout_5->addWidget(label_player1);

        label_player1_score = new QLabel(centralwidget);
        label_player1_score->setObjectName("label_player1_score");
        QFont font3;
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setUnderline(true);
        label_player1_score->setFont(font3);
        label_player1_score->setStyleSheet(QString::fromUtf8("color: \"White\";"));

        horizontalLayout_5->addWidget(label_player1_score);

        label_player2 = new QLabel(centralwidget);
        label_player2->setObjectName("label_player2");
        label_player2->setFont(font2);
        label_player2->setStyleSheet(QString::fromUtf8("color: \"red\";\n"
""));

        horizontalLayout_5->addWidget(label_player2);

        label_player2_score = new QLabel(centralwidget);
        label_player2_score->setObjectName("label_player2_score");
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setUnderline(true);
        label_player2_score->setFont(font4);
        label_player2_score->setStyleSheet(QString::fromUtf8("color: \"white\";\n"
""));

        horizontalLayout_5->addWidget(label_player2_score);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        font5.setPointSize(13);
        font5.setBold(true);
        groupBox->setFont(font5);

        horizontalLayout_6->addWidget(groupBox);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox_choose = new QGroupBox(centralwidget);
        groupBox_choose->setObjectName("groupBox_choose");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_choose->sizePolicy().hasHeightForWidth());
        groupBox_choose->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Rockwell Extra Bold")});
        font6.setPointSize(12);
        font6.setBold(true);
        groupBox_choose->setFont(font6);
        horizontalLayout_3 = new QHBoxLayout(groupBox_choose);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        comboBox = new QComboBox(groupBox_choose);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setSizeIncrement(QSize(0, 0));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font7.setPointSize(12);
        font7.setBold(true);
        comboBox->setFont(font7);

        horizontalLayout_3->addWidget(comboBox);

        pushButton_choose = new QPushButton(groupBox_choose);
        pushButton_choose->setObjectName("pushButton_choose");
        sizePolicy1.setHeightForWidth(pushButton_choose->sizePolicy().hasHeightForWidth());
        pushButton_choose->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton_choose);


        verticalLayout_4->addWidget(groupBox_choose);

        groupBox_Guess = new QGroupBox(centralwidget);
        groupBox_Guess->setObjectName("groupBox_Guess");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_Guess->sizePolicy().hasHeightForWidth());
        groupBox_Guess->setSizePolicy(sizePolicy3);
        groupBox_Guess->setFont(font6);
        verticalLayout_3 = new QVBoxLayout(groupBox_Guess);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(groupBox_Guess);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font8.setPointSize(12);
        font8.setBold(true);
        font8.setUnderline(false);
        listWidget->setFont(font8);

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_guess = new QLineEdit(groupBox_Guess);
        lineEdit_guess->setObjectName("lineEdit_guess");

        horizontalLayout_2->addWidget(lineEdit_guess);

        pushButton_guess = new QPushButton(groupBox_Guess);
        pushButton_guess->setObjectName("pushButton_guess");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font9.setPointSize(12);
        font9.setBold(true);
        pushButton_guess->setFont(font9);

        horizontalLayout_2->addWidget(pushButton_guess);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(groupBox_Guess);
        label_5->setObjectName("label_5");
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(label_5);

        label_trials = new QLabel(groupBox_Guess);
        label_trials->setObjectName("label_trials");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font10.setPointSize(12);
        font10.setBold(true);
        font10.setUnderline(true);
        label_trials->setFont(font10);

        horizontalLayout->addWidget(label_trials);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox_Guess);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_6->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font11.setPointSize(20);
        font11.setBold(true);
        statusbar->setFont(font11);
        statusbar->setLayoutDirection(Qt::LeftToRight);
        statusbar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuOptions->addAction(actionPen_Color);
        menuOptions->addAction(actionPen_Width);
        menuOptions->addSeparator();
        menuOptions->addAction(actionClear_Screen);
        menuAbout->addAction(actionAbout_Game);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPen_Color->setText(QCoreApplication::translate("MainWindow", "Pen Color", nullptr));
        actionPen_Width->setText(QCoreApplication::translate("MainWindow", "Pen Width", nullptr));
        actionClear_Screen->setText(QCoreApplication::translate("MainWindow", "Clear Screen", nullptr));
        actionAbout_Game->setText(QCoreApplication::translate("MainWindow", "About Game", nullptr));
        label_round->setText(QCoreApplication::translate("MainWindow", "Round: 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Word:", nullptr));
        label_wordLength->setText(QCoreApplication::translate("MainWindow", "_ _ _ _ _ _", nullptr));
        label_player1->setText(QCoreApplication::translate("MainWindow", "Arhan's Score:", nullptr));
        label_player1_score->setText(QCoreApplication::translate("MainWindow", "0,", nullptr));
        label_player2->setText(QCoreApplication::translate("MainWindow", "Faizan's Score", nullptr));
        label_player2_score->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Drawing app", nullptr));
        groupBox_choose->setTitle(QCoreApplication::translate("MainWindow", "Player Guess", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose a word", nullptr));
        pushButton_choose->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        groupBox_Guess->setTitle(QCoreApplication::translate("MainWindow", "Player Guess", nullptr));
        lineEdit_guess->setPlaceholderText(QCoreApplication::translate("MainWindow", "Guess a word", nullptr));
        pushButton_guess->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "No Of trials: ", nullptr));
        label_trials->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
