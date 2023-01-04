#ifndef DECORATER_H
#define DECORATER_H

#include <QString>



class Decorater
{
public:
    Decorater();
    int getid();
    QString getname();
    int getsalary();
    Decorater(int,QString,int);
private:
    int id;
    QString name;
    int salary;
    bool is_employee=1;
};

#endif // DECORATER_H
