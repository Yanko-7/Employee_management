#include "decorater.h"

Decorater::Decorater(){

}

void Decorater::search(int searchtype, string idtxt,data::EmployeePosition,QStandardItemModel *model){//searchtype==1说明没有指定ID,
    //
    //
    //updateview(data::Manager::getInstance()->SearchEmployee(),model);
}


void Decorater::Add(string idtxt, string nametxt, float salary,string city,data::EmployeePosition pos,QStandardItemModel *model){
    data::Employee *newemployee = new data::Employee(idtxt,nametxt,city,pos,0,salary);
    *data::Manager::getInstance()+*newemployee;
    //updateview(data::Manager::getInstance()->SearchEmployee(),model);
}

void Decorater::Del(string idtxt, QStandardItemModel *model){
    //
    //
    //
    //updateview(data::Manager::getInstance()->SearchEmployee(),model);
}

void Decorater::Modify(string idtxt, string nametxt, float slary, string citytxt, data::EmployeePosition pos, QStandardItemModel *model){

}


void Decorater::updateview(std::set<data::Employee> sett, QStandardItemModel *model){
    model->removeRows(0,model->rowCount());
    for(auto x:sett){
        QList<QStandardItem*> items;
        items<<new QStandardItem(QString::fromStdString(x.getID()))<<new QStandardItem(QString::fromStdString(x.getName()))<<new QStandardItem(QString::number(x.getSalary()))<<new QStandardItem(QString::fromStdString(x.getCity()))<<new QStandardItem(QString::fromStdString(x.getStringPosition()));
        model->appendRow(items);
    }
}

bool Decorater::loggin(string name, string password){

    return true;
}

bool Decorater::reggister(string name, string password){

}


void Decorater::ModifyManger(string employeeid,string Mangeridtxt, QStandardItemModel *model){

}





