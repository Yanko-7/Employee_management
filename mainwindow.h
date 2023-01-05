#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <qstandarditemmodel.h>
#include <QDebug>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QMenu>
#include <QStandardItemModel>
#include <decorater.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model=new QStandardItemModel();
    QMenu *menu;


public slots:
    void slotContextMenu(const QPoint &pos);
    void Addmember();
    void Searchmember();
    void delslot();
    void modifyslot();
};
#endif // MAINWINDOW_H
