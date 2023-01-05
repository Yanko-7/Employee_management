/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_2;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit;
    QComboBox *comboBox_3;
    QPushButton *SearchButton;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddButton;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QTableView *tableView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 3, 1, 1, 1);

        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        gridLayout->addWidget(comboBox_4, 3, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 3, 0, 1, 1);

        SearchButton = new QPushButton(centralwidget);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));

        gridLayout->addWidget(SearchButton, 0, 2, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(400, 100, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout_2->addWidget(AddButton);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalLayout->setStretch(0, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        formWidget = new QWidget(centralwidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tableView = new QTableView(formWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        formLayout->setWidget(0, QFormLayout::SpanningRole, tableView);


        verticalLayout_2->addWidget(formWidget);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 10);

        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\346\211\200\346\234\211\347\261\273\345\210\253", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\350\201\214\345\221\230", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\350\200\205", nullptr));

#if QT_CONFIG(statustip)
        comboBox_3->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        SearchButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\250\241\347\263\212\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\347\262\276\347\241\256\346\220\234\347\264\242", nullptr));

        //comboBox->setPlaceholderText(QString());
        AddButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
