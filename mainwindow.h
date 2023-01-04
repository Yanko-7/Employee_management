#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <decorater.h>
#include <QList>
#include <QMainWindow>
#include <qstandarditemmodel.h>

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
    void updateview(QList<Decorater*> list);
private:
    Ui::MainWindow *ui;
    QStandardItemModel *model=new QStandardItemModel();
    QMenu *menu;
public slots:
    void slotContextMenu(const QPoint &pos);
    void addslot();
    void delslot();
};
#endif // MAINWINDOW_H
