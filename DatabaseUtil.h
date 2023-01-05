#pragma once
#include"sqlite3.h"
#include<string>
#include<iostream>
using namespace std;
class DatabaseUtil
{
public:
    static DatabaseUtil& getInstance();
    bool connect();
    void disconnect();
    bool updateData(string& sql);
    bool saveData(string& sql);
    bool deleteData(string& sql);
    void find(string& sql, char*** result, int& nrow, int& ncol);
    ~DatabaseUtil();
private:
    DatabaseUtil();
    void createTable();
    static DatabaseUtil* instance;
    bool execute(string& sql);
    sqlite3* pdb;
};
