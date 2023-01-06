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
    static QString setPushButtonQss(QPushButton* btn,                               //��ť����
        int radius = 5,                                 //Բ�ǰ뾶
        int padding = 8,                                //���
        const QString& normalColor = "#34495E",         //������ɫ
        const QString& normalTextColor = "#FFFFFF",     //������ɫ
        const QString& hoverColor = "#4E6D8C",          //��ͣ��ɫ
        const QString& hoverTextColor = "#F0F0F0",      //��ͣ������ɫ
        const QString& pressedColor = "#2D3E50",        //������ɫ
        const QString& pressedTextColor = "#B8C6D1");   //����������ɫ

//�����ı�����ʽ
    static QString setLineEditQss(QLineEdit* txt,                                   //�ı������
        int radius = 3,                                   //Բ�ǰ뾶
        int borderWidth = 2,                              //�߿��С
        const QString& normalColor = "#DCE4EC",           //������ɫ
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
