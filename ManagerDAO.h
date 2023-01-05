#pragma once
#include"Manager.h"
#include<string>
#include"DatabaseUtil.h"
using namespace std;
using namespace data;
class ManagerDAO
{
public:
    bool saveData(Manager& manager);
    bool updateData(Manager& manager);
    bool deleteData(Manager& manager);
    Manager* findData(string& id);
};

