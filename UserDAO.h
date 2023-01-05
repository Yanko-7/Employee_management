#pragma once
#include"User.h"
#include"DatabaseUtil.h"
using namespace data;
class UserDAO
{
public:
    bool saveData(User& user);
    bool updateData(User& user);
    bool deleteData(User& user);
    User* findData(string& id);
};