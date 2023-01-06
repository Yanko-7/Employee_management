#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFormLayout>
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
    table_headers<<"职员ID"<<"姓名"<<"工资"<<"城市"<<"职位";
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
    //setPushButtonQss(ui->AddButton);
    //setLineEditQss(ui->lineEdit);
    //右键菜单
    menu = new QMenu(ui->tableView);
    QAction *modifyaction = new QAction("修改员工信息");
    QAction *modifMangeryaction = new QAction("修改员工管理员");
    QAction *delaction = new QAction("删除");
    menu->addAction(modifyaction);
    menu->addAction(modifMangeryaction);
    menu->addAction(delaction);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
    connect(modifyaction,SIGNAL(triggered()),this,SLOT(modifyslot()));
    connect(modifMangeryaction,SIGNAL(triggered()),this,SLOT(modifyMangerslot()));
    connect(delaction,SIGNAL(triggered()),this,SLOT(delslot()));


    //Decorater decorater;decorater.updateview(data::Manager::getInstance()->SearchEmployee(),model);
    //test
    qDebug()<<model->rowCount();
    //
}

QString MainWindow::setPushButtonQss(QPushButton *btn, int radius, int padding, const QString &normalColor, const QString &normalTextColor, const QString &hoverColor, const QString &hoverTextColor, const QString &pressedColor, const QString &pressedTextColor){
    QStringList list;
        list.append(QString("QPushButton{border-style:none;padding:%1px;border-radius:%2px;color:%3;background:%4;}")
                    .arg(padding).arg(radius).arg(normalTextColor).arg(normalColor));
        list.append(QString("QPushButton:hover{color:%1;background:%2;}")
                    .arg(hoverTextColor).arg(hoverColor));
        list.append(QString("QPushButton:pressed{color:%1;background:%2;}")
                    .arg(pressedTextColor).arg(pressedColor));

        QString qss = list.join("");
        btn->setStyleSheet(qss);
        return qss;
}

QString MainWindow::setLineEditQss(QLineEdit *txt, int radius, int borderWidth, const QString &normalColor, const QString &focusColor){
    QStringList list;
        list.append(QString("QLineEdit{border-style:none;padding:3px;border-radius:%1px;border:%2px solid %3;}")
                    .arg(radius).arg(borderWidth).arg(normalColor));
        list.append(QString("QLineEdit:focus{border:%1px solid %2;}")
                    .arg(borderWidth).arg(focusColor));

        QString qss = list.join("");
        txt->setStyleSheet(qss);
        return qss;
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

    QComboBox *posbox = new QComboBox(&dialog);
    QStringList list;
    for(int i=1;i<4;i++){
        list<<QString::fromStdString(PosString[i]);
    }
    posbox->addItems(list);
    form.addRow("职位",posbox);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        data::EmployeePosition pos=data::EmployeePosition::All;
        if(posbox->currentText()=="Ordinary")pos=data::EmployeePosition::Ordinary;
        if(posbox->currentText()=="Internship")pos=data::EmployeePosition::Internship;
        if(posbox->currentText()=="Senior")pos=data::EmployeePosition::Senior;
        Decorater decorater; decorater.Add(idtxt->text().toStdString(),nametxt->text().toStdString(),salarytxt->text().toFloat(),citytxt->text().toStdString(),pos,model);
    }
}

void MainWindow::Searchmember(){
    int searchtype=0;
    if(ui->lineEdit->text().isEmpty())searchtype=1;
    data::EmployeePosition pos=data::EmployeePosition::All;
    if(ui->comboBox_3->currentText()=="Ordinary")pos=data::EmployeePosition::Ordinary;
    if(ui->comboBox_3->currentText()=="Internship")pos=data::EmployeePosition::Internship;
    if(ui->comboBox_3->currentText()=="Senior")pos=data::EmployeePosition::Senior;
    Decorater decorater;decorater.search(searchtype,ui->lineEdit->text().toStdString(),pos,model);
}



void MainWindow::delslot(){
    std::string id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toString().toStdString();
    Decorater decorater;decorater.Del(id,model);
}

void MainWindow::modifyslot(){

    QString id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toString();
    QString name=model->data(model->index(ui->tableView->currentIndex().row(),1)).toString();
    int salary=model->data(model->index(ui->tableView->currentIndex().row(),2)).toInt();
    QString city=model->data(model->index(ui->tableView->currentIndex().row(),3)).toString();
    QString pos=model->data(model->index(ui->tableView->currentIndex().row(),4)).toString();


    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("要修改的员工信息:"));

    QLineEdit *nametxt=new QLineEdit(&dialog);
    nametxt->setText(name);
    form.addRow("姓名",nametxt);

    QLineEdit *salarytxt=new QLineEdit(&dialog);
    salarytxt->setText(QString::number(salary));
    form.addRow("工资",salarytxt);

    QLineEdit *citytxt=new QLineEdit(&dialog);
    citytxt->setText(city);
    form.addRow("城市",citytxt);

    QComboBox *posbox = new QComboBox(&dialog);
    QStringList list;
    for(int i=1;i<4;i++){
        list<<QString::fromStdString(PosString[i]);
    }
    posbox->addItems(list);
    form.addRow("职位",posbox);



    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        data::EmployeePosition pos=data::EmployeePosition::All;
        if(posbox->currentText()=="Ordinary")pos=data::EmployeePosition::Ordinary;
        if(posbox->currentText()=="Internship")pos=data::EmployeePosition::Internship;
        if(posbox->currentText()=="Senior")pos=data::EmployeePosition::Senior;
        Decorater decorater;decorater.Modify(id.toStdString(),nametxt->text().toStdString(),salarytxt->text().toFloat(),citytxt->text().toStdString(),pos,model);
    }
}

void MainWindow::modifyMangerslot(){
    QDialog dialog(this);
    QFormLayout form(&dialog);
    QLineEdit *Mangeridtxt=new QLineEdit(&dialog);
    form.addRow("要修改成的管理员ID:",Mangeridtxt);
    QString id=model->data(model->index(ui->tableView->currentIndex().row(),0)).toString();
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        Decorater decorater;
        decorater.ModifyManger(id.toStdString(),Mangeridtxt->text().toStdString(),model);
    }
}


