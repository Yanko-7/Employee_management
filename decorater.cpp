#include "decorater.h"
#include "User.h"
using namespace data;

Decorater::Decorater() {

}


void Decorater::search(int searchtype, string idtxt, EmployeePosition position, QStandardItemModel* model) {
    //获取对应职位的员工集合
    set<Employee> employeeSet;
    if (position == EmployeePosition::All)
    {
        employeeSet = Manager::getInstance()->SearchEmployee();
    }
    else
    {
        employeeSet = Manager::getInstance()->SearchEmployee(position);
    }
    //searchtype !=1说明指定了ID，则二次筛选
    if (searchtype != 1)
    {
        for (auto iter = employeeSet.cbegin(); iter != employeeSet.cend(); iter++)
        {
            if (((Employee)*iter).getID() == idtxt)
            {
                Employee e = *iter;
                employeeSet.clear();
                employeeSet.insert(e);
                break;
            }
        }
    }
    updateview(employeeSet, model);
}


void Decorater::Add(string idtxt, string nametxt, float salary, string city, EmployeePosition pos, QStandardItemModel* model) {
    Employee* newemployee = new Employee(idtxt, nametxt, city, pos, salary);
    *Manager::getInstance() + *newemployee;
    updateview(Manager::getInstance()->SearchEmployee(), model);
}

void Decorater::Del(string idtxt, QStandardItemModel* model) {
    *Manager::getInstance() - (Manager::getInstance()->SearchEmployee(idtxt));
    updateview(Manager::getInstance()->SearchEmployee(), model);
}

void Decorater::Modify(string idtxt, string nametxt, float salary, string citytxt, EmployeePosition pos, QStandardItemModel* model) {
    Manager::getInstance()->SetEmployeeInfo(idtxt, nametxt, citytxt, pos);
    Manager::getInstance()->ChangeEmployeeSalary(idtxt, salary);
    updateview(Manager::getInstance()->SearchEmployee(), model);
}

void Decorater::ModifyManger(string employeeID, string managerID, QStandardItemModel* model)
{
    Manager::getInstance()->ChangeEmployeeManager(employeeID, managerID);
    updateview(Manager::getInstance()->SearchEmployee(), model);
}


void Decorater::updateview(std::set<Employee> sett, QStandardItemModel* model) {
    model->removeRows(0, model->rowCount());
    for (auto x : sett) {
        QList<QStandardItem*> items;
        items << new QStandardItem(QString::fromStdString(x.getID())) << new QStandardItem(QString::fromStdString(x.getName())) << new QStandardItem(QString::number(x.getSalary())) << new QStandardItem(QString::fromStdString(x.getCity())) << new QStandardItem(QString::fromStdString(x.getStringPosition()));
        model->appendRow(items);
    }
}

bool Decorater::loggin(string id, string password) {
    User* user = new User(id, password);
    if (user->Login())
    {
        delete user;
        return true;
    }
    delete user;
    return false;
}

bool Decorater::reggister(string id, string password) {
    User* user = new User(id, password);
    if (user->Register())
    {
        delete user;
        return true;
    }
    delete user;
    return false;
}
