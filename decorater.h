#ifndef DECORATER_H
#define DECORATER_H

#include <mainwindow.h>
#include <QString>
#include <Employee.h>
#include <Manager.h>
#include <EmployeePosition.cpp>
#include <Employee.h>
#include <set>



class Decorater{

public:
    Decorater();
    void search(int searchtype,std::string idtxt,data::EmployeePosition,QStandardItemModel *model);//searchtype==0精确搜索,==1模糊搜索
    void Add(std::string idtxt,std::string nametxt,float salary,std::string city,data::EmployeePosition pos,QStandardItemModel *model);
    void Del(std::string idtxt,QStandardItemModel *model);
    void Modify(std::string idtxt,std::string nametxt,float slary,std::string citytxt,data::EmployeePosition pos,QStandardItemModel *model);
    void updateview(std::set<data::Employee>,QStandardItemModel *model);
    bool loggin(std::string name,std::string password);
    bool reggister(std::string name,std::string password);
    void ModifyManger(std::string employeeid,std::string Mangeridtxt,QStandardItemModel *model);
private:


};

#endif // DECORATER_H
