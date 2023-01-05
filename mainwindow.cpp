#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace data;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::init(){
    //表头设置
    QStringList table_headers;
    table_headers<<"职员ID"<<"姓名"<<"工资"<<"城市";
    model->setHorizontalHeaderLabels(table_headers);

    //一些按键的信号槽绑定
    connect(ui->AddButton,&QPushButton::clicked,this,&MainWindow::Addmember);
    connect(ui->SearchButton,&QPushButton::clicked,this,&MainWindow::Searchmember);

    //tableview基础设置
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    //右键菜单
    menu = new QMenu(ui->tableView);
    QAction *modifyaction = new QAction("修改");
    QAction *delaction = new QAction("删除");
    menu->addAction(modifyaction);menu->addAction(delaction);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
    connect(modifyaction,SIGNAL(triggered()),this,SLOT(modifyslot()));
    connect(delaction,SIGNAL(triggered()),this,SLOT(delslot()));

    //test
    qDebug()<<model->rowCount();
    //QList<Decorater*> list;list<<new Decorater(1,"w1",2)<<new Decorater(2,"w2",3);
    //updateview(list);
    //
}


void MainWindow::slotContextMenu(const QPoint &pos){
    auto index = ui->tableView->indexAt(pos);
    if (index.isValid()){
        menu->exec(QCursor::pos());
    }
}

void MainWindow::Addmember(){
    //
    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("输入员工信息:"));

    QLineEdit *idtxt=new QLineEdit(&dialog);
    form.addRow("员工ID",idtxt);

    QLineEdit *nametxt=new QLineEdit(&dialog);
    form.addRow("姓名",nametxt);

    QLineEdit *salarytxt=new QLineEdit(&dialog);
    form.addRow("工资",salarytxt);

    QLineEdit *citytxt=new QLineEdit(&dialog);
    form.addRow("城市",citytxt);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    if (dialog.exec() == QDialog::Accepted) {
        Decorater decorater; decorater.Add(idtxt->text().toStdString(),nametxt->text().toStdString(),salarytxt->text().toFloat(),citytxt->text().toStdString(),model);
        qDebug()<<nametxt->text();
    }
    //qDebug()<<"??";
}

void MainWindow::Searchmember()
{

}



void MainWindow::delslot(){
    int id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toInt();
    //qDebug()<<"no";
    //得到要删除的员工id后要做什么

}

void MainWindow::modifyslot(){

    int id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toInt();
    QString name=model->data(model->index(ui->tableView->currentIndex().row(),1)).toString();
    int salary=model->data(model->index(ui->tableView->currentIndex().row(),2)).toInt();
    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("要修改的员工信息:"));

    QLineEdit *idtxt=new QLineEdit(&dialog);
    idtxt->setText(QString::number(id));
    form.addRow("员工ID",idtxt);

    QLineEdit *nametxt=new QLineEdit(&dialog);
    nametxt->setText(name);
    form.addRow("姓名",nametxt);

    QLineEdit *salarytxt=new QLineEdit(&dialog);
    salarytxt->setText(QString::number(salary));
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


