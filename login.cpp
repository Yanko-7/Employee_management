#include "decorater.h"
#include "login.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>



Login::Login(QDialog *parent):QDialog(parent){

    form = new QFormLayout(this);

    UserName=new QLineEdit(this);
    MainWindow::setLineEditQss(UserName);
    form->addRow("用户名:",UserName);

    UserPassword=new QLineEdit(this);
    MainWindow::setLineEditQss(UserPassword);
    form->addRow("密码:",UserPassword);

    QPushButton *load = new QPushButton("登录",this);
    QPushButton *regst = new QPushButton("注册",this);

    MainWindow::setPushButtonQss(load);
    MainWindow::setPushButtonQss(regst);
    form->addRow(load,regst);
    connect(load,&QPushButton::clicked,this,&Login::loggin);
    connect(regst,&QPushButton::clicked,this,&Login::reggister);
}

void Login::loggin(){
    Decorater decorater;
    if(decorater.loggin(UserName->text().toStdString(),UserPassword->text().toStdString())){
        accept();
    }
}
void Login::reggister(){
    Decorater decorater;
    decorater.reggister(UserName->text().toStdString(),UserPassword->text().toStdString());
}
