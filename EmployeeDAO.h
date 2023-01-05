#pragma once
#include<set>
#include"Employee.h"
#include<string>
#include"DatabaseUtil.h"
#include <cstring>
using namespace std;
using namespace data;
class EmployeeDAO
{
public:
    bool saveData(Employee& employee);
    bool updateData(Employee& employee);
    bool deleteData(Employee& employee);
    Employee* findData(string& id);
    set<Employee*> findAll();
};

