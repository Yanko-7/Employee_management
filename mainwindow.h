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
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void init();
    static QString setPushButtonQss(QPushButton* btn,                               //按钮对象
        int radius = 5,                                 //圆角半径
        int padding = 8,                                //间距
        const QString& normalColor = "#34495E",         //正常颜色
        const QString& normalTextColor = "#FFFFFF",     //文字颜色
        const QString& hoverColor = "#4E6D8C",          //悬停颜色
        const QString& hoverTextColor = "#F0F0F0",      //悬停文字颜色
        const QString& pressedColor = "#2D3E50",        //按下颜色
        const QString& pressedTextColor = "#B8C6D1");   //按下文字颜色

//设置文本框样式
    static QString setLineEditQss(QLineEdit* txt,                                   //文本框对象
        int radius = 3,                                   //圆角半径
        int borderWidth = 2,                              //边框大小
        const QString& normalColor = "#DCE4EC",           //正常颜色
        const QString& focusColor = "#34495E");

private:
    Ui::MainWindow* ui;
    QStandardItemModel* model = new QStandardItemModel();
    QMenu* menu;


public slots:
    void slotContextMenu(const QPoint& pos);
    void Addmember();
    void Searchmember();
    void delslot();
    void modifyslot();
    void modifyMangerslot();
};
#endif // MAINWINDOW_H
