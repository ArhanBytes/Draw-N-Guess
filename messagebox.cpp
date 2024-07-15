#include "messagebox.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

// Constructor for the MessageBox class
MessageBox::MessageBox(const QString &title, const QString &message, QWidget *parent)
    : QDialog(parent)
{
    // Set the title of the message box
    setWindowTitle(title);

    // Set the layout for the message box
    layout = new QVBoxLayout(this);

    // Create and add the message label
    messageLabel = new QLabel(message, this);
    messageLabel->setWordWrap(true); // Enable word wrap for the message
    layout->addWidget(messageLabel);

    // Create and add the OK button
    okButton = new QPushButton("OK", this);
    layout->addWidget(okButton);

    // Connect the OK button's clicked signal to the dialog's accept slot
    connect(okButton, &QPushButton::clicked, this, &MessageBox::accept);

    // Set the layout for the dialog
    setLayout(layout);

    // Apply the stylesheet
    QFile file(":/resourceFile/messageBoxStylesheet.rtf");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open stylesheet file";
        return;
    }

    QTextStream in(&file);
    QString stylesheet = in.readAll();
    setStyleSheet(stylesheet);

    file.close();
}
