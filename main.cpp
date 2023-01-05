#include "Login.h"
#include "mainwindow.h"

#include <QApplication>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login g;
    if(g.exec()==QDialog::Accepted){
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
