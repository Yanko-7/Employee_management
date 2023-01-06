#include "DatabaseUtil.h"

DatabaseUtil* DatabaseUtil::instance = nullptr;

DatabaseUtil::DatabaseUtil() {
    connect();
}

DatabaseUtil::~DatabaseUtil() {
    disconnect();
}

DatabaseUtil& DatabaseUtil::getInstance() {
    //单例模式
    if (!instance)
        instance = new DatabaseUtil();
    return *instance;
}

bool DatabaseUtil::connect() {
    //连接数据库
    string filePath = "./database.db";
    int ret = sqlite3_open(filePath.c_str(), &pdb);
    if (ret != SQLITE_OK) {
        cout << "数据库连接失败！" << endl;
        return false;
    }
    cout << "数据库连接成功！" << endl;
    //尝试建表
    createTable();
    //打开外键约束
    string sql = "PRAGMA foreign_keys = ON;";
    ret = sqlite3_exec(pdb, sql.c_str(), 0, 0, NULL);
    return true;
}

void DatabaseUtil::disconnect() {
    sqlite3_close(pdb);
    cout << "关闭连接" << endl;
}

void DatabaseUtil::createTable()
{
    //创建表
    int ret;
    //创建user表
    string user = "create table if not exists user(id text, password text, primary key(id)); ";
    ret = sqlite3_exec(pdb, user.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "表 user 创建失败：" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "表 user 创建/获取成功！" << endl;
    }
    //创建manager表
    string manager = "create table if not exists manager( id text, name text, primary key(id), constraint fk_user foreign key(id) references user(id) ); ";
    ret = sqlite3_exec(pdb, manager.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "表 manager 创建失败：" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "表 manager 创建/获取成功！" << endl;
    }
    //创建employee表
    string employee = "create table if not exists employee( id text, name text, city text, position text, manager_id text, salary real, primary key(id), constraint fk_manager foreign key(manager_id) references manager(id)); ";
    ret = sqlite3_exec(pdb, employee.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        cout << "表 employee 创建失败：" << sqlite3_errmsg(pdb) << endl;
    }
    else {
        cout << "表 employee 创建/获取成功！" << endl;
    }
    return;
}

bool DatabaseUtil::updateData(string& sql)
{
    //更新操作
    if (!execute(sql)) {
        cout << "更新失败：" << sql << endl;
        cout << "原因：" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

bool DatabaseUtil::saveData(string& sql)
{
    //保存操作
    if (!execute(sql)) {
        cout << "保存失败：" << sql << endl;
        cout << "原因：" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

bool DatabaseUtil::deleteData(string& sql)
{
    //删除操作
    if (!execute(sql)) {
        cout << "删除失败：" << sql << endl;
        cout << "原因：" << sqlite3_errmsg(pdb) << endl;
        return false;
    }
    return true;
}

void DatabaseUtil::find(string& sql, char*** result, int& nrow, int& ncol) {
    //查询操作
    int ret = sqlite3_get_table(pdb, sql.c_str(), result, &nrow, &ncol, NULL);
    if (ret != SQLITE_OK) {
        cout << "查询失败：" << sql << endl;
        cout << "原因：" << sqlite3_errmsg(pdb) << endl;
    }
}

bool DatabaseUtil::execute(string& sql) {
    //执行语句操作
    int ret = sqlite3_exec(pdb, sql.c_str(), 0, 0, NULL);
    if (ret != SQLITE_OK) {
        return false;
    }
    return true;
}