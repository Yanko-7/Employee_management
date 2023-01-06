#include "Login.h"
#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QFile f(":/qdarkstyle/light/lightstyle.qss");
    if (!f.exists()) {
        printf("Unable to set stylesheet, file not found\n");
        return 0;
    }
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    QApplication a(argc, argv);
    Login g;
    if (g.exec() == QDialog::Accepted) {
        MainWindow w;
        w.setStyleSheet(ts.readAll());
        w.show();
        return a.exec();
    }
    return 0;
}
