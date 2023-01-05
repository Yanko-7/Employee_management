#pragma once
#include "EmployeeDAO.h"
#include "ManagerDAO.h"
#include "UserDAO.h"
class DiFactory
{
public:
    EmployeeDAO getEmployeeDAO();
    ManagerDAO getManagerDAO();
    UserDAO getUserDAO();
    static DiFactory& getInstance();
private:
    EmployeeDAO employeeDAO;
    ManagerDAO managerDAO;
    UserDAO userDAO;
    static DiFactory* instance;
};