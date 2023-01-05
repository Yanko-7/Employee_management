#ifndef DECORATER_H
#define DECORATER_H

#include <mainwindow.h>
#include <QString>

#include <Employee.h>
#include <set>



class Decorater{

public:
    Decorater();
    void Add(std::string idtxt,std::string nametxt,float salary,std::string city,QStandardItemModel *model);
    void Del(std::string idtxt,QStandardItemModel *model);
    void updateview(std::set<data::Employee>,QStandardItemModel *model);

private:


};

#endif // DECORATER_H
