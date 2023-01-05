#include "DiFactory.h"

DiFactory* DiFactory::instance = nullptr;

DiFactory& DiFactory::getInstance()
{
    if (!instance)
        instance = new DiFactory();
    return *instance;
}

EmployeeDAO DiFactory::getEmployeeDAO()
{
    return employeeDAO;
}

ManagerDAO DiFactory::getManagerDAO()
{
    return managerDAO;
}

UserDAO DiFactory::getUserDAO()
{
    return userDAO;
}
