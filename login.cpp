#include "decorater.h"
#include "login.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>



Login::Login(QDialog* parent) :QDialog(parent) {

    form = new QFormLayout(this);

    UserName = new QLineEdit(this);
    MainWindow::setLineEditQss(UserName);
    form->addRow("Username:", UserName);

    UserPassword = new QLineEdit(this);
    MainWindow::setLineEditQss(UserPassword);
    form->addRow("password:", UserPassword);

    QPushButton* load = new QPushButton("Login", this);
    QPushButton* regst = new QPushButton("Register", this);

    MainWindow::setPushButtonQss(load);
    MainWindow::setPushButtonQss(regst);
    form->addRow(load, regst);
    connect(load, &QPushButton::clicked, this, &Login::loggin);
    connect(regst, &QPushButton::clicked, this, &Login::reggister);
}

void Login::loggin() {
    Decorater decorater;
    if (decorater.loggin(UserName->text().toStdString(), UserPassword->text().toStdString())) {
        accept();
    }
    else {
        QMessageBox::critical(this, "Note", "User non-existent or uncorrect password");
    }
}
void Login::reggister() {
    Decorater decorater;
    if (decorater.reggister(UserName->text().toStdString(), UserPassword->text().toStdString())) {
        QMessageBox::about(this, "Note", "Succeed");
    }
    else {
        QMessageBox::critical(this, "Note", "User already exist");
    }
}
