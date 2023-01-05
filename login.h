#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>



class Login:public QDialog
{
public:
    Login(QDialog *parent =NULL);

public slots:
    void loggin();
    void reggister();
private:
    QFormLayout *form;
    QLineEdit *UserName;
    QLineEdit *UserPassword;
};

#endif // LOGIN_H
