#include "decorater.h"

Decorater::Decorater(){

}

int Decorater::getid(){
    return id;
}

QString Decorater::getname(){
    return name;
}

int Decorater::getsalary(){
    return salary;
}

Decorater::Decorater(int id1, QString name1, int salary1):id(id1),name(name1),salary(salary1){
}

bool Decorater::isemployee(){
    return is_employee;
}
