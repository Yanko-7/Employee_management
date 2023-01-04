#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QMenu>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
    //表头设置
    model->setColumnCount(3);
    QStringList table_headers;
    table_headers<<"职员ID"<<"姓名"<<"工资";
    model->setHorizontalHeaderLabels(table_headers);
    //

    connect(ui->AddButton,&QPushButton::clicked,this,&MainWindow::Addmember);

    //tableview基础设置
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    //右键菜单
    menu = new QMenu(ui->tableView);
    QAction *addaction = new QAction("添加");
    QAction *delaction = new QAction("删除");
    menu->addAction(addaction);menu->addAction(delaction);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
    //connect(addaction,SIGNAL(triggered()),this,SLOT(addslot()));
    connect(delaction,SIGNAL(triggered()),this,SLOT(delslot()));

    //test
    qDebug()<<model->rowCount();
    QList<Decorater*> list;list<<new Decorater(1,"w1",2)<<new Decorater(2,"w2",3);
    updateview(list);
    //
}

void MainWindow::updateview(QList<Decorater*> list){//重写view
    model->removeRows(0,model->rowCount());
    for(auto x:list){
        QList<QStandardItem*> items;
        items<<new QStandardItem(QString::number(x->getid()))<<new QStandardItem(x->getname())<<new QStandardItem(QString::number(x->getsalary()));
        model->appendRow(items);
    }
}

void MainWindow::slotContextMenu(const QPoint &pos)
{
    auto index = ui->tableView->indexAt(pos);
    if (index.isValid()){
        menu->exec(QCursor::pos());
    }
}

void MainWindow::Addmember(){
    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("输入员工信息"));
    QLineEdit *idtxt=new QLineEdit(&dialog);
    form.addRow("员工ID",idtxt);
    QLineEdit *nametxt=new QLineEdit(&dialog);
    form.addRow("姓名",nametxt);
    QLineEdit *salarytxt=new QLineEdit(&dialog);
    form.addRow("工资",salarytxt);
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    if (dialog.exec() == QDialog::Accepted) {
        // 填入添加信息后要做什么
        qDebug()<<nametxt->text();
    }
    //qDebug()<<"??";
}



void MainWindow::delslot(){
    int id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toInt();
    //qDebug()<<"no";
    //得到要删除的员工id后要做什么

}


