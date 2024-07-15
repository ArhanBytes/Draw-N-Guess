#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

// The MessageBox class provides a custom message dialog
class MessageBox : public QDialog
{
    Q_OBJECT

public:
    // Constructor
    explicit MessageBox(const QString &title, const QString &message, QWidget *parent = nullptr);

private:
    QVBoxLayout *layout; // Layout for arranging widgets vertically
    QLabel *messageLabel; // Label to display the message
    QPushButton *okButton; // Button to close the dialog
};

#endif // MESSAGEBOX_H
