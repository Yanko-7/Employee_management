#include "Manager.h"
#include "DiFactory.h"
using namespace data;

Manager* Manager::instance = NULL;


Employee Manager::SearchEmployee(string id)
{
    return employeeMap.find(id)->second;
}
set<Employee> Manager::SearchEmployee()
{
    set<Employee> employeeSet;
    map<string, Employee>::iterator iter;
    for (iter = employeeMap.begin(); iter != employeeMap.end(); iter++)
    {
        employeeSet.insert(iter->second);
    }
    return employeeSet;
}
set<Employee> Manager::SearchEmployee(EmployeePosition position)
{
    set<Employee> employeeSet;
    map<string, Employee>::iterator iter;
    for (iter = employeeMap.begin(); iter != employeeMap.end(); iter++)
    {
        if (iter->second.position == position)
        {
            employeeSet.insert(iter->second);
        }
    }
    return employeeSet;
}

bool Manager::ChangeEmployeeSalary(string id, float salary)
{
    if (employeeMap.count(id) == 0)
    {
        return false;
    }
    employeeMap.find(id)->second.salary = salary;
    Employee e = employeeMap.find(id)->second;
    DiFactory::getInstance().getEmployeeDAO().updateData(e);
    return true;
}

bool Manager::ChangeEmployeeSalary(set<string> idSet, float salary)
{
    for (auto iter = idSet.cbegin(); iter != idSet.cend(); iter++)
    {
        if (employeeMap.count(*iter) == 0)
        {
            return false;
        }
        employeeMap.find(*iter)->second.salary = salary;
        Employee e = employeeMap.find(*iter)->second;
        DiFactory::getInstance().getEmployeeDAO().updateData(e);
    }
    return true;
}
bool data::Manager::ChangeEmployeeManager(string id, string manager_id)
{
    if (employeeMap.count(id) == 0)
    {
        return false;
    }
    //查看数据库缓存是否存在该管理员
    Employee e = employeeMap.find(id)->second;
    if (DiFactory::getInstance().getEmployeeDAO().updateData(e))
    {
        employeeMap.find(id)->second.manager_id = manager_id;
        employeeMap.erase(id);
        return true;
    }
    return false;
}
void Manager::SetEmployeeInfo(string id, string name, string city, EmployeePosition position)
{
    if (employeeMap.count(id) == 0)
    {
        return;
    }
    //修改缓存map
    employeeMap.find(id)->second.name = name;
    employeeMap.find(id)->second.city = city;
    employeeMap.find(id)->second.position = position;
    //修改数据库
    Employee e = employeeMap.find(id)->second;
    DiFactory::getInstance().getEmployeeDAO().updateData(e);
}
Manager& Manager::operator+(const Employee& employee)
{
    //修改缓存map
    employeeMap.insert(make_pair(employee.id, employee));
    employeeMap.find(employee.id)->second.manager_id = id;
    //修改数据库
    Employee e = employeeMap.find(employee.id)->second;
    DiFactory::getInstance().getEmployeeDAO().saveData(e);
    return *this;
}
Manager& Manager::operator-(const Employee& employee)
{
    if (employeeMap.count(id) != 0)
    {
        //修改缓存map
        employeeMap.erase(employee.id);
        //修改数据库
        Employee e(employee);
        DiFactory::getInstance().getEmployeeDAO().deleteData(e);
    }
    return *this;
}
Manager* Manager::getInstance()
{
    return Manager::instance;
}
void Manager::Init(string id, string name)
{
    Manager::instance = new Manager(id, name);
    if (DiFactory::getInstance().getManagerDAO().findData(id) == NULL)
    {
        DiFactory::getInstance().getManagerDAO().saveData(*instance);
    }
    //初始化map
    set<Employee*> employeeSet = DiFactory::getInstance().getEmployeeDAO().findAll();
    for (auto iter = employeeSet.cbegin(); iter != employeeSet.cend(); iter++)
    {
        if ((*iter)->manager_id == id)
        {
            instance->employeeMap.insert(make_pair((*iter)->id, **iter));
        }
    }
}
Manager::Manager(string id, string name) :Person(id, name)
{
}