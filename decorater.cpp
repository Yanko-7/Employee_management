#include "decorater.h"

Decorater::Decorater(){

}


void Decorater::Add(string idtxt, string nametxt, float salary,string city, QStandardItemModel *model){

}

void Decorater::Del(string idtxt, QStandardItemModel *model){

}

void Decorater::updateview(std::set<data::Employee> sett, QStandardItemModel *model){
    model->removeRows(0,model->rowCount());
    for(auto x:sett){
        QList<QStandardItem*> items;
        items<<new QStandardItem(QString::fromStdString(x.getID()))<<new QStandardItem(QString::fromStdString(x.getName()))<<new QStandardItem(QString::number(x.getSalary()))<<new QStandardItem(QString::fromStdString(x.getCity()));
        model->appendRow(items);
    }
}


//void Decorater::updateview(){

//    void MainWindow::updateview(QList<Decorater*> list){//更新talbeview  需要传入list
//        model->removeRows(0,model->rowCount());
//        for(auto x:list){
//            QList<QStandardItem*> items;
//            items<<new QStandardItem(QString::number(x->getid()))<<new QStandardItem(x->getname())<<new QStandardItem(QString::number(x->getsalary()));
//            model->appendRow(items);
//        }
//    }
//}




