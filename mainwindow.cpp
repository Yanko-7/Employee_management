#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
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
    connect(addaction,SIGNAL(triggered()),this,SLOT(addslot()));
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
    if (index.isValid())
    {
        menu->exec(QCursor::pos());
    }
}

void MainWindow::addslot(){
    int row=ui->tableView->currentIndex().row();
    int id=model->data(model->index(row,0)).toInt();
    //拿到员工id后
    qDebug()<<model->data(model->index(row,0)).toInt();
}

void MainWindow::delslot(){
    int id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toInt();
    //qDebug()<<"no";


}


